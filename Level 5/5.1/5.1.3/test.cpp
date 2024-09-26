//test.cpp
//Author: TengxiaoFan
//This is the test file for some boost string splitting and joining algorithms
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/lexical_cast.hpp>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
 
boost::gregorian::date convert_to_date(const std::string& str)
{//Turns a string of date to gregorian date
	std::vector<std::string> splitarray;
	boost::split(splitarray, str, boost::is_any_of("-./_"));
	int y = boost::lexical_cast<int>(splitarray[0]);
	int m = boost::lexical_cast<int>(splitarray[1]);
	int d = boost::lexical_cast<int>(splitarray[2]);
	boost::gregorian::date dat(y, m, d);//result
	return dat;
}

std::map<std::string, double> to_map(std::string& str)
{//Turns a string of information of map to a map
	std::map<std::string, double> result;
	str.erase(std::remove_if(str.begin(), str.end(), boost::is_space()),str.end());//remove all the spaces
	std::vector<std::string> splitarray;
	boost::split(splitarray, str, boost::is_any_of(","));//Split by comma
	for (auto it = splitarray.begin();it != splitarray.end();it++)
	{//make the instances
		std::vector<std::string> tmp;
		boost::split(tmp, (*it), boost::is_any_of("="));//Split by equality
		result[tmp[0]] = boost::lexical_cast<double>(tmp[1]);
	}
	return result;
}

int main()
{
	//Test split and join
	std::string sA("1,2,3,4/5/9*56");
	std::vector<std::string> splitarray;
	boost::split(splitarray, sA, boost::is_any_of(",/*"));
	std::string MyJoin = boost::join(splitarray, "/");
	std::cout << "Split and Join: " << MyJoin << std::endl;

	//Conversion to date
	std::string sDate1("1999-08-21");
	std::string sDate2("1999.09.21");
	boost::gregorian::date d1 = convert_to_date(sDate1);
	boost::gregorian::date d2 = convert_to_date(sDate2);
	std::cout << "1999-08-21: " << "Year " << d1.year() << "; Month " << d1.month() << "; Day " << d1.day() << std::endl;
	std::cout << "1999.09.21: " << "Year " << d2.year() << "; Month " << d2.month() << "; Day " << d2.day() << std::endl;

	//Convert string to a key-value map
	std::string strmap = " mike=5,jack=3.5,   moon=0.1  ";
	auto result = to_map(strmap);
	for (auto it = result.begin();it != result.end();it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}