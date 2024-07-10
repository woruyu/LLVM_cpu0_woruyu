
set (LLVM_TARGET_DEFINITIONS woruyu.td)

# Generate woruyuGenRegisterInfo.inc and woruyuGenInstrInfo.inc which included by
#  your hand code C++ files.
# woruyuGenRegisterInfo.inc came from woruyuRegisterInfo.td, woruyuGenInstrInfo.inc
#  came from woruyuInstrInfo.td.
tablegen(LLVM woruyuenSubtargetInfo.inc -gen-subtarget)

# woruyuCommonTableGen must be defined
add_public_tablegen_target(woruyuCommonTableGen)

# woruyuCodeGen should match with LLVMBuild.txt woruyuCodeGen
add_llvm_target(woruyuCodeGen
  woruyuTargetMachine.cpp
  )

# Should match with "subdirectories = MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)