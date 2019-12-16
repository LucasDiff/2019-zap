#include <time.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _POSIX_C_SOURCE 200201L

#define EMPTY  	  ' '
#define RAIN      'F'
#define WALL      '#'
#define PLAYER    'O'
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
struct player {
	char shape; 
	int HP;
	int speed;
};
struct rain {
	char shape;
	int damage;
	int x,y;
};
int is_move_okay(int y, int x);
void draw_map(const int COLS, const int LINES);
int main(void)
{

	int ch;
	int x,y;

	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);	
	clear();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
	draw_map(10,10);
	mvprintw(18,42, "Move - WASD or arrows. Quit - Q");
	y = 28;
	x = 30;

	struct rain weak;
	weak.shape  = 'f';
	weak.damage = 0;
	weak.y      = 2;
	weak.x      = 21 + rand() % 18;

	struct rain super;
	super.shape  = 'O';
	super.damage = 0;
	super.y      = 2;
	super.x      = 21 + rand() % 18;

	struct rain strong;
	strong.shape  = 'F';
	strong.damage = 0;
	strong.y      = 2;
	strong.x      = 21 + rand() % 18;

	struct rain heal;
	heal.shape = 'H';
	heal.y = 2;
	heal.damage = 0;
	heal.x = 21 + rand() % 18;

	int hp = 100;
	int a = 35;
	int c = 0;
	int f = 0;
	mvprintw(4,24,"TOP SCORES");
	mvprintw(6,23,"_TREXXX_ : 65");
	mvprintw(7,23,"ez_win   : 49");
	mvprintw(8,23,"yourmama : 38");
	mvprintw(9,23,"Michael  : 32");
	mvprintw(10,23,"David    : 28");
	int k = 0;
	int j = 0;
	do {
		switch (ch) {
			case KEY_LEFT:
			case 'a':
			case 'A':
				if ((x > 0) && is_move_okay(y, x - 1)) {
					mvaddch(y, x, EMPTY);
					x = x - 1;
					delay(0);
				}
				break;	
			case KEY_RIGHT:
			case 'd':
			case 'D':
				if ((x < COLS - 1) && is_move_okay(y, x + 1)) {
					mvaddch(y, x, EMPTY);
					x = x + 1;
					delay(0);
				}

		}
		if (hp < 31){
			attron(COLOR_PAIR(1));
			mvaddch(y, x, PLAYER);
			attroff(COLOR_PAIR(1));
		}
		if (hp < 61 && hp >= 31){
			attron(COLOR_PAIR(2));
			mvaddch(y, x, PLAYER);
			attroff(COLOR_PAIR(2));
		}
		if (hp < 101 && hp >= 61){
			attron(COLOR_PAIR(3));
			mvaddch(y, x, PLAYER);
			attroff(COLOR_PAIR(3));
		}
		if ( hp >= 101 && hp < 160){
			attron(COLOR_PAIR(5));	
			mvaddch(y, x, PLAYER);
			attroff(COLOR_PAIR(5));
		}
		if ( hp >= 160){
			attron(COLOR_PAIR(4));	
			mvaddch(y, x, PLAYER);
			attroff(COLOR_PAIR(4));
		}
		a++;
		move(y, x);
		if (f >= 5 * 28 - 11){
			mvprintw(a, strong.x, "F");
			strong.damage = 30;
			mvprintw(19,2,"F = -30 hp");
		}
		if (f >= 10 * 28 - 11){
			mvprintw(a, super.x, "O");
			super.damage = 40;
			f++;
			mvprintw(20,2,"O = -40 hp");
		}
		if(f >= 20 * 28) {
			mvprintw(a, heal.x,"H");
			heal.damage = -30;
			mvprintw(21,2,"H = +30 hp");
		}
		if (f <= 10000000){
			mvprintw(a, weak.x, "f");
			weak.damage = 20;
			mvprintw(18,2,"f = -20 hp");
		}
		f++;
		if (a == 28 && weak.x == x){
			hp -= weak.damage;
			k++;
		}
		if (a == 28 && super.x == x &&f >= 10 * 28 - 11 ){
			hp -= super.damage;
			k++;
		}
		if (a == 28 && strong.x == x &&f >= 5 * 28 - 11 ){
			hp -= strong.damage;
			k++;
		}
		if (a == 28 && heal.x == x && f >= 20 * 28 ){
			hp = hp + (-1) * heal.damage;
		}
		mvprintw(20, 42,"You got hit : %d",k-j);
		delay(75000-(f * 20));
		if (a >= 15){
			mvprintw(a-1, strong.x, " ");
			mvprintw(a-1, weak.x, " ");
			mvprintw(a-1, super.x, " ");
			mvprintw(a-1, heal.x, " ");
		}
		if (c < 10){
			attron(COLOR_PAIR(8));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(8));
		}
		if (c >= 10 && c < 20){
			attron(COLOR_PAIR(5));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(5));
		}
		if (c >= 20 && c < 40){
			attron(COLOR_PAIR(4));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(4));
		}
		if (c >= 40 && c < 80){
			attron(COLOR_PAIR(2));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(2));
		}
		if (c >= 80 && c < 120){
			attron(COLOR_PAIR(6));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(6));
		}
		if (c >= 120){
			attron(COLOR_PAIR(1));	
			mvprintw(21, 42,"Your score is : %d",c);
			attroff(COLOR_PAIR(1));
		}
		mvprintw(19, 42, "Your hp : %d  ",hp);
		if (a > 27){
			c++;
			mvprintw(a, strong.x, " ");
			mvprintw(a, weak.x, " ");
			mvprintw(a, super.x, " ");
			mvprintw(a, heal.x, " ");
			a = 15;
			strong.x = 21 + rand() % 18;
			weak.x = 21 + rand() % 18;
			super.x = 21 + rand() % 18;
			heal.x = 21 + rand() % 18;
			if (weak.x == strong.x){
				weak.x += 1;
			}
		}
		if ( hp <= 0){
			for ( int r = 15; r < 29; r++){
				mvhline(r, 39, WALL, 1);
			}	       
			mvprintw(18,2,"          ");
			mvprintw(19,2,"          ");
			mvprintw(20,2,"          ");
			mvprintw(21,2,"          ");
			mvprintw(1,0,"                                                               ");
			if (c <= 28){
				mvprintw(4, 41,"YOU LOST!");
				mvprintw(5, 41,"Your score is : %d",c-1);
				mvprintw(2, 30,"PRESS Q TO QUIT!");
				mvprintw(17, 40,"                                   ");
				mvprintw(18, 40,"                                   ");
				mvprintw(19, 40,"                                   ");
				mvprintw(20, 40,"                                   ");
				mvprintw(21, 40,"                                              ");
			}
			if (c > 28){
				mvprintw(4, 41,"YOU WON!");
				mvprintw(5, 41,"Your score is : %d",c-1);
				mvprintw(2, 30,"PRESS Q TO QUIT!");
				mvprintw(17, 40,"                                              ");
				mvprintw(18, 40,"                                              ");
				mvprintw(19, 40,"                                              ");
				mvprintw(20, 40,"                                              ");
				mvprintw(21, 40,"                                              ");
			}
			if (c > 29 && c <= 33){
				mvprintw(10,23,"YOU      : %d",c-1);
			}
			if (c > 33 && c <= 39 ){
				mvprintw(6,23,"_TREXXX_ : 65");
				mvprintw(7,23,"ez_win   : 49");
				mvprintw(8,23,"yourmama : 38");
				mvprintw(9,23,"You      : %d",c-1);
				mvprintw(10,23,"Michael  : 32");
			}
			if (c > 39 && c <= 50 ){
				mvprintw(6,23,"_TREXXX_ : 65");
				mvprintw(7,23,"ez_win   : 49");
				mvprintw(8,23,"YOU      : %d",c-1);
				mvprintw(9,23,"yourmama : 38");
				mvprintw(10,23,"Michael  : 32");
			}
			if (c > 50 && c <= 66 ){
				mvprintw(6,23,"_TREXXX_ : 65");
				mvprintw(7,23,"YOU      : %d",c-1);
				mvprintw(8,23,"ez_win   : 49");
				mvprintw(9,23,"yourmama : 38");
				mvprintw(10,23,"Michael  : 32");
			}
			if (c > 66){
				mvprintw(6,23,"YOU      : %d",c-1);
				mvprintw(7,23,"_TREXXX_ : 65");
				mvprintw(8,23,"ez_win   : 49");
				mvprintw(9,23,"yourmama : 38");
				mvprintw(10,23,"Michael  : 32");
			}
			ch = getch();
			if (ch == 'q' || ch == 'Q'){
				endwin();
				exit(0);
			}
			a = 0;
		}
		refresh();
		ch = getch();

	}
	while ((ch != 'q') && (ch != 'Q'));

	endwin();

	exit(0);
}

int is_move_okay(int y, int x)
{
	int testch;

	testch = mvinch(y, x);
	return ((testch == EMPTY) || (testch == EMPTY));
}

void draw_map(const int COLS, const int LINES)
{
	mvhline(14, 20, WALL, 20);
	mvhline(29, 20, WALL, 20);
	for ( int d = 15; d < 29; d++){
		mvhline(d, 20, WALL, 1);
	}	       
	for ( int d = 15; d < 29; d++){
		mvhline(d, 39, WALL, 1);
	}	       

}
