#include "Point.hpp"

Point::Point(unsigned int x_pos, unsigned int y_pos, unsigned int initial_value):
	value(initial_value),
	_x(x_pos),
	_y(y_pos)
{
}

unsigned int Point::XPos() const
{
	return _x;
}

unsigned int Point::YPos() const
{
	return _y;
}

/**
 * Funkcja sprawdza czy obiekt ma zerowe współrzędne, jeżeli tak, zwraca true.
 */
bool Point::isNullPos() const
{
	if((_x==0)&&(_y==0))
		return true;
	return false;
}

bool operator<(const Point &l, const Point &r)
{
	if(l.YPos()<r.YPos())
		return true;
	if(l.YPos()==r.YPos())
	{
		if(l.XPos()<r.XPos())
			return true;
	}
	return false;
}
