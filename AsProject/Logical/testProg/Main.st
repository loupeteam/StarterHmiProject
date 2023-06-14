
PROGRAM _INIT

	 
END_PROGRAM

PROGRAM _CYCLIC

	//subscribeCommandBool('bringPizza', 'bishop', test);
	subscribePLCOpen('bringPizza', 'bishop', test, PLCOpenStatus);
	
END_PROGRAM

PROGRAM _EXIT

	 
END_PROGRAM

