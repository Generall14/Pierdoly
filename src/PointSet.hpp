#ifndef POINTSET_HPP
#define POINTSET_HPP

#include <set>
#include <string>
#include "Point.hpp"

/**
 * @class PointSet
 * Klasa zbiera obiekty Point w jeden kontener (sortowany, bez powtorzeń). Udostępnia metodę 
 * addPoint(...) która dodaje Point do kontenera lub dodaje samą wartość do już istniejącego 
 * obiektu Point. Posiada metodę normalized która zwraca PointSet z danymi przesuniętymi do 
 * punktu 0,0 i przeskalowanymi od 0 do wskazanej wartości. Metoda merge dodaje wszystkie pozycje 
 * z wskazanego innego obiektu.
 * 
 * Metoda toBitmap(...) przekształca zbiór w bitmape i zapisuje ją pod wskazanym adresem.
 */
class PointSet
{
public:
	typedef unsigned int uint;
	PointSet();
	
	std::set<Point>::iterator begin();
	std::set<Point>::iterator end();
	uint size() const;
	void getRanges(int &x_min, int &x_max, int &y_min, int &y_max, uint &v_min, uint &v_max) const;
	
	void addPoint(const Point added);
	void logarithm();
	void multiply(float mul);
	void sqrt();

	void toBitmap(std::string fileAdr) const;
	
private:
	void merge(PointSet &other);
	PointSet normalized(uint maxValue=0xFF) const;
	
	std::set<Point> _set;
};

#endif
