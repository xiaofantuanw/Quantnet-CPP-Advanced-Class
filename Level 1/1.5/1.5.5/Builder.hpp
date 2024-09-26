//Builder.hpp
//Author:TengxiaoFan
//This is an ABC for Builder class
#ifndef BUILDER_HPP
#define BUILDER_HPP
#include <tuple>
#include <memory>
#include "Shape.hpp"
#include "IODevice.hpp"

using ShapePointer = std::shared_ptr<Shape>; 
using IODevicePointer = std::shared_ptr<IODevice>;
class Builder 
{ 
	// A Builder hierarchy that builds shapes and io devices
public: 
	std::tuple<ShapePointer, IODevicePointer> getProduct() 
	{ // GOF (!) Template Method pattern
		return std::tuple<ShapePointer, IODevicePointer>(getShape(), getIODevice());
	}
	  // Hook functions that derived classes must implement 
	virtual ShapePointer getShape() = 0; 
	virtual IODevicePointer getIODevice() = 0; 
};


#endif // !BUILDER_HPP
