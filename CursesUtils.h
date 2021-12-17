/*
 * CursesUtils.h
 *
 *  Created on: Oct 7, 2016
 *      Author: serge
 */

#ifndef CURSESUTILS_H_
#define CURSESUTILS_H_

#include <ncurses.h>// #include "curses.h"
#include <string>

enum ArrowKeys
{
	AK_UP = KEY_UP,
	AK_DOWN = KEY_DOWN,
	AK_LEFT = KEY_LEFT,
	AK_RIGHT = KEY_RIGHT
};

enum PlayerColors
{
	PLAYER_COLOR_PAIR = 1,
	PLAYER_COLOR_BACKGROUND = COLOR_YELLOW,
	PLAYER_COLOR_FOREGROUND = COLOR_YELLOW
};

enum ScreenColors
{
	YELLOW_SCREEN_COLOR_PAIR = 2,
	ALL_SCREENS_COLOR_PAIR = 3,
	CYAN_SCREEN_COLOR_PAIR = 4,
	BLACK_SCREEN_COLOR_PAIR = 5,
	BLUE_SCREEN_COLOR_PAIR = 6,
	GREEN_SCREEN_COLOR_PAIR = 7,
	MAGENTA_SCREENS_COLOR_PAIR = 8,
	RED_SCREEN_COLOR_PAIR = 9,
	WHITE_SCREEN_COLOR_PAIR = 10
};

enum ColorsPairs
{
	YELLOW_FG = COLOR_YELLOW,
	YELLOW_BG = COLOR_WHITE,
	CYAN_FG = COLOR_CYAN,
	CYAN_BG = COLOR_WHITE,
	BLACK_FG = COLOR_BLACK,
	BLACK_BG = COLOR_WHITE,
	BLUE_FG = COLOR_BLUE,
	BLUE_BG = COLOR_BLUE,
	GREEN_FG = COLOR_GREEN,
	GREEN_BG = COLOR_GREEN,
	MAGENTA_FG = COLOR_MAGENTA,
	MAGENTA_BG = COLOR_MAGENTA,
	RED_FG = COLOR_RED,
	RED_BG = COLOR_RED,
	WHITE_FG = COLOR_WHITE,
	WHITE_BG = COLOR_WHITE
};

enum ItemColors
{
	ITEM_COLOR_PAIR = 32,
	ITEM_COLOR_FG = COLOR_BLACK,
	ITEM_COLOR_BG = COLOR_WHITE,
	YELLOW_COLOR_ITEM_PAIR = 31,
};

enum blocks
{
	BLOCK_WIDTH = 10,
	BLOCK_HEIGHT = 4
};

void InitializeCurses(bool nodelay);
void InitializeColor();
void ShutdownCurses();
void ClearScreen();
void RefreshScreen();
int ScreenWidth();
int ScreenHeight();
int GetChar();
void DrawCharacter(int xPos, int yPos, char aCharacter);
void MoveCursor(int xPos, int yPos);
void DrawSprite(int xPos, int yPos, const char * sprite[], int spriteHeight, const short colorPair, int offset = 0);
//void DrawString(int xPos, int yPos, const std::string& string);
//void DrawBlock(int xPos, int yPos, char aCharacter);


#endif /* CURSESUTILS_H_ */
