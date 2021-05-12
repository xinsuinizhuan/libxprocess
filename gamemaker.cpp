#include "crossprocess.h"

#ifdef _WIN32
#define EXPORTED_FUNCTION extern "C" __declspec(dllexport)
#else /* macOS, Linux, and BSD */
#define EXPORTED_FUNCTION extern "C" __attribute__((visibility("default")))
#endif

// GameMaker only accept double/ptr
#define RET_BOOL             double
#define RET_VOID             double
#define ARG_PROCID           double
#define RET_CONST_CHAR_PTR   void *
#define ARG_CONST_CHAR_PTR   void *
#define ARG_PROCID_OUT       void *
#define ARG_PROCID_OUT_VEC   void *
#define ARG_CHAR_PTR_VEC     void *
#define ARG_CHAR_OUT_PTR     void *
#define ARG_CHAR_OUT_PTR_VEC void *

EXPORTED_FUNCTION RET_VOID ProcIdEnumerate(ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size);
  CrossProcess::ProcIdEnumerate((PROCID **)&procId, (int *)&size); return 0;
}

EXPORTED_FUNCTION RET_VOID ProcIdFromSelf(ARG_PROCID_OUT procId) {
  CrossProcess::ProcIdFromSelf((PROCID *)&procId); return 0;
}

EXPORTED_FUNCTION RET_VOID ParentProcIdFromSelf(ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromSelf((PROCID *)&parentProcId); return 0;
}

EXPORTED_FUNCTION RET_BOOL ProcIdExists(ARG_PROCID procId) {
  return CrossProcess::ProcIdExists((PROCID)procId);
}

EXPORTED_FUNCTION RET_BOOL ProcIdKill(ARG_PROCID procId) {
  return CrossProcess::ProcIdKill((PROCID)procId);
}

EXPORTED_FUNCTION RET_VOID ParentProcIdFromProcId(ARG_PROCID procId, ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromProcId((PROCID)procId, (PROCID *)&parentProcId); return 0;
}

EXPORTED_FUNCTION RET_VOID ProcIdFromParentProcId(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size) {
  CrossProcess::ProcIdFromParentProcId((PROCID)parentProcId, (PROCID **)&procId, (int *)&size); return 0;
}

EXPORTED_FUNCTION RET_VOID *ExeFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::ExeFromProcId((PROCID)procId, (char **)&buffer); return 0;
}

EXPORTED_FUNCTION RET_CONST_ARG_CHAR *DirectoryGetCurrentWorking() {
  return CrossProcess::DirectoryGetCurrentWorking();
}

EXPORTED_FUNCTION RET_BOOL DirectorySetCurrentWorking(ARG_CONST_CHAR_PTR dname) {
  return CrossProcess::DirectorySetCurrentWorking((char *)dname);
}

EXPORTED_FUNCTION RET_VOID CwdFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::CwdFromProcId((PROCID)procId, (PROCID *)&buffer); return 0;
}

EXPORTED_FUNCTION RET_VOID FreeCmdline(ARG_CHAR_PTR_VEC buffer) {
  CrossProcess::FreeCmdline((char **)buffer); return 0;
}

EXPORTED_FUNCTION RET_VOID CmdlineFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size) {
  CrossProcess::CmdlineFromProcId((PROCID)procId, (char ***)&buffer, (int *)&size); return 0;
}

EXPORTED_FUNCTION RET_VOID ParentProcIdFromProcIdSkipSh(ARG_PROCID procId, ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromProcIdSkipSh((PROCID)procId, (PROCID *)&parentProcId); return 0;
}

EXPORTED_FUNCTION RET_VOID ProcIdFromParentProcIdSkipSh(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size) {
  CrossProcess::ProcIdFromParentProcIdSkipSh((PROCID)parentProcId, (PROCID **)&procId, (int *)&size); return 0;
}

EXPORTED_FUNCTION RET_CONST_ARG_CHAR *EnvironmentGetVariable(ARG_CONST_CHAR_PTR name) {
  return CrossProcess::EnvironmentGetVariable((char *)name);
}

EXPORTED_FUNCTION RET_BOOL EnvironmentSetVariable(ARG_CONST_CHAR_PTR name, ARG_CONST_CHAR_PTR value) {
  return CrossProcess::EnvironmentSetVariable((char *)name, (char *)value);
}

EXPORTED_FUNCTION RET_VOID FreeEnviron(ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::FreeEnviron((char **)buffer); return 0;
}

EXPORTED_FUNCTION RET_VOID EnvironFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size) {
  CrossProcess::EnvironFromProcId((PROCID)procId, (char ***)&buffer, (int *)&size); return 0;
}

EXPORTED_FUNCTION RET_VOID EnvironFromProcIdEx(ARG_PROCID procId, ARG_CONST_CHAR_PTR name, ARG_CHAR_OUT_PTR value) {
  CrossProcess::EnvironFromProcIdEx((PROCID)procId, (char *)name, (char **)&value); return 0;
}
