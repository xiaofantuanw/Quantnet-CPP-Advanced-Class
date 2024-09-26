//test.cpp
//Author: TengxiaoFan
//This is a test program for a simple vector space, using type traits to realize.
#include <type_traits>
#include <vector>
#include <array>
#include <iostream>
#include <complex>

template <typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type)
{//This is the addition for vector or array
	T t = t1;
	for (int i = 0;i < t1.size();i++)
	{
		t[i] += t2[i];
	}
	return t;
}
template <typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type)
{//This is the addition for scalar
	return (t1 + t2);
}

template <typename T> 
T Addition(const T& t1, const T& t2) 
{ // Vector space addition
	// Best(?) approximation to testing for an array 
	return Addition_impl(t1, t2, std::is_compound<T>()); 
}

template <typename T>
void AdditiveInverse_impl(T& val, std::true_type)
{//This is the additive inverse for vector or array
	for (int i = 0;i < val.size();i++)
	{
		val[i]=-val[i];
	}
}
template <typename T>
void AdditiveInverse_impl(T& val, std::false_type)
{//This is the additive inverse for scalar
	val = -val;
}

template <typename T> 
void AdditiveInverse(T& val) 
{ 
	// val -> -val for a scalar or a vector
	AdditiveInverse_impl(val, std::is_compound<T>());
}

template <typename ScalarT, typename VectorT>
VectorT ScalarMultiply(const ScalarT& t1, const VectorT& t2)
{ // Vector space scalar multiply
	// Best(?) approximation to testing for an array 
	VectorT t = t2;
	for (int i = 0;i < t2.size();i++)
	{
		t[i] *= t1;
	}
	return t;
}


int main()
{
	//Test the functions with double, array and vector
	double a = 5.0, b = 10.0;
	std::array<double,3> arraya = { 1.0,2.0,3.0 },arrayb={4.0,5.0,6.0};
	std::vector<double> veca = { 1.0,2.0,3.0 }, vecb = { 2.0,4.0,6.0 };

	//Test the addition function
	std::cout << "Addition of doubles: "<<Addition(a, b) << std::endl;
	auto array0 = Addition(arraya, arrayb);
	std::cout << "Addtion of arrays: {"<<array0[0]<<", "<<array0[1]<<", " << array0[2] << "}" << std::endl;
	auto vec0 = Addition(veca, vecb);
	std::cout << "Addtion of vectors: {" << vec0[0] << ", " << vec0[1] << ", " << vec0[2] << "}" << std::endl;

	//Test of additive inverse
	AdditiveInverse(a);
	AdditiveInverse(arraya);
	AdditiveInverse(veca);
	std::cout << "Additive inverse of double a: " << a << std::endl;
	std::cout << "Addtive inverse of array a: {" << arraya[0] << ", " << arraya[1] << ", " << arraya[2] << "}" << std::endl;
	std::cout << "Addtive inverse of vector a: {" << veca[0] << ", " << veca[1] << ", " << veca[2] << "}" << std::endl;

	//Test of Scalar Multiplication
	auto array1=ScalarMultiply(a, arrayb);
	auto vec1=ScalarMultiply(b, veca);
	std::cout<<"a*arrayb: {" << array1[0] << ", " << array1[1] << ", " << array1[2] << "}" << std::endl;
	std::cout << "b*veca: {" << vec1[0] << ", " << vec1[1] << ", " << vec1[2] << "}" << std::endl;

	//Test for std::complex<double>
	std::complex<double> c1(1, 1), c2(2, 2);
	std::vector<std::complex<double>> vc = { c1,c2 };
	std::cout << "Addition: {" << Addition(vc, vc)[0] <<", "<< Addition(vc, vc)[1]<<"}" << std::endl;
	AdditiveInverse(vc);
	std::cout << "Additive inverse: {"<<vc[0] << ", " << vc[1] << "}" << std::endl;
	std::cout<<"Scalar Multiply: {"<<ScalarMultiply(3,vc)[0]<<", " << ScalarMultiply(3, vc)[1] << "}" << std::endl;
}