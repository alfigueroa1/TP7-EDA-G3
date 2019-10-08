#include <cstdio>
#include <iostream>
#include <windows.h>
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"
#include "lcdWriteIR.h"
#include "basicLCD.h"

using namespace std;

basicLCD::basicLCD() {
	lcdInit(0);
	cadd = 1;
	previous_cadd = 1;
	FT_HANDLE lcdHandle;
	deviceHandler = &lcdHandle;
}

basicLCD::~basicLCD() {
	lcdWriteIR(deviceHandler, LCD_CLEAR);		//???? No se que mas va
	cadd = 1;
}

void basicLCD::lcdUpdateCursor() {				//Chicos tengo sueño creo que le estoy mandando cualquiera
	int shift = cadd - previous_cadd;
	if (shift < 0)
		for (int i = 0; i < (-shift); i++)
			lcdWriteIR(deviceHandler, LCD_SHIFT_CURSOR_L);
	else
		for (int i = 0; i < (-shift); i++)
			lcdWriteIR(deviceHandler, LCD_SHIFT_CURSOR_R);
	return;
}


