//test.cpp
//Author: TengxiaoFan
//This is the test file for boost and std error_condition
#include <iostream>
#include <boost/system/error_condition.hpp>
#include <boost/system/error_code.hpp>
#include <string>
#include <fstream>


std::error_condition prtfile(std::string filename)
{
	//This function prints the lines in a file.
	std::ifstream infile(filename.data());
	if (!infile.is_open())
	{//If the file doesn't exist, return error.
		auto err = std::make_error_condition(std::errc::invalid_argument);
		return err;
	}
	std::string tmp;
	while (std::getline(infile, tmp))
	{//Print the lines
		std::cout << tmp << std::endl;
	}
	infile.close();//Close the file
	std::error_condition err2;//Default error condition
	return err2;
}

boost::system::error_condition prtfile_boost(std::string filename)
{
	//This function prints the lines in a file. Using boost error
	std::ifstream infile(filename.data());
	if (!infile.is_open())
	{//If the file doesn't exist, return error.
		boost::system::error_condition err=boost::system::errc::make_error_condition(boost::system::errc::invalid_argument);
		return err;
	}
	std::string tmp;
	while (std::getline(infile, tmp))
	{//Print the lines
		std::cout << tmp << std::endl;
	}
	infile.close();//Close the file
	boost::system::error_condition err2 = boost::system::errc::make_error_condition(boost::system::errc::success);//Default error condition
	return err2;
}

int main()
{
	//Test of std
	auto err = prtfile("test.txt");//Exist
	std::cout << err.message() << std::endl;

	err = prtfile("text.txt");//Doesn't exist
	std::cout << err.message() << std::endl<<"------------------"<<std::endl;

	//Test of boost
	auto err_boost = prtfile_boost("test.txt");//Exist
	std::cout << err_boost.message() << std::endl;
	err_boost = prtfile_boost("text.txt");//Doesn't exist
	std::cout << err_boost.message() << std::endl;

}