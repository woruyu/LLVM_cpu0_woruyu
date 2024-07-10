#include "woruyu.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheworuyuTarget() {
  static Target TheworuyuTarget;
  return TheworuyuTarget;
}

extern "C" void LLVMInitializeworuyuTargetInfo() {
  RegisterTarget<Triple::woruyu, true> X(getTheworuyuTarget(), "woruyu", "liuzhenya's RISC-V backend",
                                      "woruyu");
}