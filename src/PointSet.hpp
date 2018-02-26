#ifndef POINTSET_HPP
#define POINTSET_HPP

#include <set>
#include "Point.hpp"

/**
 * @class PointSet
 * Klasa zbiera obiekty Point w jeden kontener (sortowany, bez powtorzeń). Udostępnia metodę 
 * addPoint(...) która dodaje Point do kontenera lub dodaje samą wartość do już istniejącego 
 * obiektu Point. Posiada metodę normalized która zwraca PointSet z danymi przesuniętymi do 
 * punktu 0,0 i przeskalowanymi od 0 do wskazanej wartości. Metoda merge dodaje wszystkie pozycje 
 * z wskazanego innego obiektu.
 */
class PointSet
{
public:
	typedef unsigned int uint;
	PointSet();
	
	std::set<Point>::iterator begin();
	std::set<Point>::iterator end();
	uint size() const;
	void getRanges(uint &x_min, uint &x_max, uint &y_min, uint &y_max) const;
	
	void addPoint(const Point added);

	void merge(PointSet &other);
	//PointSet normaized(unsigned int maxValue=0xFF) const;
	
private:
	std::set<Point> _set;
};

#endif
