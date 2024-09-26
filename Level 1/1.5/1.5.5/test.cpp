//Test.cpp
//Author:TengxiaoFan
//This is the test file for the builder and IODevice
#include "Circle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "IODevice.hpp"
#include "IO_A.hpp"
#include "Builder.hpp"
#include "Builder_A.hpp"
#include "Builder_B.hpp"
#include <iostream>

int main()
{
	//Test the display by iodevice
	Circle c1(Point(0, 0), 1);
	Line l1(Point(0, 0), Point(1, 1));
	IO_A io_a1;
	c1.display(io_a1);
	l1.display(io_a1);

	//Test the builder
	ShapePointer l2_ptr;
	IODevicePointer io_a2_ptr;
	Builder_A builder_a;
	std::tie(l2_ptr, io_a2_ptr) = builder_a.getProduct();
	l2_ptr->display(*io_a2_ptr);

	//Test another builder
	ShapePointer l3_ptr;
	IODevicePointer io_a3_ptr;
	Builder_B builder_b;
	std::tie(l3_ptr, io_a3_ptr) = builder_b.getProduct();
	l3_ptr->display(*io_a3_ptr);
}