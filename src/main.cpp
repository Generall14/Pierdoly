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
	Generator gen(new TestEquation(0.5), Point(1, 1));
	auto t1 = std::chrono::high_resolution_clock::now();
	PointSet psg = gen.generate(1000, 2000);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Wygenerowano PointSet w " << ms.count() << " ms" << std::endl;
	
	
	std::cout << "result size: " << psg.size() << std::endl;
	unsigned int v_min, v_max;
	int x_min, x_max, y_min, y_max;
	psg.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	std::cout << x_min << " " << x_max << " " << y_min << " " << y_max << " " << v_min << " " << v_max << std::endl;
	
	
	t1 = std::chrono::high_resolution_clock::now();
	psg.toBitmap("test.bmp");
	t2 = std::chrono::high_resolution_clock::now();
	ms = t2 - t1;
	std::cout << "Zapisano do bitmapy w " << ms.count() << " ms" << std::endl;
	return 0;
}
