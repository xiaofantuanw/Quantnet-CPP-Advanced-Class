//test.cpp
//This is the test file for different distance strategies
#include "DistanceStrategy.hpp"
#include <memory>
#include "Point.hpp"
#include <iostream>

int DistanceStrategy::count = 0;
int main()
{
	//DistanceStrategy::SetCount(0);
	//Approximate strategy type
	StrategyType approx = [](const Point& p1, const Point& p2)
	{
		double result = abs(p1.X() - p2.X()) + abs(p1.Y() - p2.Y());
		return result;
	};
	std::shared_ptr<DistanceStrategy> s1(new DistanceStrategy(approx));
	//Exact strategy type
	StrategyType exact = [](const Point& p1, const Point& p2)
	{
		double result = sqrt((p1.X() - p2.X()) * (p1.X() - p2.X()) + (p1.Y() - p2.Y()) * (p1.Y() - p2.Y()));
		return result;
	};
	std::shared_ptr<DistanceStrategy> s2(new DistanceStrategy(exact));


	Point p1(2, 2), p2(3, 3);
	//Default distance strategy is exact distance
	std::cout<<"Exact Distance (stateless): "<<p1.Distance(p2)<<std::endl;
	//Switch the strategy
	Point::SetDistanceStrategy(s1);
	std::cout << "Approximate Distance (stateless): " << p1.Distance(p2) << std::endl;

	//state-based distance
	std::cout << "Exact Distance (state-based): " << p1.Distance(p2, s2) << std::endl;
	std::cout << "Approximate Distance (state-based): " << p1.Distance(p2, s1) << std::endl;

	//a static counter that is incremented each time the algorithm is called
	std::cout << "Distance Strategy times: " << DistanceStrategy::GetCount() << std::endl;
}