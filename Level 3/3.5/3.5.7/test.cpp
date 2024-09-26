//test.cpp
//Author: TengxiaoFan
//This is the test file for std::ratio
#include <ratio>
#include <iostream>

template<typename T>
void output(const T& t)
{//Output of a ratio
	std::cout << t.num<<"/"<<t.den << std::endl;
}

int main()
{
	//two instance of ratio
	std::ratio<1, 3> r1;
	std::deci r2;//deci=ratio<1,10>
	output(r1);
	output(r2);
	
	//test add, subtract, multiply and divide
	std::ratio_add<decltype(r1),decltype(r2)> r_add;
	output(r_add);
	std::ratio_subtract<decltype(r1), decltype(r2)> r_sub;
	output(r_sub);
	std::ratio_multiply<decltype(r1), decltype(r2)> r_mul;
	output(r_mul);
	std::ratio_divide<decltype(r1), decltype(r2)> r_div;
	output(r_div);

}