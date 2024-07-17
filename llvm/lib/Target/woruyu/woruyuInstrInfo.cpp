#include "woruyuInstrInfo.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "woruyuGenInstrInfo.inc"

using namespace llvm;

woruyuInstrInfo::woruyuInstrInfo() : woruyuGenInstrInfo() {}