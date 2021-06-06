/*

 MIT License
 
 Copyright © 2021 Samuel Venable
 Copyright © 2021 Lars Nilsson
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
*/

#include "crossprocess.h"

namespace enigma_user {

using CrossProcess::PROCID;
using CrossProcess::PROCESS;
using CrossProcess::PROCINFO;
using CrossProcess::_PROCINFO;
using CrossProcess::PROCINFOLIST;
using CrossProcess::_PROCINFOLIST;
using CrossProcess::ProcIdEnumerate;
using CrossProcess::FreeProcId;
using CrossProcess::ProcIdFromSelf;
using CrossProcess::ParentProcIdFromSelf;
using CrossProcess::ProcIdExists;
using CrossProcess::ProcIdKill;
using CrossProcess::ParentProcIdFromProcId;
using CrossProcess::ProcIdFromParentProcId;
using CrossProcess::ExeFromProcId;
using CrossProcess::DirectoryGetCurrentWorking;
using CrossProcess::DirectorySetCurrentWorking;
using CrossProcess::CwdFromProcId;
using CrossProcess::FreeCmdline;
using CrossProcess::CmdlineFromProcId;
using CrossProcess::ParentProcIdFromProcIdSkipSh;
using CrossProcess::ProcIdFromParentProcIdSkipSh;
using CrossProcess::EnvironmentGetVariable;
using CrossProcess::EnvironmentSetVariable;
using CrossProcess::FreeEnviron;
using CrossProcess::EnvironFromProcId;
using CrossProcess::EnvironFromProcIdEx;
using CrossProcess::ProcInfoFromInternalProcInfo;
using CrossProcess::InternalProcInfoFromProcInfo;
using CrossProcess::ProcInfoFromProcId;
using CrossProcess::InternalProcInfoFromProcId;
using CrossProcess::FreeProcInfo;
using CrossProcess::FreeInternalProcInfo;
using CrossProcess::ProcessId;
using CrossProcess::ExecutableImageFilePath;
using CrossProcess::CurrentWorkingDirectory;
using CrossProcess::ParentProcessId;
using CrossProcess::ChildProcessId;
using CrossProcess::ChildProcessIdLength;
using CrossProcess::CommandLine;
using CrossProcess::CommandLineLength;
using CrossProcess::Environment;
using CrossProcess::EnvironmentLength;
using CrossProcess::ProcessExecute;
using CrossProcess::ProcessExecuteAsync;
using CrossProcess::ExecutedProcessWriteToStandardInput;
using CrossProcess::ExecutedProcessReadFromStandardOutput;
using CrossProcess::FreeExecutedProcessStandardInput;
using CrossProcess::FreeExecutedProcessStandardOutput;
using CrossProcess::CompletionStatusFromExecutedProcess;
using CrossProcess::ProcInfoListFromInternalProcInfoList;
using CrossProcess::InternalProcInfoListFromProcInfoList;
using CrossProcess::InternalProcInfoEnumerate;
using CrossProcess::ProcInfoEnumerate;
using CrossProcess::FreeInternalProcInfoList;
using CrossProcess::FreeProcInfoList;
using CrossProcess::ProcessInfo;
using CrossProcess::ProcessInfoLength;
#if defined(XPROCESS_GUIWINDOW_IMPL)
using CrossProcess::WINDOW;
using CrossProcess::WINDOWID;
using CrossProcess::WindowIdFromNativeWindow;
using CrossProcess::NativeWindowFromWindowId;
using CrossProcess::WindowIdEnumerate;
using CrossProcess::ProcIdFromWindowId;
using CrossProcess::WindowIdFromProcId;
using CrossProcess::FreeWindowId;
using CrossProcess::WindowIdExists;
using CrossProcess::WindowIdKill;
using CrossProcess::OwnedWindowId;
using CrossProcess::OwnedWindowIdLength;
#endif

} // namespace enigma_user
