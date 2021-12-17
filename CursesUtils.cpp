/*
 * CursesUtils.cpp
 *
 *  Created on: Oct 7, 2016
 *      Author: serge
 */
#include "CursesUtils.h"

void InitializeCurses(bool noDelay)
{
	initscr();
	noecho();
	curs_set(false);
	nodelay(stdscr, noDelay);
	keypad(stdscr, true);
}

void InitializeColor()
{
	start_color();
	init_pair(PLAYER_COLOR_PAIR, PLAYER_COLOR_FOREGROUND, PLAYER_COLOR_BACKGROUND); // Colors of the Player
  init_pair(YELLOW_SCREEN_COLOR_PAIR,YELLOW_FG,YELLOW_FG); // yellow drawing Color on screens
	init_pair(ALL_SCREENS_COLOR_PAIR,YELLOW_BG,YELLOW_BG); // all backgrounds
  init_pair(CYAN_SCREEN_COLOR_PAIR,CYAN_FG,CYAN_FG); // cyan  drawing Color on screens
	init_pair(BLACK_SCREEN_COLOR_PAIR,BLACK_FG,BLACK_FG); // black drawing Color on screens
	init_pair(BLUE_SCREEN_COLOR_PAIR,BLUE_FG,BLUE_FG); // blue drawing Color on screens
	init_pair(GREEN_SCREEN_COLOR_PAIR,GREEN_FG,GREEN_FG); // green drawing Color on screens
	init_pair(MAGENTA_SCREENS_COLOR_PAIR,MAGENTA_BG,MAGENTA_BG); // magenta backgrounds
  init_pair(RED_SCREEN_COLOR_PAIR,RED_FG,RED_FG); // red  drawing Color on screens
	init_pair(WHITE_SCREEN_COLOR_PAIR,WHITE_FG,WHITE_FG); // wite drawing Color on screens

	init_pair(BLACK_COLOR_ITEM_PAIR, BLACK_FG, WHITE_BG); // black items
	init_pair(CYAN_COLOR_ITEM_PAIR, CYAN_FG, WHITE_BG); // cyan items
	init_pair(YELLOW_COLOR_ITEM_PAIR, YELLOW_FG, WHITE_BG); // yellow items
	init_pair(ITEM_COLOR_PAIR,ITEM_COLOR_FG,ITEM_COLOR_BG); // block items
}

void ShutdownCurses()
{
	endwin();
}

void ClearScreen()
{
	clear();
}

void RefreshScreen()
{
	refresh();
}

int ScreenWidth()
{
	return COLS;
}

int ScreenHeight()
{
	return LINES;
}

int GetChar()
{
	return getch();
}

void DrawCharacter(int xPos, int yPos, char aCharacter)
{
	mvaddch(yPos, xPos, aCharacter);
}


//void MoveCursor(int xPos, int yPos)
//{
//	move(yPos, xPos);
//}

void DrawSprite(int xPos, int yPos, const char * sprite[], int spriteHeight, const short colorPair, int offset)
{
	attron(COLOR_PAIR(colorPair));
	for(int h = 0; h < spriteHeight; h++)
	{
		mvprintw(yPos + h, xPos, "%s", sprite[h+offset]);
	}
	attroff(COLOR_PAIR(colorPair));
}
//
//void DrawString(int xPos, int yPos, const std::string& string)
//{
//	mvprintw(yPos, xPos, string.c_str());
//}
//
//void DrawBlock(int xPos, int yPos, char aCharacter)
//{
//	for (int j = 0; j < BLOCK_HEIGHT; j++)
//	{
//		for (int i = 0; i < BLOCK_WIDTH; i++)
//		{
//			mvaddch(yPos + j, xPos + i, aCharacter);
//		}
//	}
//}
//
