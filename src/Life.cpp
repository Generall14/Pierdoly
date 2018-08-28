#include "Life.hpp"
#include <iostream>
#include <chrono>

Life::Life(unsigned int rows, unsigned int cols)
{
    buff[0].cols = cols;
    buff[0].rows = rows;
    buff[1].cols = cols;
    buff[1].rows = rows;

    buff[0].ptr = new char[(rows+cols)/8+1];
    buff[1].ptr = new char[(rows+cols)/8+1];
}

Life::~Life()
{
    delete[] buff[1].ptr;
    delete[] buff[0].ptr;
}

void Life::sim(unsigned int steps)
{
    std::cout << "Sim " << steps << " steps by " << _name << "..." << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << "Generated in " << ms.count() << " ms" << std::endl;
    std::cout << "...done in " << ms.count() << " ms" << std::endl;
}

const Life::dat* Life::get()
{
    return &buff[_currentBuff];
}
