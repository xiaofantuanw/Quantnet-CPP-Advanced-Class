//test.cpp
//Author: TengxiaoFan
//test for deprecated. you should first change the settings in case of the error.
#include <iostream>

//Deprecated free function
[[deprecated("old free function")]] void Func() 
{ 
	// whatever 
}

//Deprecated class with deprecated member function
class [[deprecated("old class")]] A
{
public:
	[[deprecated("old member function")]] void prt() { std::cout << "Class A" << std::endl; }
};

//Undeprecated class with deprecated member function
class B
{
public:
	[[deprecated("old member function 2")]] void prt() { std::cout << "Class B" << std::endl; }
};


//Deprecated global variable
[[deprecated("Old global variable")]] int x;

//Deprecated enumerate and enum class
enum [[deprecated("Old enumerate")]] color{red, green, blue};
enum class [[deprecated("Old enumerate class")]] newcolor { white, yellow, purple };

template <typename T>//main template
void printfun(T t)
{
	std::cout << t << std::endl;
}

//deprecated template specification
template <>
void [[deprecated("Old template specification")]] printfun(int t)
{
	std::cout << "Int: " << t << std::endl;
}

int main()
{
	Func();//Warning C4996 old free function
	A a;//warning C4996 old class
	a.prt();//warning C4996 old member function
	B b;
	b.prt();//warning C4996 old member function 2
	x++;//Use the deprecated global variable, warning C4996 old global variable
	color r=red;//Use the deprecated enumerate, warning C4996 old enumerate
	newcolor y = newcolor::yellow;//Warning C4996 old enumerate class
	printfun(3);//Warning C4996 old template specification
	[[deprecated("Old lambda function")]] auto lambdafunc = [&]()  {std::cout << "Lambda! " << std::endl;};
	lambdafunc();//Warning C4996 Old lambda function
}