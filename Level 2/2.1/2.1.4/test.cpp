#include <iostream>
#include <type_traits>

class Shape
{
	//Base class Shape
public:
	virtual void draw() = 0;
};

class Point : public Shape
{
	//Derived class Point
public:
	Point() {}
	virtual void draw() override {}
};

class Point_Deleted :public Shape
{
	//Derived class Point
public:
	Point_Deleted() {}
	Point_Deleted(const Point_Deleted& source) = delete;//Deleted copy constructor
	Point_Deleted& operator=(const Point_Deleted& source) = delete;//Deleted copy assignment
	virtual void draw() override {}
	
};

class Point_Added :public Shape
{
	//Derived class Point
public:
	Point_Added() {}
	Point_Added(const Point_Added& source) = delete;//Deleted copy constructor
	Point_Added& operator=(const Point_Added& source) = delete;//Deleted copy assignment
	Point_Added(Point_Added&& source) = default;//Move constructor added
	Point_Added& operator=(Point_Added&& source)=default;//Move assignment added
	virtual void draw() override {}

};

int main()
{
	std::cout << std::boolalpha<<"Point"<<std::endl;
	//Virtual destructor?
	std::cout << "Virtual destructor? " << std::has_virtual_destructor<Point>::value << std::endl;//false
	//Constructors
	std::cout << "Default constructor? " << std::is_default_constructible<Point>::value << std::endl;//true
	std::cout << "Copy constructor? " << std::is_copy_constructible<Point>::value << std::endl;//true
	std::cout << "Move constructor? " << std::is_move_constructible<Point>::value << std::endl;//true
	//Assignment
	std::cout << "Copy assignment? " << std::is_copy_assignable<Point>::value << std::endl;//true
	std::cout << "Move assignment? " << std::is_move_assignable<Point>::value << std::endl<<std::endl;//true

	//Test for Point_Deleted
	std::cout << "Point_Deleted" << std::endl;
	//Constructors
	std::cout << "Default constructor? " << std::is_default_constructible<Point_Deleted>::value << std::endl;//true
	std::cout << "Copy constructor? " << std::is_copy_constructible<Point_Deleted>::value << std::endl;//false
	std::cout << "Move constructor? " << std::is_move_constructible<Point_Deleted>::value << std::endl;//false
	//Assignment
	std::cout << "Copy assignment? " << std::is_copy_assignable<Point_Deleted>::value << std::endl;//false
	std::cout << "Move assignment? " << std::is_move_assignable<Point_Deleted>::value << std::endl << std::endl;//false
	//Result: Both move& copy constructor&assignment unavalable

	//Test for Point_Deleted
	std::cout << "Point_Added" << std::endl;
	//Constructors
	std::cout << "Default constructor? " << std::is_default_constructible<Point_Added>::value << std::endl;//true
	std::cout << "Copy constructor? " << std::is_copy_constructible<Point_Added>::value << std::endl;//false
	std::cout << "Move constructor? " << std::is_move_constructible<Point_Added>::value << std::endl;//false
	//Assignment
	std::cout << "Copy assignment? " << std::is_copy_assignable<Point_Added>::value << std::endl;//false
	std::cout << "Move assignment? " << std::is_move_assignable<Point_Added>::value << std::endl << std::endl;//false
	//Result: Move assignment and constructor are added
}