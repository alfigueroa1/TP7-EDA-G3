#include <cstdio>
#include <iostream>
#include <windows.h>
#include <chrono>
#include "hitachiLCD.h"


#include "lcdWriteIR.h"
#include "lcdWriteDR.h"

int main()
{
    hitachiLCD lcd;
	FT_HANDLE* testHandle = lcd.getLCDHandler();
    if(!lcd.lcdInitOk())
        return 1;

	cursorPosition pos;
	lcd.lcdClear();
    //lcd << 'e';
	lcdWriteDR(testHandle, 'e');

	return 0;
}





