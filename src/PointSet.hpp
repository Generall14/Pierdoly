#ifndef POINTSET_HPP
#define POINTSET_HPP

#include <set>
#include <string>
#include <functional>
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
 * Metody toBitmap(...) przekształca zbiór w bitmape i zapisuje ją pod wskazanym adresem.
 * 
 * Metody logarithm(), multiply(), sqrt() wykonują zadane operacje matematyczne na elementach zbioru.
 */
class PointSet
{
public:
	typedef unsigned int uint;
	PointSet(std::string name="");
	
	std::set<Point>::iterator begin();
	std::set<Point>::iterator end();
	uint size() const;
	std::string name() const;
	
	void addPoint(const Point added);
	void logarithm();
	void multiply(float mul);
	void sqrt();

	typedef std::function< char(char)> fun;
	void toBitmap(std::string fileAdr, fun r, fun g, fun b) const;
	void toBitmap(std::string fileAdr, fun all) const;
	void toBitmap(std::string fileAdr) const;
	void toBitmapc(std::string fileAdr) const;
	void about() const;
	
	void merge(PointSet &other);
	
private:
	void getRanges(int &x_min, int &x_max, int &y_min, int &y_max, uint &v_min, uint &v_max) const;
	PointSet normalized(uint maxValue=0xFF) const;
	
	std::set<Point> _set;
	std::string _name;
};

#endif
