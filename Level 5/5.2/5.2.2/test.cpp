//test.cpp
//Author: TengxiaoFan
//This is the test file for regex_search
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
	boost::regex mySearchReg("(rain)|(Spain)");
	std::string myText("The rain in Spain stays mainly on the plain");
	boost::smatch myMatch;//To see whether matched
	
	std::cout << "Matched? " << std::boolalpha<<boost::regex_search(myText, myMatch, mySearchReg) << std::endl;//Matched or not
	if (myMatch[1].matched)
	{
		std::cout << "rain" << std::endl;//This will appear
	}
	if (myMatch[2].matched)
	{
		std::cout << "Spain" << std::endl;//Not matched
	}
}