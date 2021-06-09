#include "crossprocess.h"

#ifdef _WIN32
#define EXPORTED_FUNCTION extern "C" __declspec(dllexport)
#else /* macOS, Linux, and BSD */
#define EXPORTED_FUNCTION extern "C" __attribute__((visibility("default")))
#endif

// execute process from the shell, return process id
EXPORTED_FUNCTION double ProcessExecute(char *command);

// execute process from the shell async, return process id
EXPORTED_FUNCTION double ProcessExecuteAsync(char *command);

//  get whether executed process has quit based on process id
EXPORTED_FUNCTION double CompletionStatusFromExecutedProcess(double procIndex);

// write to executed process standard input file descriptor based on process id
EXPORTED_FUNCTION double ExecutedProcessWriteToStandardInput(double procIndex, char *input);

// read from executed process standard output file descriptor based on process id
EXPORTED_FUNCTION char *ExecutedProcessReadFromStandardOutput(double procIndex);

// free executed process standard input string based on process id
EXPORTED_FUNCTION double FreeExecutedProcessStandardInput(double procIndex);

// free executed process standard ouptut string based on process id
EXPORTED_FUNCTION double FreeExecutedProcessStandardOutput(double procIndex);

// returns whether process process exists based on process id
EXPORTED_FUNCTION double ProcIdExists(double procId);

// kill process based on process id, return whether succeeded
EXPORTED_FUNCTION double ProcIdKill(double procId);

// create a list for all process info
EXPORTED_FUNCTION char *ProcListCreate();

// get process info pointer based on process list at index
EXPORTED_FUNCTION char *ProcessInfo(char *procList, double i);

// get the amount of process info available for iteration
EXPORTED_FUNCTION double ProcessInfoLength(char *procList);

// free iterations of process info list
EXPORTED_FUNCTION double FreeProcInfo(char *procInfo);

// free list of process info, (free the iterations separately)
EXPORTED_FUNCTION double FreeProcList(char *procList);

// get process id from process info iteration
EXPORTED_FUNCTION double ProcessId(char *procInfo);

// get executable image file path from process info iteration
EXPORTED_FUNCTION char *ExecutableImageFilePath(char *procInfo);

// get current working directory ffrom process info iteration
EXPORTED_FUNCTION char *CurrentWorkingDirectory(char *procInfo);

// get parent processs id from process info iteration
EXPORTED_FUNCTION double ParentProcessId(char *procInfo);

// get child process id from process info iteration at index
EXPORTED_FUNCTION double ChildProcessId(char *procInfo, double i);

// get amount of child processes from process info iteration
EXPORTED_FUNCTION double ChildProcessIdLength(char *procInfo);

// get command line argument from process info iteration at index
EXPORTED_FUNCTION char *CommandLine(char *procInfo, double i);

// get amount of command line arguments from process info iteration
EXPORTED_FUNCTION double CommandLineLength(char *procInfo);

// get environment variable (NAME=VALUE) from process info at index
EXPORTED_FUNCTION char *Environment(char *procInfo, double i);

// get amount of anvironment variables from process info at index
EXPORTED_FUNCTION double EnvironmentLength(char *procInfo);

#if defined(XPROCESS_GUIWINDOW_IMPL)
/* get owned window id string from process info at index; 
on Win32 this is an address, otherwise a number string */
EXPORTED_FUNCTION char *OwnedWindowId(char *procInfo, double i);

// get amount of owned window id's from process info at index
EXPORTED_FUNCTION double OwnedWindowIdLength(char *procInfo);

// get whether a process exists based on one of its window id's
EXPORTED_FUNCTION double WindowIdExists(char *winId);

// kill a process based on one of its window id's, return whether succeeded
EXPORTED_FUNCTION double WindowIdKill(char *winId);
#endif
