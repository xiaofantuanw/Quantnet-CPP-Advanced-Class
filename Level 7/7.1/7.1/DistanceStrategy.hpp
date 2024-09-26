//DistanceStrategy.hpp
//Author: TengxiaoFan
//This is the header file for different distance strategies
#ifndef DistanceStrategy_HPP
#define DistanceStrategy_HPP
#include "Point.hpp"
#include <cmath>

//Abstract class for different distance strategies
class DistanceStrategy
{
public:
	virtual double Distance(const Point& p1, const Point& p2)=0;
};

//Class for exact distance stategy
class ExactDistance :public DistanceStrategy
{
public:
	double Distance(const Point& p1, const Point& p2)
	{
		double result = sqrt((p1.X()-p2.X())* (p1.X() - p2.X())+ (p1.Y() - p2.Y())* (p1.Y() - p2.Y()));
		return result;
	}
};

//Class for approximate distance stategy: taxi
class ApproximateDistance :public DistanceStrategy
{
public:
	double Distance(const Point& p1, const Point& p2)
	{
		double result = abs(p1.X()-p2.X())+abs(p1.Y()-p2.Y());
		return result;
	}
};

#endif // !DistanceStrategy_HPP
