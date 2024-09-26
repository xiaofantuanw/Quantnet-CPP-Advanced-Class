//test.cpp
//Author: TengxiaoFan
//This is the test file for some mutating algorithms
#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void prtvec(const std::vector<T>& v)
{//To print a vector
	std::cout << "{";
	for (auto i = v.begin();i != v.end();i++)
	{
		std::cout << (*i) << ",";
	}
	std::cout << "}";
}

void prtPowerSet(std::vector<std::vector<int>> v)
{
	std::cout << "{";
	for (auto i = v.begin();i != v.end();i++)
	{
		prtvec(*i);
		std::cout << ",";
	}
	std::cout << "}\n";
}

std::vector<std::vector<int>> PowerSet(const std::vector<int>& vec)
{//Output the power set of a vector
	if (vec.size() > 1)
	{//Recursion
		std::vector<int> subvec;
		auto it = vec.begin();
		++it;
		std::copy(it, vec.end(), std::back_inserter(subvec));
		std::vector<std::vector<int>> result = PowerSet(subvec);
		auto size = result.size();
		for (int i = 0;i < size;i++)
		{
			auto set = result[i];
			set.push_back(*vec.begin());//Push the recursive element
			result.push_back(set);
		}
		return result;
	}
	else
	{//End of recursion
		std::vector<std::vector<int>> result{ vec,std::vector<int>{} };
		return result;
	}
}

int main()
{
	std::vector<int> S = { 1,-1,7,8,9,10 };
	std::vector<int> S2,S3;
	//Reverse S as a modifier option and copy to a second container.
	std::reverse_copy(S.begin(), S.end(), std::back_inserter(S2));
	prtvec(S2);std::cout << "\n";
	//Rotate S so that the value 8 is the beginning of the container.
	auto pivot = std::find(S.begin(), S.end(), 8);
	std::rotate_copy(S.begin(), pivot, S.end(), std::back_inserter(S3));
	prtvec(S3);std::cout << "\n";
	//Power set
	auto result = PowerSet(S);
	prtPowerSet(result);
	//Move the elements to the front
	std::swap_ranges(S.begin(), pivot, pivot);
	prtvec(S);
}