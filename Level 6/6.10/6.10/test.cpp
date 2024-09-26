//ShapeDecorator.hpp
// Author: TengxiaoFan
//This is the test file for ShapeDecorator Classes.
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include <memory>
#include "ShapeComposite.hpp"
#include "ShapeVisitor.hpp"

int main()
{
	//Build some shapes
	Point p1(0, 1);
	Line l1(p1, Point(3, 4));
	Circle c1(p1, 3);
	ShapeComposite sc,sc2;
	sc.AddShape(&p1);sc.AddShape(&l1);sc.AddShape(&c1);
	sc2.AddShape(&sc); sc2.AddShape(&p1);
	//Test the print visitor
	ShapeVisitor* sv = new PrintVisitor;
	p1.Accept(sv);
	l1.Accept(sv);
	c1.Accept(sv);
	sc.Accept(sv);
	sc2.Accept(sv);
	std::cout << "\n";
	//Test the translate visitor
	ShapeVisitor* sv2 = new TranslateVisitor(2.0);
	p1.Accept(sv2);
	p1.Accept(sv);
	l1.Accept(sv2);
	l1.Accept(sv);
	c1.Accept(sv2);
	c1.Accept(sv);
	sc2.Accept(sv2);
	sc2.Accept(sv);
	//delete the pointers
	delete sv;
	delete sv2;
}
