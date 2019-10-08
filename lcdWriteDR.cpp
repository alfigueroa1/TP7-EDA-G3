#include <cstdio>
#include <iostream>
#include <windows.h>
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdWriteDR.h"


void lcdWriteDR(FT_HANDLE* deviceHandler, BYTE valor) {
    if((valor & LCD_RS_OFF) != 0)
        valor = valor & (~LCD_RS_OFF);
    sendNybble(*deviceHandler, 1, valor | LCD_NYBBLE_H);
    sendNybble(*deviceHandler, 1, valor | LCD_NYBBLE_L);

    return;
}


void sendNybbleDR(FT_HANDLE lcdHandle, DWORD sizeSent, unsigned char byte) {
    unsigned char info;
    info = ((LCD_EN_OFF) | (byte));
    FT_Write(lcdHandle, &info, 1, &sizeSent);
    Sleep(1);
    info = ((LCD_EN_ON) | (byte));
    FT_Write(lcdHandle, &info, 1, &sizeSent);
    Sleep(1);
    info = ((LCD_EN_OFF) | (byte));
    FT_Write(lcdHandle, &info, 1, &sizeSent);
    Sleep(1);

    return;
}