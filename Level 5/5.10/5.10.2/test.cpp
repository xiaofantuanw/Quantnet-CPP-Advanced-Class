//test.cpp
//Author: TengxiaoFan
//This is the test program for basic functionalities of boost ublas dense matrix
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include <algorithm>
#include <functional>
#include <iostream>


namespace ublas = boost::numeric::ublas;
int main()
{
	ublas::matrix<double> mat1(6, 7);
	//Stored in bounded array, column major order
	ublas::matrix<double, ublas::column_major, ublas::bounded_array<double, 6*7>> mat2(6, 7);

	//Use the operator () to access and modify the elements of matrices.
	for (int i = 0;i < mat1.size1();i++)
	{
		for (int j = 0;j < mat1.size2();j++)
		{//modify the elements
			mat1(i, j) = i + j;
			mat2(i, j) = i * j;
		}
	}
	//Output
	std::cout << mat1 << std::endl;
	std::cout << mat2 << std::endl;
	//Add and subtract matrices.
	std::cout << mat1 + mat2 << std::endl;
	std::cout << mat1 - mat2 << std::endl;

	//Resize the matrix
	mat1.resize(2, 5);
	std::cout << mat1 << std::endl;
	//mat1.resize(9, 9);
	//std::cout << mat1 << std::endl;

	//Identity and zero matrices
	ublas::identity_matrix<double> I(3);
	ublas::zero_matrix<double> Z(3,4);
	std::cout << I << std::endl;
	std::cout << Z << std::endl;
}
