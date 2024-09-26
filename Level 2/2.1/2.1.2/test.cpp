//test.cpp
//Author: TengxiaoFan
//This is the test file for Bridge functionality
#include <type_traits>
#include <iostream>

template <typename T>
void IsPointer_impl(const T& t, std::true_type)
{ // This function is called for a pointer (switch)
	std::cout <<  *t << std::endl;//Dereferenced and print
}
template <typename T>
void IsPointer_impl(const T& t, std::false_type)
{ // This function is called for a non-pointer (switch)
	std::cout  << t << std::endl;//print directly
}

template <typename T>
void Print(const T& val)
{ // This code can print both pointers and scalar value
	IsPointer_impl(val, std::is_pointer<T>());
}


int main()
{
	int p = 10;
	int* q = new int;
	*q = 15;
	int& p0 = p;
	Print(p);//Print scalar
	Print(q);//Print pointer
	Print(p0);//Print reference
	delete(q);
}