#include "woruyuFrameLowering.h"

using namespace llvm;

woruyuFrameLowering::woruyuFrameLowering()
    : TargetFrameLowering(StackGrowsDown, 16, 0) {}

void woruyuFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}

void woruyuFrameLowering::emitEpilogue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}

bool woruyuFrameLowering::hasFP(const MachineFunction &MF) const { return false; }