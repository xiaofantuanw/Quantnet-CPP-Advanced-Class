//test.cpp
//This is the test file for inner and outer products
#include "Vector.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <complex>

//Wrapper for std::innerproduct
template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue)
{
	//std::cout << (*v1.begin()) << std::endl;
	return std::inner_product(v1.begin(),v1.end(),v2.begin(), initValue);
}

template <typename T>
using BinaryFunction = std::function < T(const T& t1, const T& t2)>;
//Wrapper for std::innerproduct
template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue, const BinaryFunction<T>& op1, const BinaryFunction<T>& op2)
{
	return std::inner_product(v1.begin(), v1.end(), v2.begin(), initValue, op1,op2);
}

//Outer product
template<typename T,int NR, int NC>
Matrix<T, NR, NC> OuterProduct(const Vector<T, NR>& v1, const Vector<T, NC>& v2)
{
	Matrix<T, NR, NC> mat;//result matrix
	for (int it = 0;it<NR;it++)
	{
		std::array<T, NC> v;
		T value = v1[it];
		//Transform the line
		std::transform(v2.begin(), v2.end(), v.begin(), [&](T t) {return value * t;});
		mat.SetRow(it, v);
	}
	return mat;
}

//Outer product template for complex type
template<typename T,int NR, int NC>
Matrix<std::complex<T>, NR, NC> OuterProduct(const Vector<std::complex<T>, NR>& v1, const Vector<std::complex<T>, NC>& v2)
{
	Matrix<std::complex<T>, NR, NC> mat;
	for (int it = 0;it < NR;it++)
	{
		std::array<std::complex<T>, NC> v;
		std::complex<T> value = v1[it];
		//Conjunction!
		std::transform(v2.begin(), v2.end(), v.begin(), [&](std::complex<T> t) {return value * std::conj(t);});
		mat.SetRow(it, v);
	}
	return mat;
}


int main()
{
	//Test of inner products & outer products of double
	Vector<double, 5> vec1(5.0);
	Vector<double, 5> vec2(2.5);
	Vector<double, 4> vec3(3.0);
	vec3[0] = 4;
	std::cout<<inner_product<double, 5>(vec1, vec2, 0) <<std::endl;
	BinaryFunction<double> Reduceop = [](const double& t1, const double& t2) {return t1 + t2;};
	BinaryFunction<double> Transformop = [](const double& t1, const double& t2) {return t1 * t2;};
	std::cout << inner_product<double,5>(vec1, vec2, 0, Reduceop, Transformop)<<std::endl;
	OuterProduct(vec1, vec3).Print();

	//Test of inner products & outer products of std::complex<double> 
	Vector<std::complex<double>, 5> vec4(std::complex<double>(1.0, 2.0));
	vec4.Print();
	Vector<std::complex<double>, 5> vec5(std::complex<double>(1.0, 1.0));
	std::cout << inner_product<std::complex<double>, 5>(vec4, vec5, 0) << std::endl;
	OuterProduct(vec4, vec5).Print();

}