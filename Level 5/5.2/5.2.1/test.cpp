//test.cpp
//Author: TengxiaoFan
//This is the test file for regex_match
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
	////Test 1
	boost::regex myReg("[a-z]*"); 
	boost::regex myReg2("[a-z]+");
	std::string s1("aza"); //true, true
	std::string s2("1"); //false, false
	std::string s3("b"); //true, true
	std::string s4("ZZ TOP");//false, false
	std::cout << std::boolalpha;
	std::cout << "s1: " << boost::regex_match(s1, myReg) << ", " << boost::regex_match(s1, myReg2) << std::endl;
	std::cout << "s2: " << boost::regex_match(s2, myReg) << ", " << boost::regex_match(s2, myReg2) << std::endl;
	std::cout << "s3: " << boost::regex_match(s3, myReg) << ", " << boost::regex_match(s3, myReg2) << std::endl;
	std::cout << "s4: " << boost::regex_match(s4, myReg) << ", " << boost::regex_match(s4, myReg2) << std::endl;

	//Test 2
	// Digits 
	boost::regex myNumericReg("\\d{2}"); 
	std::string f("34"); //true
	std::string s("345");//false
	std::cout << "f: " << boost::regex_match(f, myNumericReg)  << std::endl;
	std::cout << "s: " << boost::regex_match(s, myNumericReg) << std::endl;

	//Test 3
	// Alternatives 
	boost::regex myAltReg("(new)|(delete)"); 
	std::string s4A("new"); //true
	std::string s5("delete"); //true
	std::string s6("malloc");//false
	std::cout << "s4A: " << boost::regex_match(s4A, myAltReg) << std::endl;
	std::cout << "s5: " << boost::regex_match(s5, myAltReg) << std::endl;
	std::cout << "s6: " << boost::regex_match(s6, myAltReg) << std::endl;

	//Test 4
	// Use of Kleene star syntax 
	boost::regex myReg3("A*"); //false
	boost::regex myReg4("A+"); //false
	boost::regex myReg5("(\\d{2})"); //false
	boost::regex myReg6("\\d{2, 4}"); //false
	boost::regex myReg7("\\d{1,}");//true
	std::string testA("1");
	std::cout << "testA vs myReg3: " << boost::regex_match(testA, myReg3) << std::endl;
	std::cout << "testA vs myReg4: " << boost::regex_match(testA, myReg4) << std::endl;
	std::cout << "testA vs myReg5: " << boost::regex_match(testA, myReg5) << std::endl;
	std::cout << "testA vs myReg6: " << boost::regex_match(testA, myReg6) << std::endl;
	std::cout << "testA vs myReg7: " << boost::regex_match(testA, myReg7) << std::endl;


	//Test 5
	// Alphanumeric characters 
	boost::regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9 
	boost::regex rC1("(\\W)*"); // Not a word 
	boost::regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9
	std::string sC1("abc"); //true, false, true
	std::string sC2("A12678Z909za");//true, false, true
	std::cout << "sC1 vs rC, rC1, rC2: " << boost::regex_match(sC1, rC) <<", "<< boost::regex_match(sC1, rC1) <<", "<< boost::regex_match(sC1, rC2)<<std::endl;
	std::cout << "sC2 vs rC, rC1, rC2: " << boost::regex_match(sC2, rC) << ", " << boost::regex_match(sC2, rC1) << ", " << boost::regex_match(sC2, rC2)<<std::endl;

	//Test 6
	//Perl
	boost::regex rPerl("a*b", boost::regex::perl | boost::regex::icase);
	std::string sPerl1("aaab");//true
	std::string sPerl2("aaabb");//false
	std::cout << "sPerl1: " << boost::regex_match(sPerl1, rPerl) << std::endl;
	std::cout << "sPerl2: " << boost::regex_match(sPerl2, rPerl) << std::endl;

}