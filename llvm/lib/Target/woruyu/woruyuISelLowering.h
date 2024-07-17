#ifndef LLVM_LIB_TARGET_WORUYU_WORUYUISELLOWERING_H
#define LLVM_LIB_TARGET_WORUYU_WORUYUISELLOWERING_H
#include <llvm/CodeGen/SelectionDAG.h>
#include <llvm/CodeGen/TargetLowering.h>

namespace llvm {
class woruyuSubtarget;
class woruyuTargetLowering : public TargetLowering {
public:
  woruyuTargetLowering(const TargetMachine &TM, const woruyuSubtarget &STI);

  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               const SmallVectorImpl<ISD::InputArg> &Ins,
                               const SDLoc &DL, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, const SDLoc &DL,
                      SelectionDAG &DAG) const override;
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_WORUYU_WORUYUISELLOWERING_H
