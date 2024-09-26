//Matrix.cpp
// Author: TengxiaoFan
//This is the test file for compile time matrix class
#ifndef Matrix_HPP
#define Matrix_HPP
#include <iostream>
#include <functional>
#include <algorithm>
#include <array>
#include "Vector.hpp"

template<typename T, int NR, int NC> 
class Matrix
{
private:
	std::array<std::array<T, NC>, NR> arr;//Private data member, use array, determined at compile time
public:
	//Constructors
	Matrix() = default;//default consturctor
	Matrix(const T& value)
	{//Constructor with value
		for (int i = 0;i < NR;i++)
		{
			for (int j = 0;j < NC;j++)
				arr[i][j] = value;
		}
	}
	Matrix(const Matrix<T,NR,NC> & source) = default;//Default copy ctor

	//Element access operator
	std::array<T, NC>& operator[] (int index)
	{
		return arr[index];
	}
	//Element access operator- const ver.
	const std::array<T, NC>& operator[] (int index) const
	{
		return arr[index];
	}

	//Add
	Matrix<T,NR,NC> operator + (const Matrix<T,NR,NC>& vec) const
	{
		Matrix<T, NR,NC> result;
		for (int i = 0;i < NR;i++)
		{
			for (int j=0;j<NC;j++)
				result.arr[i][j] = vec.arr[i][j] + arr[i][j];
		}
		return result;
	}

	//Subtraction
	Matrix<T, NR, NC> operator - (const Matrix<T, NR, NC>& vec) const
	{
		Matrix<T, NR, NC> result;
		for (int i = 0;i < NR;i++)
		{
			for (int j = 0;j < NC;j++)
				result.arr[i][j] = -vec.arr[i][j] + arr[i][j];
		}
		return result;
	}

	//Unary Minus
	Matrix<T, NR, NC> operator - () const
	{
		Matrix<T, NR, NC> result;
		for (int i = 0;i < NR;i++)
		{
			for (int j = 0;j < NC;j++)
				result.arr[i][j] =  - arr[i][j];
		}
		return result;
	}

	//Scalar Multiplication
	template <typename T, int NR,int NC, typename F> 
	friend Matrix<T, NR, NC> operator * (const F& a, const Matrix<T, NR, NC>& pt);

	//Modifier
	void modify(const std::function<T(T&)>& f)
	{
		for (int i = 0;i < NR;i++)
		{
			for (int j=0;j<NC;j++)
				arr[i][j] = f(arr[i][j]);
		}
	}

	//Print the vector
	void Print()
	{
		for (int i = 0;i < NR;i++)
		{
			for (int j = 0;j < NC;j++)
			{
				std::cout << arr[i][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout<<"\n";
	}

	void SetRow(int index, std::array<T, NC> a)
	{
		arr[index] = a;
	}
};

template <typename T, int NR, int NC, typename F>
Matrix<T, NR, NC> operator * (const F& a, const Matrix<T, NR, NC>& pt)
{
	Matrix<T, NR, NC> result;
	for (int i = 0;i < NR;i++)
	{
		for (int j = 0;j < NC;j++)
			result.arr[i][j] = a * pt.arr[i][j];
	}
	return result;
}
#endif // !Vector_HPP
