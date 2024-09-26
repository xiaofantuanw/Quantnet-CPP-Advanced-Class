//test.cpp
//Author: TengxiaoFan
//This program tests some of the nonmodifying std algorithms
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <numeric>
#include <functional>

template <typename T>
std::vector<std::tuple<T, int>> count_frequency(const std::vector<T>& vec)
{//This function gives a vector of elements and their count
	std::vector<std::tuple<T, int>> result;
	for (auto it = vec.begin();it != vec.end();it++)
	{
		if (std::find(vec.begin(), it, (*it)) == it)
		{
			std::tuple <T, int> tmp = std::make_tuple((*it), (int)std::count(vec.begin(), vec.end(), (*it)));
			result.push_back(tmp);
		}
	}
	return result;
}

template <typename T>
void prttuplevec(const std::vector<std::tuple<T, int>>& v)
{//Print the result
	std::cout << "{";
	for (auto it = v.begin();it != v.end();it++)
	{
		std::cout << "{" << std::get<0>(*it) << ", " << std::get<1>(*it) << "}, ";
	}
	std::cout << "}\n";
}

template <typename T>
std::tuple<T, T, T, double> statistics(const std::vector<T>& v)
{//Make a tuple of minimum, maximum, sum and average
	T min, max, sum;
	double avg;
	min = (*std::min_element(v.begin(), v.end()));
	max = (*std::max_element(v.begin(), v.end()));
	sum = std::accumulate(v.begin(), v.end(), 0);
	avg = (double)sum / v.size();
	return std::make_tuple(min, max, sum, avg);
}

template <typename T>
void prttuple(std::tuple<T, T, T, double> result)
{
	std::cout << "{ " << std::get<0>(result) << ", " << std::get<1>(result) << ", " << std::get<2>(result) << ", " << std::get<3>(result) << " }" << std::endl;
}

bool mod(int x, int y) 
{ //mod function
	return x % y == 0; 
}

int main()
{
	using namespace std::placeholders;
	//Count the frequencies
	std::vector<int> vec = { 1,2,4,5,4,1 };
	auto result = count_frequency(vec);
	prttuplevec(result);
	//Return the statistics
	auto result2 = statistics(vec);
	prttuple(result2);

	//Find the position of the first 5 in the vector
	std::vector<int> S = { 1,2,-3,4,5,5,5,6 };
	auto pos = std::find(S.begin(), S.end(), 5);
	auto dis = std::distance(S.begin(), pos);
	std::cout << "First 5: " << dis << std::endl ;
	//Find the first even number (3 ways)
	//bind2nd
	auto b1 = std::bind2nd(std::ptr_fun(mod), 2);
	pos = std::find_if(S.begin(), S.end(), b1);
	dis = std::distance(S.begin(), pos);
	std::cout << "First even (bind2nd): " << dis << std::endl;
	//bind
	auto b2 = std::bind(mod, _1, 2);
	pos = std::find_if(S.begin(), S.end(), b2);
	dis = std::distance(S.begin(), pos);
	std::cout << "First even (bind): " << dis << std::endl;
	//lambda
	pos = std::find_if(S.begin(), S.end(), [](int x) {return x % 2 == 0;});
	dis = std::distance(S.begin(), pos);
	std::cout << "First even (lambda): " << dis << std::endl;

	std::vector<int> S2 = { 1,2,5,5,-3,4,5,5,5,6,3,4,5 };
	//Return the position of the first three consecutive elements having the value 5.
	pos=std::search_n(S2.begin(), S2.end(), 3, 5);
	std::cout << "First three consecutive elements having the value 5: " << std::distance(S2.begin(), pos)<<std::endl;
	//Return the position of the first element of the first subrange matching {3,4,5}.
	int sub[] = { 3,4,5 };
	pos = std::search(S2.begin(), S2.end(), sub, sub+3);
	std::cout << "First element of the first subrange matching {3,4,5}: " << std::distance(S2.begin(), pos) << std::endl;
	//Return the position of the first element of the last subrange matching {3,4,5}.
	pos = std::find_end(S2.begin(), S2.end(), sub, sub + 3);
	std::cout << "First element of the last subrange matching {3,4,5}: " << std::distance(S2.begin(), pos) << std::endl;
	//Find the first element in S that has a value equal to the value of the following element.
	pos = std::adjacent_find(S2.begin(), S2.end());
	std::cout << "First element in S that has a value equal to the value of the following element: " << std::distance(S2.begin(), pos) << std::endl;
	//Determine whether the elements in S1 are equal to the elements in S.
	std::vector<int> S1 = { 1,2,5 };
	bool equal = true;
	for (auto elem : S1)
	{
		if (std::find(S2.begin(), S2.end(), elem) == S2.end())
		{
			equal = false;
			break;
		}
	}
	std::cout << "Whether the elements in S1 are equal to the elements in S: " << std::boolalpha << equal << std::endl;

}