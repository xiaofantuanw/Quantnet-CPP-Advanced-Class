//C.hpp
//Author: TengxiaoFan
//This is the header file for class C
#ifndef C_HPP
#define C_HPP
#include <vector>

template <typename T>
class C
{
private:
	//Data members, cannot seen by users
	std::vector<T> m_dat;
public:
	//Member functions, public
	//Constructors and Destructor
	C()=default;//Default Constructor
	constexpr explicit C(int size);//A Constructor with size, constexpr
	C(const C<T>& source)=delete;//Copy constructor,deleted
	virtual ~C();//Destructor

	//Assignment operator, deleted
	const C<T>& operator = (const C<T>& source)=delete;

	//Member functions
	void print() noexcept;//Function that prints the vector
};


#endif // !C_HPP
