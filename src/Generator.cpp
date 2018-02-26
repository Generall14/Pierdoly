#include "Generator.hpp"
#include <iostream>

Generator::Generator(Equations* equation, Point firstStep):
	eq(equation),
	first(firstStep)
{
}

Generator::~Generator()
{
	delete eq;
}
	
PointSet Generator::generate(unsigned int range, unsigned int repeates)
{
	PointSet ps;
	
	for(int i=0;i<repeates;i++)
	{
		Point stand(0, 0);
		Point jump(first.XPos(), first.YPos());
		for(int j=0;j<range;j++)
		{
			Point temp = eq->step(jump);
			stand = Point(stand.XPos()+jump.XPos(), stand.YPos()+jump.YPos());
			ps.addPoint(stand);
			if(temp.isNullPos())
			{
				std::cout << "NULL POSS" << std::endl;
				break;
			}
			else
				jump = Point(temp.XPos(), temp.YPos());
		}
	}
	
	return ps;
}
