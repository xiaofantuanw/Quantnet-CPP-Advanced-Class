//test.cpp
//Author: TengxiaoFan
//This is the test file for class ShapeComposite and class Polyline
#include "ShapeComposite.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Singleton.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Polyline.hpp"


int main()
{
	//Some shapes
	Point p1(1, 1), p2(2, 2);
	Line l1(p1, p2);
	Circle c1(p1, 1);
	ShapeComposite sc1,sc2;
	sc1.AddShape(&p1);
	sc1.AddShape(&p2);
	sc2.AddShape(&sc1);
	sc2.AddShape(&p1);
	sc2.AddShape(&l1);
	sc2.AddShape(&c1);
	//Print sc1 and sc2
	sc1.Print();
	sc2.Print();

	Polyline pl1;
	pl1.AddPoint(&p1);
	pl1.AddPoint(&p2);
	Point p3;
	pl1.AddPoint(&p3);
	pl1.Print();
	std::cout << "Length: " << pl1.Length()<<std::endl;
	//pl1.AddShape(&l1);//Cannot access private member
}