//IODevice.hpp
//Author:TegnxiaoFan
//This is the ABC for IODevice class, which is used for displaying CAD objects
#ifndef IODEVICE_HPP
#define IODEVICE_HPP

class Circle;
class Line;

class IODevice
{
    // Interface for displaying CAD objects
public:
    virtual void operator << (const Circle& c) = 0;
    virtual void operator << (const Line& c) = 0;
};

#endif // !#IODEVICE_HPP
