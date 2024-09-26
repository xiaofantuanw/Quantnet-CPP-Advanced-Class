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

class ShapeFactory
{//Virtual methods to create shapes
public:
	virtual std::shared_ptr<Shape> CreateCircle()=0;
	virtual std::shared_ptr<Shape> CreatePoint() = 0;
	virtual std::shared_ptr<Shape> CreateLine() = 0;
	virtual std::shared_ptr<Shape> CreateCircle(Point p,double rad) = 0;
	virtual std::shared_ptr<Shape> CreatePoint(double x,double y) = 0;
	virtual std::shared_ptr<Shape> CreateLine(Point start,Point end) = 0;
};

class ConsoleShapeFactory:public ShapeFactory
{//methods to create shapes
public:
	std::shared_ptr<Shape> CreateCircle()
	{
		std::shared_ptr<Shape> ptr(new Circle);
		return ptr;
	}
	std::shared_ptr<Shape> CreatePoint()
	{
		std::shared_ptr<Shape> ptr(new Point);
		return ptr;
	}
	std::shared_ptr<Shape> CreateLine()
	{
		std::shared_ptr<Shape> ptr(new Line);
		return ptr;
	}
	std::shared_ptr<Shape> CreateCircle(Point p, double rad)
	{
		std::shared_ptr<Shape> ptr(new Circle(p,rad));
		return ptr;
	}
	std::shared_ptr<Shape> CreatePoint(double x, double y)
	{
		std::shared_ptr<Shape> ptr(new Point(x,y));
		return ptr;
	}
	std::shared_ptr<Shape> CreateLine(Point start,Point end)
	{
		std::shared_ptr<Shape> ptr(new Line(start,end));
		return ptr;
	}
};

#endif // !ShapeFactory_HPP
