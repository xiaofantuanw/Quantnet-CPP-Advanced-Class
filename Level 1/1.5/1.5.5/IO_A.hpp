//IO_A.cpp
//Author: TengxiaoFan
//Derived class for IODevice
#ifndef IOA_HPP
#define IOA_HPP
#include "IODevice.hpp"
#include <iostream>

class IO_A:public IODevice
{
    // Interface for displaying CAD objects
public:
    virtual void operator << (const Circle& c) override
    {
        std::cout << c.ToString() << std::endl;
    }
    virtual void operator << (const Line& c) override
    {
        std::cout << c.ToString() << std::endl;
    }
};


#endif