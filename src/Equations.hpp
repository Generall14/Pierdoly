#ifndef EQUATIONS_HPP
#define EQUATIONS_HPP

#include <vector>
#include <string>

/**
 * @class Equations
 * Klasa reprezentuje zbiór równań tworzących dla IFS. Udostępnia metodę calcNextPoint która na podstawie posiadanych równań oblicza kolejny punkt. Obiekty 
 * tej klasy mogą być tworzone tylko przez przeznaczone do tego statyczne metody (uzupełniają one przy okazji prywatne dane specyfikujące dany zestaw równań).
 */
class Equations
{
public:
	Equations(const Equations &other);
	void calcNextPoint(float &x, float &y);
	std::string name() const;
	
	static Equations* Barnsley();
	static Equations* Sierpinski();
	static Equations* Spiral();
	static Equations* Maple();
	static Equations* Tree();
	static Equations* Tree2();
	static Equations* Ice();
	static Equations* Feather();
	static Equations* Koch();
	
private:
	struct Equation
	{
		float xa, xb, xc, ya, yb, yc;
		unsigned int chance; // prawdopodobieństwo wylosowania funkcji (w promilach, suma we wszystkich równaniach powinna się sumować do 1000)
	};
	
	Equations(std::string name);
	
	std::vector<Equation> eqs;
	std::string _name;
	Equation choseEquation();
};

#endif
