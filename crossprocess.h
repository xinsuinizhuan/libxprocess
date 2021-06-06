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

#include <unordered_map>
#if defined(XPROCESS_GUIWINDOW_IMPL)
#if defined(_WIN32)
#include <windows.h>
#else
#if (defined(__APPLE__) && defined(__MACH__)) && !defined(XPROCESS_XQUARTZ_IMPL)
#include <CoreGraphics/CoreGraphics.h>
#include <CoreFoundation/CoreFoundation.h>
#elif (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__) || defined(XPROCESS_XQUARTZ_IMPL)
#include <X11/Xlib.h>
#endif
#endif
#endif

namespace CrossProcess {

#if !defined(_WIN32)
typedef int PROCID;
#else
typedef unsigned long PROCID;
#endif
typedef PROCID PROCESS;
#if defined(XPROCESS_GUIWINDOW_IMPL)
#if defined(_WIN32)
typedef HWND WINDOW;
#elif (defined(__APPLE__) && defined(__MACH__)) && !defined(XPROCESS_XQUARTZ_IMPL)
typedef CGWindowID WINDOW;
#elif (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__) || defined(XPROCESS_XQUARTZ_IMPL)
typedef Window WINDOW;
#endif
typedef char *WINDOWID;
#endif
typedef char *PROCINFO;
typedef char *PROCINFOLIST;
typedef struct {
  PROCID ProcessId;
  char *ExecutableImageFilePath;
  char *CurrentWorkingDirectory;
  PROCID ParentProcessId;
  PROCID *ChildProcessId;
  int ChildProcessIdLength;
  char **CommandLine;
  int CommandLineLength;
  char **Environment;
  int EnvironmentLength;
  #if defined(XPROCESS_GUIWINDOW_IMPL)
  WINDOWID *OwnedWindowId;
  int OwnedWindowIdLength;
  #endif
} _PROCINFO;
typedef _PROCINFO *_PROCINFOLIST;

void ProcIdEnumerate(PROCID **procId, int *size);
void FreeProcId(PROCID *procId);
void ProcIdFromSelf(PROCID *procId);
void ParentProcIdFromSelf(PROCID *parentProcId);
bool ProcIdExists(PROCID procId);
bool ProcIdKill(PROCID procId);
void ParentProcIdFromProcId(PROCID procId, PROCID *parentProcId);
void ProcIdFromParentProcId(PROCID parentProcId, PROCID **procId, int *size);
void ExeFromProcId(PROCID procId, char **buffer);
const char *DirectoryGetCurrentWorking();
bool DirectorySetCurrentWorking(const char *dname);
void CwdFromProcId(PROCID procId, char **buffer);
void FreeCmdline(char **buffer);
void CmdlineFromProcId(PROCID procId, char ***buffer, int *size);
void ParentProcIdFromProcIdSkipSh(PROCID procId, PROCID *parentProcId);
void ProcIdFromParentProcIdSkipSh(PROCID parentProcId, PROCID **procId, int *size);
const char *EnvironmentGetVariable(const char *name);
bool EnvironmentSetVariable(const char *name, const char *value);
void FreeEnviron(char **buffer);
void EnvironFromProcId(PROCID procId, char ***buffer, int *size);
void EnvironFromProcIdEx(PROCID procId, const char *name, char **value);
 PROCINFO  ProcInfoFromInternalProcInfo(_PROCINFO *procInfo);
_PROCINFO *InternalProcInfoFromProcInfo( PROCINFO  procInfo);
 PROCINFO  ProcInfoFromProcId(PROCID procId);
_PROCINFO *InternalProcInfoFromProcId(PROCID procId);
 PROCINFOLIST  ProcInfoListFromInternalProcInfoList(_PROCINFOLIST *procInfo);
_PROCINFOLIST *InternalProcInfoListFromProcInfoList( PROCINFOLIST  procInfo);
void FreeProcInfo(PROCINFO procInfo);
void FreeInternalProcInfo(_PROCINFO *procInfo);
#if defined(XPROCESS_GUIWINDOW_IMPL)
WINDOWID WindowIdFromNativeWindow(WINDOW window);
WINDOW NativeWindowFromWindowId(WINDOWID winid);
void WindowIdEnumerate(WINDOWID **winId, int *size);
void ProcIdFromWindowId(WINDOWID winId, PROCID *procId);
void WindowIdFromProcId(PROCID procId, WINDOWID **winId, int *size);
void FreeWindowId(WINDOWID *winId);
bool WindowIdExists(WINDOWID winId);
bool WindowIdKill(WINDOWID winId);
#endif

static std::unordered_map<PROCINFOLIST, int> procInfoListSize;
inline _PROCINFOLIST *InternalProcInfoEnumerate(int *size) { PROCID *procId; ProcIdEnumerate(&procId, size); 
_PROCINFOLIST *procInfoList = new _PROCINFOLIST[*size](); for (int i = 0; i < *size; i++) 
 procInfoList[i] = InternalProcInfoFromProcId(procId[i]); FreeProcId(procId); return procInfoList; }
inline  PROCINFOLIST ProcInfoEnumerate(int *size) { 
return ProcInfoListFromInternalProcInfoList(InternalProcInfoEnumerate(size)); }
inline void FreeInternalProcInfoList(_PROCINFOLIST *procInfoList, int size) { 
for (int i = 0; i < size; i++) FreeInternalProcInfo(procInfoList[i]);
procInfoListSize.erase(ProcInfoListFromInternalProcInfoList(procInfoList)); }
inline void FreeProcInfoList(PROCINFOLIST procInfoList, int size) { 
_PROCINFOLIST *_procInfoList = InternalProcInfoListFromProcInfoList(procInfoList);
FreeInternalProcInfoList(_procInfoList, size); }
inline PROCINFOLIST ProcInfoListCreate() { int size; 
PROCINFOLIST procInfoList = ProcInfoEnumerate(&size);
procInfoListSize[procInfoList] = size; return procInfoList; }
inline PROCINFO ProcessInfo(PROCINFOLIST procInfoList, int i) { 
_PROCINFOLIST *_procInfoList = InternalProcInfoListFromProcInfoList(procInfoList); 
return ProcInfoFromInternalProcInfo(_procInfoList[i]); }
inline int ProcessInfoLength(PROCINFOLIST procInfoList) {
FreeProcInfoList(procInfoList, procInfoListSize[procInfoList]); 
return procInfoListSize[procInfoList]; }

inline PROCID ProcessId(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->ProcessId; }
inline char *ExecutableImageFilePath(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->ExecutableImageFilePath; }
inline char *CurrentWorkingDirectory(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->CurrentWorkingDirectory; }
inline PROCID ParentProcessId(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->ParentProcessId; }
inline PROCID *ChildProcessId(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->ChildProcessId; }
inline PROCID ChildProcessId(PROCINFO procInfo, int i) { return InternalProcInfoFromProcInfo(procInfo)->ChildProcessId[i]; }
inline int ChildProcessIdLength(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->ChildProcessIdLength; }
inline char **CommandLine(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->CommandLine; }
inline char *CommandLine(PROCINFO procInfo, int i) { return InternalProcInfoFromProcInfo(procInfo)->CommandLine[i]; }
inline int CommandLineLength(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->CommandLineLength; }
inline char **Environment(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->Environment; }
inline char *Environment(PROCINFO procInfo, int i) { return InternalProcInfoFromProcInfo(procInfo)->Environment[i]; }
inline int EnvironmentLength(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->EnvironmentLength; }
#if defined(XPROCESS_GUIWINDOW_IMPL)
inline WINDOWID *OwnedWindowId(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->OwnedWindowId; }
inline WINDOWID OwnedWindowId(PROCINFO procInfo, int i) { return InternalProcInfoFromProcInfo(procInfo)->OwnedWindowId[i]; }
inline int OwnedWindowIdLength(PROCINFO procInfo) { return InternalProcInfoFromProcInfo(procInfo)->OwnedWindowIdLength; }
#endif

PROCESS ProcessExecute(const char *command);
PROCESS ProcessExecuteAsync(const char *command);
void ExecutedProcessWriteToStandardInput(PROCESS procIndex, const char *input);
const char *ExecutedProcessReadFromStandardOutput(PROCESS procIndex);
void FreeExecutedProcessStandardInput(PROCESS procIndex);
void FreeExecutedProcessStandardOutput(PROCESS procIndex);
bool CompletionStatusFromExecutedProcess(PROCESS procIndex);

} // namespace CrossProcess

