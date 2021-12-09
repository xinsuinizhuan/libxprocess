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

#include <cstdint>

#include "gamemaker.h"

using ngs::proc::PROCID;
using ngs::proc::LOCALPROCID;
using ngs::proc::PROCINFO;
using ngs::proc::PROCLIST;
#if defined(XPROCESS_GUIWINDOW_IMPL)
using ngs::proc::WINDOWID;
#endif

// execute process from the shell, return process id
double ProcessExecute(char *command) {
  return ngs::proc::process_execute(command);
}

// execute process from the shell async, return process id
double ProcessExecuteAsync(char *command) {
  return ngs::proc::process_execute_async(command);
}

//  get whether executed process has quit based on process id
double CompletionStatusFromExecutedProcess(double procIndex) {
  return ngs::proc::completion_status_from_executed_process((LOCALPROCID)procIndex);
}

// write to executed process standard input file descriptor based on process id
double ExecutedProcessWriteToStandardInput(double procIndex, char *input) {
  ngs::proc::executed_process_write_to_standard_input((LOCALPROCID)procIndex, input); return 0;
}

// read from current process standard input file descriptor
char *CurrentProcessReadFromStandardInput() {
  return (char *)ngs::proc::current_process_read_from_standard_input();
}

// read from executed process standard output file descriptor based on process id
char *ExecutedProcessReadFromStandardOutput(double procIndex) {
  return (char *)ngs::proc::executed_process_read_from_standard_output((LOCALPROCID)procIndex);
}

// free executed process standard input string based on process id
double FreeExecutedProcessStandardInput(double procIndex) {
  ngs::proc::free_executed_process_standard_input((LOCALPROCID)procIndex); return 0;
}

// free executed process standard ouptut string based on process id
double FreeExecutedProcessStandardOutput(double procIndex) {
  ngs::proc::free_executed_process_standard_output((LOCALPROCID)procIndex); return 0;
}

// get process id from self
double ProcIdFromSelf() {
  return ngs::proc::proc_id_from_self();
}

// get parent process id from self
double ParentProcIdFromSelf() {
  return ngs::proc::parent_proc_id_from_self();
}

// get whether process exists based on process id
double ProcIdExists(double procId) {
  return ngs::proc::proc_id_exists((PROCID)procId);
}

// kill process based on process id, return whether succeeded
double ProcIdKill(double procId) {
  return ngs::proc::proc_id_kill((PROCID)procId);
}

// get executable image file path from self
char *ExecutableFromSelf() {
  return (char *)ngs::proc::executable_from_self();
}

// get executable image file path from process id
char *ExeFromProcId(double procId) {
  return (char *)ngs::proc::exe_from_proc_id((PROCID)procId);
}

// get current working directory from process id
char *CwdFromProcId(double procId) {
  return (char *)ngs::proc::cwd_from_proc_id((PROCID)procId);
}

// get process info from process id
double ProcInfoFromProcId(double procId) {
  return ngs::proc::proc_info_from_proc_id((PROCID)procId);
}

// free process info data from memory
double FreeProcInfo(double procInfo) {
  ngs::proc::free_proc_info((PROCINFO)procInfo); return 0;
}

// create a list of all process id's
double ProcListCreate() {
  return ngs::proc::proc_list_create();
}

// get process id from process list at index
double ProcessId(double procList, double i) {
  return ngs::proc::process_id((PROCLIST)procList, (int)i);
}

// get amount of process id's in process list
double ProcessIdLength(double procList) {
  return ngs::proc::process_id_length((PROCLIST)procList);
}

// free list of process id's from memory
double FreeProcList(double procList) {
  ngs::proc::free_proc_list((PROCLIST)procList); return 0;
}

// get executable image file path from process info data
char *ExecutableImageFilePath(double procInfo) {
  return ngs::proc::executable_image_file_path((PROCINFO)procInfo);
}

// get current working directory ffrom process info data
char *CurrentWorkingDirectory(double procInfo) {
  return ngs::proc::current_working_directory((PROCINFO)procInfo);
}

// get parent processs id from process info data
double ParentProcessId(double procInfo) {
  return ngs::proc::parent_process_id((PROCINFO)procInfo);
}

// get child process id from process info data at index
double ChildProcessId(double procInfo, double i) {
  return ngs::proc::child_process_id((PROCINFO)procInfo, (int)i);
}

// get amount of child processes from process info data
double ChildProcessIdLength(double procInfo) {
  return ngs::proc::child_process_id_length((PROCINFO)procInfo);
}

// get command line argument from process info data at index
char *CommandLine(double procInfo, double i) {
  return ngs::proc::commandline((PROCINFO)procInfo, (int)i);
}

// get amount of command line arguments from process info data
double CommandLineLength(double procInfo) {
  return ngs::proc::commandline_length((PROCINFO)procInfo);
}

// get environment variable (NAME=VALUE) from process info at index
char *Environment(double procInfo, double i) {
  return ngs::proc::environment((PROCINFO)procInfo, (int)i);
}

// get amount of anvironment variables from process info at index
double EnvironmentLength(double procInfo) {
  return ngs::proc::environment_length((PROCINFO)procInfo);
}

// get current working directory
char *DirectoryGetCurrentWorking() {
  return (char *)ngs::proc::directory_get_current_working();
}

// set current working directory based on a given dname
double DirectorySetCurrentWorking(char *dname) {
  return ngs::proc::directory_set_current_working(dname);
}

// get the environment variable of the given name
char *EnvironmentGetVariable(char *name) {
  return (char *)ngs::proc::environment_get_variable(name);
}

// set the environment variable with the given name and value
double EnvironmentSetVariable(char *name, char *value) {
  return ngs::proc::environment_set_variable(name, value);
}

// unset the environment variable with the given name
double EnvironmentUnsetVariable(char *name) {
  return ngs::proc::environment_unset_variable(name);
}

// get temporary directory path
char *DirectoryGetTemporaryPath() {
  return (char *)ngs::proc::directory_get_temporary_path();
}

#if defined(XPROCESS_GUIWINDOW_IMPL)
// get owned window id string from process info at index
char *OwnedWindowId(double procInfo, double i) {
  return ngs::proc::owned_window_id((PROCINFO)procInfo, (int)i);
}

// get amount of owned window id's from process info at index
double OwnedWindowIdLength(double procInfo) {
  return ngs::proc::owned_window_id_length((PROCINFO)procInfo);
}

// get whether a process exists based on one of its window id's
double WindowIdExists(char *winId) {
  return ngs::proc::window_id_exists((WINDOWID)winId);
}

// kill a process based on one of its window id's, return whether succeeded
double WindowIdKill(char *winId) {
  return ngs::proc::window_id_kill((WINDOWID)winId);
}

// return a window id from native window handle
char *WindowIdFromNativeWindow(void *window) {
  #if (defined(__APPLE__) && defined(__MACH__))
  return ngs::proc::window_id_from_next_step_window(window);
  #else
  return ngs::proc::window_id_from_native_window((ngs::proc::WINDOW)(uintptr_t)window);
  #endif
} 
#endif
