//C.cpp
//Author: TengxiaoFan
//This is the source file for class C
#ifndef C_CPP
#define C_CPP
#include "C.hpp"
#include <iostream>

//template <typename T>
//C<T>::C()
//{
//	std::cout << "Constructor called." << std::endl;
//}

template <typename T>
constexpr C<T>::C(int size)//Constructor with size
{
	m_dat = std::vector<T>(size,0);//Build a vector with size and all the elements are 0
	std::cout << "Constructor with size called." << std::endl;
}

//template <typename T>
//C<T>::C(const C<T>& source)
//{
//	m_dat = source.m_dat;
//	std::cout << "Copy constructor called." << std::endl;
//}

//Move constructor
template <typename T>
C<T>::C(C<T>&& source)
{
	m_dat = std::move(source.m_dat);
	std::cout << "Moving constructor called." << std::endl;
}

template <typename T>
C<T>::~C()//Destructor
{
	std::cout << "Destructor called." << std::endl;
}

//template <typename T>
//const C<T>& C<T>::operator = (const C<T>& source)
//{
//	if (this == &source)
//		return *this;
//	m_dat = source.m_dat;
//	return *this;
//}

template <typename T>
const C<T>& C<T>::operator = (const C<T>&& source)//Move operator
{
	m_dat = std::move(source.m_dat);
	std::cout << "Move operator = called." << std::endl;
	return *this;
}

//A function to print the contents of the vector
template <typename T>
void C<T>::print() noexcept
{
	for (auto iter = m_dat.begin();iter != m_dat.end();iter++)//Print by iteration
	{
		std::cout << *iter << std::endl;
	}
}

template <typename T>//Getter function
std::vector<T>& C<T>::GetVec()
{
	return m_dat;
}

template <typename T>//Setter function
void C<T>::SetVec(const std::vector<T>& vec)
{
	m_dat = vec;
}
#endif