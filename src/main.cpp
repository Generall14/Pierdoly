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
	
	Point c(6, 2);
	res = mySet.insert(c);
	if(!res.second)
		(*res.first).value++;
	std::cout << res.second << ": ";
	for(auto it = mySet.begin();it!=mySet.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	
	Point d(5, 3);
	d.value=3;
	
	
	
	PointSet ps;
	ps.addPoint(c);
	ps.addPoint(b);
	ps.addPoint(a);
	ps.addPoint(d);
	ps.merge(ps);
	std::cout << "PointSet: ";
	for(auto it = ps.begin();it!=ps.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	unsigned int x_min, x_max, y_min, y_max, v_min, v_max;
	ps.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	std::cout << x_min << " " << x_max << " " << y_min << " " << y_max << " " << v_min << " " << v_max << std::endl;
	
	PointSet psn = ps.normalized();
	std::cout << "PointSet normalized: ";
	for(auto it = psn.begin();it!=psn.end();it++)
		std::cout << (*it).value << " ";
	std::cout << std::endl;
	psn.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	std::cout << x_min << " " << x_max << " " << y_min << " " << y_max << " " << v_min << " " << v_max << std::endl;
	
	std::cout << "empty program" << std::endl;
	return 0;
}
