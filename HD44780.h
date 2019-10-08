#pragma once
#include "basicLCD.h"
#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"
#include "lcdWriteIR.h"

#define ROWS	16
#define COLS	2
#define HOME	1

class HD44780: public basicLCD {
public:
	HD44780();
	~HD44780();
	virtual bool lcdInitOk();
	virtual FT_STATUS lcdGetError();
	virtual bool lcdClear();
	virtual bool lcdClearToEOL();
	virtual basicLCD& operator<<(const unsigned char c);
	virtual basicLCD& operator<<(const unsigned char* c);
	virtual bool lcdMoveCursorUp();
	virtual bool lcdMoveCursorDown();
	virtual bool lcdMoveCursorRight();
	virtual bool lcdMoveCursorLeft();
	virtual bool lcdSetCursorPosition(const cursorPosition pos);
	virtual cursorPosition lcdGetCursorPosition();
protected:
	virtual void lcdUpdateCursor();
private:
	FT_HANDLE* lcdHandle;
	int lcdID;
};