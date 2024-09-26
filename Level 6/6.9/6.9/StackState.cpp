//StackState.cpp
//Author: TengxiaoFan
//This is the source file for StackState classes, representing the state of stack
#include "StackState.hpp"
#include "Stack.hpp"
#include "StackException.hpp"
#include "Singleton.cpp"

//Push function for StackState, pure virtual
void StackState::Push(Stack* st, double NewElement)
{
	// Push an element on the stack
	st->m_array.SetElement(st->m_current, NewElement);//Set the element of the current index
	st->m_current++;//Change the current index of the stack. If unsuccessful, it will not change.
}

//Pop function for StackState, pure virtual
double StackState::Pop(Stack* st)
{
	// Pop the last pushed element of the stack
	double result;
	result = st->m_array[st->m_current - 1];//Get the element
	st->m_current--;//Change the current index
	//An ArrayException will be thrown to the outer function if out of bound.
	return result;
}

////Push function for emptyState
void EmptyState::Push(Stack* st, double NewElement)
{
	// Push an element on the stack
	StackState::Push(st, NewElement);
	//Change the state
	if (st->m_current < st->m_maxsize)
		ChangeState(st, NotEmptyNotFullState::Instance());
	else
		ChangeState(st, FullState::Instance());
}

//Pop function for emptyState
double EmptyState::Pop(Stack* st)
{
	// Pop the last pushed element of the stack
	throw PopFromEmptyException(st->m_current);
}

//Push function for NotEmptyNotFullState
void NotEmptyNotFullState::Push(Stack* st, double NewElement)
{
	// Push an element on the stack
	StackState::Push(st, NewElement);
	//Change the state
	if (st->m_current == st->m_maxsize)
		ChangeState(st, FullState::Instance());
}

//Pop function for NotEmptyNotFullState
double NotEmptyNotFullState::Pop(Stack* st)
{
	if (st->m_current==1)
		ChangeState(st, EmptyState::Instance());
	return StackState::Pop(st);
}

//Push function for FullState
void FullState::Push(Stack* st, double NewElement)
{
	throw PushOntoFullException(st->m_maxsize);
}

//Pop function for FullState
double FullState::Pop(Stack* st)
{
	if (st->m_current == 1)
		ChangeState(st, EmptyState::Instance());
	else
		ChangeState(st, NotEmptyNotFullState::Instance());
	return StackState::Pop(st);
}


//Instance functions
std::shared_ptr<EmptyState> EmptyState::Instance()
{
	// Return a unique instance
	return Singleton<EmptyState>::instance();
}

std::shared_ptr<FullState> FullState::Instance()
{
	// Return a unique instance
	return Singleton<FullState>::instance();
	//std::shared_ptr<FullState> r(new FullState);
	//return r;
}

std::shared_ptr<NotEmptyNotFullState> NotEmptyNotFullState::Instance()
{
	// Return a unique instance
	return Singleton<NotEmptyNotFullState>::instance();
}