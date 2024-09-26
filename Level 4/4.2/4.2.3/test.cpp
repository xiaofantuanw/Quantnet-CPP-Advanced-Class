//test.cpp
//Author: TengxiaoFan
//This file tests a lot of std algorithms
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <ranges>
#include <random>

template <typename T>
void prtvec(std::vector<T>& vec)
{
	std::cout << "{ ";
	for (auto it = vec.begin();it != vec.end();it++)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << "}\n";
}

int main()
{
	std::vector<double> vec{ 1.0,2.0,3.0,7.0,6.5,7.1,8.8,9.0,1.0,2.0 };

	//a. Scale all values by a given factor
	//C2. Modifying
	double fac = 2.0;
	std::transform(vec.begin(), vec.end(), vec.begin(), [&](double x) {return x * fac;});
	prtvec(vec);

	//b. Count the number of elements whose values are in a given range
	//C1. Nonmodifying
	auto count=std::count_if(vec.begin(), vec.end(), [](double x) {return (x < 7.0);});
	std::cout << count << std::endl;

	//c. Find the average, minimum and maximum values in a container.
	//C7. Numeric
	//C1. Nonmodifying
	std::cout << "Min: " << ( * std::min_element(vec.begin(), vec.end())) << std::endl;
	std::cout<<"Max: "<< (*std::max_element(vec.begin(), vec.end())) << std::endl;
	double avg = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
	std::cout << "Avg: " << avg << std::endl;

	//d. Find the first element that is (that is not) in a range.
	//C1. Nonmodifying
	auto result = std::find_if(vec.begin(), vec.end(), [](double x) {return (x < 15 && x>6);});
	if (result != vec.end())
		std::cout << (*result) << std::endl;
	else
		std::cout << "Not found";
	result = std::find_if_not(vec.begin(), vec.end(), [](double x) {return (x < 15 && x>6);});
	if (result != vec.end())
		std::cout << (*result) << std::endl;
	else
		std::cout << "Not found";

	//e. Search for all occurence
	//C1. Nonmodifying
	auto it = vec.begin();
	while (it != vec.end())
	{
		it=std::find(it, vec.end(), 2.0);
		if (it != vec.end())
		{
			std::cout << std::distance(vec.begin(), it) << "; ";
			it++;
		}
	}
	std::cout << std::endl;

	//f. Determine if the elements in two ranges are equal
	//C1. Nonmodifying
	std::cout<<std::boolalpha<<std::equal(vec.begin(),vec.end(), vec.begin(), vec.end()) << std::endl;

	//g. Determine if a set is some permutation of ¡®12345¡¯.
	//C1. Nonmodifying
	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<int> vec2{ 5,3,2,4,1 };
	std::cout << std::is_permutation(vec1.begin(), vec1.end(), vec2.begin())<<std::endl;
	
	//h. Is a container already sorted?
	//C1. Nonmodifying
	std::cout << std::is_sorted(vec.begin(), vec.end())<<std::endl;

	//i. Copy a container into another container.
	//C2. Modifying
	std::vector<double> container{};
	std::copy(vec.begin(), vec.end(), std::back_inserter(container));
	prtvec(container);

	//j. Move the last 5 elements of a container to the front
	//C2. Modifying
	auto startit = vec.end();
	for (int i = 0;i < 5;i++) startit--;
	std::move(startit, vec.end(), vec.begin());
	prtvec(vec);

	//k. Swap two ranges at a given position.
	//C2. Modifying
	std::swap_ranges(++startit, vec.end(), vec.begin());
	prtvec(vec);

	//l. Generate values in a container based on some formula.
	//C2. Modifying
	std::vector<int> vecgen(5);
	std::generate(vecgen.begin(), vecgen.end(), [n = 0]() mutable { return n++; });
	prtvec(vecgen);

	//m. Replace all uneven numbers by zero
	//C2. Modifying
	std::replace_if(vecgen.begin(), vecgen.end(), [](int x) {return x % 2;}, 0);
	prtvec(vecgen);

	//n.Remove all elements whose value is less than 10.
	//C2. Modifying
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](double x) {return x < 10;}),vec.end());
	prtvec(vec);

	//o. Shuffle a container randomly
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(vec.begin(), vec.end(), g);
	//pre C++11
	//std::random_shuffle(vec.begin(),vec.end(),g);
	prtvec(vec);

	//p. Compute one-sided divided differences of the values in a container.
	//C7. Numeric
	std::vector<double> Container2;
	std::adjacent_difference(vec.begin(), vec.end(), std::back_inserter(Container2));
	prtvec(Container2);
}