//ShapeFactory.hpp
//Author: TengxiaoFan
//This is the header file for ShapeFactory classes- build some shapes
#ifndef NewShapeFactory_HPP
#define NewShapeFactory_HPP
#include "Shape.hpp"
#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include <memory>
#include <iostream>
#include <tuple>
#include <functional>
#include <string>

using ShapeFunc = std::function<std::shared_ptr<Shape>()>;
using ShapeTuple = std::tuple< std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;
class NewShapeFactory
{//Virtual methods to create shapes
private:
	//Methods for making Point Line and Circle
	ShapeFunc fPoint;
	ShapeFunc fLine;
	ShapeFunc fCircle;
public:
	NewShapeFactory()
	{//Default construtor, making all the methods default
		fPoint = []() {std::shared_ptr<Shape> s(new Point); return s;};
		fLine= []() {std::shared_ptr<Shape> s(new Line); return s;};
		fCircle= []() {std::shared_ptr<Shape> s(new Circle); return s;};
	}
	NewShapeFactory(ShapeFunc fp, ShapeFunc fl, ShapeFunc fc)
	{//Constructor with 3 methods
		fPoint = fp;
		fLine = fl;
		fCircle = fc;
	}
	void SetPointFunction(ShapeFunc fp)
	{//Set the point method
		fPoint = fp;
	}
	void SetLineFunction(ShapeFunc fl)
	{//set the line method
		fPoint = fl;
	}
	void SetCircleFunction(ShapeFunc fc)
	{//set the circle method
		fPoint = fc;
	}
	~NewShapeFactory() {}
	virtual ShapeTuple CreateShape() const	{//Create a shape tuple using methods
		return std::make_tuple(fPoint(), fLine(), fCircle());
	}

};


#endif // !ShapeFactory_HPP
