//test.cpp
//Author: TengxiaoFan
//This is the test file for some modifying std algorithm
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>
#include <string>
#include "Point.hpp"

template <typename T>
void prtvec(const std::vector<T>& v)
{//To print a vector
	std::cout << "{";
	for (auto i = v.begin();i != v.end();i++)
	{
		std::cout << (*i) << ",";
	}
	std::cout << "}\n";
}

//STRING FUNCS
void trim(std::string& str)
{//Trim all leading and trailing blanks (space, tabs etc.) from the string.
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](char c) {return !isspace(c);}));//left
	str.erase(std::find_if(str.rbegin(), str.rend(), [](char c) {return !isspace(c);}).base(), str.end());//right
}

using Unary = std::function<bool(char c)>;

void trim_if(std::string& str,Unary u)
{//Trim all leading and trailing blanks based on a unary predicate from the string.
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [&](char c) {return !u(c);}));//left
	str.erase(std::find_if(str.rbegin(), str.rend(), [&](char c) {return !u(c);}).base(), str.end());//right
}

std::vector<std::string> split(const std::string& str, char pattern)
{//Produce a vector of strings from a character-separated string.
	std::vector<std::string> result;
	auto it = str.begin();
	while (it != str.end())
	{
		auto pos = std::find(it, str.end(), pattern);//find the first position of pattern
		std::string s;
		std::copy(it, pos, std::back_inserter(s));//a substring is copied
		result.push_back(s);
		if (pos != str.end())
		{
			pos++;
			it = pos;
		}
		else
			break;
	}
	return result;
}

std::string join(const std::string& s1, const std::string& s2)
{//Join two strings
	std::string result;
	std::copy(s1.begin(), s1.end(), std::back_inserter(result));
	std::copy(s2.begin(), s2.end(), std::back_inserter(result));
	return result;
}

int main()
{
	//Remove the element in S1 that can be found in S2
	std::vector<int> S1 = { 1,2,3,4,5,6 };
	std::vector<int> S2 = { 3,6 };
	S1.erase(std::remove_if(S1.begin(), S1.end(), [&](int x) {return (std::find(S2.begin(), S2.end(), x) != S2.end());}),S1.end());
	prtvec<int>(S1);
	//Executions of point array
	std::vector<Point> Pvec{ Point(1,1),Point(1,2),Point(1,3),Point(1,1),Point(0,0),Point(100,99),Point(1,2)};
	//Transform to no duplicate
	auto comp = [](const Point& P1, const Point& P2)
	{//A comparison to sort
		return P1.Distance() < P2.Distance();
	};
	std::sort(Pvec.begin(), Pvec.end(), comp);
	Pvec.erase(std::unique(Pvec.begin(), Pvec.end()),Pvec.end());//erase the duplicate
	prtvec<Point>(Pvec);
	//Filter this set if distance>3
	Pvec.erase(std::remove_if(Pvec.begin(), Pvec.end(), [](const Point& p) {return p.Distance() > 3;}),Pvec.end());
	prtvec<Point>(Pvec);

	//Test the string functions
	//trim
	std::string str("   Apple     ");
	trim(str);
	std::cout << str << std::endl;
	//trim_if
	Unary u = [](char c) {return c == 'a';};
	std::string str2("aaJackaaaaa");
	trim_if(str2, u);
	std::cout << str2 << std::endl;
	//split
	std::string str3("I am strong ");
	auto v = split(str3, ' ');
	prtvec<std::string>(v);
	//join
	std::cout << join(str3, str2) << std::endl;
}