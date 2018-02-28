#include "Generator.hpp"
#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>

/**
 * Konstruktor.
 * @param equation - wskaźnik na obiekt z równaniami na podstawie któwych ma zostać wygenerowany zbiór PointSet.
 * @param x0 - współrzędna początkowa dla osi x.
 * @param y0 - współrzędna początkowa dla osi y.
 */
Generator::Generator(Equations* equation, float x0, float y0):
	eq(equation),
	_x0(x0),
	_y0(y0)
{
}

Generator::~Generator()
{
	delete eq;
}

/**
 * Funkcja generuje zbiór PointSet na podstawie wskazanych w konstruktorze równań Equations. Jeżeli jest taka możliwość i żądana liczba powtórzeń przekracza 
 * 10000 to obliczenie zostaną zróœnoleglone.
 * @param repeates - całkowita liczba kroków symulacji, jeżeli repeates>10000 to każdy wątek wykona repeates/n kroków od punktu początkowego (n do optymalna liczba
 * wątków dla danej platformy).
 * @param intToFLoat - obliczone współrzędne zmiennoprzecinkowe x i y są przekształcane na współrzędne obiektu Point na podstawie zależności x_int = (int)(x_float*intToFLoat), 
 * analogicznie dla współrzędnej y.
 */
PointSet Generator::generate(unsigned int repeates, unsigned int intToFLoat)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	PointSet ps(eq->name());
	
	if((intToFLoat==0)||(repeates==0))
		return ps;
	
	unsigned int n = std::thread::hardware_concurrency();
	if((repeates<10000)||(n<=1))
		privateGenerate(&ps, repeates, intToFLoat);
	else
	{
		std::vector<PointSet> psets;
		std::vector<std::thread> threads;
		for(int i=0;i<n;++i)
			psets.push_back(PointSet());
		for(int i=0;i<n;++i)
		{
			std::thread th{&Generator::privateGenerate, this, &(psets[i]), repeates/n, intToFLoat};
			threads.push_back(move(th));
		}
		for(int i=0;i<n;++i)
			threads[i].join();
		for(int i=0;i<n;++i)
			ps.merge(psets[i]);
	}
	
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Generated in " << ms.count() << " ms" << std::endl;
	return ps;
}

void Generator::privateGenerate(PointSet *ps, unsigned int repeates, unsigned int intToFLoat)
{
	if((repeates==0)||(intToFLoat==0))
		return;
	float x = _x0, y = _y0;
	while(repeates-->0)
	{
		eq->calcNextPoint(x, y);
		ps->addPoint(Point(y*intToFLoat, x*intToFLoat));
// 		ps->addPoint(Point(x*intToFLoat, y*intToFLoat));
	}
}
