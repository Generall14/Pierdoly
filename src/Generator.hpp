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
	
	PointSet generate(unsigned int range, unsigned int repeates);
	
private:
	Equations* eq = nullptr;
	Point first;
};

#endif
