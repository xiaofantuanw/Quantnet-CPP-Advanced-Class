//test.cpp
//Author: TengxiaoFan
//This is a test file for ShapeFactory
#include "NewShapeFactory.hpp"
#include "Shape.hpp"
#include "ShapeFactory.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <memory>
#include <tuple>

class FOPoint
{//Function object to create a new point
public:
	std::shared_ptr<Shape> operator()()
	{
		std::shared_ptr<Shape> s(new Point(3.0, 4.0));
		return s;
	}
};

using ShapeTuple = std::tuple< std::shared_ptr<Shape>, std::shared_ptr<Shape>, std::shared_ptr<Shape>>;
int main()
{
	//Lambda function to create a new point
	auto LambdaLine = []() {std::shared_ptr<Shape> s(new Line(Point(1, 1), Point(0, 3))); return s;};
	//std::bind to create a new circle
	ConsoleShapeFactory sf_old;
	auto BindCircle = std::bind(&ConsoleShapeFactory::CreateCircle, &sf_old);
	FOPoint fo;
	//Define a shape factory
	std::shared_ptr<NewShapeFactory> sf(new NewShapeFactory(fo,LambdaLine,BindCircle));
	//Create shapes
	std::shared_ptr<Shape> s1, s2, s3;
	ShapeTuple result = sf->CreateShape();
	//Get the results from the tuple
	s1 = std::get<0>(result);
	s2 = std::get<1>(result);
	s3 = std::get<2>(result);
	//Print shapes
	s1->Print();//Point
	s2->Print();//Line
	s3->Print();//Circle

	std::shared_ptr<ShapeFactory> factory(new ConsoleShapeFactory()); 
	double valx = 3,valy=5; 
	//auto facP1= [val](){ return Pointer<P1>(new P11(val)); }; 
	auto facP1 = [&]() 
	{ //modify objects using captured variables after they have been default initialised using GOF factories.
		auto p1 = factory->CreatePoint(); 
		std::shared_ptr<Point> p= std::dynamic_pointer_cast<Point>(p1);
		p->X(valx);
		p->Y(valy);
		return p; };
	//Set the new bind function to the new factory
	sf->SetPointFunction(facP1);
	result = sf->CreateShape();
	s1 = std::get<0>(result);
	s1->Print();
}

//consider the suitability of this design to other pattern such as Strategy and Command? 
//How does the new design compare with the corresponding GOF design?
//Answer: This new design is more flexible since the user can define his own function to make shapes

