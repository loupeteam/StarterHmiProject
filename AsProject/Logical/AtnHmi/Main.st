
PROGRAM _INIT
	(* Insert code here *)
	 commandFilter;
END_PROGRAM

PROGRAM _CYCLIC

	atncyclic( ADR(gConsole.Console), SIZEOF(gConsole.Console) );
	
	IF refreshState THEN
		refreshState := FALSE;
		systemJson( ADR(systemState), SIZEOF(systemState));
	END_IF	
	
	FOR index := 0 TO PLCOpenCall_MAI DO
	
		IF AtnPLCOpenCall[index].Busy OR AtnPLCOpenCall[index].Execute THEN 
			
			AtnPLCOpenCall[index]();		
		END_IF		
		AtnPLCOpenCall[index].Execute := FALSE;		
	END_FOR
	
	FOR index := 0 TO PLCOpenCall_MAI DO
		
		IF readState[index].Status[0] <> '' THEN
			FOR line := 0 TO SIZEOF(readState[index].Status)/SIZEOF(readState[index].Status[0]) - 1 DO
				readState[index].Status[line] := '';
			END_FOR	
		END_IF
		
			
		stateStatus( readState[index].State, ADR(readState[index].Status), SIZEOF(readState[index].Status)); 	

	END_FOR
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

