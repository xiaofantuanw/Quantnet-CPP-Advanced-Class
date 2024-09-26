//ShapeDecorator.hpp
// Author: TengxiaoFan
//This is the header file for ShapeDecorator Classes.
#ifndef ShapeDecorator_HPP
#define ShapeDecorator_HPP
#include "Shape.hpp"
#include <memory>
#include <sstream>
#include <string>

class ShapeDecorator :public Shape
{
private:
	std::shared_ptr<Shape> m_ps;
public:
	//constructors and destructors
	ShapeDecorator()
	{
		m_ps = nullptr;
	}
	ShapeDecorator(std::shared_ptr<Shape> ps)
	{
		m_ps = ps;
	}
	virtual ~ShapeDecorator() {}
	ShapeDecorator(const ShapeDecorator& source) :Shape(source), m_ps(source.m_ps) {}
	//Assignment op
	ShapeDecorator& operator= (const ShapeDecorator& source) = default;
	//Getter and Setter
	std::shared_ptr<Shape> GetShape() const
	{
		return m_ps;
	}
	void SetShape(std::shared_ptr<Shape> ps)
	{
		m_ps = ps;
	}
	//Clone Function
	virtual Shape* Clone() const
	{
		Shape* result(new ShapeDecorator(*this));
		return result;
	}
	//Tostring function
	virtual std::string ToString() const
	{
		std::stringstream stream;//Use a stringstream to make the string
		std::string result;
		std::string s = m_ps->ToString();//Use the ToString function in the underlying Shape.
		stream << "Shape Decorator of: \n"<<s ;
		result = stream.str();
		return result;
	}
};

class NameDecorator : public ShapeDecorator
{
private:
	std::string m_name;
public:
	//Constructors and destructors
	NameDecorator() : ShapeDecorator(), m_name(" ") {}
	NameDecorator(std::shared_ptr<Shape> ps, std::string name) :ShapeDecorator(ps), m_name(name) {}
	NameDecorator(const NameDecorator& source) :ShapeDecorator(source), m_name(source.m_name) {}
	virtual ~NameDecorator() {}
	//Assignment Op
	NameDecorator& operator=(const NameDecorator& source) = default;
	//Get and Set name
	std::string GetName() const
	{
		return m_name;
	}
	void SetName(std::string name)
	{
		m_name = name;
	}
	//Clone Function
	virtual Shape* Clone() const
	{
		Shape* result(new NameDecorator(*this));
		return result;
	}
	//Tostring function
	virtual std::string ToString() const
	{
		std::stringstream stream;//Use a stringstream to make the string
		std::string result;
		std::string s = ShapeDecorator::ToString();//Use the ToString function in the Shape Decorator.
		stream <<  s<<"; Name: "<<m_name;
		result = stream.str();
		return result;
	}
};


#endif