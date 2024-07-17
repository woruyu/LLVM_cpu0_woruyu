#include "woruyuSubtarget.h"

#define DEBUG_TYPE "woruyu-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "woruyuGenSubtargetInfo.inc"

using namespace llvm;

woruyuSubtarget::woruyuSubtarget(const Triple &TT, StringRef &CPU,
                                 StringRef &FS, const TargetMachine &TM)
    : woruyuGenSubtargetInfo(TT, CPU, FS),TLInfo(TM, *this) {}