//test.cpp
//Author: TengxiaoFan
//This is the test file for self-created class BitMatrix
#include "BitMatrix.cpp"
#include <iostream>

int main()
{
	BitMatrix<3, 5> bm1,bm2;
	std::cout << bm1 << std::endl;//test the output operator
	bm1.set(0);//set a row
	std::cout << bm1 << std::endl;
	bm1.set();//set all
	std::cout << bm1 << std::endl;
	bm1.reset(2);//reseta row
	std::cout << bm1 << std::endl;
	bm1.reset();//reset all
	std::cout << bm1 << std::endl;
	bm1.flip(1);//flip a row
	std::cout << bm1 << std::endl;
	bm1.flip();//flip all
	std::cout << bm1 << std::endl;
	std::cout << std::boolalpha;
	std::cout << "Matrix None? " << bm1.none() << std::endl;//false
	std::cout << "Row 1 None? " << bm1.none(1) << std::endl;//true
	std::cout << "Matrix Any? " << bm1.any() << std::endl;//true
	std::cout << "Row 0 Any? " << bm1.any(0) << std::endl;//true
	std::cout << "Matrix All? " << bm1.all() << std::endl;//false
	std::cout << "Row 2 All? " << bm1.all(2) << std::endl;//true
	std::cout << "Num of bits set: " << bm1.count() << std::endl;//10
	std::cout << "Num of bits set for row 0: " << bm1.count(0) << std::endl;//5
	std::cout <<std::noboolalpha<< "One of the elements: " << bm1[2][3] << std::endl;//access element
	//Test XOR OR AND operations
	auto bmXOR = bm1 ^ bm2;
	auto bmOR = bm1 | bm2;
	auto bmAND = bm1 & bm2;
	std::cout << bmXOR << std::endl;
	std::cout << bmOR << std::endl;
	std::cout << bmAND << std::endl;

}