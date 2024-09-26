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
#include "Polyline.hpp"

class ShapeFactory
{//Virtual methods to create shapes
public:
	virtual std::shared_ptr<Shape> CreateCircle() const=0;
	virtual std::shared_ptr<Shape> CreatePoint() const= 0;
	virtual std::shared_ptr<Shape> CreateLine() const= 0;

	template<
		template<typename, typename> typename Container,
		typename Alloc = std::allocator<Point>
	>
	std::shared_ptr<Shape> CreatePolyline()
	{
		//Interact with the user to create a polyline
		std::string str;
		std::shared_ptr<Polyline<Container, Alloc>> s(new Polyline<Container,Alloc>);
		while (1)
		{
			std::cout << "Add Point? (y,n)\n";
			std::cin >> str;
			if (str == "y")
			{//If yes, make a point and add to the poly
				double x, y;
				std::cout << "x of the point: \n";
				std::cin >> x;
				std::cout << "y of the point: \n";
				std::cin >> y;
				s->AddPoint(Point(x, y));
			}
			else
				break;//Skip out of the loop
		}
		return s;
	}
};

class ConsoleShapeFactory:public ShapeFactory
{//methods to create shapes
public:
	std::shared_ptr<Shape> CreateCircle() const override;
	std::shared_ptr<Shape> CreatePoint() const override;
	virtual std::shared_ptr<Shape> CreateLine() const override final;//use symbol final
};

#endif // !ShapeFactory_HPP
