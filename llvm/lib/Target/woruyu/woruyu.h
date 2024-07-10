#ifndef LLVM_LIB_TARGET_WORUYU_WORUYU_H
#define LLVM_LIB_TARGET_WORUYU_WORUYU_H

#include "MCTargetDesc/woruyuMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class woruyuTargetMachine;
  class FunctionPass;
}

#define ENABLE_GPRESTORE  // The $gp register caller saved register enable

#endif// LLVM_LIB_TARGET_WORUYU_WORUYU_H
