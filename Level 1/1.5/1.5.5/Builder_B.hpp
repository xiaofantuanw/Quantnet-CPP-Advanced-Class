//Builder_A.hpp
//Author: TengxiaoFan
//This is a derived class from Builder, used to build a shape of Circle
#ifndef BUILDER_B_HPP
#define BUILDER_B_HPP
#include "Builder.hpp"
#include "Circle.hpp"
#include "IO_A.hpp"


class Builder_B :public Builder
{
	//The shape is Circle
	ShapePointer getShape()
	{
		ShapePointer myshape(new Circle);
		return myshape;
	}
	//The IODevice is IO_A
	IODevicePointer getIODevice()
	{
		IODevicePointer myiodevice(new IO_A);
		return myiodevice;
	}
};


#endif