#include "Equations.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Equations::Equations()
{
	srand (time(NULL));
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi Paproć Barnsley'a.
 */
Equations* Equations::Barnsley()
{
	Equations* eq = new Equations();;
	eq->eqs.push_back(Equation{0.85, 0.04, 0.0, -0.04, 0.85, 1.6, 850});
	eq->eqs.push_back(Equation{0.2, -0.26, 0.0, 0.23, 0.22, 1.6, 70});
	eq->eqs.push_back(Equation{-0.15, 0.28, 0.0, 0.26, 0.24, 0.44, 70});
	eq->eqs.push_back(Equation{0.0, 0.0, 0.0, 0.0, 0.16, 0.0, 10});
	return eq;
}

Equations::Equation Equations::choseEquation()
{
	if(eqs.empty())
		return Equation{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0};
	unsigned int randomNumber = rand()%1001, cumulatedChances = 0;
	
	for(int i=0;i<eqs.size();++i)
	{
		cumulatedChances += eqs[i].chance;
		if(cumulatedChances>=randomNumber)
			return eqs[i];
	}
	throw "asdf";
	return eqs[eqs.size()-1];
}

/**
 * Oblicza kolejne punkty x i y na podstawie posiadanych równań.
 */
void Equations::calcNextPoint(float &x, float &y)
{
	Equation eq = choseEquation();
	float newX, newY;
	newX = x*eq.xa + y*eq.xb + eq.xc;
	newY = x*eq.ya + y*eq.yb + eq.yc;
	x = newX;
	y = newY;
}
