/*Line.cpp
* Author: Tengxiao Fan
* Definition of member function in Line class
* This file should be used with the point class
*/

#include "LineSegment.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
#include <boost/container_hash/hash.hpp>


LineSegment::LineSegment():startpoint(0,0), endpoint(0,0)//Default constructor using colon syntax
{
	//startpoint = Point(0, 0);//Set the start point to be (0,0)
	//endpoint = Point(0, 0);//Set the end point to be (0,0)
}

LineSegment::LineSegment(const Point& startpt, const Point& endpt):startpoint(startpt),endpoint(endpt)
//Initialize with value, using colon syntax
{
	//startpoint = startpt;//Initialize with the value
	//endpoint = endpt;
}

LineSegment::LineSegment(const LineSegment& source) :startpoint(source.startpoint), endpoint(source.endpoint)
//Copy constructor,using colon syntax
{
	//startpoint = source.startpoint;//Copy the startpoint
	//endpoint = source.endpoint;//Copy the endpoint
}

LineSegment::~LineSegment()//Destructor
{

}

const Point& LineSegment::P1() const//Getter function for startpoint
{
	return startpoint;
}

const Point& LineSegment::P2() const//Getter function for endpoint
{
	return endpoint;
}

void LineSegment::P1(const Point& startpt)//Setter function for startpoint
{
	startpoint = startpt;
}

void LineSegment::P2(const Point& endpt)//Setter function for endpoint
{
	endpoint = endpt;
}

std::string LineSegment::ToString() const//Make a string that describe the Line
{
	std::stringstream stream;//Use a stringstream to make the string,override.
	std::string result;
	//std::string s = Shape::ToString();//Use the ToString function in the base class Shape.
	stream << "; LineSegment: (" << startpoint.X() << ", " << startpoint.Y() << ") to (" << endpoint.X() << ", " << endpoint.Y() << ")";//Make the stream
	result = stream.str();//Turn to string
	return result;
}

double LineSegment::Length() const//Length function
{
	return startpoint.Distance(endpoint);
}

const LineSegment& LineSegment::operator = (const LineSegment& source)//Assignment operator
{
	if (this == &source)//preclude self-assignment
	{
		return *this;
	}
	//Shape::operator=(source);
	startpoint = source.startpoint;
	endpoint = source.endpoint;
	return *this;
}

std::ostream& operator << (std::ostream& os, const LineSegment& line) // Send to ostream.
{
	os << line.ToString();//Use ToString to send information to the ostream
	return os;
}

std::size_t hash_value(const LineSegment& line)
{
	std::size_t seed = 0;
	boost::hash_combine(seed, line.startpoint);
	boost::hash_combine(seed, line.endpoint);
	return seed;
}