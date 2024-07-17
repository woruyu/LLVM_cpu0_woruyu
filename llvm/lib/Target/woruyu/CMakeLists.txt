
set (LLVM_TARGET_DEFINITIONS woruyu.td)

# Generate woruyuGenRegisterInfo.inc and woruyuGenInstrInfo.inc which included by
#  your hand code C++ files.
# woruyuGenRegisterInfo.inc came from woruyuRegisterInfo.td, woruyuGenInstrInfo.inc
#  came from woruyuInstrInfo.td.
tablegen(LLVM woruyuGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM woruyuGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM woruyuGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM woruyuGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM woruyuGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM woruyuGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM woruyuGenCallingConv.inc -gen-callingconv)

# woruyuCommonTableGen must be defined
add_public_tablegen_target(woruyuCommonTableGen)

# woruyuCodeGen should match with LLVMBuild.txt woruyuCodeGen
add_llvm_target(woruyuCodeGen
  woruyuTargetMachine.cpp
  woruyuISelDAGToDAG.cpp
  woruyuAsmPrinter.cpp
  woruyuTargetObjectFile.cpp
  woruyuSubtarget.cpp
  woruyuISelLowering.cpp
  woruyuFrameLowering.cpp
  )

# Should match with "subdirectories = MCTargetDesc TargetInfo" in LLVMBuild.txt
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
add_subdirectory(InstPrinter)