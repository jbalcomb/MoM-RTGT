// ---------------------------------------------------------------------------
// Copyright:   2011 Klaas van Aarsen
// License:     GPL
// Author:      I like Serena (aka Klaas van Aarsen)
// Created:     2010-05-01
// ---------------------------------------------------------------------------

// OS Specific
#include <errno.h>      // errno, strerror()
#include <fcntl.h>      // O_RDONLY, O_WRONLY, O_LARGEFILE
#include <sys/ptrace.h> // ptrace()
#include <sys/types.h>  // pid_t, __off64_t
#include <sys/wait.h>   // waitpid()
#include <unistd.h>     // open(), close(), pread64(), pwrite64()

// Standard C++ Library
#include <fstream>
#include <iomanip>
#include <iostream>
#include <signal.h>     // kill()
#include <stdio.h>      // fflush()
#include <stdlib.h>     // system()
#include <string.h>     // memcmp()

// Libraries / Local
#include "MoMUtility.h"

#include "MoMProcess.h"

namespace MoM {

namespace {

const std::string gPID_FILENAME = "dosbox.pid";

void detachProcess(pid_t pid)
{
    // Try a couple of times
//    std::cout << "PTRACE_DETACH from pid=" << (unsigned)pid << std::endl;
    if (-1 == ptrace(PTRACE_DETACH, pid, NULL, NULL))
    {
        MoMProcess::printError(errno, "PTRACE_DETACH");
    }
}

bool attachProcess(pid_t pid)
{
    // Try a couple of times
//    std::cout << "PTRACE_ATTACH to pid=" << pid << std::endl;
    if (-1 == ptrace(PTRACE_ATTACH, pid, NULL, NULL))
    {
        MoMProcess::printError(errno, "PTRACE_ATTACH");
        return false;
    }

    int status = 0;
    if (pid != waitpid(pid, &status, 0))
    {
        MoMProcess::printError(errno, "waitpid");
        // Note: if we choose to return false here, we need to DETACH the process first
    }
    else
    {
//        std::cout << "waitpid reports status 0x" << std::hex << status << std::dec << std::endl;
    }

    // Note: if we choose to return false here, we need to DETACH the process first
    return true;
}

}

void MoMProcess::closeProcess() throw()
{
    m_hProcess = NULL;
}

bool MoMProcess::findProcessAndData()
{
    const std::string title = "dosbox";

    // Find pid of DOSBox
    std::string cmd = "ps -e | awk '/" + title + "/ { print $1; }' >" + gPID_FILENAME;
    std::cout << cmd << std::endl;
    fflush(NULL);   // Flush before system()
    if (0 != system(cmd.c_str()))
    {
        std::cout << "MoM process '" << title << "' not found" << std::endl;
        return false;
    }

    pid_t pid = 0;
    bool ok = false;
    std::ifstream ifs(gPID_FILENAME.c_str());
    while (!ok && ifs >> pid)
    {
        close();

        std::cout << "Trying process '" << title << "' with pid=" << pid << std::endl;

        ok = tryLinuxPid((void*)pid);
    }

    return ok;
}

bool MoMProcess::tryLinuxPid(void* vPid)
{
    pid_t pid = (pid_t)vPid;
    m_hProcess = vPid;

    bool ok = true;
    std::vector<uint8_t> data;

    // Try to find the memory region of MoM within DOSBox (or use the defaults)
    std::cout << "Search for MoM Data Segment (DS) Identifier (size " << ARRAYSIZE(gDATASEGMENT_IDENTIFIER) << "): ";
    std::cout << gDATASEGMENT_IDENTIFIER + 4 << std::endl;
    std::string filename = "/proc/" + toStr(pid) + "/maps";
    unsigned long start = 0;
    unsigned long stop = 0;
    std::ifstream ifs(filename.c_str());
    if (!ifs)
    {
        printError(errno, "Could not open '" + filename + "'");
        ok = false;
    }
    while (ok && ifs && (0 == m_lpBaseAddress) && ((0 == m_dwOffsetDatasegment) || m_exeFilepath.empty()))
    {
        char ch = '\0';
        ifs >> std::hex >> start >> ch >> stop;
        ifs.ignore(1000, '\n');
        size_t size = stop - start;
        if (m_verbose) std::cout << "Scanning 0x" << std::hex << start << " size 0x" << size << std::dec << std::endl;
        if (readProcessData(m_hProcess, (const uint8_t*)start, size, data))
        {
            ok = findSignatures(start, data);
        }
    }
    ifs.close();

    ok = registerResults(ok);

    return ok;
}

bool MoMProcess::readProcessData(void* hProcess, const uint8_t* lpBaseAddress, size_t size, std::vector<uint8_t>& data)
{
    if (NULL == hProcess)
        return false;
    if (0 == lpBaseAddress)
        return false;
    if (0 == size)
        return false;

    pid_t pid = (pid_t)hProcess;

    if (!attachProcess(pid))
    {
        return false;
    }

    data.resize(size);

    bool ok = true;

    char memfile[256];
    sprintf(memfile, "/proc/%u/mem", (unsigned)pid);
    int fd = open(memfile, O_RDONLY | O_LARGEFILE);
    if (-1 == fd)
    {
        printError(errno, "open");
        ok = false;
    }

    if (-1 == pread64(fd, &data[0], size, (unsigned long)lpBaseAddress))
    {
        printError(errno, "pread64");
        ok = false;
    }

    if (-1 != fd)
    {
        ::close(fd);
    }

    detachProcess(pid);

    return ok;
}

bool MoMProcess::writeData(const void* pointer, size_t size)
{
    std::cout << "MoMProcess::writeData()" << std::endl;
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

    pid_t pid = (pid_t)m_hProcess;

    if (!attachProcess(pid))
    {
        return false;
    }

    bool ok = true;

    size_t i = 0;
    for(; i + sizeof(long) - 1 < size; i += sizeof(long))
    {
        if (-1 == ptrace(PTRACE_POKEDATA, pid, m_lpBaseAddress + m_dwOffsetDatasegment + offset + i, *(long*)((uint8_t*)pointer + i)))
        {
            printError(errno, "PTRACE_POKEDATA");
            ok = false;
            break;
        }
    }

    if (ok && i < size)
    {
        long buf = ptrace(PTRACE_PEEKDATA, pid, m_lpBaseAddress + m_dwOffsetDatasegment + offset + i, NULL);
        if (0 != errno)
        {
            printError(errno, "PTRACE_PEEKDATA");
            ok = false;
        }
        if (ok)
        {
            uint8_t* ptr = (uint8_t*)&buf;
            size_t last_offset = i;
            for (; i < size; ++i)
            {
                ptr[i - last_offset] = *((uint8_t*)pointer + i);
            }
            if (-1 == ptrace(PTRACE_POKEDATA, pid, m_lpBaseAddress + m_dwOffsetDatasegment + offset + last_offset, buf))
            {
                printError(errno, "PTRACE_POKEDATA(last bytes)");
                ok = false;
            }
        }
    }

    detachProcess(pid);

    return ok;
}

void MoMProcess::printError(int errorNumber, const std::string& msg)
{
    std::cout << "WARN: " << msg << ": " << strerror(errorNumber) << std::endl;
}

}
