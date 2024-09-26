#include "ShapeFactory.hpp"
#include <iostream>

std::shared_ptr<Shape> ConsoleShapeFactory::CreateCircle() const
{//Create a circle, default
	std::shared_ptr<Shape> ptr(new Circle);
	return ptr;
}


std::shared_ptr<Shape> ConsoleShapeFactory::CreatePoint() const
{//Create a point, interacting
	double x, y;
	std::cout << "Create a Point:\n";
	std::cout << "x? " << std::endl;
	std::cin >> x;
	std::cout << "y? " << std::endl;
	std::cin >> y;
	std::shared_ptr<Shape> ptr(new Point(x,y));
	return ptr;
}

std::shared_ptr<Shape> ConsoleShapeFactory::CreateLine() const
{//Create a line, interacting
	std::cout << "Create a Line:\nPoint start\n";
	//Make a shape factory
	ConsoleShapeFactory f1;
	//Create start point using CreatePoint
	std::shared_ptr<Shape> p1 = f1.CreatePoint();
	//Create end point using CreatePoint
	std::cout << "Point end\n";
	std::shared_ptr<Shape> p2=f1.CreatePoint();
	std::shared_ptr<Point> pstart = std::dynamic_pointer_cast<Point>(p1);
	std::shared_ptr<Point> pend = std::dynamic_pointer_cast<Point>(p2);
	std::shared_ptr<Shape> ptr(new Line(*pstart,*pend));//Make the line
	return ptr;
}