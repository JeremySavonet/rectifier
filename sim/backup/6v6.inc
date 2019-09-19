.SUBCKT 6V6GT 1 2 3 4 ; A G2 G1 C;
*      Extract V1.980
* Model created:  7-Jun-2014
* NOTE: LOG(x) is base e LOG or natural logarithm.
* For some Spice versions, e.g. MicroCap, this has to be changed to LN(x).
X1 1 2 3 4 BTetrodeDE  MU= 10.56 EX=1.306 kG1= 609.8 KP=  47.9 kVB = 2171.5 kG2=17267.3
+Sc=.81E-01 ap=  .013 w=    18. nu=   .92 lam=     5.7
+ Ookg1mOokG2=.158E-02 Aokg1=.57E-06 alkg1palskg2=.158E-02 be=  .068 als= 18.72 RGI=2000
+ CCG1=9.0P  CCG2 = 0.0p CPG1 = 0.7p  CG1G2 = 0.0p CCP=7.5P  ;
.ENDS
****************************************************
.SUBCKT BTetrodeDE 1 2 3 4; A G2 G1 C
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1 7 0 VALUE=
+{V(2,4)/KP*LOG(1+EXP(KP*(1/MU+V(3,4)/SQRT(KVB+V(2,4)*V(2,4)))))}
E2   8 0 VALUE = {Ookg1mOokG2 + Aokg1*V(1,4) - alkg1palskg2*Exp(-be*V(1,4)*SQRT(be*V(1,4)))}
E3   9 0 VALUE = {Sc/kG2*V(1,4)*(1+tanh(-ap*(V(1,4)-V(2,4)/lam+w+nu*V(3,4))))}
G1   1 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))*(V(8)-V(9))}
G2   2 4 VALUE = {0.5*(PWR(V(7),EX)+PWRS(V(7),EX))/KG2 *(1+als*Exp(-be*V(1,4) * SQRT(be*V(1,4))))}
RCP  1 4  1G      ; FOR CONVERGENCE    A  - C
C1   3 4  {CCG1}   ; CATHODE-GRID 1    C  - G1
C4   2 4  {CCG2}   ; CATHODE-GRID 2    C  - G2
C5   2 3  {CG1G2}   ; Grid 1-GRID 2    G1  - G2
C2   1 3  {CPG1}  ; GRID 1-PLATE    G1 - A
C3   1 4  {CCP}   ; CATHODE-PLATE    A  - C
R1   3 5  {RGI}   ; FOR GRID CURRENT    G1 - 5
D3   5 4  DX      ; FOR GRID CURRENT    5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS BTetrodeDE
