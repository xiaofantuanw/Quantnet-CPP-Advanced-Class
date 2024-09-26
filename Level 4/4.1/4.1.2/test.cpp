//test.cpp
// Author: TengxiaoFan
//This is the test file for compile time vector class
#include "Vector.hpp"

int main()
{
	//Create some instance of vector
	Vector<int, 8> v1(2),v2(3),v3;
	//print
	v1.Print();
	v2.Print();
	//Access and modify an element
	v1[3] = 9;
	v1.Print();
	//add
	v3 = v1 + v2;
	v3.Print();
	//Subtract
	v3 = v2 - v1;
	v3.Print();
	//Scalar Multiply
	v3 = 3 * v1;
	v3.Print();
	//Unary minus
	(-v1).Print();
	//Modify
	v1.modify([](int i) {return i * 3 + 1;});
	v1.Print();
}