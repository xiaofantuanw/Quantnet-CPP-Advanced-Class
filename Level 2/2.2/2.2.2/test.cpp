//test.cpp
//Author: TengxiaoFan
//This is the test file for arrays catagories
#include <iostream>
#include <vector>
#include <array>
#include <type_traits>

class A {};

int main()
{
	//test for std::is_array
	std::cout << std::boolalpha;
	std::cout << std::is_array<void>::value << std::endl;//fundamental type, false
	std::cout << std::is_array<int>::value << std::endl;//fundamental, scalar, object, arithmetic type, false
	std::cout << std::is_array<int[]>::value << std::endl;//true
	std::cout << std::is_array<int[3]>::value << std::endl;//true
	std::cout << std::is_array<int&>::value << std::endl;//refrence, false
	std::cout << std::is_array<std::vector<int>>::value << std::endl;//false
	std::cout << std::is_array<std::array<int,4>>::value << std::endl;//false
	std::cout << std::is_array<A>::value << std::endl;//false
	std::cout << std::is_array<A[]>::value << std::endl<<std::endl;//true

	//test for rank and extent
	std::cout << std::rank<int[][3][4][5]>::value << std::endl;//rank=4
	std::cout << std::extent<int[][3][4][5], 0>::value << std::endl;//extent0: 0
	std::cout << std::extent<int[][3][4][5], 1>::value << std::endl;//extent1: 3
	std::cout << std::extent<int[][3][4][5], 2>::value << std::endl;//extent2: 4
	std::cout << std::extent<int[][3][4][5], 3>::value << std::endl << std::endl;//extent3: 5

	//test for remove_extent and remove_all_extents
	typedef std::remove_extent<int[][3][4][5]>::type TypeA;//int[3][4][5]
	typedef std::remove_all_extents<int[][3][4][5]>::type TypeB;//int
	std::cout << "Is TypeA int[3][4][5]? " << std::is_same<TypeA, int[3][4][5]>::value << std::endl;//True
	std::cout << "Is TypeB int? " << std::is_same<TypeB, int>::value << std::endl;//True
}