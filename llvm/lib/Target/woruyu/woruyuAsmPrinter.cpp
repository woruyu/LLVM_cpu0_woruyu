#include "woruyuAsmPrinter.h"
#include "MCTargetDesc/woruyuMCTargetDesc.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

bool woruyuAsmPrinter::runOnMachineFunction(MachineFunction &MF) {}

// void woruyuAsmPrinter::EmitInstruction(const MachineInstr *MI) {}

// void woruyuAsmPrinter::EmitFunctionEntryLabel() {}

// void woruyuAsmPrinter::EmitFunctionBodyStart() {}

// void woruyuAsmPrinter::EmitFunctionBodyEnd() {}

// void woruyuAsmPrinter::EmitStartOfAsmFile(Module &M) {}

bool woruyuAsmPrinter::PrintAsmOperand(const MachineInstr *MI, unsigned OpNum,
                     unsigned AsmVariant, const char *ExtraCode,
                     raw_ostream &O) {}

bool woruyuAsmPrinter::PrintAsmMemoryOperand(const MachineInstr *MI, unsigned OpNum,
                           unsigned AsmVariant, const char *ExtraCode,
                           raw_ostream &O) {}


extern "C" void LLVMInitializeworuyuAsmPrinter() {
  RegisterAsmPrinter<woruyuAsmPrinter> X(getTheworuyuTarget());
}