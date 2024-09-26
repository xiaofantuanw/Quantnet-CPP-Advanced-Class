#ifndef C1_HPP
#define C1_HPP
#include <iostream>

class C1
{
private:
	int a;
	char b;
public:
	C1() = default;//Default constructor
	C1(int a0, char b0):a(a0),b(b0) {}//Value constructor
	C1(const C1& source) = default;//Default copy constructor
	void prt() { std::cout << a << ", " << b << std::endl; }//print function
};

#endif // !C1_HPP
