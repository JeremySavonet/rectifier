.SUBCKT PP_OUTPUT_XFRMR 1 2 3 4 5					
*			35	primary DC resistance	
*			0.5	secondary DC resistance	
*			100	total primary L	
*			5200	primary Z	
*			8	secondary Z	
LP1	1	2	25	Rser= 	17.5
LP2	2	3	25	Rser= 	17.5
LS1	4	5	0.153846154	Rser= 	0.5
KALL LP1 LP2 LS1 .9999875 					
.ENDS					
				
			
