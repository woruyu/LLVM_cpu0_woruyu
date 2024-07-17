#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "woruyuGenSubtargetInfo.inc"

namespace llvm {
class woruyuTargetMachine;
class woruyuSubtarget : public woruyuGenSubtargetInfo {
public:
  woruyuSubtarget(const Triple &TT, StringRef &CPU, StringRef &FS,
                  const woruyuTargetMachine &TTM);

  ~woruyuSubtarget() override {}

  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
