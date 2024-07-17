#include "woruyuTargetObjectFile.h"

using namespace llvm;

void woruyuTargetObjectFile::Initialize(MCContext &Ctx, TargetMachine const &TM) {
  TargetLoweringObjectFileELF::Initialize(Ctx, TM);
  InitializeELF(false);
}