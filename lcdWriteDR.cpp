#include <cstdio>
#include <iostream>
#include <windows.h>
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdWriteDR.h"
#include "lcdWriteIR.h"


void lcdWriteDR(FT_HANDLE* deviceHandler, BYTE valor) {

	sendNybble(*deviceHandler, 1, (valor & LCD_NYBBLE_H) | LCD_RS_ON);
	sendNybble(*deviceHandler, 1, ((valor & LCD_NYBBLE_L) << 4) | LCD_RS_ON);

    return;
}