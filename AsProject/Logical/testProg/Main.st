
PROGRAM _INIT

	subscribeCommandBool('bringPizza', 'bishop', test);
	subscribeCommandBool('bringSoda', 'bishop', test);
	subscribeCommandBool('bringChips', 'bishop', test);
	subscribeCommandBool('playGames', 'bishop', test);
	subscribeCommandBool('haveFun', 'bishop', test);
	subscribeCommandBool('iSpecificallyRequestedIt', 'bishop', test);
	subscribeCommandBool('apple', 'bishop', test);
	subscribeCommandBool('bacon', 'bishop', test);
	subscribeCommandBool('BACON', 'bishop', test);
	
	registerStateBool('bringPizza', 'bishop', test);
	registerStateBool('bringSoda', 'bishop', test);
	registerStateBool('bringChips', 'bishop', test);
	registerStateBool('playGames', 'bishop', test);
	registerStateBool('haveFun', 'bishop', test);
	registerStateBool('iSpecificallyRequestedIt', 'bishop', test);
	registerStateBool('apple', 'bishop', test);
	registerStateBool('bacon', 'bishop', test);
	
	subscribePLCOpen('plcopen', 'bishop', test, PLCOpenStatus);
	
END_PROGRAM

PROGRAM _CYCLIC


END_PROGRAM

PROGRAM _EXIT

	 
END_PROGRAM

