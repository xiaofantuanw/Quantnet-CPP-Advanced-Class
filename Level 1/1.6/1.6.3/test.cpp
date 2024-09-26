//test.cpp
//Author: TengxiaoFan
//This file tests the different ways of initialization
#include "C1.hpp"

struct S
{
	int x;
	struct Foo
	{
		int i; int j; int a[3];
	} b;
};

int main()
{
	C1 c1;//Default initialization
	C1 c2{};//Value initialization
	C1 c3(1, 'a');//Direct initialization
	C1 c4{ 1,'a'};//List initialization
	C1 c5(c4);//Copy initialization
	C1& c6 = c4;//Reference initialization
	//C1 c7();//ill-formed, no such a constructor
	//C1 c8 = ( 1, 'a' );//ill-formed. Must use list initilization
	//c1.prt();//c1 is not initialized to a value
	c2.prt();
	c3.prt();
	c4.prt();
	c5.prt();
	c6.prt();

	S s1{ 1,{2,3,{0,0,0}} };//Aggregate initialization
	std::cout << "s1: " << s1.x <<", " << s1.b.i <<", "<< s1.b.j <<", " << s1.b.a[0] << std::endl;
	//Different ways of initializing
	S s2{};//Every element will be 0
	std::cout << "s2: " << s2.x << ", " << s2.b.i << ", " << s2.b.j << ", " << s2.b.a[0] << std::endl;
	S s3{ 1,{} };//struct foo b will be 0
	std::cout << "s3: " << s3.x << ", " << s3.b.i << ", " << s3.b.j << ", " << s3.b.a[0] << std::endl;
}