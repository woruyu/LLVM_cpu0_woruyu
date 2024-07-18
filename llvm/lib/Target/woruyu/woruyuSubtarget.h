#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
#include "woruyuFrameLowering.h"
#include "woruyuISelLowering.h"
#include "woruyuInstrInfo.h"
#include "woruyuRegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "woruyuGenSubtargetInfo.inc"

namespace llvm {
class woruyuTargetMachine;
class woruyuSubtarget : public woruyuGenSubtargetInfo {
private:
  woruyuTargetLowering TLInfo;
  woruyuFrameLowering FrameLowering;
  woruyuInstrInfo InstrInfo;
  woruyuRegisterInfo RegInfo;

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

  const woruyuInstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const woruyuRegisterInfo *getRegisterInfo() const override {
    return &RegInfo;
  }
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUSUBTARGET_H
