#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUASMPRINTER_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUASMPRINTER_H

#include "woruyuSubtarget.h"
#include "woruyuTargetMachine.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Target/TargetMachine.h"
#include "woruyuMCInstLower.h"

namespace llvm {
class MCStreamer;
class MachineInstr;
class MachineBasicBlock;
class Module;
class raw_ostream;
class LLVM_LIBRARY_VISIBILITY woruyuAsmPrinter : public AsmPrinter {
private:
  woruyuMCInstLower MCInstLowering;
public:
  explicit woruyuAsmPrinter(TargetMachine &TM,
                            std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  virtual StringRef getPassName() const override {
    return "woruyu Assmebly Printer";
  }

  // EmitInstruction() must exists or will have run time error
  void EmitInstruction(const MachineInstr *MI) override;
  // void EmitFunctionEntryLabel() override;
  // void EmitFunctionBodyStart() override;
  // void EmitFunctionBodyEnd() override;
  // void EmitStartOfAsmFile(Module &M) override;
  bool PrintAsmOperand(const MachineInstr *MI, unsigned OpNum,
                       unsigned AsmVariant, const char *ExtraCode,
                       raw_ostream &O) override;
  bool PrintAsmMemoryOperand(const MachineInstr *MI, unsigned OpNum,
                             unsigned AsmVariant, const char *ExtraCode,
                             raw_ostream &O) override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUASMPRINTER_H
