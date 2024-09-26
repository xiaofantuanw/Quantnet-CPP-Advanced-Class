//test.cpp
//Author: TengxiaoFan
//This is the test program for basic functionalities of boost ublas dense vector
#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/io.hpp>
#include <algorithm>
#include <functional>
#include <iostream>

namespace ublas = boost::numeric::ublas;
int main()
{
	ublas::vector<double> v1(5);
	ublas::vector<double> v2(5);
	for (int i = 0;i < 5;i++)
	{//Use the indexing operators () and [] to access the elements of the vector.
		v1(i) = (double)i;
		v2[i] = 10 - (double)i;
	}
	//Use std::transform and std::multiply<> to multiply v1 and v2 to produce a vector v3.
	ublas::vector<double> v3(5);
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::multiplies<>());
	std::cout << v3 << std::endl;

	//Compute v1 += v2, v1 *= 2.5, v1 -= v3.
	v1 += v2;
	std::cout << v1<<std::endl;
	v1 *= 2.5;
	std::cout << v1 << std::endl;
	v1 -= v3;
	std::cout << v1 << std::endl;
	//Produce a scalar vector of size 100 all of whose values are equal to 5.0.
	ublas::scalar_vector<double> s1(100, 5.0);
	std::cout << s1 << std::endl;
}