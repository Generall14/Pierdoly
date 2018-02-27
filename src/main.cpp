#include <iostream>
#include <set>
#include "Point.hpp"
#include "PointSet.hpp"
#include "TestEquation.hpp"
#include "Equations.hpp"
#include "Generator.hpp"
#include <chrono>

int main()
{
	Generator gen(new TestEquation(0.5), Point(10, 128)); // x, y
	PointSet psg = gen.generate(20, 1000); // zasieg, powtorzenia
	
	
	psg.about();
	
	
// 	psg.multiply(10.0);
	psg.logarithm();
// 	psg.sqrt();
	
	
	psg.toBitmap("test.bmp");
	
	return 0;
}
