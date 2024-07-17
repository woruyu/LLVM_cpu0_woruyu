#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "woruyuGenInstrInfo.inc"

namespace llvm {
class woruyuInstrInfo : public woruyuGenInstrInfo {

public:
  woruyuInstrInfo();
};

} // namespace llvm

#endif// LLVM_LIB_TARGET_WORUYU_WORUYUINSTRINFO_H
