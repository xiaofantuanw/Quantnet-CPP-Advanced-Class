//Shape.hpp
//Author: TengxiaoFan
//This is the header file of the class Shape (base class)
#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
//A virtual function rotate
public:
	virtual void rotate(double d) const = 0;
};

#endif