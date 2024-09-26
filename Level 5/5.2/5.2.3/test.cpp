//test.cpp
//Author: TengxiaoFan
//This is the test file for regex iterators
#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <set>

template <typename T>
void prtset(std::set<T> s)
{//Print a set of type T
	std::cout << "{";
	for (auto i = s.begin();i != s.end();i++)
	{
		std::cout << (*i) << " ";
	}
	std::cout << "}\n";
}

int main()
{
	std::string S2 = "1,1,2,3,5,8,13,21";
	boost::regex myReg("(\\d+),?");
	boost::sregex_iterator it(S2.begin(), S2.end(), myReg);//Build the sregex_iterator
	boost::sregex_iterator end;
	std::set<int> set_int;
	std::set<std::string> set_string;
	while (it != end)
	{//Insert the str/int into the set for every iteration
		std::string str((*it).str());
		int x = std::stoi((*it).str());
		if (set_string.find(str) == set_string.end())
			set_string.insert(str);
		if (set_int.find(x) == set_int.end())
			set_int.insert(x);
		//Print it
		std::cout << (*it) << std::endl;
		it++;
	}
	prtset(set_int);
	prtset(set_string);
}