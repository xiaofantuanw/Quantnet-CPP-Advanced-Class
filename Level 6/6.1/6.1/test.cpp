//test.cpp
//Author: TengxiaoFan
//This is the test program for hierachy class shape (circle,point,line)
//Both 6.1.1 and 6.1.2 are in this project

#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include <iostream>

int main()
{
	Point p1(1.0, 2.0), p2(2.0,3.0);
	//Print the points
	p1.Print();
	std::cout << p2 << std::endl;
	//Make a line
	Line l1(p1, p2);
	std::cout << l1 << std::endl;
	//Make a circle
	Circle c1(p1, 1);
	std::cout << c1 << std::endl;

	//A Point to a shape pointer
	Shape* s1=new(Point);
	s1->Print();

	//Test of Distance and Length
	std::cout << p1.Distance(p2) << std::endl;
	std::cout << l1.Length() << std::endl;
	
}