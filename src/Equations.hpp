#ifndef EQUATIONS_HPP
#define EQUATIONS_HPP

#include <vector>

class Equations
{
public:
	void calcNextPoint(float &x, float &y);
	
	static Equations Barnsley();
	
private:
	struct Equation
	{
		float xa, xb, xc, ya, yb, yc;
		unsigned int chance; // prawdopodobieństwo wylosowania funkcji (w promilach, suma we wszystkich równaniach powinna się sumować do 1000)
	};
	
	Equations();
	
	std::vector<Equation> eqs;
	Equation choseEquation();
};

#endif
