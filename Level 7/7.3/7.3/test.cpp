//test.cpp
//Author: TengxiaoFan
//This is a test file for ShapeFactory
#include "ShapeFactory.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <memory>
#include <tuple>
#include "Polyline.hpp"
#include <list>


int main()
{
	//Define a shape factory
	std::shared_ptr<ShapeFactory> sf(new ConsoleShapeFactory);
	//Create shapes
	std::shared_ptr<Shape> s1, s2, s3,s4;
	//Get the results
	s1 = sf->CreatePoint();
	s2 = sf->CreateLine();
	s3 = sf->CreateCircle();
	//Print shapes
	s1->Print();//Point
	s2->Print();//Line
	s3->Print();//Circle

	//Test of polyline
	s4 = sf->CreatePolyline<std::list>();
	s4->Print();//Polyline
}


