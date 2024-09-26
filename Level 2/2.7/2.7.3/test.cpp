//test.cpp
//Author: TengxiaoFan
//This is the test file for building different error_condition
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
	//Create error condition instances based on the following POSIX error codes
	std::error_condition err1(std::errc::io_error);//io_error
	std::error_condition err2 (std::errc::network_unreachable);//network_unreachable
	std::error_condition err3 (std::errc::no_such_file_or_directory);//no_such_file_or_directory
	std::error_condition err4 (std::errc::not_a_socket);//not_a_socket
	std::error_condition err5 (std::errc::permission_denied);//permission_denied

	//Print the above error_condition
	prt_info(info_err(err1));
	prt_info(info_err(err2));
	prt_info(info_err(err3));
	prt_info(info_err(err4));
	prt_info(info_err(err5));

	//Create an std::error_condition object based on the value 128 and the generic error category
	std::error_condition err6(128, std::generic_category());
	prt_info(info_err(err6));//not a socket error

	//Use std::make_error_condition (with std::io_errc as argument) to create an instance of std::error_condition.
	auto err7 = std::make_error_condition(std::errc::address_in_use);
	prt_info(info_err(err7));

}