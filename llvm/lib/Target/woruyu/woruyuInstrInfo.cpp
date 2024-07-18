#include "woruyuInstrInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "woruyuGenInstrInfo.inc"

using namespace llvm;

woruyuInstrInfo::woruyuInstrInfo() : woruyuGenInstrInfo() {}

void woruyuInstrInfo::storeRegToStackSlot(MachineBasicBlock &MBB,
                            MachineBasicBlock::iterator MBBI, unsigned SrcReg,
                            bool IsKill, int FrameIndex,
                            const TargetRegisterClass *RC,
                            const TargetRegisterInfo *TRI) const {
  DebugLoc DL;

  unsigned Opc = woruyu::STORE;
  BuildMI(MBB, MBBI, DL, get(Opc))
      .addReg(SrcReg, getKillRegState(IsKill))
      .addFrameIndex(FrameIndex)
      .addImm(0);
}