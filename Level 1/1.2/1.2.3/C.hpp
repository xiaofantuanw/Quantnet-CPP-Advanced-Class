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
	C(C<T>&& source);//Move constructor
	virtual ~C();//Destructor

	//Assignment operator, deleted
	const C<T>& operator = (const C<T>& source)=delete;
	const C<T>& operator = (const C<T>&& source);//Move operator

	//Member functions
	void print() noexcept;//Function that prints the vector

	//Getter function and Setter function
	std::vector<T>& GetVec();
	void SetVec(const std::vector<T>& vec);
};


#endif // !C_HPP
