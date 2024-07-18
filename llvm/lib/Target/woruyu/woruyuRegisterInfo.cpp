#include "woruyuRegisterInfo.h"
#include "MCTargetDesc/woruyuMCTargetDesc.h"
#include "woruyuSubtarget.h"
#include "llvm/Support/GenericDomTreeConstruction.h"

#define GET_REGINFO_TARGET_DESC
#include "woruyuGenRegisterInfo.inc"

#define DEBUG_TYPE "woruyu register info"
using namespace llvm;

woruyuRegisterInfo::woruyuRegisterInfo(woruyuSubtarget const &ST,
                                       unsigned HwMode)
    : woruyuGenRegisterInfo(0, 0, 0, 0, HwMode) {}

void woruyuRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                             int SPAdj, unsigned FIOperandNum,
                                             RegScavenger *RS) const {
  MachineInstr &MI = *II;
  LLVM_DEBUG(errs() << MI);
  return;
}

MCPhysReg const *
woruyuRegisterInfo::getCalleeSavedRegs(MachineFunction const *MF) const {
  return CSR_SaveList;
}

BitVector woruyuRegisterInfo::getReservedRegs(MachineFunction const &MF) const {
  constexpr uint16_t ReservedCPURegs[] = {woruyu::ZERO};
  BitVector Reserved(getNumRegs());
  for (auto const reg : ReservedCPURegs) {
    Reserved.set(reg);
  }
  return Reserved;
}

unsigned woruyuRegisterInfo::getFrameRegister(MachineFunction const &MF) const {
  return woruyu::SP;
}