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

int main()
{
    hitachiLCD lcd;
	FT_HANDLE* testHandle = lcd.getLCDHandler();
    if(!lcd.lcdInitOk())
        return 1;

	cursorPosition pos = {2,0};
	lcd.lcdClear();
	lcd << "Hola Malu";
	lcd.lcdSetCursorPosition(pos);

	lcd << "Perdi  -Grupo 3";
	Sleep(5000);
	lcd.lcdSetCursorPosition({1,1});
	lcd.lcdClear();
	lcd << "Jobs done! <3";

	return 0;
}