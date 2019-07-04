#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <map>
#include <stack>

// Olana kwestia asercji danych wejściowych!

using namespace std;

auto getData()
{
	vector<string> temp;
	string line;
	getline(cin, line);
	istringstream is(line);
	
	copy(istream_iterator<string>(is), istream_iterator<string>(),
		 back_inserter(temp));
	return temp;
}

double rpn(vector<string>& inputs)
{
	map<string, double(*)(double, double)> m = {
		{"+", [](double a, double b){return a+b;}},
		{"-", [](double a, double b){return a-b;}},
		{"*", [](double a, double b){return a*b;}},
		{"/", [](double a, double b){return a/b;}}
	};
	stack<double> s;
	
	for(auto val: inputs)
	{
		if(m.find(val)!=m.end())
		{
			double b = s.top();
			s.pop();
			double a = s.top();
			s.pop();
			s.push(m[val](a, b));
		}
		else
			s.push(stod(val));
	}
	
	return s.top();
}

int main()
{
	auto s = getData();
	
	cout << rpn(s) << endl;
	
	return 0;
}
