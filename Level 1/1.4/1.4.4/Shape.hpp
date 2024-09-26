//Shape.hpp
// Author:TengxiaoFan
//This is the header file of the class Shape
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <functional>

using VoidFunctionType = std::function<void(double)>;

class Shape
{
	//Protected data member f
protected:
	VoidFunctionType f;//Protected data member f
public:
	//Constructor
	Shape(VoidFunctionType f0) :f(f0) { }
	//Rotate function
	void rotate(double d) { f(d); }
};


#endif // !SHAPE_HPP
