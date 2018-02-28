#include <iostream>
#include <set>
#include "Point.hpp"
#include "PointSet.hpp"
#include "Equations.hpp"
#include "Generator.hpp"
#include <chrono>
#include <thread>
#include <map>

char r(char a)
{
	return 0xFF-a;
}

int main()
{
	float x0=1.0, y0=1.0;
	unsigned int res = 80;
	unsigned int steps = 20000000;
	std::multimap<float, Generator> gens;
	
	gens.insert(std::pair<float, Generator>(1.0, Generator(Equations::Barnsley(), x0, y0)));
	gens.insert(std::pair<float, Generator>(3.0, Generator(Equations::Sierpinski(), x0, y0)));
	gens.insert(std::pair<float, Generator>(0.5, Generator(Equations::Spiral(), x0, y0)));
	gens.insert(std::pair<float, Generator>(1.5, Generator(Equations::Maple(), x0, y0)));
	gens.insert(std::pair<float, Generator>(5.0, Generator(Equations::Tree(), x0, y0)));
	gens.insert(std::pair<float, Generator>(10.0, Generator(Equations::Tree2(), x0, y0)));
	gens.insert(std::pair<float, Generator>(10.0, Generator(Equations::Ice(), x0, y0)));
	gens.insert(std::pair<float, Generator>(10.0, Generator(Equations::Feather(), x0, y0)));
	gens.insert(std::pair<float, Generator>(10.0, Generator(Equations::Koch(), x0, y0)));
	
	for(auto g: gens)
	{
		PointSet psg = g.second.generate(steps, res*g.first);
		
		psg.about();
		
		psg.multiply(100000.0);psg.sqrt();psg.sqrt();
// 		psg.multiply(1000.0);psg.sqrt();
// 		psg.logarithm();
		
// 		psg.toBitmap("fr_"+psg.name()+".bmp", r, r, r);
// 		psg.toBitmap("fr_"+psg.name()+".bmp", [=](char a)->char{return 0xFF-a;});
		psg.toBitmap("fr_"+psg.name()+".bmp");
// 		psg.toBitmapc("fr_"+psg.name()+".bmp");
	}
	
	return 0;
}
