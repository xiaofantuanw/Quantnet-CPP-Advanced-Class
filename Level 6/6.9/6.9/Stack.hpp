/*Array.hpp
* This is the header file for template Stack.
* This class defines array of a class that dynamically allocates memory.
*/
#ifndef Stack_HPP
#define Stack_HPP
#include "Array.hpp"
#include <memory>

class StackState;
class Stack
{
private:
	//Data members, invisible to users
	Array<double> m_array;//The array data member
	int m_current;//Current index
	int m_maxsize;//Max size
	void Init(int size);
	std::shared_ptr<StackState> m_state;//State
public:
	//menmer functions
	//Constructors and destructors
	Stack();//Defalt constructor
	Stack(int size);//Constructor with size
	Stack(const Stack& source);//Copy constructor
	~Stack();//Destructor

	//Assignment operator
	const Stack& operator= (const Stack& source);
	//Push and Pop functions
	void Push(double element);//Push function
	const double Pop();//Pop function
	//Friend classes and functions
	friend class StackState;//StackState is a friend class
	friend class EmptyState;
	friend class FullState;
	friend class NotEmptyNotFullState;
	friend void ChangeState(Stack* st, std::shared_ptr<StackState> state);//function to change the state
};



#endif // !Stack_HPP
