/*StackException.hpp
* This file defines and declares the exception class and its derived classes.
*/
#ifndef StackException_HPP//avoid repeated inclusion
#define StackException_HPP
#include <string>

class StackException
{
public:
	//Constructors and Destructors
	StackException() {}//Default constructor
	virtual ~StackException() {}//Destructor
	//Abstract GetMessage()
	virtual std::string GetMessage() const = 0;
};

class PopFromEmptyException :public StackException
{
private:
	int m_index;//Index which is out of bound.

public:
	//Constructors and Destructors
	PopFromEmptyException() { m_index = 0; }//Default constructor
	PopFromEmptyException(int index) { m_index = index; }//Constructor with error index
	virtual ~PopFromEmptyException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const { return "Pop from empty stack."; }
};

class PushOntoFullException:public StackException
{
private:
	int m_index;//Index which is out of bound.

public:
	//Constructors and Destructors
	PushOntoFullException() { m_index = 0; }//Default constructor
	PushOntoFullException(int index) { m_index = index; }//Constructor with error index
	virtual ~PushOntoFullException() {}//Destructor
	//GetMessage Function
	std::string GetMessage() const { return "Push onto full stack."; }
};



#endif // !ArrayException_HPP
