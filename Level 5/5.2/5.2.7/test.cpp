//test.cpp
//Author: TengxiaoFan
//This is the test file for std::regex_replace
#include <regex>
#include <iostream>
#include <string>

int main()
{
	std::string text("Quick brown fox");
	std::regex vowels("a|e|i|o|u");
	// Replace all the vowels to *
	//"Q**ck br*wn f*x"
	std::string result=std::regex_replace( text, vowels, "*");
	std::cout << text << std::endl; 
	std::cout << result << std::endl;// "Q**ck br*wn f*x"
}