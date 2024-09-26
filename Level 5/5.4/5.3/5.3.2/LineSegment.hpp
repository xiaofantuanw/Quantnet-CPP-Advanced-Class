/*Line.hpp
* Author: Tengxiao Fan
* A class that include two points, which are the start and end points of a line.
*/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP
#include "Point.hpp"

class LineSegment
{
private:
	//Datas, not accessible to users.
	Point startpoint;//start point of the line
	Point endpoint;//end point of the line

public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	LineSegment();//Default
	LineSegment(const Point& startpt, const Point& endpt);//Initialized
	LineSegment(const LineSegment& source);//copy
	virtual ~LineSegment();//Destructor

	//Overload Getters
	const Point& P1() const;//Get the start point
	const Point& P2() const;//Get the end point

	//Overload Setters
	void P1(const Point& startpt);//Set the start point 
	void P2(const Point& endpt);//Set the end point

	//String Description function
	std::string ToString() const;//Output the string description of the Line

	//Line length function
	double Length() const;//Output the length of the line

	//Assignment Operator
	const LineSegment& operator = (const LineSegment& source);

	friend std::size_t hash_value(const LineSegment& line);

};
std::ostream& operator << (std::ostream& os, const LineSegment& line); // Send to ostream.

#endif