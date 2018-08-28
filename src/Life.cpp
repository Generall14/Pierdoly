#include "Life.hpp"
#include <iostream>
#include <chrono>
#include <cstdlib>

Life::Life(unsigned int rows, unsigned int cols)
{
    buff[0].cols = cols;
    buff[0].rows = rows;
    buff[1].cols = cols;
    buff[1].rows = rows;

    buff[0].ptr = new char[(rows*cols)];
    buff[1].ptr = new char[(rows*cols)];
	
	int cnt;
	for(uint row=0;row<buff[0].rows;row++)
	{
		for(uint column=0;column<buff[0].cols;column++)
			buff[0].ptr[row*buff[0].cols+column]=rand()&0x01;
	}
}

Life::~Life()
{
    delete[] buff[1].ptr;
    delete[] buff[0].ptr;
}

void Life::sim(unsigned int steps)
{
//     std::cout << "Sim " << steps << " steps by " << _name << "..." << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();

    while(steps--)
    {
        for(uint row=0;row<buff[0].rows;row++)
        {
            for(uint column=0;column<buff[0].cols;column++)
                siml(buff[(_currentBuff+1)&0x01], buff[_currentBuff], column, row);
        }
        _currentBuff = (_currentBuff+1)&0x01;
    }

    auto t2 = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::milli> ms = t2 - t1;
//     std::cout << "...done in " << ms.count() << " ms" << std::endl;
}

const Life::dat* Life::get()
{
    return &buff[_currentBuff];
}
