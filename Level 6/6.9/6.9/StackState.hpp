//StackState.hpp
//Author: TengxiaoFan
//This is the header file for StackState classes, representing the state of stack
#ifndef StackState_HPP
#define StackState_HPP
#include <memory>
#include <string>

class Stack;
class StackState
{//Abstract base class for stack states
public:
	//constructors and destructors
	StackState() {}
	StackState(const StackState& source) {}// Copy constructor
	StackState& operator = (const StackState& source) {}
	virtual ~StackState() {}
	//Push and pop functions , pure virtual
	virtual void Push(Stack * st, double NewElement) = 0;
	virtual double Pop(Stack* st) = 0;
};


//Declare the states
class EmptyState : public StackState
{//Empty state
	// Singleton must be able to create instance of me
	//friend class Singleton<EmptyState>;

private:
	//Private stuffs
	EmptyState(const EmptyState& source) = default;  // Copy constructor
	EmptyState& operator = (const EmptyState& source) = default;//Assignment op
	std::string info ="Empty";
public:
	// Constructors & destructor
	EmptyState()=default;                       // Default constructor
	virtual ~EmptyState() {}             // Destructor

	void Push(Stack* st, double NewElement);
	double Pop(Stack* st);                    // Pop the last pushed element of the stack

	static std::shared_ptr<EmptyState> Instance();
};

class FullState : public StackState
{//Full State
	// Singleton must be able to create instance of me
	//friend class Singleton<FullState>;

private:
	//private stuffs
	std::string info = "Full";
	FullState(const FullState& source) = default;  // Copy constructor
	FullState& operator = (const FullState& source) = default;//Assignment op

public:
	// Constructors & destructor
	FullState() = default;                       // Default constructor
	virtual ~FullState() {}             // Destructor

	void Push(Stack* st, double NewElement);
	double Pop(Stack* st);                    // Pop the last pushed element of the stack

	static std::shared_ptr<FullState> Instance();
};

class NotEmptyNotFullState : public StackState
{
	// Singleton must be able to create instance of me
	//friend class Singleton<NotEmptyNotFullState>;

private:
	std::string info = "Not Empty Not Full";
	NotEmptyNotFullState(const NotEmptyNotFullState& source) = default;  // Copy constructor
	NotEmptyNotFullState& operator = (const NotEmptyNotFullState& source) = default;//Assignment op

public:
	// Constructors & destructor
	NotEmptyNotFullState() = default;                       // Default constructor
	virtual ~NotEmptyNotFullState() {}             // Destructor

	void Push(Stack* st, double NewElement);
	double Pop(Stack* st);                    // Pop the last pushed element of the stack

	static std::shared_ptr<NotEmptyNotFullState> Instance();
};

#endif // !StackState_HPP
