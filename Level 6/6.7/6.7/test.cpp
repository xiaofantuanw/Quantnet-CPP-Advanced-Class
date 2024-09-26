//test.cpp
//Author: TengxiaoFan
//This is a test file for ShapeFactory
#include "ShapeFactory.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <memory>

int main()
{
	//Define a shape factory
	std::shared_ptr<ShapeFactory> sf(new ConsoleShapeFactory);
	//Create shapes
	std::shared_ptr<Shape> s1, s2, s3;
	s1 = sf->CreatePoint(1, 2);
	s2 = sf->CreateLine();
	s3 = sf->CreateCircle(Point(1, 1), 2);
	//Print shapes
	s1->Print();
	s2->Print();
	s3->Print();
}