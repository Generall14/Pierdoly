#include "Generator.hpp"
#include <iostream>
#include <chrono>

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
	auto t1 = std::chrono::high_resolution_clock::now();
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
