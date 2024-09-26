//test.cpp
//Author: TengxiaoFan
//This program tests the Variadics and Polymorphic Behaviour of classes
#include "Shape.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Valve.hpp"
#include <array>

template <typename T>//The terminal function for variadic template
void rotate(double factor,const T& object)
{
	object.rotate(factor);
}

template <typename T, typename ... Types>//The recursive function for variadic template
void rotate(double factor, const T& object, const Types& ... objects)
{
	object.rotate(factor);//Rotate one object
	rotate(factor, objects...);//Rotate the next objects
}

int main()
{
	Circle circle; Line line; Valve valve;//Circle and line are derived from shape, Valve is not.
	double factor = 2.0;

	//Test examples
	rotate(factor, circle);
	rotate(factor, circle, line);
	rotate(factor, circle, valve);
	rotate(factor * 2, circle, valve, line);

	// The other way of doing it. 
	std::array<Shape*, 5> shapeList{ &circle, &line, &circle, &circle, &line };
	double factor2 = 20.0;
	for (auto& elem : shapeList)
	{
		elem->rotate(factor2);
	}
	//This method cannot be used in the class Valve.
	//Since it is not a derived class of Shape, 
	//so it cannot be included in the shapeList.
	//Also, the elem->rotate cannot call the rotate function in class Valve,
	//It can only call the functions in the derived class of Shape through override.
}