//This is a test function of a modifiable OriginPoint derived from Singleton
//Author: TengxiaoFan
#include "Shape.hpp"
#include "Point.hpp"
#include "OriginPoint.hpp"
#include "Singleton.cpp"
#include <iostream>

int main()
{//Test the distance function
	Point p(1, 1);
	std::cout<<p.Distance()<<std::endl;
}