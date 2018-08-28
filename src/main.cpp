#include <iostream>
#include "SimpleLife.hpp"
#include "Life.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

	int row, col;
	initscr();
	getmaxyx(stdscr,row, col);
    SimpleLife life(row, col);
    

	while(1)
	{
		wclear(stdscr);
// 		refresh();
		
		const Life::dat* d = life.get();
		for(uint rowm=0;rowm<d->rows;rowm++)
        {
            for(uint column=0;column<d->cols;column++)
			{
				if((d->ptr[rowm*d->cols+column])&0x01)
					mvprintw(rowm, column, "*");
			}
        }
		
		curs_set(0);
		refresh();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
// 		getchar();
		
		life.sim(1);
	}
    endwin();

    return 0;
}
