#include "woruyuTargetMachine.h"
#include "woruyu.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "woruyu"

extern "C" void LLVMInitializeworuyuTarget() {
  RegisterTargetMachine<woruyuTargetMachine> X(getTheworuyuTarget());
}
