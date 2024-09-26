#ifndef OriginPoint_HPP
#define OriginPoint_HPP
#include "Singleton.cpp"
#include "Point.hpp"

class OriginPoint :public Singleton<Point>
{
public:
    //Constructors
    OriginPoint() {}
    OriginPoint(const OriginPoint& source) = delete;

    // Assignment operator
    OriginPoint& operator = (const OriginPoint& source) = delete;

    //Destructor
    virtual ~OriginPoint() {};
    
};

#endif // !OriginPoint_HPP
