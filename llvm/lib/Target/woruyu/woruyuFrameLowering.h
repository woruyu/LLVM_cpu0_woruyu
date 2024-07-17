#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUFRAMELOWERING_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUFRAMELOWERING_H

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class woruyuFrameLowering : public TargetFrameLowering {
public:
  woruyuFrameLowering();
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  bool hasFP(const MachineFunction &MF) const override;
};
} // namespace llvm

#endif// LLVM_LIB_TARGET_WORUYU_WORUYUFRAMELOWERING_H
