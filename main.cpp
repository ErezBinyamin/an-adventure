#include <ncurses.h>
#include <iostream>

#define LASTLINE (LINES - 1)
#define COLS_NET (COLS - 2)

using namespace std;

enum {
	DEFAULT_BACKGROUND = 1,
	BLACK_STUFF = 2,
	GREEN_DRAGON = 3
};

int oneNth (int divider, int length);
void fillWithChars(int NumberOfBricks, char brick);
void fillTowerTop(void);

int main()
{
	initscr();                 /* Start curses mode     */
	refresh();

	if (has_colors() == TRUE) {
		start_color();
		init_pair(DEFAULT_BACKGROUND, COLOR_YELLOW, COLOR_WHITE); // default background
		init_pair(BLACK_STUFF, COLOR_BLACK, COLOR_WHITE);
		init_pair(GREEN_DRAGON, COLOR_GREEN, COLOR_WHITE);


		wbkgd(stdscr,COLOR_PAIR(1));
		// touchwin(stdscr);
		refresh();
	}

	for (int i = 0; i < 32; i++) {
		addch(A_ALTCHARSET | ACS_BLOCK);
    }
    for (int i = 0; i < 32; i++) {
		addch(A_ALTCHARSET | ACS_BLOCK);
    }
    for (int i = 0; i < 32; i++) {
		addch(' ');
    }
    for (int i = 0; i < 32; i++) {
		addch(A_ALTCHARSET | ACS_BLOCK);
    }
    for (int i = 0; i < 32; i++) {
		addch(A_ALTCHARSET | ACS_BLOCK);
    }

	attrset(COLOR_PAIR(GREEN_DRAGON));
    mvprintw(10,60,"     ## ");
    mvprintw(11,60,"    ####");
    mvprintw(12,60,"####  ##");
    mvprintw(13,60,"#######");
    mvprintw(14,60,"    ###");
    mvprintw(15,60,"     #  ");
    mvprintw(16,60,"     #  ");
    mvprintw(17,60,"   #### ");
    mvprintw(18,60,"  ######");
    mvprintw(19,60," #######");
    mvprintw(20,60,"###   ##");
    mvprintw(21,60,"##    ##");
    mvprintw(22,60,"##    ##");
    mvprintw(23,60,"##   ###");
    mvprintw(24,60,"########");
    mvprintw(25,60,"  ####  ");
    mvprintw(26,60,"    #   ");
    mvprintw(27,60,"#   ####");
    mvprintw(28,60,"###    #");
    mvprintw(29,60,"  ######");
	attrset(COLOR_PAIR(DEFAULT_BACKGROUND));

	mvprintw(31,60," #      ");
    mvprintw(32,60,"########");
	mvprintw(33,60," #      ");

	attrset(COLOR_PAIR(BLACK_STUFF));
	mvprintw(35,60,"     ###");
    mvprintw(36,60,"###### #");
	mvprintw(37,60,"# #  ###");
	attrset(COLOR_PAIR(DEFAULT_BACKGROUND));


	mvprintw(39,60,"######");
    mvprintw(40,60,"######");
	mvprintw(41,60,"######");

    getch();                   /* Wait for user input */

	clear();
	mvprintw(0,0,"#####################################     ####     ####     ####                                ####     ####     ####     #####################################");
	printw("#                               #####     ####     ####     ####                                ####     ####     ####     #####                               #");
	printw("#                               #####     ####     ####     ####                                ####     ####     ####     #####                               #");
	printw("#                               ################################                                ################################                               #");
	printw("#                               ################################                                ################################                               #");
	printw("#                               ################################                                ################################                               #");
	printw("#                               ################################                                ################################                               #");
	printw("#                               ################################                                ################################                               #");
	printw("#                               ################################################################################################                               #");
	printw("#                               ################################################################################################                               #");
	printw("#                               ################################################################################################                               #");
	printw("#                               ################################################################################################                               #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        ###############################################################################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                        #######################                                ########################                                       #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("#                                                                                                                                                              #");
	printw("################################################################                                ################################################################");


	attrset(COLOR_PAIR(BLACK_STUFF));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
		mvaddch(20+i,76+j,'#');
		}
	}
	attrset(COLOR_PAIR(DEFAULT_BACKGROUND));

	getch();                   /* Wait for user input */

	clear();
	mvprintw(0,0,"######### # # # #         # # # ##########\n");
	printw("#         # # # #         # # # #        #\n");
	printw("#        ########        ########        #\n");
	printw("#        ########################        #\n");
	printw("#        ########################        #\n");
	printw("#          ####################          #\n");
	printw("#          ####################          #\n");
	printw("#          #######       ######          #\n");
	printw("#          #######       ######          #\n");
	printw("#                                        #\n");
	printw("#                                        #\n");
	printw("#################        #################\n");


	attrset(COLOR_PAIR(BLACK_STUFF));
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
		mvaddch(8+i,21+j,'#');
		}
	}
	attrset(COLOR_PAIR(DEFAULT_BACKGROUND));

	getch();                   /* Wait for user input */

	clear();
	move(0,0);
	for (int i = 0; i < COLS; i++) {
		printw("#");
	}
	// top line
	move(0,0);
	fillWithChars(oneNth(5,COLS),'#');
	fillTowerTop();
	fillWithChars(oneNth(5,COLS),' ');
	fillTowerTop();
	fillWithChars(oneNth(5,COLS),'#');

	// top of the towers
	for (int j = 0; j < oneNth(24,LINES); j++){
	move(1+j,oneNth(5,COLS));
	fillTowerTop();
	fillWithChars(oneNth(5,COLS),' ');
	fillTowerTop();
	}

	// castle upper part
	for (int j = 0; j < oneNth(12,LINES); j++){
	move(1 + oneNth(24,LINES) + j,oneNth(5,COLS));
	fillWithChars(oneNth(5,COLS),'#');
	fillWithChars(oneNth(5,COLS),'#');
	fillWithChars(oneNth(5,COLS),'#');
	}

	// castle lower part
	for (int j = 0; j < oneNth(6,LINES); j++){
	move(1 + oneNth(24,LINES) + oneNth(12,LINES) + j,oneNth(4,COLS));
	fillWithChars(oneNth(6,COLS),'#');
	fillWithChars(oneNth(6,COLS),'#');
	fillWithChars(oneNth(6,COLS),'#');
	}

	// castle entrance part
	for (int j = 0; j < oneNth(6,LINES); j++){
	move(1 + oneNth(24,LINES) + oneNth(12,LINES) + oneNth(6,LINES) + j,oneNth(4,COLS));
	fillWithChars(oneNth(6,COLS),'#');
	fillWithChars(oneNth(6,COLS),' ');
	fillWithChars(oneNth(6,COLS),'#');
	}

	// castle entrance door
		attrset(COLOR_PAIR(BLACK_STUFF));
	for (int j = 0; j < oneNth(6,LINES); j++){
	move(1 + oneNth(24,LINES) + oneNth(12,LINES) + oneNth(6,LINES) + j, 12 * oneNth(24,COLS));
	fillWithChars(oneNth(10,COLS),'#');
	}
	attrset(COLOR_PAIR(DEFAULT_BACKGROUND));

	for (int j = 0; j < LINES; j++) {
		move(j,0);
		printw("#");
		move (j, COLS - 1);
		printw("#");
	}


	// lowest line
	move (LASTLINE,1);
	fillWithChars(oneNth(5,COLS),'#');
	fillWithChars(oneNth(5,COLS),'#');
	fillWithChars(oneNth(5,COLS),' ');
	fillWithChars(oneNth(5,COLS),'#');
	fillWithChars(oneNth(5,COLS),'#');

    refresh();                 /* Print it on to the real screen */
    getch();                   /* Wait for user input */
    endwin();                  /* End curses mode    */

    return 0;
}


int oneNth (int divider, int length) {

	return (length / divider);
}

void fillWithChars(int NumberOfBricks, char brick) {

	for (int i = 0; i < NumberOfBricks; i++) {
		addch(brick);
	}
	return;
}

void fillTowerTop(void) {
	fillWithChars(oneNth(5,oneNth(7,COLS)),'#');
	fillWithChars(oneNth(5,oneNth(7,COLS)),' ');
	fillWithChars(oneNth(5,oneNth(7,COLS)),'#');
	fillWithChars(oneNth(5,oneNth(7,COLS)),' ');
	fillWithChars(oneNth(5,oneNth(7,COLS)),'#');
	fillWithChars(oneNth(5,oneNth(7,COLS)),' ');
	fillWithChars(oneNth(5,oneNth(7,COLS)),'#');
}

// TODO (jens#1#09/11/21): ncurses in cpp
// TODO (jens#1#09/11/21): screen size on atari
// TODO (jens#1#09/11/21): setting terminal in cpp

