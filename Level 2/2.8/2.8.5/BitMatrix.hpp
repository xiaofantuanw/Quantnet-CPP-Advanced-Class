//BitMatrix.hpp
//Author: TengxiaoFan
//This is the header file for class BitMatrix
#ifndef BitMatrix_HPP
#define BitMatrix_HPP
#include <bitset>
#include <iostream>
#include <array>

template <unsigned int N, unsigned int M>
class BitMatrix
{
private:
	//data member
	std::array<std::bitset<M>, N> data;
public:
	//member functions
	//Constructors and destructors
	BitMatrix();
	BitMatrix(const BitMatrix<N, M>& source) = default;//Default copy constructor
	BitMatrix(BitMatrix<N, M>&& source) = default;//Default move constructor
	virtual ~BitMatrix() = default;//Destructor

	//set and reset
	void set();//each row
	void set(int row);//for a given row
	void reset();
	void reset(int row);//for a given row

	//flip the bits
	void flip();
	void flip(int row);//for a given row

	//Test if none, all or any bits are set.
	bool none();
	bool none(int row);
	bool all();
	bool all(int row);
	bool any();
	bool any(int row);

	//Access the row
	std::bitset<M> operator [](int index);//then access the element with the operator in std::bitset

	//Count the num of set bits
	int count();
	int count(int row);

	//Operator << for output
	friend std::ostream& operator<<(std::ostream& os, BitMatrix<N,M>& bm)
	{
		for (auto elem : bm.data)
		{
			os << elem << "\n";
		}
		return os;
	}

	//Friend operators
	friend BitMatrix<N, M> operator ^(BitMatrix<N, M>& a, BitMatrix<N, M>& b)//XOR
	{
		BitMatrix<N,M> result;
		for (int i = 0;i < N;i++)
		{
			result.data[i] = a.data[i] ^ b.data[i];
		}
		return result;
	}
	friend BitMatrix<N, M> operator |(BitMatrix<N, M>& a, BitMatrix<N, M>& b)//OR
	{
		BitMatrix<N, M> result;
		for (int i = 0;i < N;i++)
		{
			result.data[i] = a.data[i] | b.data[i];
		}
		return result;
	}
	friend BitMatrix<N, M> operator &(BitMatrix<N, M>& a, BitMatrix<N, M>& b)//AND
	{
		BitMatrix<N, M> result;
		for (int i = 0;i < N;i++)
		{
			result.data[i] = a.data[i] & b.data[i];
		}
		return result;
	}
};


#endif