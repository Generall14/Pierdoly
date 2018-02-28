// #include "BarnslayEquations.hpp"
// 
// #include <ctime>
// #include <cstdlib>
// #include <cmath>
// #include <iostream>
// 
// BarnsleyEquations::BarnsleyEquations(float first, float seconds, float third)
// {
// 	if((first<0)||(first>1))
// 		first = 0.25;
// 	_first = 1000*first;
// 	
// 	if((seconds<0)||(seconds>1))
// 		seconds = 0.25;
// 	_second = 1000*seconds;
// 	
// 	if((third<0)||(third>1))
// 		third = 0.25;
// 	_third = 1000*third;
// 	srand (time(NULL));
// }
// 
// Point BarnsleyEquations::step(Point &other)
// {
// 	int x, y;
// 	int lx = other.XPos();
// 	int ly = other.YPos();
// 	
// 	float length = sqrt(pow((float)lx, 2)+pow((float)ly, 2))*0;
// 	
// 	unsigned int v = (rand()%1000);
// 	
// 	if(v<_first)
// 	{
// 		x = lx*0.85 + ly*0.04;
// 		y = lx*-0.04 + ly*0.85 + length*0.08;
// 	}
// 	else if(v<_first+_second)
// 	{
// 		y = lx*-0.15 + ly*0.28;
// 		x = lx*0.26 + ly*0.24 + length*0.044;
// 	}
// 	else if(v<_first+_second+_third)
// 	{
// 		x = lx*0.2 + ly*-0.26;
// 		y = lx*0.23 + ly*0.22 + length*0.08;
// 	}
// 	else
// 	{
// 		x = 0;
// 		y = ly*0.16;
// 	}
// 	
// 	
// 	
// // 	if(v<_first)
// // 	{
// // 		x = lx*0.85 + ly*0.04;
// // 		y = lx*-0.04 + ly*0.85;
// // 	}
// // 	else if(v<_first+_second)
// // 	{
// // 		x = lx*-0.15 + ly*0.28;
// // 		y = lx*0.26 + ly*0.24;
// // 	}
// // 	else if(v<_first+_second+_third)
// // 	{
// // 		x = lx*0.2 + ly*-0.26;
// // 		y = lx*0.23 + ly*0.22;
// // 	}
// // 	else
// // 	{
// // 		x = 0;
// // 		y = ly*0.16;
// // 	}
// 	return Point(x, y);
// }
