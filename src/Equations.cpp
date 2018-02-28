#include "Equations.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Equations::Equations(std::string name):
	_name(name)
{
	srand (time(NULL));
}

Equations::Equations(const Equations &other)
{
	this->_name = other._name;
	this->eqs = other.eqs;
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi Paproć Barnsley'a.
 */
Equations* Equations::Barnsley()
{
	Equations* eq = new Equations("Barnsley");;
	eq->eqs.push_back(Equation{0.85, 0.04, 0.0, -0.04, 0.85, 1.6, 850});
	eq->eqs.push_back(Equation{0.2, -0.26, 0.0, 0.23, 0.22, 1.6, 70});
	eq->eqs.push_back(Equation{-0.15, 0.28, 0.0, 0.26, 0.24, 0.44, 70});
	eq->eqs.push_back(Equation{0.0, 0.0, 0.0, 0.0, 0.16, 0.0, 10});
	return eq;
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi trójkąt Sierpińskiego.
 */
Equations* Equations::Sierpinski()
{
	Equations* eq = new Equations("SierpinskiTriangle");;
	eq->eqs.push_back(Equation{0.5, 0.0, -0.5, 0.0, 0.5, 0.5, 333});
	eq->eqs.push_back(Equation{0.5, 0.0, -0.5, 0.0, 0.5, -0.5, 333});
	eq->eqs.push_back(Equation{0.5, 0.0, 0.5, 0.0, 0.5, -0.5, 334});
	return eq;
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi spirale.
 */
Equations* Equations::Spiral()
{
	Equations* eq = new Equations("Spiral");;
	eq->eqs.push_back(Equation{0.7878, -0.4242, 1.7586, 0.2424, 0.5998, 1.4081, 896});
	eq->eqs.push_back(Equation{-0.1212, 0.2576, -6.7216, 0.1515, 0.05303, 1.3772, 52});
	eq->eqs.push_back(Equation{0.1818, -0.1363, 6.0861, 0.09090, 0.1818, 1.5680, 52});
	return eq;
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi liść klonu.
 */
Equations* Equations::Maple()
{
	Equations* eq = new Equations("Maple");;
	eq->eqs.push_back(Equation{0.14, 0.01, -1.31, 0.0, 0.51, 0.1, 100});
	eq->eqs.push_back(Equation{0.43, 0.52, 1.49, -0.45, 0.5, -0.75, 350});
	eq->eqs.push_back(Equation{0.45, -0.49, -1.62, 0.47, 0.47, -0.74, 350});
	eq->eqs.push_back(Equation{0.49, 0.0, 0.02, 0.0, 0.51, 1.62, 200});
	return eq;
}

/**
 * Tworzy obiekt z danymi odpowiadającymi równaniom generującymi drzewo.
 */
Equations* Equations::Tree()
{
	Equations* eq = new Equations("Tree");;
	eq->eqs.push_back(Equation{0.05, 0.0, -0.06, 0.0, 0.4, -0.47, 142});
	eq->eqs.push_back(Equation{-0.05, 0.0, -0.06, 0.0, -0.4, -0.47, 143});
	eq->eqs.push_back(Equation{0.03, -0.14, -0.16, 0.0, 0.26, -0.01, 143});
	eq->eqs.push_back(Equation{-0.03, 0.14, -0.16, 0.0, -0.26, -0.01, 143});
	eq->eqs.push_back(Equation{0.56, 0.44, 0.3, -0.37, 0.51, 0.15, 143});
	eq->eqs.push_back(Equation{0.19, 0.07, -0.2, -0.1, 0.15, 0.28, 143});
	eq->eqs.push_back(Equation{-0.33, -0.34, -0.54, -0.33, 0.34, 0.39, 143});
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

std::string Equations::name() const
{
	return _name;
}
