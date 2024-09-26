//test.cpp
//Author: TengxiaoFan
//This is the test program for a function giving a tuple of information of errors
//and different ways to build an error_condition
#include <iostream>
#include <tuple>
#include <string>

std::tuple < std::string, int, std::string> info_err(std::error_condition err)
{//Return the message, error code and category name of an error condition
	std::string mes = err.message();//message
	int code = err.value();//error code
	std::string cat = err.category().name();//category name
	auto result = std::make_tuple(mes, code, cat);//return the tuple
	return result;
}

void prt_info(std::tuple < std::string, int, std::string> info)
{
	//Print the information of an error
	std::cout << std::endl;
	std::cout << "Message: " << std::get<0>(info) << std::endl;
	std::cout << "Error code: " << std::get<1>(info) << std::endl;
	std::cout << "Category name: " << std::get<2>(info) << std::endl;

}

int main()
{
	std::error_condition err1;//Based on default constructor
	prt_info(info_err(err1));

	std::error_condition err2 = std::make_error_condition(std::errc::invalid_argument);//Based on std::errc
	prt_info(info_err(err2));

	std::error_condition err3(1,std::generic_category());//Value and error category
	prt_info(info_err(err3));
}