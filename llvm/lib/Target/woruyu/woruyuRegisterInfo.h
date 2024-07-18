#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUREGISTERINFO_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"
#define GET_REGINFO_HEADER
#include "woruyuGenRegisterInfo.inc"

namespace llvm {
class woruyuSubtarget;
class woruyuRegisterInfo : public woruyuGenRegisterInfo {
public:
  woruyuRegisterInfo(woruyuSubtarget const &ST, unsigned HwMode);
  MCPhysReg const *getCalleeSavedRegs(MachineFunction const *MF) const override;
  
  BitVector getReservedRegs(MachineFunction const &MF) const override;
  void eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj, unsigned FIOperandNum, RegScavenger *RS = nullptr) const override;
  unsigned getFrameRegister(MachineFunction const &MF) const override;
};

} // namespace llvm
#endif// LLVM_LIB_TARGET_WORUYU_WORUYUREGISTERINFO_H
