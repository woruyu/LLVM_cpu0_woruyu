#include "woruyuInstPrinter.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

#define PRINT_ALIAS_INSTR
#include "woruyuGenAsmWriter.inc"

void woruyuInstPrinter::printInst(MCInst const *MI, raw_ostream &O,
                                  StringRef Annot, MCSubtargetInfo const &STI) {
  printInstruction(MI, O);
}

void woruyuInstPrinter::printRegName(raw_ostream &OS, unsigned RegNo) const {
  OS << getRegisterName(RegNo);
}

void woruyuInstPrinter::printOperand(const MCInst *MI, unsigned OpNo,
                                     raw_ostream &OS) {
  const MCOperand &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    printRegName(OS, Op.getReg());
    return;
  }

  if (Op.isImm()) {
    OS << Op.getImm();
    return;
  }

  Op.getExpr()->print(OS, &MAI, true);
}

void woruyuInstPrinter::printMemOperand(const MCInst *MI, int opNum,
                                        raw_ostream &O) {
  printOperand(MI, opNum + 1, O);
  O << "(";
  printOperand(MI, opNum, O);
  O << ")";
}