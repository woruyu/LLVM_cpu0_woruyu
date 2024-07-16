
class woruyuInst<dag outs, dag ins, string asm, list<dag> pattern, InstrItinClass itin> :Instruction
{
  let Namespace = "woruyu";

  let OutOperandList = outs;
  let InOperandList = ins;

  let AsmString = asm;
  let Pattern = pattern;
  let Itinerary = itin;

  let DecoderNamespace = "woruyu";
}

class InstI<dag outs, dag ins, string asm, list<dag> pattern, InstrItinClass itin>: woruyuInst<outs, ins, asm, pattern, itin> {}

class InstR<dag outs, dag ins, string asm, list<dag> pattern,
      InstrItinClass itin>: woruyuInst<outs, ins, asm, pattern, itin> {}

class InstU<dag outs, dag ins, string asm, list<dag> pattern,
      InstrItinClass itin>: woruyuInst<outs, ins, asm, pattern, itin> {}

class Pseudo<dag outs, dag ins, list<dag> pattern>
    : woruyuInst<outs, ins, "", pattern, IIAlu> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
