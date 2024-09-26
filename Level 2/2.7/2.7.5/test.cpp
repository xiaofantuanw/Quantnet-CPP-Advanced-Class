//test.cpp
// Author: TengxiaoFan
//This is the test code for throwing an error and catching it
#include <iostream>
#include <fstream>
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
	std::ifstream file(std::string("DOESNOTEXIST.txt"));
	try 
	{
		// Set the exception mask of the file stream 
		// In this case 1) logical error on I/O operation or 
		// 2) read/write error on I/O operation 
		file.exceptions(file.failbit | file.badbit); 
	} 
	catch (const std::ios_base::failure& e) 
	{ 
		if (e.code() == std::io_errc::stream)//Comparison(true)
		{
			std::error_code ec1(e.code());//Create an error code instance ec1 with e.code() as argument
			std::error_condition ec2=ec1.default_error_condition();//Create an error condition ec2 instance with ec1 as argument
			prt_info(info_errcond(ec2));//Print the properties value, message and error category of ec2.
		}
	} 
	catch (...) 
	{ 
		std::cout << "catch all\n"; 
	}
}