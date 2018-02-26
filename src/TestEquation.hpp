#ifndef TESTEQUATION_HPP
#define TESTEQUATION_HPP

#include "Point.hpp"
#include "Equations.hpp"

class TestEquation : public Equations
{
public:
	TestEquation(float first=0.5);
	virtual Point step(Point &other);
	
private:
	unsigned int _first;
};

#endif
