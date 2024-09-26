#include <iostream>
#include <memory>


struct Base 
{ 
	virtual void draw() { std::cout << "print a base\n"; } 
	//The class should be virtual to be overrided
	virtual void print() {} 
	~Base() { std::cout << "bye base\n"; } 
};
struct Derived final : public Base 
{ 
	Derived() {} 
	void draw() override { std::cout << "print a derived\n"; } 
	//The override in base class has no const keyword
	//void draw() const override {} 
	void print() override {} 
	~Derived() { std::cout << "bye derived\n"; } 
};

//Cannot derive a class from the final class type
//class Derived2 : public Derived 
//{

//};

int main()
{
	std::shared_ptr<Base> ptr1(new Derived);//Use smart pointer to build a pointer to derived class
	ptr1->draw();
	return 0;
}