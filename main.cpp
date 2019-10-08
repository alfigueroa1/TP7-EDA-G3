#include <cstdio>
#include <iostream>
#include <windows.h>
#include <chrono>
#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"

int main()
{	
	int iDevice = 1;		//????
	lcdInit(iDevice);

	return 0;
}





