//ShapeVisitor.hpp
//Authro: TengxiaoFan
//This is the header file for ShapeVisitor classes
#ifndef ShapeVisitor_HPP
#define ShapeVisitor_HPP
#include "Shape.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "ShapeComposite.hpp"

class ShapeVisitor
{//abstract shape visitor
public:
	//abstract visit methods for different classes
	virtual void visit(Point& p) = 0;
	virtual void visit(Circle& c) = 0;
	virtual void visit(Line& l) = 0;
	virtual void visit(ShapeComposite& sc) = 0;
};

class PrintVisitor : public ShapeVisitor
{//print visitor
public:
	//Visit methods for different classes
	virtual void visit(Point& p) ;
	virtual void visit(Circle& c);
	virtual void visit(Line& l) ;
	virtual void visit(ShapeComposite& sc) ;
};

class TranslateVisitor : public ShapeVisitor
{//translate visitor
private:
	double m_d;
public:
	//Constructor with d
	TranslateVisitor() { m_d = 1.0; }
	TranslateVisitor(double d) { m_d = d; }
	//Visit methods for different classes
	virtual void visit(Point& p);
	virtual void visit(Circle& c);
	virtual void visit(Line& l);
	virtual void visit(ShapeComposite& sc);
	//Set the distance of translate
	void D(double d) { m_d = d; }
};

#endif // !ShapeVisitor_HPP
