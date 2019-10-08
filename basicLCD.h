#pragma once

#include <cstdio>
#include <iostream>
#include <windows.h>
#include <chrono>
#include "ftd2xx.h"

struct cursorPosition
{
	int row;
	int column;
};

class basicLCD
{
public:

	basicLCD();
	~basicLCD();

	virtual bool lcdInitOk() = 0;
	virtual FT_STATUS lcdGetError() = 0;
	virtual bool lcdClear() = 0;
	virtual bool lcdClearToEOL() = 0;

	virtual basicLCD& operator<<(const unsigned char c) = 0;
	virtual basicLCD& operator<<(const unsigned char* c) = 0;

	virtual bool lcdMoveCursorUp() = 0;
	virtual bool lcdMoveCursorDown() = 0;
	virtual bool lcdMoveCursorRight() = 0;
	virtual bool lcdMoveCursorLeft() = 0;
	virtual bool lcdSetCursorPosition(const cursorPosition pos) = 0;
	virtual cursorPosition lcdGetCursorPosition() = 0;

protected:

	int cadd;
	void lcdUpdateCursor();

private:

	FT_HANDLE* deviceHandler;
	int previous_cadd;

};