//test.cpp
//Author: TengxiaoFan
//This is the test file for building different error_code and compare it with error condition
#include <iostream>
#include <tuple>
#include <string>

std::tuple < std::string, int, std::string> info_errcode(std::error_code err)
{//Return the message, error code and category name of an error code
	std::string mes = err.message();//message
	int code = err.value();//error code
	std::string cat = err.category().name();//category name
	auto result = std::make_tuple(mes, code, cat);//return the tuple
	return result;
}

std::tuple < std::string, int, std::string> info_errcond(std::error_condition err)
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
	//Create a default error code
	std::error_code errcode1;
	//Create an error code with a platform-dependent error code value and an error category.
	std::error_code errcode2(11, std::generic_category());
	//Print the information
	prt_info(info_errcode(errcode1));
	prt_info(info_errcode(errcode2));

	//Create a default error condition
	std::error_condition errcond1;
	//Create an error conditionwith a platform-independent error code value and an error category.
	std::error_condition errcond2(11, std::generic_category());
	//Print the information
	prt_info(info_errcond(errcond1));
	prt_info(info_errcond(errcond2));

	//Compare the error code and error condition
	std::cout << std::boolalpha;
	std::cout << "Error code and error condition the same for default? " << (errcode1 == errcond1) << std::endl;//true
	std::cout << "Error code and error condition the same for non-default? " << (errcode2 == errcond2) << std::endl;//true
}