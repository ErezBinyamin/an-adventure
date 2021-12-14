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

const char * PLAYER_SPRITE[] = {"###", "###"};

const char * EMPTY_SPACE_COMPRESSED[] = {	"                    ",\
																					"                    ",\
																					"     EMPTYNESS      ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",\
																					"                    ",};

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
//

const char * BRIDGE[] = {	"BBBB     BBBB",\
													"BBBB     BBBB",\
													"   B     B   ",\
													"   B     B   ",\
													"   B     B   ",\
													"   B     B   ",\
													"   B     B   ",\
													"   B     B   ",\
													"BBBB     BBBB",\
													"BBBB     BBBB",\
												};

const char * KEY[] = {"nn---O"};

const char * SWORD[] = {"<-----"};

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
};

enum GameState
{
	GS_PLAY,
};

struct Position
{
	int x;
	int y;
};

struct Size
{
	int width;
	int height;
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
	short ScreenID;
	char * compressedContent;
	int content[CURRENT_SCREEN_HEIGHT][CURRENT_SCREEN_WIDTH];
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

struct Game
{
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
//static const byte objectGfxChallise [] =
//{
//    9,
//    0x81,                  // K    K
//    0x7E,                  // KKKKKK
//    0x18,                  //   KK
//    0x7E                   // KKKKKK
//};
//
//// Object #11 : State FF : Graphic
//static const byte objectGfxMagnet [] =
//{
//    8,
//    0x7E,                  //  MMMM
//		0xC3,                  // MM  MM
//		0xC3,                  // MM  MM
//		0xC3,                  // MM  MM
//};
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
