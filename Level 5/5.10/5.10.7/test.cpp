//test.cpp
//Author: TengxiaoFan
//This is the test program for some vector and matrix expressions
#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/operation.hpp>
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include <algorithm>
#include <functional>
#include <iostream>

namespace ublas = boost::numeric::ublas;
int main()
{
	//Initialize
	ublas::vector<double> v1(5);
	ublas::vector<double> v2(5);
	for (int i = 0;i < 5;i++)
	{//Use the indexing operators () and [] to access the elements of the vector.
		v1(i) = (double)i;
		v2[i] = 10 - (double)i;
	}

	ublas::matrix<double> mat1(6, 5);
	//Use the operator () to access and modify the elements of matrices.
	for (int i = 0;i < mat1.size1();i++)
	{
		for (int j = 0;j < mat1.size2();j++)
		{//modify the elements
			mat1(i, j) = i + j;
		}
	}

	//Inner and outer products of two vectors.
	//Inner prod
	std::cout << ublas::inner_prod(v1, v2) << std::endl;
	//Outer prod
	std::cout << ublas::outer_prod(v1, v2) << std::endl;//A matrix

	//Adding and subtracting two vectors.
	//Add
	std::cout << v1 + v2 << std::endl;
	//Subtract
	std::cout << v1 - v2 << std::endl;

	//The Euclidean, L1 and max norm of a vector.
	//Euclidean norm
	std::cout << ublas::norm_2(v1) << std::endl;
	//L1 norm
	std::cout << ublas::norm_1(v1) << std::endl;
	//max norm
	std::cout << ublas::norm_inf(v1) << std::endl;
	
	//L1 and max norms of a matrix.
	//L1 norm
	std::cout << ublas::norm_1(mat1) << std::endl;
	//max norm
	std::cout << ublas::norm_inf(mat1) << std::endl;

	//The product of a matrix and a vector.
	ublas::vector<double> w(6);
	ublas::axpy_prod(mat1, v1, w);
	std::cout << w << std::endl;
}