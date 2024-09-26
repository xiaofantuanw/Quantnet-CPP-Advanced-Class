//test.cpp
//Author: TengxiaoFan
//This is the test function for different predicates
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void prtvec(const std::vector<int>& v)
{//To print a vector
	std::cout << "{ ";
	for (auto i = v.begin();i != v.end();i++)
	{
		std::cout << (*i) << ", ";
	}
	std::cout << "}\n";
}

class funcobj
{//A function object as predicate
private:
	int threshold;//Threshold
public:
	funcobj(int thres) :threshold(thres) {}
	bool operator() (double x)
	{
		return std::abs(x) > threshold;
	}
};

int main()
{
	int thres = 2;
	std::vector<int> vec{ 1,2,1,4,5,5,-1 };
	{//Use lambda function as predicates
		std::vector<int> tmp{}, result{};
		std::copy_if(vec.begin(), vec.end(), std::back_inserter(tmp), [&](int x) {return std::abs(x) > thres;});
		std::sort(tmp.begin(), tmp.end());
		std::unique_copy(tmp.begin(), tmp.end(), std::back_inserter(result));
		prtvec(result);
	}
	{//User-defined function objects
		funcobj o(thres);
		std::vector<int> tmp{}, result{};
		std::copy_if(vec.begin(), vec.end(), std::back_inserter(tmp), o);
		std::sort(tmp.begin(), tmp.end());
		std::unique_copy(tmp.begin(), tmp.end(), std::back_inserter(result));
		prtvec(result);
	}
	{//Predefined STL function objects
		using namespace std::placeholders;
		std::vector<int> tmp{}, result{};
		std::copy_if(vec.begin(), vec.end(), std::back_inserter(tmp), std::bind(std::greater<int>(), _1, thres));
		std::sort(tmp.begin(), tmp.end());
		std::unique_copy(tmp.begin(), tmp.end(), std::back_inserter(result));
		prtvec(result);
	}

	//Efficiency: lambda function is the fastest way to write the code
	//Maintain: self_designed object is easiest to maintain
	//Undersandability: I think I can understand all of them, but stl will be the clearest
}