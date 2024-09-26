//test.cpp
// //Author: tengxiaofan
//This is the test file for vector<bool>
#include <vector>
#include <iostream>
#include <bitset>

std::vector<bool> Intersect(std::vector<bool> vb1, std::vector<bool> vb2)
{
	//Create a function to compute the intersection of two instances
	std::vector<bool> result = vb1;
	for (int i=0;i<result.size();i++)
	{
		result[i] = (vb1 == vb2);//intersection
	}
	return result;
}

int main()
{
	std::vector<bool> vb1={1,0,1,1,0,1},vb2={0,1,0,0,1,0};
	for (auto elem : vb1)
	{
		std::cout << elem ;
	}
	std::cout << std::endl;
	//vb1 = ~vb1;//cannot toggle
	//auto vbXOR = vb1 ^ vb2;//no XOR operator
	//auto vbOR = vb1 | vb2;//no OR operator
	//auto vbAND=vb1&vb2//no AND operator
	//auto vbL = vb1 << 1;//no leftward move
	//auto vbL = vb1 << 1;//no rightward move
	vb1.flip();//flip the vector
	for (auto elem : vb1)
	{
		std::cout << elem;
	}
	std::cout << std::endl;

	//vb1.set();vb1.reset()//No set or reset
	//no to_string or to_ulong
	std::cout << "Size: " << vb1.size() << std::endl;//size
	std::cout << "Same? " << std::boolalpha<<(vb1 == vb2) << std::endl;//compare
	std::hash<std::vector<bool>> myhash;
	std::cout <<std::noboolalpha<< "Hash: " << myhash(vb1)<<std::endl;//set hash

	auto inter = Intersect(vb1, vb2);//111111
	for (auto elem : inter)
	{
		std::cout << elem;
	}
	std::cout << std::endl;
}