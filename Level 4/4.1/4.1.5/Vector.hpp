//Vector.cpp
// Author: TengxiaoFan
//This is the test file for compile time vector class
#ifndef Vector_HPP
#define Vector_HPP
#include <iostream>
#include <functional>
#include <algorithm>
#include <array>

template<typename T, int N> 
class Vector
{
private:
	std::array<T,N> arr;//Private data member, use array, determined at compile time
public:
	//Constructors
	Vector() = default;//default consturctor
	Vector(const T& value)
	{//Constructor with value
		for (int i = 0;i < N;i++)
			arr[i] = value;
	}
	Vector(const Vector<T,N> & source) = default;//Default copy ctor

	//Element access operator
	T& operator[] (int index)
	{
		return arr[index];
	}
	//Element access operator- const ver.
	const T& operator[] (int index) const
	{
		return arr[index];
	}

	//Add
	Vector<T,N> operator + (const Vector<T,N>& vec) const
	{
		Vector<T, N> result;
		for (int i = 0;i < N;i++)
		{
			result[i] = vec[i] + arr[i];
		}
		return result;
	}

	//Subtraction
	Vector<T, N> operator - (const Vector<T, N>& vec) const
	{
		Vector<T, N> result;
		for (int i = 0;i < N;i++)
		{
			result[i] = -vec[i] + arr[i];
		}
		return result;
	}

	//Unary Minus
	Vector<T, N> operator - () const
	{
		Vector<T, N> result;
		for (int i = 0;i < N;i++)
		{
			result[i] = - arr[i];
		}
		return result;
	}

	//Scalar Multiplication
	template <typename T, int N, typename F> 
	friend Vector<T, N> operator * (const F& a, const Vector<T, N>& pt);
	

	//Modifier
	void modify(const std::function<T(T&)>& f)
	{
		for (int i = 0;i < N;i++)
		{
			arr[i] = f(arr[i]);
		}
	}

	//Print the vector
	void Print() const
	{
		std::cout << "[ ";
		for (int i = 0;i < N;i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout<<"]\n";
	}

	//Get the iterators
	auto begin() const
	{
		return arr.begin();
	}
	auto end() const
	{
		return arr.end();
	}
};



template <typename T, int N, typename F>
Vector<T, N> operator * (const F& a, const Vector<T, N>& pt)
{
	Vector<T, N> result;
	for (int i = 0;i < N;i++)
	{
		result.arr[i] = a * pt.arr[i];
	}
	return result;
}

#endif // !Vector_HPP
