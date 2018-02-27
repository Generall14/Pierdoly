#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "Point.hpp"
#include "Equations.hpp"
#include "PointSet.hpp"

class Generator
{
public:
	Generator(Equations* equation, Point firstStep);
	~Generator();
	
	PointSet generate(unsigned int range, unsigned int repeates, unsigned int lines_resolution=0);
	
private:
	Equations* eq = nullptr;
	Point first;
	
	void drawLine(PointSet *ps, Point start, Point line, unsigned int lines_resolution);
	void privateGenerate(PointSet *ps, unsigned int range, unsigned int repeates, unsigned int lines_resolution);
};

#endif
