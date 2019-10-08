#include "hitachiLCD.h"

int main()
{
    hitachiLCD lcd;

    if(lcd.lcdInitOk())
        return 1;

    lcd.lcdClear();
    lcd << 'e';

	return 0;
}





