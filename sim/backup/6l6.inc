*-----------------------------------------------------------------------
* Filename:		dm6L6.inc  V2 12/10/97
* Simulator:		PSpice
* Device type:		Power beam tetrode
* Device model:		6L6 (and variants)
*
* Author:		Duncan Munro
* Date:			4/6/97
* Copyright:		(C)1997-2000 Duncan Amplification
*
* V2 [12/10/97]: Screen current limited to prevent screen current
*		 draw at Vs = 0.
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current is an approximation
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Email queries to postmaster@duncanamps.com
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6L6 A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/5)}
Eme	me	0	VALUE={PWR(LIMIT{V(A,K),0,2000},1.5)/1750}
Emu	mu	0	VALUE={PWRS(V(G,K),1-(LIMIT{-V(G,K),30,9999}-30)/2000)}
Egs	gs	0	VALUE={LIMIT{V(A,K)/2.5+V(S,K)*15.15+V(mu)*134,0,1E6}}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)*0.8E-6}
Ecath  	cc    	0 	VALUE={LIMIT{V(gs2)*V(at),0,V(me)}}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={0.76*V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={V(sc)*LIMIT{V(S,K),0,10}/10}
*
* Grid current
*
Gg	G	K	VALUE={PWR(LIMIT{V(G,K)+1,0,1E6},1.5)*(1.25-V(at))*650E-6}
*
* Capacitances
*
Cg1	G	K	5.0p
Cgs	G	S	5.0p
Cak	A	K	6.5p
Cg1a	G	A	0.6p

.ENDS 
