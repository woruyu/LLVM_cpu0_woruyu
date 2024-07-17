#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUTARGETOBJECTFILE_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUTARGETOBJECTFILE_H

#include <llvm/CodeGen/TargetLoweringObjectFileImpl.h>
#include <llvm/MC/MCContext.h>
#include <llvm/Target/TargetMachine.h>

namespace llvm {

class woruyuTargetObjectFile : public TargetLoweringObjectFileELF {
public:
  void Initialize(MCContext &Ctx, TargetMachine const &TM) override;
};
} // namespace llvm
#endif // LLVM_LIB_TARGET_WORUYU_WORUYUTARGETOBJECTFILE_H
