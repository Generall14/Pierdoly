#include "PointSet.hpp"

PointSet::PointSet()
{
	_set.clear();
}

std::set<Point>::iterator PointSet::begin()
{
	return _set.begin();
}

std::set<Point>::iterator PointSet::end()
{
	return _set.end();
}

PointSet::uint PointSet::size() const
{
	return _set.size();
}

void PointSet::getRanges(PointSet::uint &x_min, PointSet::uint &x_max, PointSet::uint &y_min, PointSet::uint &y_max) const
{
	x_min = 0;
	x_max = 0;
	y_min = 0;
	y_max = 0;
	if(_set.empty())
		return;
	auto it=_set.begin();
	x_min = (*it).XPos();
	x_max = x_min;
	y_min = (*it).YPos();
	y_max = y_max;
	for(auto it=_set.begin();it!=_set.end();++it)
	{
		if((*it).XPos()<x_min)
			x_min = (*it).XPos();
		if((*it).YPos()<y_min)
			y_min = (*it).YPos();
		if((*it).XPos()>x_max)
			x_max = (*it).XPos();
		if((*it).YPos()>y_max)
			y_max = (*it).YPos();
	}
	return;
}

/**
 * Funcja dodaje obiekt Point do zestawu, jeżeli obiekt o identycznych współrzędnych już istniał to 
 * dodaje pole Point::value do obiektu już istniejącego.
 */
void PointSet::addPoint(const Point added)
{
	auto res = _set.insert(added);
	if(!res.second)
		(*res.first).value += added.value;
}

/**
 * Metoda dodaje wszystkie pozycje zawarte w wskazanym obiekcie PointSet.
 */
void PointSet::merge(PointSet &other)
{
	for(auto it=other.begin();it!=other.end();++it)
		this->addPoint((*it));
}
