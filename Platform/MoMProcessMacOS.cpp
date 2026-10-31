// ---------------------------------------------------------------------------
// Copyright:   2026 MoM-RTGT contributors
// License:     GPL
// Created:     2026-10-31
// ---------------------------------------------------------------------------

// OS Specific

// macOS placeholder: attaching to a running DOSBox is not implemented yet.
// A real implementation needs task_for_pid() plus mach_vm_read_overwrite() /
// mach_vm_write(), which requires root or the com.apple.security.cs.debugger
// entitlement. Until then, the file-based features (saves, EXE, LBX) work on macOS.

#include <unistd.h>     // usleep()

#include <iostream>
#include <string.h>     // strerror()

#include "MoMProcess.h"

namespace MoM {

void MoMProcess::closeProcess() throw()
{
    m_hProcess = NULL;
}

bool MoMProcess::createProcess(const char* applicationName, const char* commandLine, const char* currentDirectory)
{
    std::cout << "MoMProcess::createProcess() not implemented on macOS" << std::endl;
    return false;
}

bool MoMProcess::terminateCreatedProcess()
{
    std::cout << "MoMProcess::terminateCreatedProcess() not implemented on macOS" << std::endl;
    return false;
}

bool MoMProcess::findProcessAndData()
{
    std::cout << "MoMProcess::findProcessAndData() not implemented on macOS" << std::endl;
    return false;
}

bool MoMProcess::readProcessData(void* hProcess, const uint8_t* lpBaseAddress, size_t size, uint8_t* data)
{
    return false;
}

bool MoMProcess::writeData(const void* pointer, size_t size)
{
    return false;
}

void MoMProcess::printError(int errorNumber, const std::string& msg)
{
    std::cout << "WARN: " << msg << ": " << strerror(errorNumber) << std::endl;
}

void MoMProcess::sleepSec(double timeout)
{
    useconds_t microseconds = (useconds_t)(timeout * 1000000 + 0.5);
    usleep(microseconds);
}

}
