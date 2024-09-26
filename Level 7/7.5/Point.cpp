/*Point.cpp
* Stateless version
* Author: Tengxiao Fan
* Definition of member function
* This program modifies Distance function and Get/Set function and uses overload
*/

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include "OriginPoint.hpp"
#include "DistanceStrategy.hpp"

//Default distance strategy is exact distance
std::shared_ptr<DistanceStrategy> Point::m_ds(new DistanceStrategy);

Point::Point():Shape(),m_x(0),m_y(0)//Default constructor using colon syntax and constructor in class Shape
{
	//m_x = m_y = 0;
	//std::cout << "Default Constructor" << std::endl;
}

Point::Point(const Point& source):Shape(source),m_x(source.m_x),m_y(source.m_y)
//Copy constructor using colon syntax and constructor in class Shape
{
	//m_x = source.m_x;
	//m_y = source.m_y;
	//std::cout << "Copy Constructor" << std::endl;
}

Point::Point(const double initxvalue, const double inityvalue):Shape(),m_x(initxvalue),m_y(inityvalue)
//Constructor with initialization,using colon syntax and constructor in class Shape
{
	//m_x = initxvalue;
	//m_y = inityvalue;
	//std::cout << "Initialized Constructor" << std::endl;
}

Point::~Point()//Default destructor
{
	//std::cout << "Point Destructor" << std::endl;
}

double Point::X() const//Get the value of x, return m_x
{
	return m_x;
}

double Point::Y() const//Get the value of y, return m_y
{
	return m_y;
}

void Point::X(const double newxvalue)//Set a new value for x
{
	m_x = newxvalue;
}

void Point::Y(const double newyvalue)//Set a new value for y
{
	m_y = newyvalue;
}

std::string Point::ToString() const//Output is the string description of the point, override
{
	std::stringstream stream;//Use a stringstream to make the string
	std::string result;
	std::string s = Shape::ToString();//Use the ToString function in the base class Shape.
	stream << s<<"; Point(" << m_x << ", " << m_y << ")";
	result = stream.str();
	return result;
}



double Point::Distance(const Point& p) const//Output the distance of the point to point P.
{
	StrategyType s = m_ds->GetStrategy();
	double result = s(p, (*this));
	DistanceStrategy::SetCount(DistanceStrategy::GetCount() + 1);
	return result;
}

double Point::Distance(const Point& p, std::shared_ptr<DistanceStrategy> ds) const//Output the distance of the point to point P.
{
	StrategyType s = ds->GetStrategy();
	double result = s(p, (*this));
	DistanceStrategy::SetCount(DistanceStrategy::GetCount() + 1);
	return result;
}

double Point::Distance() const//Output the distance of the point to origin(0,0)
{
	Point* op = OriginPoint::instance();
	//We can modify the OriginPoint
	//(*op) = Point(1, 0);
	return Distance(*op);
}

double Point::Distance(std::shared_ptr<DistanceStrategy> ds) const//Output the distance of the point to origin(0,0)
{
	Point* op = OriginPoint::instance();
	//We can modify the OriginPoint
	//(*op) = Point(1, 0);
	return Distance(*op,ds);
}

Point Point::operator-() const// Negate the coordinates.
{
	return Point(-m_x, -m_y);//Return negative coordinates.
}

Point Point::operator* (double factor) const// Scale the coordinates.
{
	return Point(factor * m_x, factor * m_y);//return factor times the coordinates
}

Point Point::operator+ (const Point& p) const// Add coordinates.
{
	return Point(m_x + p.m_x, m_y + p.m_y);//return the coordinates added respectively
}

bool Point::operator == (const Point& p) const // Equally compare operator.
{
	return (m_x == p.m_x && m_y == p.m_y);
}

const Point& Point::operator = (const Point& source) // Assignment operator.
{
	//std::cout << "Assignment Operator" << std::endl;
	if (this == &source)//preclude self-assignment
	{
		return *this;
	}
	Shape::operator=(source);//Use the assignment operator in base class
	m_x = source.m_x;//copy the coordinate
	m_y = source.m_y;
	return *this;
}

const Point& Point::operator *= (double factor) // Scale the coordinates & assign.
{
	m_x *= factor;//times the factor
	m_y *= factor;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Point& p)// Send to ostream.
{
	os << p.ToString();//Use ToString to deliver the message
	return os;
}

//void Point::Draw() const//Draw the shape (simulating with printing)
//{
//	std::cout << "Picture of: " << ToString() << std::endl;
//}