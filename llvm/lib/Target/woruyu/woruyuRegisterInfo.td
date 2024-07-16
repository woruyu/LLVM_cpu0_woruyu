let Namespace = "woruyu" in {
  class woruyuReg<string n> : Register<n>;
}

let Namespace = "woruyu" in {
  def ZERO : woruyuReg<"zero">,  DwarfRegNum<[0]>;
  def RA :   woruyuReg<"ra">,    DwarfRegNum<[1]>;
  def SP :   woruyuReg<"sp">,    DwarfRegNum<[2]>;
  def T0 :   woruyuReg<"t0">,    DwarfRegNum<[5]>;
  def T1 :   woruyuReg<"t1">,    DwarfRegNum<[6]>;
  def T2 :   woruyuReg<"t2">,    DwarfRegNum<[7]>;
  def S0 :   woruyuReg<"s0">,    DwarfRegNum<[8]>;
  def S1 :   woruyuReg<"s1">,    DwarfRegNum<[9]>;
  def A0 :   woruyuReg<"a0">,    DwarfRegNum<[10]>;
  def A1 :   woruyuReg<"a1">,    DwarfRegNum<[11]>;
}

def GPR:RegisterClass<"woruyu", [i32], 32, (add
  ZERO, RA, SP,
  T0, T1, T2,
  S0, S1,
  A0, A1)>;