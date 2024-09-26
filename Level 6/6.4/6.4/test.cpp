//test.cpp
//Author: TengxiaoFan
//This is the test file for prototype function clone
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "ShapeComposite.hpp"
#include <iostream>

int main()
{
	//Test of clone in different shape types
	Point p1(3, 3),p2;
	Shape* s1 = p1.Clone();
	s1->Print();
	Line l1(p1, p2);
	ShapeComposite sc;
	sc.AddShape(&p1);
	sc.AddShape(&p2);
	sc.AddShape(&l1);
	Shape* s2 = sc.Clone();
	s2->Print();
	//test of copy constructor and assignment operator of ShapeComposite
	ShapeComposite sc2(sc);
	sc2.AddShape(&sc);
	sc2.Print();

	//Delete the pointers
	delete s1;
	delete s2;

}