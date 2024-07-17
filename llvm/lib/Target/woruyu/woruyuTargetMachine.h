#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H

#include "woruyuSubtarget.h"
#include "woruyuTargetObjectFile.h"
#include "llvm/Target/TargetMachine.h"
#include <memory>
namespace llvm {
class woruyuTargetMachine : public LLVMTargetMachine {
public:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  std::unique_ptr<woruyuSubtarget> Subtarget;

public:
  woruyuTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, TargetOptions const &Options,
                      Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT)
      : LLVMTargetMachine(T, "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64",
                          TT, CPU, FS, Options, Reloc::Static, CodeModel::Small,
                          OL),
        TLOF(llvm::make_unique<woruyuTargetObjectFile>()),
        Subtarget(llvm::make_unique<woruyuSubtarget>(TT, CPU, FS, *this)) {
    initAsmInfo();
  }

  ~woruyuTargetMachine(){};

  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H
