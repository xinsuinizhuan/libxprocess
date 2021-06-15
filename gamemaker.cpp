#include "gamemaker.h"

using CrossProcess::PROCID;
using CrossProcess::PROCESS;
using CrossProcess::PROCINFO;
using CrossProcess::PROCLIST;
#if defined(XPROCESS_GUIWINDOW_IMPL)
using CrossProcess::WINDOWID;
#endif

// execute process from the shell, return process id
double ProcessExecute(char *command) {
  return CrossProcess::ProcessExecute(command);
}

// execute process from the shell async, return process id
double ProcessExecuteAsync(char *command) {
  return CrossProcess::ProcessExecuteAsync(command);
}

//  get whether executed process has quit based on process id
double CompletionStatusFromExecutedProcess(double procIndex) {
  return CrossProcess::CompletionStatusFromExecutedProcess((PROCESS)procIndex);
}

// write to executed process standard input file descriptor based on process id
double ExecutedProcessWriteToStandardInput(double procIndex, char *input) {
  CrossProcess::ExecutedProcessWriteToStandardInput((PROCESS)procIndex, input); return 0;
}

// read from executed process standard output file descriptor based on process id
char *ExecutedProcessReadFromStandardOutput(double procIndex) {
  return (char *)CrossProcess::ExecutedProcessReadFromStandardOutput((PROCESS)procIndex);
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
char *ExecutableFromSelf() {
  return (char *)CrossProcess::ExecutableFromSelf();
}

// create a list for all process info
double ProcListCreate() {
  return CrossProcess::ProcListCreate();
}

// get process info pointer based on process list at index
double ProcessInfo(double procList, double i) {
  return CrossProcess::ProcessInfo((PROCLIST)procList, (int)i);
}

// get the amount of process info available for iteration
double ProcessInfoLength(double procList) {
  return CrossProcess::ProcessInfoLength((PROCLIST)procList);
}

// free iterations of process info list
double FreeProcInfo(double procInfo) {
  CrossProcess::FreeProcInfo((PROCINFO)procInfo); return 0;
}

// free list of process info, (free the iterations separately)
double FreeProcList(double procList) {
  CrossProcess::FreeProcList((PROCLIST)procList); return 0;
}

// get process id from process info iteration
double ProcessId(double procInfo) {
  return CrossProcess::ProcessId((PROCINFO)procInfo);
}

// get executable image file path from process info iteration
char *ExecutableImageFilePath(double procInfo) {
  return CrossProcess::ExecutableImageFilePath((PROCINFO)procInfo);
}

// get current working directory ffrom process info iteration
char *CurrentWorkingDirectory(double procInfo) {
  return CrossProcess::CurrentWorkingDirectory((PROCINFO)procInfo);
}

// get parent processs id from process info iteration
double ParentProcessId(double procInfo) {
  return CrossProcess::ParentProcessId((PROCINFO)procInfo);
}

// get child process id from process info iteration at index
double ChildProcessId(double procInfo, double i) {
  return CrossProcess::ChildProcessId((PROCINFO)procInfo, (int)i);
}

// get amount of child processes from process info iteration
double ChildProcessIdLength(double procInfo) {
  return CrossProcess::ChildProcessIdLength((PROCINFO)procInfo);
}

// get command line argument from process info iteration at index
char *CommandLine(double procInfo, double i) {
  return CrossProcess::CommandLine((PROCINFO)procInfo, (int)i);
}

// get amount of command line arguments from process info iteration
double CommandLineLength(double procInfo) {
  return CrossProcess::CommandLineLength((PROCINFO)procInfo);
}

// get environment variable (NAME=VALUE) from process info at index
char *Environment(double procInfo, double i) {
  return CrossProcess::Environment((PROCINFO)procInfo, (int)i);
}

// get amount of anvironment variables from process info at index
double EnvironmentLength(double procInfo) {
  return CrossProcess::EnvironmentLength((PROCINFO)procInfo);
}

#if defined(XPROCESS_GUIWINDOW_IMPL)
// get owned window id string from process info at index
char *OwnedWindowId(double procInfo, double i) {
  return CrossProcess::OwnedWindowId((PROCINFO)procInfo, (int)i);
}

// get amount of owned window id's from process info at index
double OwnedWindowIdLength(double procInfo) {
  return CrossProcess::OwnedWindowIdLength((PROCINFO)procInfo);
}

// get whether a process exists based on one of its window id's
double WindowIdExists(char *winId) {
  return CrossProcess::WindowIdExists((WINDOWID)winId);
}

// kill a process based on one of its window id's, return whether succeeded
double WindowIdKill(char *winId) {
  return CrossProcess::WindowIdKill((WINDOWID)winId);
}

// get current working directory
char *DirectoryGetCurrentWorking() {
  return (char *)CrossProcess::DirectoryGetCurrentWorking();
}

// set current working directory based on a given dname
double DirectorySetCurrentWorking(char *dname) {
  return CrossProcess::DirectorySetCurrentWorking(dname);
}

// get the environment variable of the given name
char *EnvironmentGetVariable(char *name) {
  return (char *)CrossProcess::EnvironmentGetVariable(name);
}

// set the environment variable with the given name and value
double EnvironmentSetVariable(char *name, char *value) {
  return CrossProcess::EnvironmentSetVariable(name, value);
}

// unset the environment variable with the given name
double EnvironmentUnsetVariable(char *name) {
  return CrossProcess::EnvironmentUnsetVariable(name);
}
#endif
