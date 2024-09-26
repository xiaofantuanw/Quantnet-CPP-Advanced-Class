//test.cpp
//Author: TengxiaoFan
//This is the test file for dynamic bitset
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <boost/dynamic_bitset.hpp>

void test_bitset()
{
	const int Nsmall = 10, Nbig = 30;
	std::cout << "Create bitsets from unsigned long and unsigned long long: " << std::endl;
	unsigned long ul = 11111111;
	unsigned long long ull = 111111114;
	boost::dynamic_bitset<> bs1(Nsmall,ul);//create a bitset from unsigned long
	std::cout << bs1 << std::endl;
	boost::dynamic_bitset<> bs2(Nbig, ul);//create a bitset from unsigned long with more digits
	std::cout << bs2 << std::endl;
	boost::dynamic_bitset<> bs3(Nbig, ull);//create a bitset from unsigned long long
	std::cout << bs3 << std::endl << std::endl;

	//Create bitsets from string
	std::cout << "Create bitsets from string: " << std::endl;
	boost::dynamic_bitset<> bs4(std::string("0110010011"));//create a bitset from a string
	std::cout << bs4 << std::endl;
	boost::dynamic_bitset<> bs5(std::string("10110010011"));//create a bitset from a string, more digits than template
	std::cout << bs5 << std::endl;
	boost::dynamic_bitset<>  bs7(std::string("111100101"), 2);//index=2
	std::cout << bs7 << std::endl;//Create a bitset from parts of strings based on a start index
	boost::dynamic_bitset<>  bs8(std::string("111100101"), 2, 4);//index=2,num_bits=4
	std::cout << bs8 << std::endl;//Create a bitset from parts of strings based on a start index and number of btis

	//boost dynamic bitset does not throw
	//try
	//{
	//	boost::dynamic_bitset<> bs9(std::string("111100101"), 112, 4);//pos > str.size()
	//}
	//catch (std::exception ex)
	//{
	//	std::cout << ex.what() << std::endl;//invalid bitset position
	//}
	//try
	//{
	//	boost::dynamic_bitset<>  bs10(std::string("111100201"));//any character is not one or zero
	//}
	//catch (std::exception ex)
	//{
	//	std::cout << ex.what() << std::endl;//invalid bitset char
	//}
	//std::cout << std::endl;

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

	std::string strvalue ;
	boost::to_string(bs3, strvalue);//Convert to string
	unsigned long value = bs3.to_ulong();//Convert to unsigned long
	//no such conversion
	//unsigned long long llvalue = bs3.to_ullong();//Convert to unsigned long long
	std::cout << strvalue << ", " << value  << std::endl;

	std::cout << "Same? " << std::boolalpha << (bs2 == bs3) << std::endl;
	//Test if the two bitsets are the same, only for same digits
}

void test_bitset_2()
{
	//Create two bitsets with the same num of bits
	boost::dynamic_bitset<> bs1(std::string("0100100011"));
	boost::dynamic_bitset<> bs2(std::string("1101001101"));
	std::cout << "Original: \nbs1: " << bs1 << std::endl;
	std::cout << "bs2: " << bs2 << std::endl;

	//Toggle all the bits of bs1 and bs2
	bs1 = ~bs1;
	bs2 = ~bs2;
	std::cout << "Toggle all the bits\n";
	std::cout << "bs1: " << bs1 << std::endl;
	std::cout << "bs2: " << bs2 << std::endl;

	auto bsXOR = bs1 ^ bs2;//bitwise XOR
	std::cout << "XOR: " << bsXOR << std::endl;
	auto bsOR = bs1 | bs2;//bitwise OR
	std::cout << "OR: " << bsOR << std::endl;
	auto bsAND = bs1 & bs2;//bitwise AND
	std::cout << "AND: " << bsAND << std::endl;

	//left shift
	auto bsL1 = bs1 << 1;//shift 1 unit to left
	auto bsR1 = bs1 >> 1;//shift 1 unit to right
	auto bsL2 = bs2 << 1;//shift 1 unit to left
	auto bsR2 = bs2 >> 1;//shift 1 unit to right
	std::cout << "bs1 left: " << bsL1 << std::endl;
	std::cout << "bs1 right: " << bsR1 << std::endl;
	std::cout << "bs2 left: " << bsL2 << std::endl;
	std::cout << "bs2 right: " << bsR2 << std::endl;

	//Use std::hash to create hashed values
	std::hash<boost::dynamic_bitset<>> myhash;
	std::cout << "hash bs1: " << myhash(bs1) << std::endl;
	std::cout << "hash bs2: " << myhash(bs2) << std::endl;

	//create a bliteral
	auto blit = 0b1100;//A bi literal
	std::cout << "binary literal: " << blit << std::endl;
	boost::dynamic_bitset<> bslit(10,blit);
	std::cout << bslit << std::endl;
}

void test_bitset_3()
{
	//resize(), clear(), push_back(), pop_back() and append()
	boost::dynamic_bitset<> bs1(std::string("0100100011"));
	bs1.resize(15);//Resize to a bigger digits
	std::cout << "Resize to big: " << bs1 << std::endl;
	bs1.resize(5);//Resize to a smaller digits
	std::cout << "Resize to small: " << bs1 << std::endl;
	bs1.clear();//Size of the bitset to 0
	std::cout << "Size after cleared: " << bs1.size() << std::endl;
	bs1.resize(10);
	bs1.push_back(1);//Push_back
	std::cout << "Pushback: " << bs1 << std::endl;
	bs1.pop_back();//Pop_back
	std::cout << "Popback: " << bs1 << std::endl;
	bs1.append(31);//Append
	std::cout << "Append: " << bs1 << std::endl;
	//test is_subset_of
	boost::dynamic_bitset<> bs2(std::string("0101101111"));
	boost::dynamic_bitset<> bs3(std::string("0100100011"));
	std::cout << "Is bs3 subset of bs2? " << std::boolalpha << bs3.is_subset_of(bs2) << std::endl;//true
	std::cout << "Is bs2 subset of bs3? " << std::boolalpha << bs2.is_subset_of(bs3) << std::endl;//false
	boost::dynamic_bitset<> bs4(std::string("0000010010"));

	//find the first bit set
	std::cout << bs4<<", "<<bs4.find_first() << std::endl;//1
	//find the next bit set
	std::cout << bs4.find_next(2) << std::endl;//4

}

int main()
{
	test_bitset();
	test_bitset_2();
	test_bitset_3();
}