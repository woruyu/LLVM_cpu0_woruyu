#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
namespace llvm {
class woruyuTargetMachine : public LLVMTargetMachine {
public:
  woruyuTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                      StringRef FS, TargetOptions const &Options,
                      Optional<Reloc::Model> RM, Optional<CodeModel::Model> CM,
                      CodeGenOpt::Level OL, bool JIT)
      : LLVMTargetMachine(T, "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64",
                          TT, CPU, FS, Options, Reloc::Static, CodeModel::Small,
                          OL) {
                            initAsmInfo();
                          }

  ~woruyuTargetMachine(){};
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUTARGETMACHINE_H
