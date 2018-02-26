#include "TestEquation.hpp"

#include <ctime>
#include <cstdlib>

TestEquation::TestEquation(float first)
{
	if((first<0)||(first>1))
		first = 0.5;
	_first = 1000*first;
	srand (time(NULL));
}

Point TestEquation::step(Point &other)
{
	int x, y;
	x = other.XPos()*0.75;
	if((rand()%1000)<_first)
		y = other.YPos()*0.75;
	else 
		y = other.YPos()*-0.75;
	return Point(x, y);
}
