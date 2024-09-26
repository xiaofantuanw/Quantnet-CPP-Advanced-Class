//test.cpp
//Author: TengxiaoFan
//This is the test file for time series data, using regex
#include <iostream>
#include <fstream>
//Old ways
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

boost::gregorian::date convert_to_date(const std::string& str)
{//Turns a string of date to gregorian date
	//Old way	
	//std::vector<std::string> splitarray;
	//boost::split(splitarray, str, boost::is_any_of("-./_"));
	std::regex reg("-");
	std::sregex_token_iterator iToken(str.begin(), str.end(), reg, -1);//Get the information
	int y = boost::lexical_cast<int>(iToken->str());
	iToken++;
	int m = boost::lexical_cast<int>(iToken->str());
	iToken++;
	int d = boost::lexical_cast<int>(iToken->str());
	boost::gregorian::date dat(y, m, d);//result
	return dat;
}

ResultSet GetData(const std::string& f)
{//Get data from a file
	ResultSet result;
	std::ifstream fin;
	fin.open(f, std::ios::in);//Open the file
	if (!fin.is_open())
	{//If the file cannot be opened
		std::cout << "cannot open the file" << std::endl;
	}

	char buf[100] = { 0 };
	fin.getline(buf, sizeof(buf));
	//std::string str(buf);
	//str.erase(std::remove_if(str.begin(), str.end(), boost::is_space()), str.end());//remove all the spaces

	while (fin.getline(buf, sizeof(buf)))
	{//read the file by line
		std::string str(buf);//Make it an std::string
		//Split the string
		str.erase(std::remove_if(str.begin(), str.end(), boost::is_space()), str.end());//remove all the spaces
		//std::vector<std::string> splitarray;
		//boost::split(splitarray, str, boost::is_any_of(","));//Split by comma
		std::regex reg(",");
		std::sregex_token_iterator iToken(str.begin(), str.end(), reg, -1);//Get the information
		std::sregex_token_iterator iEnd;//Get the information
		//Make the double vector

		auto data1 = convert_to_date(iToken->str());//The date data
		std::vector<double> data2;
		iToken++;//Start from the second
		for (auto it = iToken;it != iEnd;it++)
		{
			data2.push_back(boost::lexical_cast<double>(it->str()));
		}
		//Make the result
		Data dat = std::make_tuple(data1, data2);
		result.push_back(dat);
	}
	fin.close();//Close the file
	return result;
}

void prtresult(const ResultSet& result)
{//Print the result
	for (auto it = result.begin();it != result.end();it++)
	{
		std::cout << "Date: " << std::get<0>(*it).year() << "-" << std::get<0>(*it).month() << "-" << std::get<0>(*it).day() << std::endl;
		std::cout << "Open: " << std::get<1>(*it)[0] << std::endl;
		std::cout << "High: " << std::get<1>(*it)[1] << std::endl;
		std::cout << "Low: " << std::get<1>(*it)[2] << std::endl;
		std::cout << "Close: " << std::get<1>(*it)[3] << std::endl;
		std::cout << "Volume: " << std::get<1>(*it)[4] << std::endl;
		std::cout << "Adj Close: " << std::get<1>(*it)[5] << std::endl << std::endl;
	}
}

int main()
{
	auto result = GetData("TimeSeries.csv");
	prtresult(result);
}