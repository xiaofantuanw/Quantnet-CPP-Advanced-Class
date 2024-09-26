#include <iostream>
#include <memory>
#include <list>



class Base { 
	// Base class 
private: 
public: 
	Base() { } 
	virtual void print() const = 0;
protected: 
	virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

class Derived : public Base 
{ // Derived class private:
public: 
	Derived() : Base() { } 
	~Derived() { std::cout << "Derived destructor\n"; } 
	void print() const { std::cout << "derived object\n"; }
};

//defining smart ptr
using baseptr = std::shared_ptr<Base>;
using baseuptr = std::unique_ptr<Base>;

baseptr CreateDerived()
{
	//Factory function for creating smart pointer to derived type
	//Cannot use unique_ptr because Base::~Base is protected member of class Base.
	baseptr sp(new Derived());
	return sp;
}

int main()
{
	std::list<baseptr> l1;
	//std::list<baseuptr> l2;//Cannot compile because Base::~Base is protected member of class Base.
	//Result: unique_ptr cannot compile
	for (int i = 0;i < 10;i++)
	{
		//Use the factory function to push elements into the list
		auto sp = CreateDerived();
		l1.push_back(sp);
	}
	//No memory leak, since all the destructors are properly called
}