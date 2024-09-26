//test.cpp
//Author: TengxiaoFan
//This is the test program for basic functionalities of boost ublas sparse and triangular matrix
#include<boost/numeric/ublas/matrix.hpp>
#include<boost/numeric/ublas/matrix_sparse.hpp>
#include<boost/numeric/ublas/triangular.hpp>
#include<boost/numeric/ublas/io.hpp>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>	
#include <complex>

namespace ublas = boost::numeric::ublas;
int main()
{
	//Test of sparse matrix
	ublas::mapped_matrix<std::complex<double>> mat1(6, 7);
	//Insertion
	mat1.insert_element(3, 4, std::complex<double>(1, 1));
	mat1.insert_element(5, 0, std::complex<double>(2, 1));
	std::cout << mat1 << std::endl;
	//erasure
	mat1.erase_element(3, 4);
	std::cout << mat1 << std::endl;
	//clear
	mat1.clear();
	std::cout << mat1 << std::endl;

	//Test of triangular matrix
	ublas::triangular_matrix<double> mat2(5, 5);
	ublas::triangular_matrix<double,ublas::upper,ublas::column_major,std::vector<double>> mat3(5, 5);
	ublas::triangular_matrix<double, ublas::strict_upper, ublas::row_major, std::vector<double>> mat4(5, 5);

	for (int i = 0;i < mat2.size1();i++)
	{//set the matrix
		for (int j = 0;j <= i;j++)
		{
			mat2(i, j) = i + 2 * j;
			mat3(j, i) = j + 3 * i;
			if (j != i)
				mat4(j, i) = j + i;
		}
	}
	std::cout << mat2 << std::endl << mat3 << std::endl << mat4 << std::endl;

	//test of triangular view
	ublas::matrix<double> m(3, 3,2);
	ublas::triangular_adaptor<ublas::matrix<double>, ublas::lower> tal(m);//adapted to a lower triangular
	std::cout << tal << std::endl;
	ublas::triangular_adaptor<ublas::matrix<double>, ublas::upper> tau(m);//adapted to an upper triangular
	std::cout << tau << std::endl;
}