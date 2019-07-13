#include "Point.hpp"

Point::Point(int x_pos, int y_pos, unsigned int initial_value):
	value(initial_value),
	_x(x_pos),
	_y(y_pos)
{
}

int Point::XPos() const
{
	return _x;
}

int Point::YPos() const
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
	if(l.XPos()<r.XPos())
		return true;
	if(l.XPos()==r.XPos())
	{
		if(l.YPos()<r.YPos())
			return true;
	}
	return false;
}
