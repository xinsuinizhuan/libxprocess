#include "crossprocess.h"

#define RET_BOOL             bool
#define RET_VOID             void
#define ARG_PROCID           PROCID
#define RET_CONST_CHAR_PTR   void *
#define ARG_CONST_CHAR_PTR   void *
#define ARG_INT_OUT          void *
#define ARG_PROCID_OUT       void *
#define ARG_PROCID_OUT_VEC   void *
#define ARG_CHAR_PTR_VEC     void *
#define ARG_CHAR_OUT_PTR     void *
#define ARG_CHAR_OUT_PTR_VEC void *

namespace enigma_user {

RET_VOID ProcIdEnumerate(ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size) {
  CrossProcess::ProcIdEnumerate((PROCID **)procId, (int *)size);
}

RET_VOID ProcIdFromSelf(ARG_PROCID_OUT procId) {
  CrossProcess::ProcIdFromSelf((PROCID *)&procId);
}

RET_VOID ParentProcIdFromSelf(ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromSelf((PROCID *)&parentProcId);
}

RET_BOOL ProcIdExists(ARG_PROCID procId) {
  return CrossProcess::ProcIdExists((PROCID)procId);
}

RET_BOOL ProcIdKill(ARG_PROCID procId) {
  return CrossProcess::ProcIdKill((PROCID)procId);
}

RET_VOID ParentProcIdFromProcId(ARG_PROCID procId, ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromProcId((PROCID)procId, (PROCID *)&parentProcId);
}

RET_VOID ProcIdFromParentProcId(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size) {
  CrossProcess::ProcIdFromParentProcId((PROCID)parentProcId, (PROCID **)&procId, (int *)&size);
}

RET_VOID ExeFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::ExeFromProcId((PROCID)procId, (char **)&buffer);
}

RET_CONST_CHAR_PTR DirectoryGetCurrentWorking() {
  return (char *)CrossProcess::DirectoryGetCurrentWorking();
}

RET_BOOL DirectorySetCurrentWorking(ARG_CONST_CHAR_PTR dname) {
  CrossProcess::DirectorySetCurrentWorking((char *)dname);
}

RET_VOID CwdFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::CwdFromProcId((PROCID)procId, (char **)&buffer);
}

RET_VOID FreeCmdline(ARG_CHAR_PTR_VEC buffer) {
  CrossProcess::FreeCmdline((char **)buffer);
}

RET_VOID CmdlineFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size) {
  CrossProcess::CmdlineFromProcId((PROCID)procId, (char ***)&buffer, (int *)&size);
}

RET_VOID ParentProcIdFromProcIdSkipSh(ARG_PROCID procId, ARG_PROCID_OUT parentProcId) {
  CrossProcess::ParentProcIdFromProcIdSkipSh((PROCID)procId, (PROCID *)&parentProcId);
}

RET_VOID ProcIdFromParentProcIdSkipSh(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size) {
  CrossProcess::ProcIdFromParentProcIdSkipSh((PROCID)parentProcId, (PROCID **)&procId, (int *)&size);
}

RET_CONST_CHAR_PTR EnvironmentGetVariable(ARG_CONST_CHAR_PTR name) {
  return (char *)CrossProcess::EnvironmentGetVariable((char *)name);
}

RET_BOOL EnvironmentSetVariable(ARG_CONST_CHAR_PTR name, ARG_CONST_CHAR_PTR value) {
  CrossProcess::EnvironmentSetVariable((char *)name, (char *)value);
}

RET_VOID FreeEnviron(ARG_CHAR_OUT_PTR buffer) {
  CrossProcess::FreeEnviron((char **)buffer);
}

RET_VOID EnvironFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size) {
  CrossProcess::EnvironFromProcId((PROCID)procId, (char ***)&buffer, (int *)&size);
}

RET_VOID EnvironFromProcIdEx(ARG_PROCID procId, ARG_CONST_CHAR_PTR name, ARG_CHAR_OUT_PTR value) {
  CrossProcess::EnvironFromProcIdEx((PROCID)procId, (char *)name, (char **)&value);
}

} // namespace enigma_user
