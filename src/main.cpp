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
	Generator gen(Equations::Barnsley(), 0, 0); // x, y
	PointSet psg = gen.generate(10000000, 180); // powtorzenia, rozdzielczość na jednostke
	
	psg.about();
	
	psg.multiply(100000.0);psg.sqrt();psg.sqrt();
// 	psg.multiply(1000.0);psg.sqrt();
// 	psg.logarithm();
	
	
// 	psg.toBitmap("test.bmp", r, r, r);
// 	psg.toBitmap("test.bmp", [=](char a)->char{return 0xFF-a;});
	psg.toBitmap("test.bmp");
// 	psg.toBitmapc("test.bmp");
	
	return 0;
}
