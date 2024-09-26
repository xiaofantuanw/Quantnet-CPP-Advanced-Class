#ifndef ActiveObject_HPP
#define ActiveObject_HPP
#include <thread>
#include <iostream>

class ActiveObject
{
private:
    // member data
    std::thread& m_th;

public:
    explicit ActiveObject(std::thread&& th) :m_th(th)
    {
        //constructor
        //m_th = std::ref(th);
    };
    virtual ~ActiveObject()
    {
        // destructor
        if (m_th.joinable())
        {
            m_th.join();
        }
        //std::cout << "Destructor Called." << std::endl;
    }

    bool associated()
    {//judge whether the thread is associated with a function
        if (m_th.joinable())
        {
            return 1;
        }
        else
        {
            throw -1;
            //return 0;
        }
    }

};

#endif