#include "woruyuISelDAGToDAG.h"

using namespace llvm;

void woruyuDAGToDAGISel::Select(SDNode *N) { SelectCode(N); }

bool woruyuDAGToDAGISel::SelectAddrFI(SDNode *Parent, SDValue Addr,
                                      SDValue &Base, SDValue &Offset) {
  EVT ValTy = Addr.getValueType();
  SDLoc DL(Addr);
  if (FrameIndexSDNode *FIN = dyn_cast<FrameIndexSDNode>(Addr)) {
    Base = CurDAG->getTargetFrameIndex(FIN->getIndex(), ValTy);
    Offset = CurDAG->getTargetConstant(0, DL, ValTy);
    return true;
  }

  if (CurDAG->isBaseWithConstantOffset(Addr)) {
    ConstantSDNode *CN = dyn_cast<ConstantSDNode>(Addr.getOperand(1));

    if (FrameIndexSDNode *FIN = dyn_cast<FrameIndexSDNode>(Addr.getOperand(0))) {
      Base = CurDAG->getTargetFrameIndex(FIN->getIndex(), ValTy);
    } else {
      Base = Addr.getOperand(0);
    }

    Offset = CurDAG->getTargetConstant(CN->getZExtValue(), DL, ValTy);
    return true;
  }
  return false;
}