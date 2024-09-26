//test.cpp
//Author: TengxiaoFan
//This is the test file for  using sregex_token_iterators to extract name-value pairs
#include <regex>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <boost/lexical_cast.hpp>

std::map<std::string, double> to_map(std::string& str)
{//Turns a string of information of map to a map, using regex
	std::map<std::string, double> result;
	str.erase(std::remove_if(str.begin(), str.end(), boost::is_space()), str.end());//remove all the spaces
	std::regex myReg10(",");//My regex

	//Take the expressions by token iterator
	std::sregex_token_iterator iToken(str.begin(),str.end(),myReg10,-1);
	std::sregex_token_iterator iEnd;//End iterator
	//std::vector<std::string> splitarray;
	//boost::split(splitarray, str, boost::is_any_of(","));//Split by comma
	while(iToken!=iEnd)
	{//make the instances
		//std::cout << (*iToken) << std::endl;
		std::vector<std::string> tmp;
		boost::split(tmp, (*iToken).str(), boost::is_any_of("="));//Split by equality
		result[tmp[0]] = boost::lexical_cast<double>(tmp[1]);
		iToken++;
	}
	return result;
}


int main()
{
	//Convert string to a key-value map
	std::string sA("a = 1, b = 2, c = 3");
	auto result = to_map(sA);
	for (auto it = result.begin();it != result.end();it++)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}