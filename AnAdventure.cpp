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
void InitWallSprite(Wall & wallToInit, char brick, int x, int y, int width, int height, short itemColorPair);
void InitScreen(GameScreens & ScreenToInit, short ScreenID, const char * compressed[], short drawingColor_pair, short backGroundColor_pair, GameScreens * ptr_up, GameScreens * ptr_down, GameScreens * ptr_left, GameScreens * ptr_right, Wall & wallToDraw, const signed short & wallType = 0);
void InitPlayer(Game & game, Player & player);
void ResetPlayer(const Game & game, Player & player);
int HandleInput(const Game & game, GameScreens * ptr_screen, Player & player);
//void UpdateGame(const Game & game, const Screen & screen, Player & player);
void DrawGame(const Game & game, GameScreens * ptr_screen, const Player & player);
void MovePlayer(const Game & game, GameScreens * ptr_screen, Player & player, int dx, int dy);
void DrawPlayer(const Player & player, const char * sprite[]);
void DrawScreen(const GameScreens * ptr_screen);
//bool occupied(const Player & player, int dx, int dy, const Screen & screen);

// Global handlers
GameScreens * ptr_currentScreen;

int main()
{
	srand(time(NULL));

	GameScreens startScreen; // 0
	GameScreens yellowCastle; // 1
	GameScreens cyanCastle; // 2
	GameScreens blackCastle; // 3
	GameScreens blueMazeTop; // 4
	GameScreens blueMaze1; // 5
	GameScreens blueMazeEntry; // 6
	GameScreens blueMazeCenter; // 7
	GameScreens blueMazeBottom; // 8
	GameScreens insideYellowCastle; // 9
	GameScreens redHallway; // 10
	GameScreens greenHallway1; // 11
	GameScreens greenHallway2; // 12
	GameScreens greenHallway3; // 13
	GameScreens yellowHallway; // 14
	GameScreens cyanHallway; // 15
	GameScreens easterEggRoom; // 16
	GameScreens purpleRoom; // 17
	GameScreens redRoom; // 18
	GameScreens greenRoom; // 19
	GameScreens redMazeUL; // 20
	GameScreens redMazeUR; // 21
	GameScreens redMazeBL; // 22
	GameScreens redMazeBR; // 23
	GameScreens orangeMazeTop; // 24
	GameScreens orangeMazeMiddle; // 25
	GameScreens orangeMazeBottom; // 26
	GameScreens orangeMazeUL; // 27
	GameScreens orangeMazeUR; // 28
	GameScreens orangeMazeBL; // 29
	GameScreens orangeMazeBR; // 30

	Wall leftWall;
	Wall rightWall;

	GameScreens * ptr_startscreen = &redHallway	;
	ptr_currentScreen = ptr_startscreen;

	Game game;
	Player player;
//
	InitializeCurses(true);
	InitializeColor();
//
	InitWallSprite(leftWall,'L', 3,0,WALL_WIDTH,CURRENT_SCREEN_HEIGHT,ITEM_COLOR_PAIR);
	InitWallSprite(rightWall,'R', CURRENT_SCREEN_WIDTH-3-WALL_WIDTH,0,WALL_WIDTH,CURRENT_SCREEN_HEIGHT,ITEM_COLOR_PAIR);
//
	InitScreen(startScreen, 0, STARTSCREEN_COMPRESSED, 9, 3, NULL, NULL, NULL, NULL, leftWall);
	InitScreen(yellowCastle, 1, CASTLE_COMPRESSED, YELLOW_SCREEN_COLOR_PAIR, 3, &insideYellowCastle, &greenHallway2, NULL, NULL, leftWall);
	InitScreen(cyanCastle, 2, CASTLE_COMPRESSED, CYAN_SCREEN_COLOR_PAIR, 3, &redMazeBR, &greenHallway3, NULL, NULL, leftWall);
	InitScreen(blackCastle, 3, CASTLE_COMPRESSED, BLACK_SCREEN_COLOR_PAIR, 3, &redHallway, &blueMazeTop, NULL, NULL, leftWall);
	InitScreen(blueMazeTop, 4, BLUE_MAZE_TOP, BLUE_SCREEN_COLOR_PAIR, 3, &blackCastle, &blueMazeCenter, &blueMazeBottom, &blueMaze1, leftWall);
	InitScreen(blueMaze1, 5, BLUE_MAZE_1, BLUE_SCREEN_COLOR_PAIR, 3, NULL, &blueMazeEntry, &blueMazeTop, &blueMazeBottom, leftWall);
	InitScreen(blueMazeEntry, 6, BLUE_MAZE_ENTRY, BLUE_SCREEN_COLOR_PAIR, 3, &blueMaze1, &greenHallway1, &blueMazeCenter, &blueMazeCenter, leftWall);
	InitScreen(blueMazeCenter, 7, BLUE_MAZE_CENTER, BLUE_SCREEN_COLOR_PAIR, 3, &blueMazeTop, &blueMazeBottom, &blueMazeEntry, &blueMazeEntry, leftWall);
	InitScreen(blueMazeBottom, 8, BLUE_MAZE_BOTTOM, BLUE_SCREEN_COLOR_PAIR, 3, &blueMazeCenter, NULL, &blueMaze1, &blueMazeTop, leftWall);
	InitScreen(insideYellowCastle, 9, BOTTOM_OPEN, YELLOW_SCREEN_COLOR_PAIR, 3, NULL, &yellowCastle, NULL, NULL, leftWall);
	InitScreen(redHallway, 10, BOTTOM_TOP_OPEN, RED_SCREEN_COLOR_PAIR, 3, &orangeMazeBR, &blackCastle, NULL, NULL, leftWall);
	InitScreen(greenHallway1, 11, HALLWAY_TOP_OPEN, GREEN_SCREEN_COLOR_PAIR, 3, &blueMazeEntry, NULL, NULL, &greenHallway2, leftWall, -1);
	InitScreen(greenHallway2, 12, HALLWAY_TOP_OPEN, GREEN_SCREEN_COLOR_PAIR, 3, &yellowCastle, NULL, &greenHallway1, &yellowHallway, leftWall);
	InitScreen(greenHallway3, 13, HALLWAY_BOTTOM_TOP_OPEN, GREEN_SCREEN_COLOR_PAIR, 3, &cyanCastle, &greenRoom, NULL, &orangeMazeBottom, leftWall, -1);
	InitScreen(yellowHallway, 14, HALLWAY_BOTTOM_OPEN, YELLOW_SCREEN_COLOR_PAIR, 3, NULL, &orangeMazeTop, &greenHallway2, &easterEggRoom, rightWall, 1);
	InitScreen(cyanHallway, 15, HALLWAY_BOTTOM_TOP_OPEN, CYAN_SCREEN_COLOR_PAIR, 3, &purpleRoom, &redRoom, &orangeMazeBottom, NULL, rightWall, 1);
	InitScreen(easterEggRoom, 16, HALLWAY_TOP_OPEN, MAGENTA_SCREENS_COLOR_PAIR, 3, NULL, NULL, &yellowHallway, NULL, leftWall);
	InitScreen(purpleRoom, 17, BOTTOM_OPEN, MAGENTA_SCREENS_COLOR_PAIR, 3, NULL, &cyanHallway, NULL, NULL, leftWall);
	InitScreen(redRoom, 18, TOP_OPEN, RED_SCREEN_COLOR_PAIR, 3, &cyanHallway, NULL, NULL, NULL, leftWall);
	InitScreen(greenRoom, 19, TOP_OPEN, GREEN_SCREEN_COLOR_PAIR, 3, &greenHallway3, NULL, NULL, NULL, leftWall);
	InitScreen(redMazeUL, 20, RED_MAZE_UL, RED_SCREEN_COLOR_PAIR, 3, NULL, &redMazeBL, &redMazeUR, &redMazeUR, leftWall);
	InitScreen(redMazeUR, 21, RED_MAZE_UR, RED_SCREEN_COLOR_PAIR, 3, NULL, &redMazeBR, &redMazeUL, &redMazeUL, leftWall);
	InitScreen(redMazeBL, 22, RED_MAZE_BL, RED_SCREEN_COLOR_PAIR, 3, &redMazeUL, NULL, &redMazeBR, &redMazeBR, leftWall);
	InitScreen(redMazeBR, 23, RED_MAZE_BR, RED_SCREEN_COLOR_PAIR, 3, &redMazeUR, &cyanCastle, &redMazeBL, &redMazeBL, leftWall);
	InitScreen(orangeMazeTop, 24, ORANGE_MAZE_TOP, YELLOW_SCREEN_COLOR_PAIR, 3, &yellowHallway, &orangeMazeMiddle, &orangeMazeMiddle, &orangeMazeMiddle, leftWall);
	InitScreen(orangeMazeMiddle, 25, ORANGE_MAZE_MIDDLE, YELLOW_SCREEN_COLOR_PAIR, 3, &orangeMazeTop, &orangeMazeBottom, &orangeMazeTop, &orangeMazeTop, leftWall);
	InitScreen(orangeMazeBottom, 26, ORANGE_MAZE_BOTTOM, YELLOW_SCREEN_COLOR_PAIR, 3, &orangeMazeMiddle, NULL, &greenHallway3, &cyanHallway, leftWall);
	InitScreen(orangeMazeUL, 20, ORANGE_MAZE_UL, YELLOW_SCREEN_COLOR_PAIR, 3, &orangeMazeBL, &orangeMazeBL, &orangeMazeBR, &orangeMazeUR, leftWall);
	InitScreen(orangeMazeUR, 21, ORANGE_MAZE_UR, YELLOW_SCREEN_COLOR_PAIR, 3, NULL, &orangeMazeBR, &orangeMazeUL, &orangeMazeBL, leftWall);
	InitScreen(orangeMazeBL, 22, ORANGE_MAZE_BL, YELLOW_SCREEN_COLOR_PAIR, 3, &orangeMazeUL, &orangeMazeUL, &orangeMazeUR, &orangeMazeBR, leftWall);
	InitScreen(orangeMazeBR, 23, ORANGE_MAZE_BR, YELLOW_SCREEN_COLOR_PAIR, 3, &orangeMazeUR, &redHallway, &orangeMazeBL, &orangeMazeUL, leftWall);

	InitGame(game);
	InitPlayer(game, player);


	bool quit = false;
	int input;

	clock_t lastTime = clock();

while(!quit)
	{
  input = HandleInput(game, ptr_currentScreen, player);
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

				DrawGame(game, ptr_currentScreen, player);

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

void InitScreen(GameScreens & ScreenToInit, short ScreenID, const char * compressed[], short drawingColor_pair, short backGroundColor_pair, GameScreens * ptr_up, GameScreens * ptr_down, GameScreens * ptr_left, GameScreens * ptr_right, Wall & wallToDraw, const signed short & wallType)
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

	ScreenToInit.ptr_up = ptr_up;
	ScreenToInit.ptr_down = ptr_down;
	ScreenToInit.ptr_left = ptr_left;
	ScreenToInit.ptr_right = ptr_right;

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

	short xPos = 0;
	if (wallType)
	{
		xPos = (wallType < 0) ? 11 : (CURRENT_SCREEN_WIDTH - wallToDraw.spriteSize.width - 11);
		// build walls, if requested, left -1, no wall 0, right 1
		for (int h = 0; h < wallToDraw.spriteSize.height; h++)
		{
			for (int w = 0; w < wallToDraw.spriteSize.width; w++)
			{
				ScreenToInit.content[h][xPos + w] = wallToDraw.content;
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

void InitWallSprite(Wall & wallToInit, char brick, int x, int y, int width, int height, short itemColorPair)
{
wallToInit.content = brick;
wallToInit.position.x = x;
wallToInit.position.y = y;
wallToInit.spriteSize.width = width;
wallToInit.spriteSize.height = height;
wallToInit.wallSpriteColorPair.colorPair = itemColorPair;
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


int HandleInput(const Game & game, GameScreens * ptr_screen, Player & player)
{
	int input = GetChar();
	switch(input) {
		case 'q':
		return input;
		case AK_LEFT:
		MovePlayer(game, ptr_screen, player,-PLAYER_MOVEMENT_AMOUNT_X, 0);
		break;
		case AK_RIGHT:
		MovePlayer(game, ptr_screen, player,PLAYER_MOVEMENT_AMOUNT_X, 0);
		break;
		case AK_UP:
		MovePlayer(game, ptr_screen, player,0, -PLAYER_MOVEMENT_AMOUNT_Y);
		break;
		case AK_DOWN:
		MovePlayer(game, ptr_screen, player, 0, PLAYER_MOVEMENT_AMOUNT_Y);
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
void DrawGame(const Game & game, GameScreens * ptr_screen, const Player & player)
{
	DrawScreen(ptr_screen);
	DrawPlayer(player, PLAYER_SPRITE);
}


void MovePlayer(const Game & game, GameScreens * ptr_screen, Player & player, int dx, int dy)
{
	bool collision = false;

// TODO (jens#1#12/15/21): Test different at the edges of screens!!!


//	if (collision != true)
//	{
		if(player.position.x + player.spriteSize.width + dx > game.windowSize.width)
		{
			player.position.x = 0;
			if (ptr_screen->ptr_right != NULL)
			{
				ptr_currentScreen = ptr_screen->ptr_right;
			}
		}
		else if (player.position.x + dx < 0)
		{
			player.position.x = game.windowSize.width - player.spriteSize.width;
			if (ptr_screen->ptr_left != NULL)
			{
				ptr_currentScreen = ptr_screen->ptr_left;
			}
		}
		else
		{
			// This is the only check for wall collision of the player sprite.
			// it checks for every move if the desired position is an empty space.
			// The Player can also cross 'C' which makes it passible to create stuff
			// like bridge and the entries to the castles
			for (int h = 0; h < player.spriteSize.height; h++)
			{
				for (int w = 0; w < player.spriteSize.width; w++)
				{
					if ((ptr_screen->content[player.position.y + dy + h][player.position.x + dx + w] != ' ') && (ptr_screen->content[player.position.y + dy + h][player.position.x + dx + w] != 'C'))
					{
					collision = true;
					}
				}
			}
			if (collision != true)
			{
			player.position.x += dx;
			}
		}


		if(player.position.y + player.spriteSize.height + dy > (game.windowSize.height))
		{
			player.position.y = 0;
			if (ptr_screen->ptr_down != NULL)
			{
			 ptr_currentScreen = ptr_screen->ptr_down;
			}
		}
		else if (player.position.y + dy < 0)
		{
			player.position.y = game.windowSize.height - player.spriteSize.height;
			if (ptr_screen->ptr_up != NULL)
			{
				ptr_currentScreen = ptr_screen->ptr_up;
			}
		}
		else
		{
			if (collision != true)
			{
			player.position.y += dy;
			}
		}
//	}
//	collision = false;
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


void DrawScreen(const GameScreens * ptr_screen)
{
short drawWithColorPair = 0;

 for(int h = 0; h < ptr_screen->ScreensSize.ScreenSizeInChars.height; h++)
	{
		for (int w = 0; w < ptr_screen->ScreensSize.ScreenSizeInChars.width ; w++)
		{
			drawWithColorPair = (ptr_screen->content[h][w] != ' ') ? ptr_screen->screenDefaultDrawingColorPair.colorPair : ptr_screen->screenDefaultBackgroundColorPair.colorPair;
			if ((ptr_screen->content[h][w] == 'L') || (ptr_screen->content[h][w] == 'R')) {drawWithColorPair = BLACK_SCREEN_COLOR_PAIR;} // ONLY TEMPORARY
			if (ptr_screen->content[h][w] == '#') {drawWithColorPair = ITEM_COLOR_PAIR;} // ONLY TEMPORARY
			attron(COLOR_PAIR(drawWithColorPair));
			DrawCharacter(w, h, ptr_screen->content[h][w]);
			attroff(COLOR_PAIR(drawWithColorPair));
		}
	}
	mvprintw(0,0,"ID: %d", ptr_screen->ScreenID);
	mvprintw(1,0,"UP: %x", ptr_screen->ptr_up);
	mvprintw(2,0,"DOWN: %x", ptr_screen->ptr_down);
	mvprintw(3,0,"LEFT: %x", ptr_screen->ptr_left);
	mvprintw(4,0,"RIGHT: %x", ptr_screen->ptr_right);
}
