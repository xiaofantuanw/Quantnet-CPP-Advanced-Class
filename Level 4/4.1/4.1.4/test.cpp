//test.cpp
//Author: TengxiaoFan
//This is the test file for Bitmap
#include "Proposition.hpp"
#include "Matrix.hpp"
#include <array>
#include <bitset>
#include <string>

using value_type = Proposition; 
template <int NR, int NC> 
using BitMap = Matrix<value_type, NR, NC>;

template <int NR, int NC> 
using BitMap2 = std::array<std::bitset<NC>, NR>;

using BitFunction = std::function <Proposition(const Proposition&, const Proposition&)>;

template <int NR, int NC>
void PrintBM2(const BitMap2<NR,NC>& bm2)
{
	for (int i = 0;i < NR;i++)
	{
		for (int j = 0;j < NC;j++)
		{
			std::cout << bm2[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

template <int NR, int NC> 
BitMap<NR, NC> mask(const BitMap<NR, NC>& bm1, const BitMap<NR, NC>& bm2, const BitFunction& masker)
{
	BitMap<NR, NC> result;
	for (int i = 0;i < NR;i++)
	{
		for (int j = 0;j < NC;j++)
		{
			result[i][j] = masker(bm1[i][j], bm2[i][j]);//Mask the two bitmap
		}
	}
	return result;
}

template <int NR,int NC>
void SetRow(BitMap2<NR, NC>& bm, int row, std::string str)
{//Set the row of a BitMap2
	std::bitset<NC> bs(str);
	bm[row] = bs;
	//PrintBM2(bm);
}

int main()
{
	//Create instance of BitMap and BitMap2, print them.
	BitMap<3, 5> bm1(1);
	bm1.Print();
	BitMap2<3, 5> b1;
	b1[1][3] = 1;
	PrintBM2(b1);
	//Test the function mask using different boolean operators
	BitMap<3, 5> bm(true); 
	bm[2][1] = false;
	bm.Print();
	//Different binary functions
	auto COND = [](const Proposition& p1, const Proposition& p2) { return p1 % p2; };
	auto AND = [](const Proposition& p1, const Proposition& p2) { return p1 & p2; };
	auto OR = [](const Proposition& p1, const Proposition& p2) { return p1 | p2; };
	auto XOR = [](const Proposition& p1, const Proposition& p2) { return p1 ^ p2; };
	auto BICOND = [](const Proposition& p1, const Proposition& p2) { return p1 %= p2; };
	//Test binary functions
	BitMap<3, 5> result;
	result = mask(bm, bm1, COND);
	result.Print();
	result = mask(bm, bm1, AND);
	result.Print();
	result = mask(bm, bm1, OR);
	result.Print();
	result = mask(bm, bm1, XOR);
	result.Print();
	result = mask(bm, bm1, BICOND);
	result.Print();
	//Set a row of BitMap and BitMap2
	//BitMap
	bm[1][2] = bm[1][3] = bm[1][4] = false;
	bm.Print();
	//BitMap2, easier
	SetRow(b1, 0, "01110");
	PrintBM2(b1);
}