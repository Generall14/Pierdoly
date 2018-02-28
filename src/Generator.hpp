#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "Point.hpp"
#include "Equations.hpp"
#include "PointSet.hpp"

class Generator
{
public:
	Generator(Equations* equation, float x0, float y0);
	~Generator();
	
	PointSet generate(unsigned int repeates, unsigned int intToFLoat=100);
	
private:
	Equations* eq = nullptr;
	float _x0, _y0;
// 	Point first;
	
// 	void drawLine(PointSet *ps, Point start, Point line, unsigned int lines_resolution);
// 	void privateGenerate(PointSet *ps, unsigned int range, unsigned int repeates, unsigned int lines_resolution);
};

#endif
