/*Array.cpp
* This is the source file for template Stack.
* This class defines array of a class that dynamically allocates me
*/

#ifndef Stack_CPP
#define Stack_CPP
#include "Stack.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include "StackState.hpp"


void Stack::Init(int size)
{//Private initializer
	if (size < 1)
		size = 1;//Check if the size is at least 1. If less set the size to 1.
	m_current = 0;//current index is zero
	m_array = Array<double>::Array(size);//Default array constructor
	m_state = EmptyState::Instance();
	m_maxsize = size;
}

Stack::Stack()//Default constructor
{
	Init(1);
}


Stack::Stack(int size)//constructor with size
{
	//m_current = 0;//current index is zero
	//m_array = Array<T>::Array(size);//array constructor with size
	Init(size);
}


Stack::Stack(const Stack& source)//Copy constructor
{
	m_current = source.m_current;//current index is the same as that of the source
	m_array = Array<double>::Array(source.m_array);//use the copy constructor
	//for (int index = 0;index < source.m_array.Size();index++)
	//{
	//	m_array.SetElement(index, source.m_array.GetElement(index));//Copy the elements of the array
	//}
}

Stack::~Stack()//Destructor
{

}


const Stack& Stack::operator= (const Stack& source)
{
	if (this == &source)//prevent self-assignment
		return *this;
	m_current = source.m_current;
	m_array = source.m_array;//Use copy constructor of the array
	return *this;
}


void Stack::Push(double element)//Push function
{

	m_state->Push(this, element);
}

const double Stack::Pop()//Pop function
{
	return m_state->Pop(this);
}

void ChangeState(Stack* st, std::shared_ptr<StackState> state)
{//Change the state of the stack
	st->m_state = state;
}

#endif