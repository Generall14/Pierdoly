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
	
	
	std::cout << "result size: " << psg.size() << std::endl;
	unsigned int v_min, v_max;
	int x_min, x_max, y_min, y_max;
	psg.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	std::cout << x_min << " " << x_max << " " << y_min << " " << y_max << " " << v_min << " " << v_max << std::endl;
	
	
// 	psg.multiply(10.0);
	psg.logarithm();
// 	psg.sqrt();
	
	
	psg.toBitmap("test.bmp");
	
	return 0;
}
