//test.cpp
//Author: TengxiaoFan
//This is the test file for some boost string classification algorithms
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <string>

bool Password_checker(const std::string& str)
{//A password checker
	//It must contain at least 8 characters.
	if (str.size() < 8)
		return false;
	//It must contain a combination of digits and characters.
	if (!std::any_of(str.begin(), str.end(), boost::is_alpha()))
		return false;
	if (!std::any_of(str.begin(), str.end(), boost::is_digit()))
		return false;
	//At least one character must be upper case
	if (!std::any_of(str.begin(), str.end(), boost::is_upper()))
		return false;
	//No control characters allowed.
	if (std::any_of(str.begin(), str.end(), boost::is_cntrl()))
		return false;
	//No spaces allowed.
	if (std::any_of(str.begin(), str.end(), boost::is_space()))
		return false;
	return true;//If all the conditions satisfied
}

int main()
{
	std::string str1(" abd1 234\\*");
	//P1 Recognise digits or letters: true
	std::cout << std::boolalpha;
	std::cout << "P1 Recognise digits or letters: " << std::any_of(str1.begin(),str1.end(), boost::is_digit() || boost::is_alpha() )<<std::endl;
	//P2 Recognise digits and not letters: true
	std::cout << "P2 Recognise digits and not letters: " << std::any_of(str1.begin(), str1.end(), boost::is_digit() && (!boost::is_alpha())) << std::endl;
	//P3 Recognise characters from the range [¡®a¡¯,¡¯z¡¯]: true
	std::cout << "P3 Recognise characters from the range [¡®a¡¯,¡¯z¡¯]: " << std::any_of(str1.begin(), str1.end(), boost::is_from_range('a', 'z'))<<std::endl;

	//test the password checker
	std::string pwd1("DanielDuffy1952"); //true
	std::string pwd2("DanielDuffy"); //false
	std::string pwd3("U19520829"); //true
	std::string pwd4("19520829U");//true
	std::string pwd5("123Wab");//False
	std::cout << "Password 1: " << Password_checker(pwd1) << std::endl;
	std::cout << "Password 2: " << Password_checker(pwd2) << std::endl;
	std::cout << "Password 3: " << Password_checker(pwd3) << std::endl;
	std::cout << "Password 4: " << Password_checker(pwd4) << std::endl;
	std::cout << "Password 5: " << Password_checker(pwd5) << std::endl;

}