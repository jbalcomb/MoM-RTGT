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


MoMProcess::MoMProcess(void) :
    m_hProcess(NULL),
    m_lpBaseAddress(0),
    m_dwBaseAddressSize(0),
    m_dwOffsetSegment0(0),
    m_dwOffsetCode(0),
    m_dwOffsetDatasegment(0),
    m_dataSegmentAndUp()
{
}

MoMProcess::~MoMProcess(void)
{
    close();
}

void MoMProcess::close() throw()
{
    m_dataSegmentAndUp.clear();

    m_lpBaseAddress = 0;
    m_dwBaseAddressSize = 0;
    m_dwOffsetSegment0 = 0;
    m_dwOffsetCode = 0;
    m_dwOffsetDatasegment = 0;
    m_hProcess = NULL;
}

bool MoMProcess::findProcessAndData()
{
    std::string title = "dosbox";

    close();

    std::string filename;
    std::string cmd;

    // Find pid of DOSBox
    pid_t pid = 0;
    filename = "dosbox.pid";
    cmd = "ps -e | grep " + title + " | awk '{ print $1; }' >" + filename;
    fflush(NULL);   // Flush before system()
    if (0 != system(cmd.c_str()))
    {
        std::cout << "MoM process '" << title << "' not found" << std::endl;
        return false;
    }
    else if (!(std::ifstream(filename.c_str()) >> pid))
    {
        std::cout << "MoM process in '" << filename << "' not parseable" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Found MoM process '" << title << "' (pid=" << pid << ")" << std::endl;
    }
    m_hProcess = (void*)pid;

    bool ok = true;
    std::vector<uint8_t> data;

    std::cout << "Detach for safety from pid=" << pid << std::endl;
    detachProcess(pid);

    // Try to find the memory region of MoM within DOSBox (or use the defaults)
    std::cout << "Search for MoM Data Segment (DS) Identifier (size " << ARRAYSIZE(gDATASEGMENT_IDENTIFIER) << "): ";
    std::cout << gDATASEGMENT_IDENTIFIER + 4 << std::endl;
    filename = "/proc/" + toStr(pid) + "/maps";
    unsigned long start = 0;
    unsigned long stop = 0;
    std::ifstream ifs(filename.c_str());
    if (!ifs)
    {
        printError(errno, "Could not open '" + filename + "'");
        ok = false;
    }
    while (ok && ifs && (0 == m_lpBaseAddress))
    {
        char ch = '\0';
        ifs >> std::hex >> start >> ch >> stop;
        ifs.ignore(1000, '\n');
        size_t size = stop - start;
        std::cout << "Scanning 0x" << std::hex << start << " size 0x" << size << std::dec << std::endl;
        if (readProcessData(m_hProcess, (const uint8_t*)start, size, data))
        {
            for (size_t i = 0; ok && (i + ARRAYSIZE(gDATASEGMENT_IDENTIFIER) < data.size()); ++i)
            {
                if (0 == memcmp(&data[i], gDATASEGMENT_IDENTIFIER, ARRAYSIZE(gDATASEGMENT_IDENTIFIER)))
                {
                    std::cout << "Found MoM BaseAddress 0x" << std::hex << start << " size 0x"<< size << std::dec << std::endl;
                    m_lpBaseAddress = (uint8_t*)start;
                    m_dwBaseAddressSize = size;
                    m_dwOffsetDatasegment = i;
                    std::cout << "Found MoM Data Segment (DS) Identifier (size " << ARRAYSIZE(gDATASEGMENT_IDENTIFIER) << ") at offset 0x" << std::hex << i << std::dec << std::endl;
                    break;
                }
            }
        }
    }
    ifs.close();

    if (0 == m_lpBaseAddress || 0 == m_dwOffsetDatasegment)
    {
        std::cout << "Could not find MoM Data Segment (DS) Identifier (size " << ARRAYSIZE(gDATASEGMENT_IDENTIFIER) << ")" << std::endl;
        ok = false;
    }

    if (ok)
    {
        ok = findSEG0(data);
    }

    if (ok)
    {
        ok = readData();
    }

    return ok;
}

std::string MoMProcess::getExeFilepath()
{
    if (NULL == m_hProcess)
        return "";

    pid_t pid = (pid_t)m_hProcess;
    std::string exeFilepath;

    std::string filename = "dosbox.proc_fd";
    std::string cmd = "ls -l /proc/" + toStr(pid) + "/fd/ | sed -ne 's/.*-> \\(.*\\.EXE\\)/\\1/p' > " + filename;
    fflush(NULL);   // Flush before system()
    if (0 != system(cmd.c_str()))
    {
        std::cout << "MoM ExeFilepath not found with '" << cmd << "'" << std::endl;
        return false;
    }

    std::ifstream ifs(filename.c_str());
    if (!std::getline(ifs, exeFilepath))
    {
        std::cout << "MoM ExeFilepath in '" << filename << "' not parseable" << std::endl;
        return false;
    }

    if (!exeFilepath.empty() && '\n' == exeFilepath[ exeFilepath.size() - 1 ])
    {
        exeFilepath.resize( exeFilepath.size() - 1 );
    }

    std::cout << "Found ExeFilepath '" << exeFilepath << "' (pid=" << pid << ")" << std::endl;

    return exeFilepath;
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

//    char memfile[256];
//    sprintf(memfile, "/proc/%u/mem", (unsigned)pid);
//    int fd = open(memfile, O_RDWR | O_LARGEFILE);
//    if (-1 == fd)
//    {
//        printError(errno, "open");
//        ok = false;
//    }
//
//    if (ok && -1 == pwrite64(fd, pointer, size, (unsigned long)(m_lpBaseAddress + m_dwOffsetDatasegment + offset)))
//    {
//        printError(errno, "pwrite64");
//        ok = false;
//    }
//
//    if (-1 != fd)
//    {
//        ::close(fd);
//    }

//    // On failure, try again with PTRACE_POKEDATA
//    if (!ok)
//    {
//        std::cout << "Commit failed, trying again with PTRACE_POKEDATA" << std::endl;
//        ok = true;

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

//    }

    detachProcess(pid);

    return ok;
}

void MoMProcess::printError(int errorNumber, const std::string& msg)
{
    std::cout << "WARN: " << msg << ": " << strerror(errorNumber) << std::endl;
}

}
