#ifndef Polyline_HPP
#define Polyline_HPP
#include "ShapeComposite.hpp"
#include "Point.hpp"

class Polyline:public ShapeComposite
{
private:
	//Copy constructors and assignment operator
	Polyline(const Polyline& source) = default;
	Polyline& operator=(const Polyline& source) = default;
	using ShapeComposite::AddShape;
public:
	//Default constructor and destructor
	Polyline() {}
	virtual ~Polyline() {}
	void AddPoint(Point* p)
	{//Add a point to the polyline
		ShapeComposite::AddShape(p);
	}
	double Length ()
	{//The length of the polyline
		double result = 0.0;
		auto endit = ShapeComposite::end();
		endit--;
		for (auto it = ShapeComposite::begin();it != endit;it++)
		{
			auto p1=(Point *)(*it);
			auto tmp = it;
			tmp++;
			auto p2 = (Point*)(*tmp);
			result += p1->Distance(*p2);
		}
		return result;
	}

};

#endif // !Polyline_HPP
