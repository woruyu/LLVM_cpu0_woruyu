#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUMCINSTLOWER_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUMCINSTLOWER_H

namespace llvm {
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class woruyuMCInstLower {
public:
  woruyuMCInstLower(){};
  void Lower(const MachineInstr *MI, MCInst &OutMI) const;
  MCOperand LowerOperand(const MachineOperand &MO) const;
};
} // namespace llvm

#endif// LLVM_LIB_TARGET_WORUYU_WORUYUMCINSTLOWER_H
