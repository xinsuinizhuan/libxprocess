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

RET_VOID ProcIdEnumerate(ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size);
RET_VOID ProcIdFromSelf(ARG_PROCID_OUT procId);
RET_VOID ParentProcIdFromSelf(ARG_PROCID_OUT parentProcId);
RET_BOOL ProcIdExists(ARG_PROCID procId);
RET_BOOL ProcIdKill(ARG_PROCID procId);
RET_VOID ParentProcIdFromProcId(ARG_PROCID procId, ARG_PROCID_OUT parentProcId);
RET_VOID ProcIdFromParentProcId(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size);
RET_VOID ExeFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer);
RET_CONST_CHAR_PTR DirectoryGetCurrentWorking();
RET_BOOL DirectorySetCurrentWorking(ARG_CONST_CHAR_PTR dname);
RET_VOID CwdFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR buffer);
RET_VOID FreeCmdline(ARG_CHAR_PTR_VEC buffer);
RET_VOID CmdlineFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size);
RET_VOID ParentProcIdFromProcIdSkipSh(ARG_PROCID procId, ARG_PROCID_OUT parentProcId);
RET_VOID ProcIdFromParentProcIdSkipSh(ARG_PROCID parentProcId, ARG_PROCID_OUT_VEC procId, ARG_INT_OUT size);
RET_CONST_CHAR_PTR EnvironmentGetVariable(ARG_CONST_CHAR_PTR name);
RET_BOOL EnvironmentSetVariable(ARG_CONST_CHAR_PTR name, ARG_CONST_CHAR_PTR value);
RET_VOID FreeEnviron(ARG_CHAR_OUT_PTR buffer);
RET_VOID EnvironFromProcId(ARG_PROCID procId, ARG_CHAR_OUT_PTR_VEC buffer, ARG_INT_OUT size);
RET_VOID EnvironFromProcIdEx(ARG_PROCID procId, ARG_CONST_CHAR_PTR name, ARG_CHAR_OUT_PTR value);

} // namespace enigma_user
