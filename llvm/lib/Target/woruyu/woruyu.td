include "llvm/Target/Target.td"

include "woruyuRegisterInfo.td"
include "woruyuSchedule.td"
include "woruyuInstrInfo.td"
include "woruyuCallingConv.td"


def : ProcessorModel<"generic-rrv32", NoSchedModel, []>;

def woruyuInstrInfo : InstrInfo;

def woruyu : Target {
  let InstructionSet = woruyuInstrInfo;
}

