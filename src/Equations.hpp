#ifndef EQUATIONS_HPP
#define EQUATIONS_HPP

#include "Point.hpp"

class Equations
{
public:
	Equations();
	
	virtual Point step(Point &other) = 0;
	
private:
};

#endif
