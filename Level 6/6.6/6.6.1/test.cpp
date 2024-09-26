//test.cpp
//This is the test file for different distance strategies
#include "DistanceStrategy.hpp"
#include <memory>
#include "Point.hpp"
#include <iostream>

int main()
{
	std::shared_ptr<DistanceStrategy> s1(new ApproximateDistance);
	Point p1(2, 2), p2(3, 3);
	//Default distance strategy is exact distance
	std::cout<<"Exact Distance: "<<p1.Distance(p2)<<std::endl;
	//Switch the strategy
	Point::SetDistanceStrategy(s1);
	std::cout << "Approximate Distance: " << p1.Distance(p2) << std::endl;

}