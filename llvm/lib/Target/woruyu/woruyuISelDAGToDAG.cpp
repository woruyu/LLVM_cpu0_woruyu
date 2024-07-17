#include "woruyuISelDAGToDAG.h"

using namespace llvm;

void woruyuDAGToDAGISel::Select(SDNode *N) { SelectCode(N); }

bool woruyuDAGToDAGISel::SelectAddrFI(SDNode *Parent, SDValue Addr,
                                      SDValue &Base, SDValue &Offset) {
  EVT ValTy = Addr.getValueType();
  SDLoc DL(Addr);
  if (FrameIndexSDNode *FIN = dyn_cast<FrameIndexSDNode>(Addr))  {
    Base = CurDAG->getTargetFrameIndex(FIN->getIndex(), ValTy);
    Offset = CurDAG->getTargetConstant(0, DL, ValTy);
    return true;
  }
  return false;                         
}