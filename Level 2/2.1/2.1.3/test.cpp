#include <iostream>
#include <type_traits>
class Shape 
{ 
	//Polymorphic and Abstract, not empty
public: 
	virtual void draw() = 0; 
};
					
class Base
{
	//None of polymorphic, abstract,empty
private:
	int y;
public:
	Base() {} 
	void draw() {}
};

class Point : public Shape 
{
	//Polymorphic, not abstract and empty
public:
	Point() {}
	virtual void draw() override {} 
};

template <typename T> void TypeInformation(const T& t)
{ // Type properties
// Decide whether a class is empty, polymorphic and absract
	std::cout << "Empty: " << std::is_empty<T>::value << std::endl;
	std::cout << "Polymorphic: " << std::is_polymorphic<T>::value << std::endl;
	std::cout << "Abstract: "<< std::is_abstract<T>::value << std::endl;
	std::cout << "\n";
}

int main()
{
	//Decide whether they are: Polymorphic, empty, abstract
	std::cout << std::boolalpha;
	Shape* shape=new Point;
	Point point;
	Base base;
	std::cout << "Shape: \n";
	TypeInformation(*shape);//Polymorphic,abstract
	std::cout << "Point: \n";
	TypeInformation(point);//Polymorphic
	std::cout << "Base: \n";
	TypeInformation(base);//None
	//std::cout << "Abstract: " << std::boolalpha << std::is_abstract<Shape>::value << std::endl;

	//Check which two classes are the same
	std::cout << "Same or not? \n";
	std::cout << "Shape and Point: " << std::is_same<Shape, Point>::value << std::endl;//false
	std::cout << "Shape and Base: " << std::is_same<Shape, Base>::value << std::endl;//false
	std::cout << "Base and Point: " << std::is_same<Base, Point>::value << std::endl<<std::endl;//false
	//Result: None of the three classes are the same

	//Check gen/spec relationship
	std::cout << "Derived or not? \n";
	std::cout << "Shape from Point: " << std::is_base_of<Point, Shape>::value << std::endl;//false
	std::cout << "Point from Shape: " << std::is_base_of<Shape, Point>::value << std::endl;//true
	std::cout << "Base from Shape: " << std::is_base_of<Shape, Base>::value << std::endl;//false
	std::cout << "Shape from Base: " << std::is_base_of<Base, Shape>::value << std::endl ;//false
	std::cout << "Base from Point: " << std::is_base_of<Point, Base>::value << std::endl;//false
	std::cout << "Point from Base: " << std::is_base_of<Base, Point>::value << std::endl<<std::endl;//false
	//Result: Point is derived from Shape

	//Check convertible
	std::cout << "Convertible or not?\n";
	std::cout << "Shape to Point: "<<std::is_convertible<Shape*, Point*>::value << std::endl;//false
	std::cout << "Point to Shape: " << std::is_convertible<Point*, Shape*>::value << std::endl;//true
	std::cout << "Shape to Base: " << std::is_convertible<Shape*, Base*>::value << std::endl;//false
	std::cout << "Base to Shape: " << std::is_convertible<Base*, Shape*>::value << std::endl;//false
	std::cout << "Base to Point: " << std::is_convertible<Base*, Point*>::value << std::endl;//false
	std::cout << "Point to Base: " << std::is_convertible<Point*, Base*>::value << std::endl;//false
	//Result: Only Point can be converted to Shape
}