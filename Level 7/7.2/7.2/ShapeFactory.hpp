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
	virtual std::shared_ptr<Shape> CreateCircle() const=0;
	virtual std::shared_ptr<Shape> CreatePoint() const= 0;
	virtual std::shared_ptr<Shape> CreateLine() const= 0;
};

class ConsoleShapeFactory:public ShapeFactory
{//methods to create shapes
public:
	std::shared_ptr<Shape> CreateCircle() const override
	{
		std::shared_ptr<Shape> ptr(new Circle);
		return ptr;
	}
	std::shared_ptr<Shape> CreatePoint() const override
	{
		std::shared_ptr<Shape> ptr(new Point);
		return ptr;
	}
	std::shared_ptr<Shape> CreateLine() const override
	{
		std::shared_ptr<Shape> ptr(new Line);
		return ptr;
	}
};

#endif // !ShapeFactory_HPP
