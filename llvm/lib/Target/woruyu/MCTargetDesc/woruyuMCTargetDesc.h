#ifndef LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
#define LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
#include "llvm/Support/DataTypes.h"

namespace llvm {
class Target;
class Triple;

Target &getTheworuyuTarget();
} // namespace llvm


#endif // LLVM_LIB_TARGET_WORUYU_MCTARGETDESC_WORUYUMCTARGETDESC_H
