//test.cpp
//Author: TengxiaoFan
//This is the test function for combine functionalities of boost hash
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <boost/container_hash/hash.hpp>
#include "Point.hpp"
#include "LineSegment.hpp"


struct PointHash : std::unary_function < Point, std::size_t> 
{//A function object giving point hash
    std::size_t operator () (const Point& pt) const 
    {
        std::size_t seed = 0; 
        boost::hash_combine(seed, pt.X()); 
        boost::hash_combine(seed, pt.Y());
        return seed;
    }
};

int main()
{
    //Instances of Point and Line
    Point p1(2.0, 3.0),p2(1.0,1.0);
    LineSegment line(p1, p2);
    //Hash with hash_combine
    std::cout << hash_value(p1) << std::endl;
    std::cout << hash_value(p2) << std::endl;
    std::cout << hash_value(line) << std::endl;

    //test boost::hash_range
    std::vector<Point> vecP{p1,p2,Point(4.0,4.0)};
    std::cout << boost::hash_range(vecP.begin(), vecP.end())<<std::endl;

    //Test the function obj
    PointHash ph;
    std::cout << ph(p1) << std::endl;
}