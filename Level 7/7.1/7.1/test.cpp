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

using ShapeTuple = std::tuple< std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;
int main()
{
	//Define a shape factory
	std::shared_ptr<ShapeFactory> sf(new ConsoleShapeFactory);
	//Create shapes
	std::shared_ptr<Shape> s1, s2, s3;
	ShapeTuple result = sf->CreateShape();
	//Get the results from the tuple
	s1 = std::get<0>(result);
	s2 = std::get<1>(result);
	s3 = std::get<2>(result);
	//Print shapes
	s1->Print();//Point
	s2->Print();//Line
	s3->Print();//Circle

}

//Comparison:
// This solution is much easier to add a new shape by just adding contents in CreateShape(), instead of 
// changing the structure of the whole class. It is easier to maintain
//