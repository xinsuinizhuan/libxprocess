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

#include "enigma.h"

using CrossProcess::PROCID;
using CrossProcess::PROCESS;
using CrossProcess::PROCINFO;
using CrossProcess::PROCLIST;
#if defined(XPROCESS_GUIWINDOW_IMPL)
using CrossProcess::WINDOWID;
#endif

namespace enigma_user {

// execute process from the shell, return process id
double ProcessExecute(std::string command) {
  return CrossProcess::ProcessExecute(command.c_str());
}

// execute process from the shell async, return process id
double ProcessExecuteAsync(std::string command) {
  return CrossProcess::ProcessExecuteAsync(command.c_str());
}

//  get whether executed process has quit based on process id
double CompletionStatusFromExecutedProcess(double procIndex) {
  return CrossProcess::CompletionStatusFromExecutedProcess((PROCESS)procIndex);
}

// write to executed process standard input file descriptor based on process id
double ExecutedProcessWriteToStandardInput(double procIndex, std::string input) {
  CrossProcess::ExecutedProcessWriteToStandardInput((PROCESS)procIndex, input.c_str()); return 0;
}

// read from executed process standard output file descriptor based on process id
std::string ExecutedProcessReadFromStandardOutput(double procIndex) {
  return CrossProcess::ExecutedProcessReadFromStandardOutput((PROCESS)procIndex);
}

// free executed process standard input string based on process id
double FreeExecutedProcessStandardInput(double procIndex) {
  CrossProcess::FreeExecutedProcessStandardInput((PROCESS)procIndex); return 0;
}

// free executed process standard ouptut string based on process id
double FreeExecutedProcessStandardOutput(double procIndex) {
  CrossProcess::FreeExecutedProcessStandardOutput((PROCESS)procIndex); return 0;
}

// get process id from self
double ProcIdFromSelf() {
  return CrossProcess::ProcIdFromSelf();
}

// get parent process id from self
double ParentProcIdFromSelf() {
  return CrossProcess::ParentProcIdFromSelf();
}

// get whether process exists based on process id
double ProcIdExists(double procId) {
  return CrossProcess::ProcIdExists((PROCID)procId);
}

// kill process based on process id, return whether succeeded
double ProcIdKill(double procId) {
  return CrossProcess::ProcIdKill((PROCID)procId);
}

// get executable image file path from self
std::string ExecutableFromSelf() {
  return CrossProcess::ExecutableFromSelf();
}

// get executable image file path from process id
std::string ExeFromProcId(double procId) {
  return CrossProcess::ExeFromProcId((PROCID)procId);
}

// get current working directory from process id
std::string CwdFromProcId(double procId) {
  return CrossProcess::CwdFromProcId((PROCID)procId);
}

// get process info from process id
double ProcInfoFromProcId(double procId) {
  return CrossProcess::ProcInfoFromProcId((PROCID)procId);
}

// free process info data from memory
double FreeProcInfo(double procInfo) {
  CrossProcess::FreeProcInfo((PROCINFO)procInfo); return 0;
}

// create a list of all process id's
double ProcListCreate() {
  return CrossProcess::ProcListCreate();
}

// get process id from process list at index
double ProcessId(double procList, double i) {
  return CrossProcess::ProcessId((PROCLIST)procList, (int)i);
}

// get amount of process id's in process list
double ProcessIdLength(double procList) {
  return CrossProcess::ProcessIdLength((PROCLIST)procList);
}

// free list of process id's from memory
double FreeProcList(double procList) {
  CrossProcess::FreeProcList((PROCLIST)procList); return 0;
}

// get executable image file path from process info data
std::string ExecutableImageFilePath(double procInfo) {
  return CrossProcess::ExecutableImageFilePath((PROCINFO)procInfo);
}

// get current working directory ffrom process info data
std::string CurrentWorkingDirectory(double procInfo) {
  return CrossProcess::CurrentWorkingDirectory((PROCINFO)procInfo);
}

// get parent processs id from process info data
double ParentProcessId(double procInfo) {
  return CrossProcess::ParentProcessId((PROCINFO)procInfo);
}

// get child process id from process info data at index
double ChildProcessId(double procInfo, double i) {
  return CrossProcess::ChildProcessId((PROCINFO)procInfo, (int)i);
}

// get amount of child processes from process info data
double ChildProcessIdLength(double procInfo) {
  return CrossProcess::ChildProcessIdLength((PROCINFO)procInfo);
}

// get command line argument from process info data at index
std::string CommandLine(double procInfo, double i) {
  return CrossProcess::CommandLine((PROCINFO)procInfo, (int)i);
}

// get amount of command line arguments from process info data
double CommandLineLength(double procInfo) {
  return CrossProcess::CommandLineLength((PROCINFO)procInfo);
}

// get environment variable (NAME=VALUE) from process info at index
std::string Environment(double procInfo, double i) {
  return CrossProcess::Environment((PROCINFO)procInfo, (int)i);
}

// get amount of anvironment variables from process info at index
double EnvironmentLength(double procInfo) {
  return CrossProcess::EnvironmentLength((PROCINFO)procInfo);
}

// get current working directory
std::string DirectoryGetCurrentWorking() {
  return CrossProcess::DirectoryGetCurrentWorking();
}

// set current working directory based on a given dname
double DirectorySetCurrentWorking(std::string dname) {
  return CrossProcess::DirectorySetCurrentWorking(dname.c_str());
}

// get the environment variable of the given name
std::string EnvironmentGetVariable(std::string name) {
  return CrossProcess::EnvironmentGetVariable(name.c_str());
}

// set the environment variable with the given name and value
double EnvironmentSetVariable(std::string name, std::string value) {
  return CrossProcess::EnvironmentSetVariable(name.c_str(), value.c_str());
}

// unset the environment variable with the given name
double EnvironmentUnsetVariable(std::string name) {
  return CrossProcess::EnvironmentUnsetVariable(name.c_str());
}

#if defined(XPROCESS_GUIWINDOW_IMPL)
// get owned window id string from process info at index
std::string OwnedWindowId(double procInfo, double i) {
  return CrossProcess::OwnedWindowId((PROCINFO)procInfo, (int)i);
}

// get amount of owned window id's from process info at index
double OwnedWindowIdLength(double procInfo) {
  return CrossProcess::OwnedWindowIdLength((PROCINFO)procInfo);
}

// get whether a process exists based on one of its window id's
double WindowIdExists(std::string winId) {
  return CrossProcess::WindowIdExists((WINDOWID)winId.c_str());
}

// kill a process based on one of its window id's, return whether succeeded
double WindowIdKill(std::string winId) {
  return CrossProcess::WindowIdKill((WINDOWID)winId.c_str());
}

// return a window id from native window handle
std::string WindowIdFromNativeWindow(void *window) {
  #if (defined(__APPLE__) && defined(__MACH__))
  return CrossProcess::WindowIdFromNextStepWindow(window);
  #else
  return CrossProcess::WindowIdFromNativeWindow((void *)(std::uintpr_t)(CrossProcess::WINDOW)window);
  #endif
} 
#endif

} // namespace enigma_user
