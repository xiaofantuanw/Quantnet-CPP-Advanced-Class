/*Point.hpp
* Author: Tengxiao Fan
* A class that include a point with x- and y- coordinates.
*/

#ifndef POINT_HPP
#define POINT_HPP
#include "Shape.hpp"
#include <string>
#include <memory>

class OriginPoint;
class DistanceStrategy;
class Point :public Shape
{
private:
	//Datas, not accesible to users
	double m_x;//x-coordinate of the point
	double m_y;//y-coordinate of the point
	static std::shared_ptr<DistanceStrategy> m_ds;
public:
	//Member functions, accessible to users
	// 
	//Constructors and destructors
	Point();//Default
	Point(const Point& source);//Copy constructor
	Point(const double initxvalue, const double inityvalue);//constructor that initializes x and y
	virtual ~Point();

	//Getter functions
	double X() const;//Get the x-coordinate value (const)
	double Y() const;//Get the y-coordinate value (const)

	//Setter functions
	void X(const double newxvalue);//Set a new x-coordinate value
	void Y(const double newyvalue);//Set a new y-coordinate value

	//ToString function: Return a string description of the point(const)
	std::string ToString() const;//

	//Distance functions
	double Distance() const; // Calculate the distance to the origin (0, 0).(const), stateless
	double Distance(const Point& p) const; // Calculate the distance between two points.(const), stateless
	double Distance(std::shared_ptr<DistanceStrategy> ds) const; // Calculate the distance to the origin (0, 0).(const), statebased
	double Distance(const Point& p, std::shared_ptr<DistanceStrategy> ds) const; // Calculate the distance between two points.(const), statebased
	//Operators
	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	const Point& operator = (const Point& source); // Assignment operator.
	const Point& operator *= (double factor); // Scale the coordinates & assign.
	//PVMF that draws the shape.
	//void Draw() const;
	//Clone the Point
	virtual std::shared_ptr<Shape> Clone() const
	{
		std::shared_ptr<Shape> result(new Point(*this));
		return result;
	}
	//Set the distance strategy
	static void SetDistanceStrategy(std::shared_ptr<DistanceStrategy> ds)
	{
		m_ds = ds;
	}
};
std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream.

#endif
