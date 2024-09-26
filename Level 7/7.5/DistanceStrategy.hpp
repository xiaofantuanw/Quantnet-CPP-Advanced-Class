//DistanceStrategy.hpp
//Author: TengxiaoFan
//This is the header file for different distance strategies
#ifndef DistanceStrategy_HPP
#define DistanceStrategy_HPP
#include "Point.hpp"
#include <cmath>
#include <functional>
using StrategyType = std::function<double(const Point&, const Point&)>;

//Abstract class for different distance strategies
class DistanceStrategy
{
private:
	StrategyType strategy;
	static int count;
public:
	//Ctors and Dtors
	DistanceStrategy()
	{//Default constructor, use exact strategy
		strategy = [](const Point& p1, const Point& p2)
		{
			double result = sqrt((p1.X() - p2.X()) * (p1.X() - p2.X()) + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y()));
			return result;
		};//Use exact strategy for default
	}

	//Ctor with strategy
	DistanceStrategy(StrategyType s)
	{
		strategy = s;
	}

	//Copy and assignment
	DistanceStrategy(const DistanceStrategy& source) = default;//Default copy constructor
	DistanceStrategy& operator= (const DistanceStrategy& source) = default;//Default assignment
	//Destructor
	virtual ~DistanceStrategy() {}
	//Set strategy function
	void SetStrategy(StrategyType s)
	{
		strategy = s;
	}
	//Get Strategy function
	StrategyType GetStrategy() const
	{
		return strategy;
	}
	//Get the count
	static int GetCount()
	{
		return count;
	}
	//Set the count
	static void SetCount(int c)
	{
		count = c;
	}
};
//int DistanceStrategy::count = 0;

#endif 
