//test.cpp
// //Author: TengxiaoFan
//This is the test file for bitset and byte 
#include <iostream>
#include <bitset>

void test_bitset_byte()
{
	//Create two bitsets with the same num of bits
	std::bitset<10> bs1("0100100011");
	std::bitset<10> bs2("1101001101");
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
	std::hash<std::bitset<10>> myhash;
	std::cout << "hash bs1: " << myhash(bs1) << std::endl;
	std::cout << "hash bs2: " << myhash(bs2) << std::endl;

	//create a bliteral
	auto blit = 0b1100;//A bi literal
	std::cout << "binary literal: " << blit << std::endl;
	std::bitset<4> bslit(blit);
	std::cout << bslit << std::endl;


	//create a byte
	std::byte b1{ 0b1100 };//create a byte from binary literal
	std::cout << "byte 1: " << std::to_integer<int>(b1) << std::endl;
	std::byte b2{ 100 };//create a byte from integer
	std::cout << "byte 2: " << std::to_integer<int>(b2) << std::endl;
	std::byte b3{ b1 | b2 };//binary logical operators on existing bytes
	std::cout << "byte 3: " << std::to_integer<int>(b3) << std::endl;

	//bitwise operations
	std::byte bAND = b1 & b2;
	std::byte bOR = b1 | b2;
	std::cout << "byte AND: " << std::to_integer<int>(bAND) << std::endl;
	std::cout << "byte OR: " << std::to_integer<int>(bOR) << std::endl;

	//shift
	std::byte b1L = b1 << 1;
	std::byte b1R = b1 >> 1;
	std::cout << "byte left: " << std::to_integer<int>(b1L) << std::endl;
	std::cout << "byte right: " << std::to_integer<int>(b1R) << std::endl;
	std::byte b4{ 255 };//extreme cases
	std::cout << std::to_integer<int>(b4 >> 1) << std::endl;//127
	std::cout << std::to_integer<int>(b4 << 1) << std::endl;//254
	std::byte b5{ 0 };//extreme cases
	std::cout << std::to_integer<int>(b5 >> 1) << std::endl;//0
	std::cout << std::to_integer<int>(b5 << 1) << std::endl;//0
	//Application of bitset and byte
	//Statistics of big data
	//calculate the intersection and union of data
}

int main()
{
	test_bitset_byte();
}