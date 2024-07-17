#include "woruyuMCTargetDesc.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MachineLocation.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_INSTRINFO_MC_DESC
#include "woruyuGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "woruyuGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "woruyuGenRegisterInfo.inc"

static MCRegisterInfo *createworuyuMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitworuyuMCRegisterInfo(X, woruyu::RA); // defined in woruyuGenRegisterInfo.inc
  return X;
}

static MCInstrInfo *createworuyuMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitworuyuMCInstrInfo(X); // defined in woruyuGenInstrInfo.inc
  return X;
}

static MCSubtargetInfo * createworuyuMCSubtargetInfo(Triple const &TT,
                                                 StringRef CPU, StringRef FS) {
  return createworuyuMCSubtargetInfoImpl(TT, CPU, FS);
}

static MCAsmInfo *createworuyuMCAsmInfo(MCRegisterInfo const &MRI,
                                     Triple const &TT) {
  MCAsmInfo *x = new MCAsmInfo();
  return x;
}

extern "C" void LLVMInitializeworuyuTargetMC() {
  TargetRegistry::RegisterMCRegInfo(getTheworuyuTarget(), createworuyuMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(getTheworuyuTarget(), createworuyuMCInstrInfo);
  TargetRegistry::RegisterMCSubtargetInfo(getTheworuyuTarget(),
                                          createworuyuMCSubtargetInfo);
  TargetRegistry::RegisterMCAsmInfo(getTheworuyuTarget(), createworuyuMCAsmInfo);
}