#ifndef MyStack_HPP
#define MyStack_HPP
#include <stack>

template <typename T>
class MyStack
{
private:
	//Private data member
	std::stack<T> m_data;
public:
	//Constructor
	MyStack() {};
	MyStack(const std::stack<T>& data): m_data(data){}
	//Conventional stack operations
	void push(const T& t)
	{
		m_data.push(t);
	}
	void pop()
	{
		m_data.pop();
	}
	T top()
	{
		return m_data.top();
	}
	//Other operations
	void max()
	{//leaves on the stack the larger of the two top values
		if (m_data.size() <= 1)
		{
			return;
		}
		T top1 = m_data.top();
		m_data.pop();
		if (top1 > m_data.top())
		{//The top 1 is bigger
			m_data.pop();
			m_data.push(top1);
		}
		else
		{
			//top2 is bigger
		}
	}
	void min()
	{//leaves on the stack the smaller of the two top values
		if (m_data.size() <= 1)
		{
			return;
		}
		T top1 = m_data.top();
		m_data.pop();
		if (top1 < m_data.top())
		{//The top 1 is smaller
			m_data.pop();
			m_data.push(top1);
		}
		else
		{
			//top2 is bigger
		}
	}

	void over()
	{//duplicates the second stack value on top of the stack
		if (m_data.size() <= 1)
		{
			return;
		}
		m_data.pop();
		m_data.push(m_data.top());
	}

	void rot()
	{//rotate the stack's third data value to the top of the stack.
		if (m_data.size() <= 2)
		{
			return;
		}
		T t1 = m_data.top();
		m_data.pop();
		T t2 = m_data.top();
		m_data.pop();
		T t3 = m_data.top();//get the third top
		m_data.pop();
		m_data.push(t2);
		m_data.push(t1);
		m_data.push(t3);
	}

	void swap()
	{//swap the stack's second data value to the top of the stack.
		if (m_data.size() <= 1)
		{
			return;
		}
		T t1 = m_data.top();
		m_data.pop();
		T t2 = m_data.top();//get the second top
		m_data.pop();
		m_data.push(t1);
		m_data.push(t2);
	}

	void drop()
	{
		if (m_data.size() < 1)
		{
			return;
		}
		m_data.pop();
	}
};


#endif // !MyStack_HPP
