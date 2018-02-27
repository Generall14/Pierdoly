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
	x = other.XPos()*1;
	if((rand()%1000)<_first)
		y = other.YPos()*0.5;
	else 
		y = other.YPos()*-0.5;
	
// 	if((rand()%1000)<_first)
// 		x = other.XPos()*1;
// 	else 
// 		x = other.XPos()*-1;
	if(y==0)
		x=0;
	return Point(x, y);
}
