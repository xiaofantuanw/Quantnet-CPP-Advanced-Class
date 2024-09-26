//ShapeDecorator.hpp
// Author: TengxiaoFan
//This is the test file for ShapeDecorator Classes.
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "ShapeDecorator.hpp"
#include <memory>

int main()
{
	//Instances of shapes
	std::shared_ptr<Shape> p1(new Point(1, 1)), p2(new Point(0, 1));
	std::shared_ptr<Shape> l1(new Line(Point(3,3),Point(4,4)));

	//Decorate them
	std::shared_ptr<Shape> nd1(new NameDecorator(p1, "MyPoint"));
	std::shared_ptr<Shape> nd2(new NameDecorator(l1, "MyLine"));
	nd1->Print();nd2->Print();

}