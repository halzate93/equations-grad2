#SimuProc 1.4.2.0}
MSG ingrese a
IN AX,1
STF 1AA
MSG ingrese b
IN AX,1
STF 2B
MSG ingrese c
IN AX,1
STF 3C
MSG min
IN AX,1
STF 1DD
MSG max
IN AX,1
ADDF 100
STF 2D
LDF 2D ; INICIO DEL CICLO
SUBF 1DD
JEQ 26 ; SALTAR AL FINAL
   LDF 1DD
   MULF 1DD
   MULF 1AA
   STF 20D
   LDF 1DD
   MULF 2B
   ADDF 20D
   ADDF 3C
   JEQ 020 ; SLATAR A IMPRIMIR
   LDF 1DD
   ADDF 100
   STF 1DD
   JMP 10 ; SALTAR AL INICIO DEL CILO
MSG Intercepto en ; IMPRIMIR
LDF 1DD
OUT 1,AX
ADDF 100
STF 1DD
JMP 10 ; SALTAR AL INICIO DEL CICLO
HLT





#100
0011111110000000
0000000000000000

