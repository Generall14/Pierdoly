#ifndef EQUATIONS_HPP
#define EQUATIONS_HPP

#include <vector>

/**
 * @class Equations
 * Klasa reprezentuje zbiór równań tworzących dla IFS. Udostępnia metodę calcNextPoint która na podstawie posiadanych równań oblicza kolejny punkt. Obiekty 
 * tej klasy mogą być tworzone tylko przez przeznaczone do tego statyczne metody (uzupełniają one przy okazji prywatne dane specyfikujące dany zestaw równań).
 */
class Equations
{
public:
	void calcNextPoint(float &x, float &y);
	
	static Equations* Barnsley();
	
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
