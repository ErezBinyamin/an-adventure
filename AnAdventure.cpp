//====================================================================================
// Name        : AnAdventure.cpp
// Author      : Jens Schendel
// Version     : 0.0.1
// Copyright   : Your copyright notice
// Description : A Tribute to the Work to Robinett in C++ and ncurses in the terminal
//====================================================================================

#include <iostream>
#include "AnAdventure.h"
#include "CursesUtils.h"
#include <ctime>
#include <cmath>
#include <cstring>
//#include <unistd.h>
//#include <cstdlib>
#include <string>
//#include <algorithm> //for sort
//#include <fstream> //for file i/o

using namespace std;

void InitGame(Game & game);
void InitScreen(GameScreens & ScreenToInit, short ScreenID, const char * compressed[], short drawingColor_pair, short backGorundColor_pair);
void InitPlayer(Game & game, Player & player);
void ResetPlayer(const Game & game, Player & player);
int HandleInput(const Game & game, const GameScreens & screen, Player & player);
//void UpdateGame(const Game & game, const Screen & screen, Player & player);
void DrawGame(const Game & game, const GameScreens & screen, const Player & player);
void MovePlayer(const Game & game, const GameScreens & screen, Player & player, int dx, int dy);
void DrawPlayer(const Player & player, const char * sprite[]);

void DrawScreen(const GameScreens & screen);
//bool occupied(const Player & player, int dx, int dy, const Screen & screen);

int main()
{
	srand(time(NULL));

	GameScreens currentScreen; // 0
	GameScreens yellowCastle; // 1
	GameScreens cyanCastle; // 2
	GameScreens blackCastle; // 3
	GameScreens blueMazeTop; // 4
	GameScreens blueMaze1; // 5
	GameScreens blueMazeEntry; // 6
	GameScreens blueMazeCenter; // 7
	GameScreens blueMazeBottom; // 7

	Game game;
	Player player;
//
	InitializeCurses(true);
	InitializeColor();
//
	InitScreen(currentScreen, 0, EMPTY_SPACE_COMPRESSED, 2, 3);
	InitScreen(yellowCastle, 1, CASTLE_COMPRESSED, 2, 3);
	InitScreen(cyanCastle, 2, CASTLE_COMPRESSED, 4, 3);
	InitScreen(blackCastle, 3, CASTLE_COMPRESSED, 5, 3);
	InitScreen(blueMazeTop, 4, BLUE_MAZE_TOP, 6, 3);
	InitScreen(blueMaze1, 5, BLUE_MAZE_1, 6, 3);
	InitScreen(blueMazeEntry, 6, BLUE_MAZE_ENTRY, 6, 3);
	InitScreen(blueMazeCenter, 7, BLUE_MAZE_CENTER, 6, 3);
	InitScreen(blueMazeBottom, 7, BLUE_MAZE_BOTTOM, 6, 3);

//	InitScreen(currentScreen,0, EMPTY_SPACE_COMPRESSED);
	InitGame(game);
	InitPlayer(game, player);


	bool quit = false;
	int input;

	clock_t lastTime = clock();

while(!quit)
	{
  input = HandleInput(game, yellowCastle, player);
		if(input != 'q')
		{
				clock_t currentTime = clock();
				clock_t dt = currentTime - lastTime;

				if (dt > CLOCKS_PER_SEC/FPS)
				{
				lastTime = currentTime;
				// UpdateGame(game, screen, player);
				// ClearScreen(); //curses utils
// TODO (jens#1#12/13/21): Use pointers to call the right screen. ...
//Make current Screent an element  player object
				//DrawGame(game, currentScreen, player);

				DrawGame(game, blueMazeEntry, player);

				// RefreshScreen(); // curses utils
				}
		}
		else
		{
			quit = true;
		}
	}

	ShutdownCurses();

	return 0;
}

void InitScreen(GameScreens & ScreenToInit, short ScreenID, const char * compressed[], short drawingColor_pair, short backGroundColor_pair)
{
	ScreenToInit.ScreenID = ScreenID;
	ScreenToInit.ScreensSize.ScreenSizeInChars.height = CURRENT_SCREEN_HEIGHT;
	ScreenToInit.ScreensSize.ScreenSizeInChars.width = CURRENT_SCREEN_WIDTH;
	ScreenToInit.ScreensSize.ScreenSizeInBlocks.height = SCREEN_HEIGHT_IN_BLOCKS;
	ScreenToInit.ScreensSize.ScreenSizeInBlocks.width = SCREEN_WIDTH_IN_BLOCKS;

	short widthOfaBlock = (CURRENT_SCREEN_WIDTH / SCREEN_WIDTH_IN_BLOCKS);
	short heightOfaBlock = (CURRENT_SCREEN_HEIGHT / SCREEN_HEIGHT_IN_BLOCKS);

	ScreenToInit.screenDefaultDrawingColorPair.colorPair = drawingColor_pair;
	ScreenToInit.screenDefaultBackgroundColorPair.colorPair = backGroundColor_pair;

	for (int height = 0; height < SCREEN_HEIGHT_IN_BLOCKS; height++)
	{
		for (int width = 0; width < SCREEN_WIDTH_IN_BLOCKS; width++)
		{
			for (short blockheight = 0; blockheight < heightOfaBlock; blockheight++)
			{
				for (short blockwidth = 0; blockwidth < widthOfaBlock; blockwidth++)
				{
					ScreenToInit.content[(height * heightOfaBlock) + blockheight][(width * widthOfaBlock) + blockwidth] = compressed[height][width];
				}
			}
		}
	}
}


void InitGame(Game & game)
{
	game.windowSize.width = ScreenWidth();
	game.windowSize.height = ScreenHeight();
	game.currentState = GS_PLAY;
}


void InitPlayer(Game & game, Player & player)
{
player.spriteSize.width = PLAYER_SPRITE_WIDTH;
player.spriteSize.height = PLAYER_SPRITE_HEIGHT;
player.playerColorPair.colorPair = PLAYER_COLOR_PAIR;
ResetPlayer(game, player);
}


void ResetPlayer(const Game & game, Player & player)
{
	player.position.x = game.windowSize.width / 2 - player.spriteSize.width / 2;
	player.position. y = game.windowSize.height - 4 * player.spriteSize.height; // 4 times player height from above
}


int HandleInput(const Game & game, const GameScreens & screen, Player & player)
{
	int input = GetChar();
	switch(input) {
		case 'q':
		return input;
		case AK_LEFT:
		MovePlayer(game, screen, player,-PLAYER_MOVEMENT_AMOUNT_X, 0);
		break;
		case AK_RIGHT:
		MovePlayer(game, screen, player,PLAYER_MOVEMENT_AMOUNT_X, 0);
		break;
		case AK_UP:
		MovePlayer(game, screen, player,0, -PLAYER_MOVEMENT_AMOUNT_Y);
		break;
		case AK_DOWN:
		MovePlayer(game, screen, player, 0, PLAYER_MOVEMENT_AMOUNT_Y);
		break;
	}
	return input;
}


//
//void UpdateGame(const Game & game,const Screen & screen, Player & player)
//{
//
//}
//
void DrawGame(const Game & game, const GameScreens & screen, const Player & player)
{
	DrawScreen(screen);
	DrawPlayer(player, PLAYER_SPRITE);
}


void MovePlayer(const Game & game, const GameScreens & screen, Player & player, int dx, int dy)
{
	if(player.position.x + player.spriteSize.width + dx > game.windowSize.width)
	{
		player.position.x = game.windowSize.width - player.spriteSize.width;
	}
	else if (player.position.x + dx < 0)
	{
		player.position.x = 0;
	}
	else // if (occupied(player, dx, dy, screen) != true)
	{
		player.position.x += dx;
	}

	if(player.position.y + player.spriteSize.height + dy > (game.windowSize.height))
	{
		player.position.y = game.windowSize.height - player.spriteSize.height;
	}
	else if (player.position.y + dy < 0)
	{
		player.position.y = 0;
	}
	else
	{  // if (player.position.y + dy != OCCUPIED)	{
		player.position.y += dy;
	}
}

//bool occupied(const Player & player, int dx, int dy, const Screen & screen)
//{
//	for (int x = 0; x < PLAYER_SPRITE_WIDTH; x++)
//		{
//			for (int y = 0; y < PLAYER_SPRITE_HEIGHT; y++)
//			{
//				// if (player.position.x + dx)
//			}
//		}
//return false;
//}


void DrawPlayer(const Player & player, const char * sprite[])
{
	DrawSprite(player.position.x, player.position.y, PLAYER_SPRITE, player.spriteSize.height, player.playerColorPair.colorPair);
}


void DrawScreen(const GameScreens & screen)
{
short drawWithColorPair = 0;

 for(int h = 0; h < screen.ScreensSize.ScreenSizeInChars.height; h++)
	{
		for (int w = 0; w < screen.ScreensSize.ScreenSizeInChars.width ; w++)
		{
			drawWithColorPair = (screen.content[h][w] != ' ') ? screen.screenDefaultDrawingColorPair.colorPair : screen.screenDefaultBackgroundColorPair.colorPair;
			if (screen.content[h][w] == '#') {drawWithColorPair = ITEM_COLOR_PAIR;} // ONLY TEMPORARY
			attron(COLOR_PAIR(drawWithColorPair));
			DrawCharacter(w, h, screen.content[h][w]);
			attroff(COLOR_PAIR(drawWithColorPair));
		}
	}
}
