#include "woruyuTargetMachine.h"
#include "woruyu.h"
#include "woruyuISelDAGToDAG.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "woruyu"

extern "C" void LLVMInitializeworuyuTarget() {
  RegisterTargetMachine<woruyuTargetMachine> X(getTheworuyuTarget());
}

const woruyuSubtarget*
woruyuTargetMachine::getSubtargetImpl(const Function &F) const { return Subtarget.get(); }

class woruyuPassConfig : public TargetPassConfig {
public:
  woruyuPassConfig(woruyuTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    addPass(new woruyuDAGToDAGISel(getTM<woruyuTargetMachine>(), getOptLevel()));
    return false;
  }
};

TargetPassConfig *woruyuTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new woruyuPassConfig(*this, PM);
}
