#include <iostream>
#include <set>
#include "Point.hpp"
#include "PointSet.hpp"
#include "Equations.hpp"
#include "Generator.hpp"
#include <chrono>
#include <thread>

char r(char a)
{
	return 0xFF-a;
}

int main()
{
	float x0=1.0, y0=1.0;
	unsigned int res = 180;
	unsigned int steps = 1000000;
	std::vector<Generator> gens;
	
	gens.push_back( Generator(Equations::Barnsley(), x0, y0) );
	
	for(auto g: gens)
	{
		PointSet psg = g.generate(steps, res);
		
		psg.about();
		
		psg.multiply(100000.0);psg.sqrt();psg.sqrt();
// 		psg.multiply(1000.0);psg.sqrt();
// 		psg.logarithm();
		
// 		psg.toBitmap("test.bmp", r, r, r);
// 		psg.toBitmap("test.bmp", [=](char a)->char{return 0xFF-a;});
		psg.toBitmap("fr_"+psg.name()+".bmp");
// 		psg.toBitmapc("test.bmp");
	}
	
	return 0;
}
