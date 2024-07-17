#ifndef LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
#define LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
#include "llvm/Support/DataTypes.h"
#include "InstPrinter/woruyuInstPrinter.h"

namespace llvm {
class Target;
class Triple;

Target &getTheworuyuTarget();
} // namespace llvm

#define GET_REGINFO_ENUM
#include "woruyuGenRegisterInfo.inc"

// Defines symbolic names for woruyu instructions.
#define GET_INSTRINFO_ENUM
#include "woruyuGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "woruyuGenSubtargetInfo.inc"

#endif // LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
