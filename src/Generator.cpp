#include "Generator.hpp"
#include <iostream>
#include <chrono>
#include <cmath>

Generator::Generator(Equations* equation, Point firstStep):
	eq(equation),
	first(firstStep)
{
}

Generator::~Generator()
{
	delete eq;
}
	
PointSet Generator::generate(unsigned int range, unsigned int repeates, unsigned int lines_resolution)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	PointSet ps;
	
	for(int i=0;i<repeates;i++)
	{
		Point stand(0, 0);
		Point jump(first.XPos(), first.YPos());
		for(int j=0;j<range;j++)
		{
			if(lines_resolution&&j)
				drawLine(ps, stand, jump, lines_resolution);
			Point temp = eq->step(jump);
			stand = Point(stand.XPos()+jump.XPos(), stand.YPos()+jump.YPos());
			ps.addPoint(stand);
			if(temp.isNullPos())
				break;
			else
				jump = Point(temp.XPos(), temp.YPos());
		}
	}
	
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Generated in " << ms.count() << " ms" << std::endl;
	return ps;
}

void Generator::drawLine(PointSet &ps, Point start, Point line, unsigned int lines_resolution)
{
	int x = line.XPos(), y = line.YPos();
	int xs = start.XPos(), ys = start.YPos();
	int length = sqrt(pow(x, 2)+pow(y, 2)), tlength=length;
	if(length<=1)
		return;
	
	float k;
	int wx, wy;
	int xlast = xs+x, ylast = ys+y;
	
	while(tlength>0)
	{
		k=(float)tlength/(float)length;
		wx = xs+x*k;
		wy = ys+y*k;
		if((wx==xs)&&(wy==ys))
			return;
		if((wx!=xlast)||(wy!=ylast))
		{
			xlast = wx;
			ylast = wy;
			ps.addPoint(Point(wx, wy));
		}
		tlength -= lines_resolution;
	}
}
