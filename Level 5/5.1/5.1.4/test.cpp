//test.cpp
//Author: TengxiaoFan
//This is the test file for time series data
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <boost/lexical_cast.hpp>
#include <string>
#include <algorithm>
#include <vector>

using Data = std::tuple<boost::gregorian::date, std::vector<double>>; 
using ResultSet = std::list<Data>;

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
	while (fin.getline(buf, sizeof(buf)))
	{//read the file by line
		std::string str(buf);//Make it an std::string
		//Split the string
		str.erase(std::remove_if(str.begin(), str.end(), boost::is_space()), str.end());//remove all the spaces
		std::vector<std::string> splitarray;
		boost::split(splitarray, str, boost::is_any_of(","));//Split by comma

		//Make the double vector
		std::vector<double> data2;
		auto beginit = splitarray.begin();
		beginit++;//Start from the second
		for (auto it = beginit;it != splitarray.end();it++)
		{
			data2.push_back(boost::lexical_cast<double>(*it));
		}
		//Make the result
		Data dat = std::make_tuple(convert_to_date(splitarray[0]), data2);
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
		std::cout << "Adj Close: " << std::get<1>(*it)[5] << std::endl<<std::endl;
	}
}

int main()
{
	auto result=GetData("TimeSeries.txt");
	prtresult(result);
}