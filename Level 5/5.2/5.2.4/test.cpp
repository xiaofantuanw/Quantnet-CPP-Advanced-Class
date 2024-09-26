//test.cpp
//Author: TengxiaoFan
//This is the test file for sregex_token_iterators
#include <regex>
#include <string>
#include <iostream>
#include <vector>

template <typename T>
void prtvec(std::vector<T> vec)
{
	std::cout << "{";
	for (auto it = vec.begin();it != vec.end();it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << "}\n";
}

int main()
{
	std::regex myReg10("/"); 
	std::string S3 = "2016/3/15";
	//Containers for date and seperator
	std::vector<int> date;
	std::vector<std::string> seperator;

	std::sregex_token_iterator itToken(S3.begin(), S3.end(), myReg10, 0);//This gives the seperators
	std::sregex_token_iterator itToken2(S3.begin(), S3.end(), myReg10, -1);//This gives the date
	std::sregex_token_iterator itEnd;
	while (itToken != itEnd)
	{//Make the seperator vector
		//std::cout << (*itToken) << std::endl;
		seperator.push_back((*itToken).str());
		itToken++;
	}
	while (itToken2 != itEnd)
	{//Make the date vector
		//std::cout << (*itToken2) << std::endl;
		date.push_back(std::stoi((*itToken2).str()));
		itToken2++;
	}
	//Print the containers
	prtvec(seperator);
	prtvec(date);
	
}