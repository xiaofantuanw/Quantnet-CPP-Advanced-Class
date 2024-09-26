//test.cpp
//Author: TengxiaoFan
//This is the test file for std::bitset and its functionalities
#include <bitset>
#include <iostream>
#include <stdexcept>

void test_bitset()
{
	const int Nsmall = 10, Nbig = 30;
	std::cout << "Create bitsets from unsigned long and unsigned long long: " << std::endl;
	unsigned long ul = 11111111;
	unsigned long long ull = 111111114;
	std::bitset<Nsmall> bs1(ul);//create a bitset from unsigned long
	std::cout << bs1 << std::endl;
	std::bitset<Nbig> bs2(ul);//create a bitset from unsigned long with more digits
	std::cout << bs2 << std::endl;
	std::bitset<Nbig> bs3(ull);//create a bitset from unsigned long long
	std::cout << bs3 << std::endl << std::endl;

	//Create bitsets from string
	std::cout << "Create bitsets from string: " << std::endl;
	std::bitset<Nsmall> bs4(std::string("0110010011"));//create a bitset from a string
	std::cout << bs4 << std::endl;
	std::bitset<Nsmall> bs5(std::string("10110010011"));//create a bitset from a string, more digits than template
	std::cout << bs5 << std::endl;
	std::bitset<Nsmall> bs6(std::string("101100100"));//create a bitset from a string, less digits than template
	std::cout << bs6 << std::endl;
	std::bitset<Nsmall> bs7(std::string("111100101"), 2);//index=2
	std::cout << bs7 << std::endl;//Create a bitset from parts of strings based on a start index
	std::bitset<Nsmall> bs8(std::string("111100101"), 2, 4);//index=2,num_bits=4
	std::cout << bs8 << std::endl;//Create a bitset from parts of strings based on a start index and number of btis

	//catch some errors about the bitset
	try
	{
		std::bitset<Nsmall> bs9(std::string("111100101"), 112, 4);//pos > str.size()
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;//invalid bitset position
	}
	try
	{
		std::bitset<Nsmall> bs10(std::string("111100201"));//any character is not one or zero
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;//invalid bitset char
	}
	std::cout << std::endl;

	//Set the bits in a bitset in different ways
	std::cout << "Set the bits in a bitset in different ways" << std::endl;
	bs1.set();//Set all the bits to be true
	std::cout << bs1 << std::endl;
	bs2.reset();//Set all the bits to be false
	std::cout << bs2 << std::endl;
	bs3.flip();//flip the bits
	std::cout << bs3 << std::endl;
	std::cout << std::boolalpha;
	std::cout << bs3.any() << std::endl;//Test if any bits are set, true
	std::cout << bs1.all() << std::endl;//Test if all bits are set, true
	std::cout << bs1.none() << std::endl;//Test if none of the bits are set, false
	for (int i = 0; i < bs3.size(); i++)
	{
		std::cout << std::noboolalpha << bs3[i] << ", ";//Access the bits
	}
	std::cout << std::endl;
	std::cout << bs3.count() << std::endl;//Number of set bits

	std::string strvalue = bs3.to_string();//Convert to string
	unsigned long value = bs3.to_ulong();//Convert to unsigned long
	unsigned long long llvalue = bs3.to_ullong();//Convert to unsigned long long
	std::cout << strvalue << ", " << value << ", " << llvalue << std::endl;

	std::cout << "Same? " << std::boolalpha << (bs2 == bs3) << std::endl;
	//Test if the two bitsets are the same, only for same digits
}

int main()
{
	test_bitset();
}