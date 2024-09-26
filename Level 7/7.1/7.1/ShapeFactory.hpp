//ShapeFactory.hpp
//Author: TengxiaoFan
//This is the header file for ShapeFactory classes- build some shapes
#ifndef ShapeFactory_HPP
#define ShapeFactory_HPP
#include "Shape.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include <memory>
#include <iostream>
#include <tuple>
#include <string>

using ShapeTuple = std::tuple< std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;
class ShapeFactory
{//Virtual methods to create shapes
public:
	virtual ShapeTuple CreateShape() const=0;
};

class ConsoleShapeFactory:public ShapeFactory
{//methods to create shapes
public:
	virtual ShapeTuple CreateShape() const override
	{
		ShapeTuple st;//A shape pointer tuple of results
		//Make a point
		//If 'y', default point; else, not default
		std::cout << "Is point default? (y,n)" << std::endl;
		std::string str;
		std::cin >> str;//get the result
		if (str == "y")
		{//Make a default point
			std::shared_ptr<Shape> tmp(new Point);
			std::get<0>(st) = tmp;
		}
		else
		{//Ask for information and make a new point
			std::cout << "x? " << std::endl;
			double x, y;
			std::cin >> x;
			std::cout << "y? " << std::endl;
			std::cin >> y;
			std::shared_ptr<Shape> tmp(new Point(x,y));
			std::get<0>(st) = tmp;
		}
		//Make a line
		//If 'y', default point; else, not default
		std::cout << "Is line default? (y,n)" << std::endl;
		//std::string str;
		std::cin >> str;
		if (str == "y")
		{//make a default line
			std::shared_ptr<Shape> tmp(new Line);
			std::get<1>(st) = tmp;
		}
		else
		{//Ask for information for a new line
			std::cout << "x of start point? " << std::endl;
			double x1, y1,x2,y2;
			std::cin >> x1;
			std::cout << "y of start point? " << std::endl;
			std::cin >> y1;
			std::cout << "x of end point? " << std::endl;
			std::cin >> x2;
			std::cout << "y of end point? " << std::endl;
			std::cin >> y2;
			std::shared_ptr<Shape> tmp(new Line(Point(x1,y1), Point(x2,y2)));
			std::get<1>(st) = tmp;
		}
		//Make a circle
		//If 'y', default circle; else, not default
		std::cout << "Is circle default? (y,n)" << std::endl;
		//std::string str;
		std::cin >> str;
		if (str == "y")
		{//make a default circle
			std::shared_ptr<Shape> tmp(new Circle);
			std::get<2>(st) = tmp;
		}
		else
		{//Ask for information of a new circle
			std::cout << "x of center point? " << std::endl;
			double x1, y1, r;
			std::cin >> x1;
			std::cout << "y of center point? " << std::endl;
			std::cin >> y1;
			std::cout << "Radius? " << std::endl;
			std::cin >> r;
			std::shared_ptr<Shape> tmp(new Circle(Point(x1, y1), r));
			std::get<2>(st) = tmp;
		}
		return st;//return the tuple
	}

};

#endif // !ShapeFactory_HPP
