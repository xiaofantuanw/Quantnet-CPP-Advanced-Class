//test.cpp
//Author: TengxiaoFan
//This is the test program for proxies to matrices
#include<boost/numeric/ublas/vector.hpp>
#include<boost/numeric/ublas/matrix_proxy.hpp>
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/io.hpp>
#include <algorithm>
#include <functional>
#include <iostream>

namespace ublas = boost::numeric::ublas;
int main()
{
	ublas::matrix<double> mat1(6, 7);
	//Use the operator () to access and modify the elements of matrices.
	for (int i = 0;i < mat1.size1();i++)
	{
		for (int j = 0;j < mat1.size2();j++)
		{//modify the elements
			mat1(i, j) = i + j;
		}
	}

	//matrix_row: a given row of a matrix (one-dimensional).
	ublas::matrix_row<ublas::matrix<double>> mr(mat1, 1);
	std::cout << mr << std::endl;
	//matrix_column: a given column of a matrix (one-dimensional).
	ublas::matrix_column<ublas::matrix<double>> mc(mat1, 3);
	std::cout << mc << std::endl;
	//matrix_range: a submatrix of a matrix(two - dimensional).
	ublas::matrix_range<ublas::matrix<double>> mrange(mat1, ublas::range(0, 3), ublas::range(0, 2));
	std::cout << mrange << std::endl;
	//matrix_slice: allows addressing a sliced sub matrix of a matrix.
	ublas::matrix<double> m(3, 3, 2); 
	ublas::matrix_slice<ublas::matrix<double> > ms(m, ublas::slice(0, 1, 3), ublas::slice(0, 1, 3));
	std::cout << ms << std::endl;
}