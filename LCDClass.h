#pragma once

#include <cstdio>
#include <iostream>
#include <windows.h>
#define FTD2XX_EXPORTS
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"
#include "lcdWriteIR.h"
#include "lcdWriteDR.h"

using namespace std;

class LCDClass {
public:
	LCDClass();
	FT_HANDLE* lcdInit(int iDevice);
	FT_HANDLE* getHandler();

private:
	FT_HANDLE handler;
	
};








