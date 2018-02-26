#include <iostream>
#include <set>
#include "Point.hpp"
#include "PointSet.hpp"

int main()
{
	std::set<Point> mySet;
	Point a(1, 2);
	auto res = mySet.insert(a);
	if(!res.second)
		(*res.first).value++;
	std::cout << res.second << ": ";
	for(auto it = mySet.begin();it!=mySet.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	
	Point b(1, 2);
	res = mySet.insert(b);
	if(!res.second)
		(*res.first).value++;
	std::cout << res.second << ": ";
	for(auto it = mySet.begin();it!=mySet.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	
	Point c(2, 2);
	res = mySet.insert(c);
	if(!res.second)
		(*res.first).value++;
	std::cout << res.second << ": ";
	for(auto it = mySet.begin();it!=mySet.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	
	
	
	PointSet ps;
	ps.addPoint(c);
	ps.addPoint(b);
	ps.addPoint(a);
	ps.merge(ps);
	std::cout << "PointSet: ";
	for(auto it = ps.begin();it!=ps.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	
	std::cout << "empty program" << std::endl;
	return 0;
}
