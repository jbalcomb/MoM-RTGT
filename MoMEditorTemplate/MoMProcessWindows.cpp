// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

#include <windows.h>

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "MoMUtility.h"

#include "MoMProcess.h"

namespace MoM {

// The DOSBox Base Address Size is different depending on OS configuration and DOSBox version
// For DOSBox 0.74 for Windows XP it is the given value (currently)
const DWORD gBASEADDRESS_MINSIZE = 0x1001000;


static BOOL CALLBACK wndEnumProc(HWND hwnd, LPARAM lParam)
{
	std::vector<std::string>& windowTitles = *(std::vector<std::string>*)lParam;

    char szTitle[4096] = "";
    if (0 < GetWindowTextA(hwnd, szTitle, sizeof(szTitle)))
    {
        std::string lowercaseTitle = lowercase(szTitle);
        if (std::string::npos != lowercaseTitle.find("dosbox"))
        {
            windowTitles.push_back(szTitle);
        }
    }

    return TRUE;
}

void MoMProcess::closeProcess() throw()
{
    if (NULL != m_hProcess)
    {
        CloseHandle(m_hProcess);
        m_hProcess = NULL;
    }
}

bool MoMProcess::findProcessAndData()
{
    std::vector<std::string> windowTitles;
    (void)EnumWindows(wndEnumProc, (LPARAM)&windowTitles);

	bool ok = false;
    for (size_t i = 0; !ok && (i < windowTitles.size()); ++i)
	{
		close();

		ok = tryWindowTitle(windowTitles[i]);
    }

	return ok;
}

bool MoMProcess::tryWindowTitle(const std::string& windowTitle)
{
    HWND hwnd = FindWindowA(0, windowTitle.c_str());
    if (0 == hwnd)
    {
        std::cout << "MoM Window '" << windowTitle << "' not found" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Found MoM Window '" << windowTitle << "' (hwnd=0x" << std::hex << (unsigned)hwnd << std::dec << ")" << std::endl;
    }

    DWORD dwProcessId = 0;
    GetWindowThreadProcessId(hwnd, &dwProcessId);

    m_hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, dwProcessId);
    if (NULL == m_hProcess)
    {
        DWORD dwError = GetLastError();
        std::cout << "OpenProcess(ProcessId=" << (unsigned)dwProcessId << ") failed: " << dwError << " (0x" << std::hex << dwError << ")" << std::dec << std::endl;
        return false;
    }
    else
    {
        std::cout << "Opened MoM process (processId=0x" << std::hex << dwProcessId << std::dec << ")" << std::dec << std::endl;
    }

    MEMORY_BASIC_INFORMATION mbi;
    LPBYTE baseAddr = 0;
    SIZE_T size = VirtualQueryEx(m_hProcess, baseAddr, &mbi, sizeof(mbi));
    if (0 == size)
    {
        printError(GetLastError(), "VirtualQueryEx");
        return false;
    }

    bool ok = true;
    std::vector<BYTE> data;

    for (; ok && (0 != size) && ((0 == m_dwOffsetDatasegment) || m_exeFilepath.empty());
        baseAddr += mbi.RegionSize, size = VirtualQueryEx(m_hProcess, baseAddr, &mbi, sizeof(mbi)))
    {
        if (m_verbose)
        {
            std::cout << std::hex << "Scanning virtual memory at baseAddr 0x" << (unsigned)baseAddr
                << ", BaseAddress=0x" << (unsigned)mbi.BaseAddress
                << ", RegionSize=0x" << mbi.RegionSize
                << ", AllocationBase=0x" << (unsigned)mbi.AllocationBase
                << ", AllocationProtect=0x" << mbi.AllocationProtect
                << ", State=0x" << mbi.State
                << ", Protect=0x" << mbi.Protect
                << ", Type=0x" << mbi.Type
                << std::dec << std::endl;
        }
        if ((gBASEADDRESS_MINSIZE <= mbi.RegionSize) && (MEM_PRIVATE == mbi.Type))
        {
            std::cout << std::hex << "Found possible MoM virtual memory (baseAddress=0x" << (unsigned)mbi.BaseAddress << ", size=0x" << mbi.RegionSize << ")" << std::dec << std::endl;
        }
        else if ((0x106000 == mbi.RegionSize) && (MEM_PRIVATE == mbi.Type))
        {
            std::cout << std::hex << "Found region with local directory" << std::endl;
        }
        else if ((mbi.Protect & PAGE_NOACCESS) || (mbi.Protect & PAGE_EXECUTE))
        {
            // Documented access violations: skip
            if (m_verbose)
            {
                std::cout << "Skipped due to protection settings" << std::endl;
            }
            continue;
        }
        else
        {
            if (m_verbose)
            {
                std::cout << "Skipped due to mismatching size" << std::endl;
            }
            continue;
        }

        data.resize(mbi.RegionSize);
        if (!ReadProcessMemory(m_hProcess, mbi.BaseAddress, &data[0], mbi.RegionSize, NULL))
        {
            printError(GetLastError(), "ReadProcessMemory"); // Show cause of failure
        }
        else
        {
            ok = findSignatures((size_t)mbi.BaseAddress, data);
        }
    }

    ok = registerResults(ok);
    
    return ok;
}

void MoMProcess::printError(int errorNumber, const std::string& msg)
{
    DWORD eNum;
    char sysMsg[256];
    char* p;

    eNum = (DWORD)(unsigned)errorNumber;
    FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, eNum,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default lang.
        sysMsg, 256, NULL );

    // Trim the end of the line and terminate it with a null
    p = sysMsg;
    while( ( *p > 31 ) || ( *p == 9 ) )
    {
        ++p;
    }
    do
    {
        *p-- = 0;
    } while( ( p >= sysMsg ) && ( ( *p == '.' ) || ( *p < 33 ) ) );

    // Display the message
    std::cout << "WARN: " << msg << " failed with error 0x" << std::hex << eNum << " (" << sysMsg << ")" << std::hex << std::endl;
}

bool MoMProcess::readProcessData(void* hProcess, const uint8_t* lpBaseAddress, size_t size, std::vector<uint8_t>& data)
{
    if (NULL == hProcess)
        return false;
    if (0 == lpBaseAddress)
        return false;
    if (0 == size)
        return false;

    data.resize(size);
    if (!ReadProcessMemory(hProcess, lpBaseAddress, &data[0], size, NULL))
    {
        printError(GetLastError(), "ReadProcessMemory"); // Show cause of failure
        return false;
    }

    return true;
}

bool MoMProcess::writeData(const void* pointer, size_t size)
{
    if (NULL == m_hProcess)
        return false;
    if (0 == m_lpBaseAddress)
        return false;
    if (0 == m_dwOffsetDatasegment)
        return false;
    if (0 == m_dwOffsetDatasegment)
        return false;
    if (m_dataSegmentAndUp.empty())
        return false;
    size_t offset = (const uint8_t*)pointer - &m_dataSegmentAndUp[0];
    if (m_dwOffsetDatasegment + offset + size > m_dwBaseAddressSize)
        return false;
    if (offset + size > m_dataSegmentAndUp.size())
        return false;

    if (!WriteProcessMemory(m_hProcess, m_lpBaseAddress + m_dwOffsetDatasegment + offset,
        pointer, size, NULL))
    {
        printError(GetLastError(), "WriteProcessMemory"); // Show cause of failure
        return false;
    }

    return true;
}

}
