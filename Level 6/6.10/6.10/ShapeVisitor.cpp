//ShapeVisitor.hpp
//Authro: TengxiaoFan
//This is the source file for ShapeVisitor classes
#include "ShapeVisitor.hpp"
#include "ShapeComposite.hpp"

void ShapeVisitor::visit(ShapeComposite& sc)
{//Accept all the shapes in the composite
	for (auto it = sc.begin();it != sc.end();it++)
	{
		(*it)->Accept(this);
	}
}

//Print visitors
void PrintVisitor::visit(Point& p)
{
	p.Print();
}

void PrintVisitor::visit(Line& l)
{
	l.Print();
}

void PrintVisitor::visit(Circle& c)
{
	c.Print();
}

void PrintVisitor::visit(ShapeComposite& sc)
{
	ShapeVisitor::visit(sc);
}


//Translate visitors 
void TranslateVisitor::visit(Point& p)
{
	p.X(p.X()+m_d);
	p.Y(p.Y()+m_d);
}

void TranslateVisitor::visit(Line& l)
{
	Point p1 = l.P1();
	Point p2 = l.P2();
	p1.Accept(this);
	p2.Accept(this);
	l.P1(p1);
	l.P2(p2);
}

void TranslateVisitor::visit(Circle& c)
{
	Point cent = c.Centrepoint();
	//std::cout << cent << std::endl;
	cent.Accept(this);
	c.Centrepoint(cent);
}

void TranslateVisitor::visit(ShapeComposite& sc)
{
	ShapeVisitor::visit(sc);
}
