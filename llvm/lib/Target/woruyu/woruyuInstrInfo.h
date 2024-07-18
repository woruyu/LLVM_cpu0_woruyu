#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"
#include "MCTargetDesc/woruyuMCTargetDesc.h"

#define GET_INSTRINFO_HEADER
#include "woruyuGenInstrInfo.inc"

namespace llvm {
class woruyuInstrInfo : public woruyuGenInstrInfo {

public:
  woruyuInstrInfo();
  void storeRegToStackSlot(MachineBasicBlock &MBB,
                           MachineBasicBlock::iterator MBBI, unsigned SrcReg,
                           bool IsKill, int FrameIndex,
                           const TargetRegisterClass *RC,
                           const TargetRegisterInfo *TRI) const override;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H
