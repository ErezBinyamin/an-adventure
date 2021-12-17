/*
 * TextInvaders.h
 *
 *  Created on: Oct 11, 2016
 *      Author: serge
 */

#ifndef ANADVENTURE_H_
#define ANADVENTURE_H_

#include <string>
#include <vector>

enum
{
    PLAYER_SPRITE_WIDTH = 3,
    PLAYER_SPRITE_HEIGHT = 2,
    PLAYER_MOVEMENT_AMOUNT_X = 2,
    PLAYER_MOVEMENT_AMOUNT_Y = 1,
    SCREEN_WIDTH_IN_BLOCKS = 20, // 10 Chars width of Block 	##########\
																															##########\
																															##########\
																															##########
    SCREEN_HEIGHT_IN_BLOCKS = 12, // 4 Chars height of block
    CURRENT_SCREEN_WIDTH = 200,
    CURRENT_SCREEN_HEIGHT = 48,
		FPS = 20,
		MAX_NUMBER_OF_SCREENS = 2,
		WALL_WIDTH = 3,
		KEYS_SWORD_SPRITE_WIDTH = 5,
		KEYS_SWORD_SPRITE_HEIGHT = 1,
		MAX_ITEM_SIZE_X = 9,
		MAX_ITEM_SIZE_Y = 10,
		INITIAL_GAMETYPE = 1
};

const char * PLAYER_SPRITE[] = {"###", "###"};

const char * STARTSCREEN_COMPRESSED[] = {	" X  X  X    X  XX   ",\
																					"X X XX X   X X X X  ",\
																					"XXX X XX   XXX X X  ",\
																					"X X X  X   X X XX   ",\
																					"X X XXXX X  X XXX   ",\
																					"X X XX   XX X  X    ",\
																					"X X X    X XX  X    ",\
																					" X  XXXX X  X  X    ",\
																					"X  X XXX XXXX       ",\
																					"X  X X X XX         ",\
																					"X  X XX  X          ",\
																					" XX  X X XXXX       ",};

const char * CASTLE_COMPRESSED[] = {	"XXXXX X X  X X XXXXX",\
																			"X   XXXXX  XXXXX   X",\
																			"X   XXXXX  XXXXX   X",\
																			"X   XXXXXXXXXXXX   X",\
																			"X   XXXXXXXXXXXX   X",\
																			"X    XXXXXXXXXX    X",\
																			"X    XXXXXXXXXX    X",\
																			"X    XXX ## XXX    X",\
																			"X    XXX ## XXX    X",\
																			"X                  X",\
																			"X                  X",\
																			"XXXXXXX      XXXXXXX"};

const char * TOP_OPEN[] = {	"XXXXXXX      XXXXXXX",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"X                  X",\
														"XXXXXXXXXXXXXXXXXXXX"};

const char * BOTTOM_OPEN[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"X                  X",\
																"XXXXXXX      XXXXXXX"};

const char * HALLWAY_TOP_OPEN[] = {	"XXXXXXX      XXXXXXX",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"                    ",\
																		"XXXXXXXXXXXXXXXXXXXX"};

const char * HALLWAY_BOTTOM_OPEN[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"                    ",\
																				"XXXXXXX      XXXXXXX"};

const char * BOTTOM_TOP_OPEN[] = {	"XXXXXXX      XXXXXXX",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"XXXXXXX      XXXXXXX"};

const char * HALLWAY_BOTTOM_TOP_OPEN[] = {	"XXXXXXX      XXXXXXX",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"                    ",\
																						"XXXXXXX      XXXXXXX"};

// Top of Blue Maze
const char * BLUE_MAZE_TOP[] = {	"XXXXXXXX    XXXXXXXX",\
																	"    X  X    X  X    ",\
																	"    X  X    X  X    ",\
																	"    X  XX  XX  X    ",\
																	"X   X  XX  XX  X   X",\
																	"X   X          X   X",\
																	"X   X          X   X",\
																	"XXXXXXXX    XXXXXXXX",\
																	"    X  X    X  X    ",\
																	"    X  X    X  X    ",\
																	"    X  X    X  X    ",\
																	"XX  X XX    XX X  XX"};

//
//// Blue Maze #1
const char * BLUE_MAZE_1[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																"                    ",\
																"                    ",\
																"                    ",\
																"XXXXX  XXXXXX  XXXXX",\
																"X        XX        X",\
																"X        XX        X",\
																"X  XXXXX XX XXXXX  X",\
																"   X   X XX X   X   ",\
																"   X   X XX X   X   ",\
																"   X   X XX X   X   ",\
																"XXXX X X XX X X XXXX"};
//
//// Bottom of Blue Maze
const char * BLUE_MAZE_BOTTOM[] = {	"XXX X X      X X XXX",\
																		"  X   X      X   X  ",\
																		"  X   X      X   X  ",\
																		"  XXXXX      XXXXX  ",\
																		"X                  X",\
																		"X                  X",\
																		"X                  X",\
																		"XXXXX          XXXXX",\
																		"    X          X    ",\
																		"    X          X    ",\
																		"    X          X    ",\
																		"XXXXXXXXXXXXXXXXXXXXX"};
//
//// CenteX of Blue Maze
const char * BLUE_MAZE_CENTER[] = {	"XX  X XX    XX X  XX",\
																		"    X XX    XX X    ",\
																		"    X XX    XX X    ",\
																		"XXXXX XX    XX XXXXXX",\
																		"XXXXX XX    XX XXXXXX",\
																		"    X XX    XX X    ",\
																		"    X XX    XX X    ",\
																		"X X X XX    XX X X XX",\
																		"X X X XX    XX X X XX",\
																		"  X X X      X X X  ",\
																		"  X X X      X X X  ",\
																		"XXX X X      X X XXX"};
//
//// Blue Maze EntXy
const char * BLUE_MAZE_ENTRY[] = { 	"XXXX X X XX X X XXXX",\
																		"   X X X    X X X   ",\
																		"   X X X    X X X   ",\
																		"X  X X XXXXXX X X  X",\
																		"X  X X XXXXXX X X  X",\
																		"   X X        X X   ",\
																		"   X X        X X   ",\
																		"XXXX XXXXXXXXXX XXXX",\
																		"XXXX XXXXXXXXXX XXXX",\
																		"                    ",\
																		"                    ",\
																		"XXXXXXX      XXXXXXX"};


// red upper left
const char * RED_MAZE_UL[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																"                    ",\
																"                    ",\
																"XXXXXXX      XXXXXXX",\
																"      X      X      ",\
																"      X      X      ",\
																"XXX   X      X   XXX",\
																"XXXXXXX      XXXXXXX",\
																"X     X      X     X",\
																"X     X      X     X",\
																"X  X  X  XX  X  X  X",\
																"X  X  X  XX  X  X  X"};
// red upper right
const char * RED_MAZE_UR[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																"         XX         ",\
																"         XX         ",\
																"XXXXXXX  XX  XXXXXXX",\
																"      X  XX  X      ",\
																"      X  XX  X      ",\
																"X  X XX  XX  XX X  X",\
																"X  X XXXXXXXXXX X  X",\
																"X  X X        X X  X",\
																"X  X X        X X  X",\
																"X  X X  X  X  X X  X",\
																"X  XXX  X  X  XXX  X"};
// red bottom left
const char * RED_MAZE_BL[] = {	"X  X  X  XX  X  X  X",\
																"X  X  X  XX  X  X  X",\
																"X  X  X  XX  X  X  X",\
																"X  X            X  X",\
																"X  X            X  X",\
																"X  X XXXXXXXXXX X  X",\
																"   X X        X X   ",\
																"   X X        X X   ",\
																"XXXXXX        XXXXXX",\
																"                    ",\
																"                    ",\
																"XXXXXXXXX  XXXXXXXXX"};
// Red_ bottom right
const char * RED_MAZE_BR[] = {	"X  XXX  X  X  XXX  X",\
																"X       X  X       X",\
																"X       X  X       X",\
																"X       X  X       X",\
																"X       X  X       X",\
																"XXXXXXXXX  XXXXXXXXX",\
																"     X        X     ",\
																"     X        X     ",\
																"XX   X        X   XX",\
																"     X        X     ",\
																"     X        X     ",\
																"XXXXXXXXX  XXXXXXXXX"};

// Orange  top
const char * ORANGE_MAZE_TOP[] = {		"XXXXXXX      XXXXXXX",\
																			"  X              X  ",\
																			"  X              X  ",\
																			"X X   XXXXXXXX   X X",\
																			"X X   XXXXXXXX   X X",\
																			"  X      XX      X  ",\
																			"  X      XX      X  ",\
																			"XXX X    XX    X XXX",\
																			"XXX X    XX    X XXX",\
																			"    X    XX    X    ",\
																			"    X XX XX XX X    ",\
																			"XXXXX XX XX XX XXXXX"};
// Organge middle
const char * ORANGE_MAZE_MIDDLE[] = {	"XXXXX XX XX XX XXXXX",\
																			"      XX    XX      ",\
																			"      XX    XX      ",\
																			"XX    XX    XX    XX",\
																			"XX    XX    XX    XX",\
																			"    XXXX    XXXX    ",\
																			"    X          X    ",\
																			"XXX X XXXXXXXX X XXX",\
																			"XXX X XX    XX X XXX",\
																			"  X X XX    XX X X  ",\
																			"  X X XX XX XX X X  ",\
																			"X X X XX XX XX X X X"};
// Orange bottom
const char * ORANGE_MAZE_BOTTOM[] = {	"X X X XX XX XX X X X",\
																			"  X X XX XX XX X X  ",\
																			"  X   XX XX XX   X  ",\
																			"  X   XX XX XX   X  ",\
																			"  XXXXXX XX XXXXXX  ",\
																			"         XX         ",\
																			"         XX         ",\
																			"  XXXX   XX   XXXX  ",\
																			"  X      XX      X  ",\
																			"  X      XX      X  ",\
																			"  X      XX      X  ",\
																			"XXXXXXXXXXXXXXXXXXXX"};
// orange upper left
const char * ORANGE_MAZE_UL[] = {	"XXXX  XXXXXXXX  XXXX",\
																	"      X      X      ",\
																	"      X      X      ",\
																	"XXXXXXX      XXXXXXX",\
																	"XXXXXXX      XXXXXXX",\
																	"                    ",\
																	"                    ",\
																	"X  XXXXXXXXXXXXXX  X",\
																	"X  XXXXXXXXXXXXXX  X",\
																	"   X            X   ",\
																	"   X            X   ",\
																	"XXXX  XXXXXXXX  XXXX"};

// orange bottom left
const char * ORANGE_MAZE_BL[] = {	"XXXX  XXXXXXXX  XXXX",\
																	"X       X           ",\
																	"X  XXXXXX           ",\
																	"X  XXXXXX    XXXXXXX",\
																	"   X         XXXXXXX",\
																	"   X         X      ",\
																	"XXXX         X      ",\
																	"XXXX         X  XXXX",\
																	"XXXX  XXXXXXXX  XXXX",\
																	"X     X   X     X   ",\
																	"X     X   X     X   ",\
																	"XXXX  XXXXXXXX  XXXX"};
// orange upper right
const char * ORANGE_MAZE_UR[] = {	"XXXXXXXXXXXXXXXXXXXX",\
																	"          X        X",\
																	"          XXXXXXX  X",\
																	"XXXXXXXX  XXXXXXX  X",\
																	"XXXXXXXX        X   ",\
																	"       X        X   ",\
																	"    XXXXXXX   XXXXXX",\
																	"X   XXXXXXX   XX   X",\
																	"X   XX   X    XX   X",\
																	"    XX   X    XX   X",\
																	"  X XX   X    XX X X",\
																	"X X XX X XX X XX X X"};
// orange bottom right
const char * ORANGE_MAZE_BR[] = {	"X X XX X XX X XX X X",\
																	"  X    X    X    X  ",\
																	"  X    X    X    X  ",\
																	"XXXXXXXX    XXXXXXXX",\
																	"XXXXXXXX    XXXXXXXX",\
																	"                    ",\
																	"                    ",\
																	"XXXXXXX      XXXXXXX",\
																	"XXXXXXX      XXXXXXX",\
																	"                    ",\
																	"                    ",\
																	"XXXXXXX      XXXXXXX"};

const char * BRIDGE[] = {	"X\\CCCCC/X",\
													"XXCCCCCXX",\
													" XCCCCCX ",\
													" XCCCCCX ",\
													" XCCCCCX ",\
													" XCCCCCX ",\
													" XCCCCCX ",\
													" XCCCCCX ",\
													"XXCCCCCXX",\
													"X/CCCCC\\X"};


// color matrix 0 = ignored, 1 = full color, 2 = foreground/background, 3 = walkway/background
const short BRIDGE_COLORPAIR_MATRIX[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X] = {	1,2,3,3,3,3,3,2,1,\
																																					1,1,3,3,3,3,3,1,1,\
																																					0,1,3,3,3,3,3,1,0,\
																																					0,1,3,3,3,3,3,1,0,\
																																					0,1,3,3,3,3,3,1,0,\
																																					0,1,3,3,3,3,3,1,0,\
																																					0,1,3,3,3,3,3,1,0,\
																																					0,1,3,3,3,3,3,1,0,\
																																					1,1,3,3,3,3,3,1,1,\
																																					1,2,3,3,3,3,3,2,1};

const char * KEY[] = {"ww--O"};

const short KEY_COLORPAIR_MATRIX[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X] = {	2,2,2,2,2,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0,\
																																				0,0,0,0,0,0,0,0,0};

const char * SWORD[] = {"<----"};

const short SWORD_COLORPAIR_MATRIX[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X] = {	2,2,2,2,2,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0};

const char * CHALICE[] = {	"X    X",
														"\\X__X/",
														"  ||  ",
														"/XXXX\\"};

const short CHALICE_COLORPAIR_MATRIX[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X] = {	1,0,0,0,0,1,0,0,0,\
																																						2,1,0,0,1,2,0,0,0,\
																																						0,0,2,2,0,0,0,0,0,\
																																						2,1,1,1,1,2,0,0,0,\
																																						0,0,0,0,0,0,0,0,0,\
																																						0,0,0,0,0,0,0,0,0,\
																																						0,0,0,0,0,0,0,0,0,\
																																						0,0,0,0,0,0,0,0,0,\
																																						0,0,0,0,0,0,0,0,0,\
																																						0,0,0,0,0,0,0,0,0};

const char * MAGNET[] =	{	" XXXX ",
													"XX  XX",
													"XX  XX",
													"XX  XX"};

const short MAGNET_COLORPAIR_MATRIX[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X] = {	0,1,1,1,1,0,0,0,0,\
																																					1,1,0,0,1,1,0,0,0,\
																																					1,1,0,0,1,1,0,0,0,\
																																					1,1,0,0,1,1,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0,\
																																					0,0,0,0,0,0,0,0,0};

enum GameState
{
	GS_PLAY,
};

struct Position
{
	short x;
	short y;
};

struct Size
{
	short width;
	short height;
};

struct Color
{
	short colorPair;
};

struct Screens
{
	Size ScreenSizeInChars;
	Size ScreenSizeInBlocks;
};

struct GameScreens
{
	GameScreens * ptr_up;
	GameScreens * ptr_down;
	GameScreens * ptr_left;
	GameScreens * ptr_right;
	short ScreenID;
	char * compressedContent;
	short content[CURRENT_SCREEN_HEIGHT][CURRENT_SCREEN_WIDTH];
	Screens ScreensSize;
	Color screenDefaultDrawingColorPair;
	Color screenDefaultBackgroundColorPair;
};

struct Player
{
	Position position;
	Size spriteSize;
	Color playerColorPair;
};

struct Items
{
	GameScreens * currentItemScreen;
	short colorMatrix[MAX_ITEM_SIZE_Y][MAX_ITEM_SIZE_X];
	Position position;
	Size spriteSize;
	Color xPartColorPair;
	Color singlePartColorPair;
	Color walkwayColorPair;
};

struct Wall
{
	char content;
	Position position;
	Size spriteSize;
	Color wallSpriteColorPair;
};

struct Game
{
	unsigned short gameType; // 1,2,3
	Size windowSize;
	GameState currentState;
	clock_t gameTimer;
};


#endif /* ANADVENTURE_H_ */


//    // Object #0E : State 03 : Graphic
//    7,
//    0x81,                  // X      X
//    0x81,                  // X      X
//    0xC3,                  // XX    XX
//    0xFF,                  //  XXXXXX
//    0x5A,                  //  XOXXOX
//    0x66,                  //   XXXX
//    0xC3,                  //
//    0x81,                  //
//    0x81,                  //
//    0x81                   //
//
//    0x80,                  // X      X
//    0x01,                  //       X
//    0x80,                  //  X
//    0x80,                  //   XXXX
//    0x5A,                  //  XOXXOX
//    0xFF,                  //  XXXXXX
//    0xC3,                  // XX    XX
//    0x81,                  // X      X
//    0x81,                  // X      X
//
// // FORMAT 7 x 11
//													 //     D
//    0D06,                  // ___DOD
//    0DFE,                  // ~~~DDDD
//    0D0E,                  //     DD
//    0D7F,                  //  DDDDD
//    0DC3,                  // DD   DD
//    0DC3,                  // DD   DD
//    0DFF,                  //  DDDDDD
//    0D08,                  //     DD
//    0D8F,                  // DD DD
//    0D3F,                  //  DDD
//
//													 //  \  D
//    0D06,                  //   \DOD
//    0DFE,                  // ~~ DDDD
//    0D0E,                  //  /  DD
//    0D7F,                  // /DDDDD
//    0DC3,                  // DDSSSDD
//    0DC3,                  // DDSSSDD
//    0DFF,                  //  DDDDDD
//    0D08,                  //     DD
//    0D8F,                  //  DDD
//    0D3F,                  //    DDDD
//
//													 //     ||
//    0D06,                  //     DOD
//    0DFE,                  //    DDD
//    0D0E,                  //    D
//    0D7F,                  // /DDDDD
//    0DC3,                  // DDSSSDD
//    0DC3,                  // DDSSSDD
//    0DFF,                  //  DDDDDD
//    0D08,                  //   DDD
//    0D8F,                  //  DD   D
//    0D3F,                  //   DDDD
//
//
//// Object #1 States 940FF (Graphic)
//static const byte objectGfxPort [] =
//{
//    // state 1
//    4,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 2
//    6,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 3
//    8,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 4
//    10,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 5
//    12,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 6
//    14,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    // state 7
//    16,
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA,                  // G G G G
//    0GFE,                  // GGGGGGG
//    0GAA                   // G G G G
