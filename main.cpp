#include <cstdio>
#include <iostream>
#include <windows.h>
#include <chrono>
#include "hitachiLCD.h"



#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"
#include "lcdWriteIR.h"
#include "LCDClass.h"

int main()
{
    hitachiLCD lcd;
	FT_HANDLE* testHandle = lcd.getLCDHandler();	//No esta andando el deviceHandler
    if(!lcd.lcdInitOk())
        return 1;

	cursorPosition pos;


	lcd.lcdClear();
    lcd << 'e';
	//lcdWriteDR(testHandle, 't');


	return 0;
}