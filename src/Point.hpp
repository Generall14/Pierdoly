#ifndef POINT_HPP
#define POINT_HPP

/**
 * @class Point
 * Klasa reprezentuje punkt w przestrzeni dwuwymiarowej, punkty X i Y są stałe po stworzeniu obiektu.
 * Obiekty są orównywane w pierwszej kolejności pod względem współrzędnej y, następnie względem 
 * współrzędnej x, wartość nie jest brana pod uwagę.
 */
class Point
{
public:
	Point(int x_pos, int y_pos, unsigned int initial_value=1);
	mutable unsigned int value;
	
	int XPos() const;
	int YPos() const;
	bool isNullPos() const;
	
private:
	int _x, _y;
};

bool operator<(const Point &l, const Point &r);

#endif
