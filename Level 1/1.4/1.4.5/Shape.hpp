//Shape.hpp
// Author:TengxiaoFan
//This is the header file of the class Shape
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <functional>

using VoidFunctionType = std::function<void(double)>;

class Shape
{
	//Private data member f and factor fac
private:
	VoidFunctionType f;
public:
	//Constructor
	Shape(VoidFunctionType f0) { f = f0; }
	//Rotate function
	void rotate(double d) { f(d); }
	//Switch function
	void SwitchFunc(VoidFunctionType f0) { f = f0; }
};


#endif // !SHAPE_HPP
