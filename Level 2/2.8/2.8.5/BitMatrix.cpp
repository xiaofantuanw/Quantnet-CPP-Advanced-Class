//BitMatrix.cpp
//This is the definition of functions in BitMatrix Class
#ifndef  BitMatrix_CPP
#define BitMatrix_CPP
#include "BitMatrix.hpp"

template <unsigned int N, unsigned int M>
BitMatrix<N, M>::BitMatrix()
{//Default constructor
	for (auto elem : data)
	{
		std::bitset<M> tmp;
		elem = std::move(tmp);
	}
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::set()
{//Set function for all rows
	for (int i=0;i<data.size();i++)
	{
		data[i].set();
	}
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::set(int row)
{//Set function for one row
	data[row].set();
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::reset()
{//Reset function for all rows
	for (int i = 0;i < data.size();i++)
	{
		data[i].reset();
	}
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::reset(int row)
{//reset function for one row
	data[row].reset();
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::flip()
{//Flip function for all row
	for (int i = 0;i < data.size();i++)
	{
		data[i].flip();
	}
}

template <unsigned int N, unsigned int M>
void BitMatrix<N, M>::flip(int row)
{//Flip function for one row
	data[row].flip();
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::all()
{//All function for all rows
	bool result = 1;
	for (auto& elem : data)
	{
		result = result && elem.all();
		if (!result) break;
	}
	return result;
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::all(int row)
{//All function for one row
	return data[row].all();
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::any()
{//Any function for all rows
	bool result = 0;
	for (auto& elem : data)
	{
		result = result || elem.any();
		if (result) break;
	}
	return result;
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::any(int row)
{//Any function for one row
	return data[row].any();
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::none()
{//None funcion for all rows
	bool result = 1;
	for (auto& elem : data)
	{
		result = result && elem.none();
		if (!result) break;
	}
	return result;
}

template <unsigned int N, unsigned int M>
bool BitMatrix<N, M>::none(int row)
{//None function for one row
	return data[row].none();
}

template <unsigned int N, unsigned int M>
std::bitset<M> BitMatrix<N, M>::operator [](int index)
{//Operator [] to access the element
	return data[index];
}

template <unsigned int N, unsigned int M>
int BitMatrix<N,M>::count()
{//count the set digits
	int sum=0;
	for (auto elem : data)
	{
		sum += elem.count();
	}
	return sum;
}

template <unsigned int N, unsigned int M>
int BitMatrix<N, M>::count(int row)
{//cont the set digits in one row
	return data[row].count();
}

#endif // ! 

