#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include "Point.hpp"
#include "Equations.hpp"
#include "PointSet.hpp"

/**
 * @class Generator
 * Klasa odpowiada za generowanie zbioru PointSet na podstawie równań dostarczonych w obiekcie Equations. 
 * 
 * W konstruktorze należy podań wskaźnik na obiekt Equations który ma posłużyć do wygenerowania zbioru punktów, dodatkowo należy podać współrzędne początkowe.
 * 
 * Zbiór punktów generowany jest przez metodę generate(...), jako argunenty należy podać ilość kroków i mnożnik jaki ma być zastosowany do przekształcenia
 * ze współrzędnych bazowych do współrzędnych w PointSet. Jeżeli jest taka możliwość, obliczenia zostaną wykonane wielowątkowo.
 */
class Generator
{
public:
	Generator(Equations* equation, float x0 = 1.0, float y0 = 1.0);
	Generator(const Generator &other);
	~Generator();
	
	PointSet generate(unsigned int repeates, unsigned int intToFLoat=100);
	
private:
	
	Equations* eq = nullptr;
	float _x0, _y0;
	
	void privateGenerate(PointSet *ps, unsigned int repeates, unsigned int intToFLoat);
};

#endif
