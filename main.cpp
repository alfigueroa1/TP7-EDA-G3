#include <cstdio>
#include <iostream>
#include <windows.h>
#include <chrono>
#include "hitachiLCD.h"

int main()
{
    hitachiLCD lcd;
	
    if(!lcd.lcdInitOk())
        return 1;

	cursorPosition pos;
	lcd.lcdClear();
    lcd << 'e';

	return 0;
}





