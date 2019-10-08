#include "ftd2xx.h"
#include "lcd.h"
#include "lcdInit.h"
#include "lcdWriteIR.h"
#include "HD44780.h"

HD44780::HD44780() {

}
HD44780::~HD44780() {

}
bool HD44780::lcdInitOk() {
}
FT_STATUS HD44780::lcdGetError() {

}
bool HD44780::lcdClear() {
	for (int i = 0; i < ROWS * COLS - 1; i++) {
		//lcd clear;
	}
	cadd = 1;
}
bool HD44780::lcdClearToEOL() {
	bool ret = true;
	if (cadd >= HOME && cadd <= COLS) {
		for (int i = cadd; i < COLS; i++) {
			//lcd clear;
		}
	}
	else if (cadd > COLS && cadd <= ROWS * COLS) {
		for (int i = cadd; i < COLS; i++) {
			//lcd clear;
		}
	}
	else
		ret = false;
	return ret;
}
basicLCD& HD44780::operator<<(const unsigned char c){

}
basicLCD& HD44780::operator<<(const unsigned char* c) {

}

bool HD44780::lcdMoveCursorUp() {
	bool ret = true;
	cadd--;											//Trabajo con 0<=cadd<=31
	if (cadd >= COLS && cadd < COLS * ROWS)
		cadd -= COLS;
	else if (cadd >= HOME - 1 && cadd < COLS)
		cadd += COLS;
	else {
		ret = false;
		return ret;
	}
	cadd++;											//Vuelvo a con 1<=cadd<=32
	lcdUpdateCursor();
	return ret;
}
bool HD44780::lcdMoveCursorDown() {
	bool ret = true;
	cadd--;											//Trabajo con 0<=cadd<=31
	if (cadd >= COLS && cadd < COLS*ROWS)
		cadd -= COLS;
	else if (cadd >= HOME - 1 && cadd < COLS)
		cadd += COLS;
	else {
		ret = false;
		return ret;
	}
	cadd++;											//Vuelvo a con 1<=cadd<=32
	lcdUpdateCursor();
	return ret;
}
bool HD44780::lcdMoveCursorRight() {
	bool ret = true;
	cadd--;											//Trabajo con 0<=cadd<=31
	if (cadd == COLS * ROWS - 1)
		cadd = HOME - 1;
	else if (cadd >= HOME - 1 && cadd < COLS * ROWS-1)
		cadd++;
	else {
		ret = false;
		return ret;
	}
	cadd++;											//Vuelvo a con 1<=cadd<=32
	lcdUpdateCursor();
	return ret;
}
bool HD44780::lcdMoveCursorLeft() {
	bool ret = true;
	cadd--;											//Trabajo con 0<=cadd<=31
	if (cadd == HOME - 1)
		cadd = COLS * ROWS - 1;
	else if (cadd > HOME - 1 && cadd < COLS * ROWS)
		cadd--;
	else {
		ret = false;
		return ret;
	}
	cadd++;											//Vuelvo a con 1<=cadd<=32
	lcdUpdateCursor();
	return ret;
}
bool HD44780::lcdSetCursorPosition(const cursorPosition pos) {
	bool ret = false;
	if (pos.column < 0 || pos.column > ROWS-1 || pos.row < 0 || pos.row > COLS-1)
		ret = false;
	else {
		ret = true;
		cadd = pos.column + (pos.row * ROWS) + 1;
		lcdUpdateCursor();
	}
	return ret;
}
cursorPosition HD44780::lcdGetCursorPosition() {
	cursorPosition ret;
	ret.column = (cadd - 1) % ROWS;
	ret.row = (cadd - 1) / ROWS;
	return ret;
}
void HD44780::lcdUpdateCursor() {

}