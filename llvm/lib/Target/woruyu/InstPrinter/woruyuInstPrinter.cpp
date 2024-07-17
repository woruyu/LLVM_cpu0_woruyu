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

void woruyuInstPrinter::printInst(MCInst const *MI, raw_ostream &O, StringRef Annot, MCSubtargetInfo const &STI) {}

void woruyuInstPrinter::printRegName(raw_ostream &OS, unsigned RegNo) const {}

void woruyuInstPrinter::printOperand(const MCInst *MI, unsigned OpNo, raw_ostream &O) {}

void woruyuInstPrinter::printMemOperand(const MCInst *MI, int opNum, raw_ostream &O){}