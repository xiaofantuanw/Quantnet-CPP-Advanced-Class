//test.cpp
//Author: TengxiaoFan
//This is the test file for some boost string algorithms such as trim
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string_regex.hpp>
#include <string>
#include <cctype>

int main()
{
	//Test trim
	std::string str1 = "      Hello     ";
	std::string str2 = boost::trim_copy(str1);//trim, a copy of the input string is created.
	boost::trim(str1);//trim, string is modified
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;

	//Trim using different predicates
	std::string str3 = "123Apple321";
	boost::trim_if(str3, boost::is_digit());
	std::cout << str3 << std::endl;
	std::string str4 = "/**/*///*Apple//*";
	boost::trim_if(str4, boost::is_any_of("*/"));//Using is_any_of
	std::cout << str4 << std::endl;
	std::string str5 = "/**1/32*4///*Apple/5/23*";
	boost::trim_if(str5, boost::is_any_of("*/")||boost::is_digit());//Using OR
	std::cout << str5 << std::endl;

	//Test if a string starts or ends with a given string
	std::string str6 = "AAAstringaaa";//A string starts with AAA and ends with aaa
	std::cout << std::boolalpha;
	std::cout << "Start with AAA? " << boost::starts_with(str6, "AAA")<<std::endl;//case-sensitive, true
	std::cout << "Start with aaa? " << boost::starts_with(str6, "aaa") << std::endl;//case-sensitive, false
	std::cout << "Start with aaa or AAA? " << boost::istarts_with(str6, "aaa") << std::endl;//case-insensitive. true
	std::cout << "End with AAA? " << boost::ends_with(str6, "AAA") << std::endl;//case-sensitive, false
	std::cout << "End with aaa? " << boost::ends_with(str6, "aaa") << std::endl;//case-sensitive, true
	std::cout << "End with aaa or AAA? " << boost::iends_with(str6, "aaA") << std::endl;//case-insensitive. true

	//Test if a string contains a given string
	std::cout << "Contains string? " << boost::contains(str6, "string") << std::endl;//case sensitive, true
	std::cout << "Contains STRING? " << boost::contains(str6, "STRING") << std::endl;//case sensitive, false
	std::cout << "Contains STRING or string? " << boost::icontains(str6, "STRING") << std::endl;//case insensitive, true
	//Equality
	std::string str7 = "aaaSTRINGaaa";//Another stirng
	std::cout << "Equal? " << boost::equals(str6, str7) << std::endl;//case sensitive,false
	std::cout << "Equal (insensitive)? " << boost::iequals(str6, str7) << std::endl;//case insensitive, true

}
