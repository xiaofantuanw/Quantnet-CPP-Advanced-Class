//test.cpp
//Author: TengxiaoFan
//This is the test file for some wrapped functions to find the range
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/io.hpp>

using Range = std::tuple<std::size_t, std::size_t>;
using Result = std::tuple<Range, bool>;
using Result2 = std::tuple<std::size_t, bool>;
namespace ublas = boost::numeric::ublas;

template <typename T>
Result find_if_greater(const ublas::vector<T>& v, T x)
{//Find the range where x is in, using find_if.
	auto it = std::find_if(v.begin(), v.end(), [&](T t) {return t > x;});
	if (it != v.end())
	{//Found
		auto dis = std::distance(v.begin(), it);
		Range rg = std::make_tuple(dis - 1, dis);
		return std::make_tuple(rg, true);
	}
	else
	{//Not found
		return std::make_tuple(std::make_tuple(999, 999), false);
	}
}

template <typename T>
Result find_ifnot_greater(const ublas::vector<T>& v, T x)
{//Find the range where x is in, using find_if_not.
	auto it = std::find_if_not(v.begin(), v.end(), [&](T t) {return t <= x;});
	if (it != v.end())
	{//found
		auto dis = std::distance(v.begin(), it);
		Range rg = std::make_tuple(dis - 1, dis);
		return std::make_tuple(rg, true);
	}
	else
	{//not found
		return std::make_tuple(std::make_tuple(999, 999), false);
	}
}

template<typename T>
Result2 find_index(const ublas::vector<T>& v, T x)
{//find the index where x equals to
	auto it = std::find(v.begin(), v.end(), x);
	if (it != v.end())
	{//found
		auto dis = std::distance(v.begin(), it);
		return std::make_tuple(dis, true);
	}
	else
	{//not found
		return std::make_tuple(999, false);
	}
}

template <typename T>
Result find_lb_greater(const ublas::vector<T>& v, T x)
{//Find the range where x is in, using lower_bound.
	auto it = std::lower_bound(v.begin(), v.end(), x);
	if (*it == x)
	{//Exclude equality case
		it++;
	}
	if (it != v.end())
	{//found
		auto dis = std::distance(v.begin(), it);
		Range rg = std::make_tuple(dis - 1, dis);
		return std::make_tuple(rg, true);
	}
	else
	{//not found
		return std::make_tuple(std::make_tuple(999, 999), false);
	}
}

template <typename T>
Result find_ub_greater(const ublas::vector<T>& v, T x)
{//Find the range where x is in, using upper_bound.
	auto it = std::upper_bound(v.begin(), v.end(), x);
	if (it != v.end())
	{//found
		auto dis = std::distance(v.begin(), it);
		Range rg = std::make_tuple(dis - 1, dis);
		return std::make_tuple(rg, true);
	}
	else
	{//not found
		return std::make_tuple(std::make_tuple(999, 999), false);
	}
}

template <typename T>
Result find_er_greater(const ublas::vector<T>& v, T x)
{//Find the range where x is in, using equal_range.
	auto p = std::equal_range(v.begin(), v.end(), x);
	auto it = std::get<1>(p);//Get the upper bound
	if (it != v.end())
	{//found
		auto dis = std::distance(v.begin(), it);
		Range rg = std::make_tuple(dis - 1, dis);
		return std::make_tuple(rg, true);
	}
	else
	{//not found
		return std::make_tuple(std::make_tuple(999, 999), false);
	}
}

int main()
{
	//Build the vector
	ublas::vector<double> v(4);
	
	v(0)=(1.5);
	v(1)=(3.4);
	v(2)=(7.0);
	v(3)=(5.0);
	//Sort
	std::sort(v.begin(), v.end());
	//Test the results
	std::cout << std::boolalpha;
	Result r = find_if_greater<double>(v, 5.5);
	std::cout << std::get<1>(r) << ", " << "( " << std::get<0>(std::get<0>(r)) << ", " << std::get<1>(std::get<0>(r)) << " )" << std::endl;
	r = find_ifnot_greater<double>(v, 1.5);
	std::cout << std::get<1>(r) << ", " << "( " << std::get<0>(std::get<0>(r)) << ", " << std::get<1>(std::get<0>(r)) << " )" << std::endl;
	r = find_lb_greater<double>(v, 3.4);
	std::cout << std::get<1>(r) << ", " << "( " << std::get<0>(std::get<0>(r)) << ", " << std::get<1>(std::get<0>(r)) << " )" << std::endl;
	r = find_ub_greater<double>(v, 7.0);
	std::cout << std::get<1>(r) << ", " << "( " << std::get<0>(std::get<0>(r)) << ", " << std::get<1>(std::get<0>(r)) << " )" << std::endl;
	r = find_er_greater<double>(v, 5.5);
	std::cout << std::get<1>(r) << ", " << "( " << std::get<0>(std::get<0>(r)) << ", " << std::get<1>(std::get<0>(r)) << " )" << std::endl;
	Result2 r2 = find_index<double>(v, 3.1);
	std::cout << std::get<1>(r2) << ", " << std::get<0>(r2) << std::endl;

}