#include <ncurses.h>

#include <iostream>

using namespace std;




int main()
{
	initscr();                 /* Start curses mode     */
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

    mvprintw(10,60,"     XX ");
    mvprintw(11,60,"    XXXX");
    mvprintw(12,60,"XXXX  XX");
    mvprintw(13,60,"XXXXXXX");
    mvprintw(14,60,"    XXX");
    mvprintw(15,60,"     X  ");
    mvprintw(16,60,"     X  ");
    mvprintw(17,60,"   XXXX ");
    mvprintw(18,60,"  XXXXXX");
    mvprintw(19,60," XXXXXXX");
    mvprintw(20,60,"XXX   XX");
    mvprintw(21,60,"XX    XX");
    mvprintw(22,60,"XX    XX");
    mvprintw(23,60,"XX   XXX");
    mvprintw(24,60,"XXXXXXXX");
    mvprintw(25,60,"  XXXX  ");
    mvprintw(26,60,"    X   ");
    mvprintw(27,60,"X   XXXX");
    mvprintw(28,60,"XXX    X");
    mvprintw(29,60,"  XXXXXX");

	mvprintw(31,60," X      ");
    mvprintw(32,60,"XXXXXXXX");
	mvprintw(33,60," X      ");

	mvprintw(35,60,"     XXX");
    mvprintw(36,60,"XXXXXX X");
	mvprintw(37,60,"X X  XXX");

	mvprintw(39,60,"######");
    mvprintw(40,60,"######");
	mvprintw(41,60,"######");




//
//    for (int i = 0; i < 20; i++) {
//		for (int j = 0; j < 8; j++) {
//			mvaddch(60+j,10+i,dragon[i][j]);
//		}
//    }




    refresh();                 /* Print it on to the real screen */
    getch();                   /* Wait for user input */
    endwin();                  /* End curses mode    */

    return 0;
}


// TODO (jens#1#09/11/21): ncurses in cpp
// TODO (jens#1#09/11/21): screen size on atari
// TODO (jens#1#09/11/21): setting terminal in cpp

