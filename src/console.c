//console.c
//by cloidnerux
//eine minimale Version um grundlegende Steuerbefehle zu haben.

#include "include/system.h"

/// Eine Simple Konsole
void Console()
{
	char *command;
	while(1)
	{
		Printf("$>");
		GetString(command);
		if(StrComp(command, "quit\0") == TRUE)
		{
			CPUReset();
		}
		else if(StrComp(command, "pageFault\0") == TRUE)
		{
			  u32int *ptr = (u32int*)0xA0000000;
			  u32int doPageFault = *ptr;
			  doPageFault = 3;
		}
	}
}