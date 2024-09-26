//Builder_A.hpp
//Author: TengxiaoFan
//This is a derived class from Builder, used to build a shape of Line
#ifndef BUILDER_A_HPP
#define BUILDER_A_HPP
#include "Builder.hpp"
#include "Line.hpp"
#include "IO_A.hpp"


class Builder_A:public Builder
{
	//The shape is Line
	ShapePointer getShape()
	{
		ShapePointer myshape(new Line);
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