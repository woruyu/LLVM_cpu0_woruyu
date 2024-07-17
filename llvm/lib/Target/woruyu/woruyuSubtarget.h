#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#include "woruyuFrameLowering.h"
#include "woruyuISelLowering.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "woruyuGenSubtargetInfo.inc"

namespace llvm {
class woruyuTargetMachine;
class woruyuSubtarget : public woruyuGenSubtargetInfo {
private:
woruyuTargetLowering TLInfo;
woruyuFrameLowering FrameLowering;

public:
  woruyuSubtarget(const Triple &TT, StringRef &CPU, StringRef &FS,
                  const TargetMachine &TM);

  ~woruyuSubtarget() override {}

  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);
  const woruyuTargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }

    const woruyuFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
