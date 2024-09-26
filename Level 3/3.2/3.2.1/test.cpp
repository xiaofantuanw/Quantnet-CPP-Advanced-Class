//test.cpp
// Author: TengxiaoFan
//This is the test file for atomic operations on shared_ptr
#include <iostream>
#include <memory>

struct X 
{
	double val;
	X() : val(0.0) {} 
	void operator ()() 
	{ 
		std::cout << "An X " << val << std::endl; 
	}
};

// C++11 
template <typename T> 
using GenericPointerType = std::shared_ptr<T>; 

using PointerType = GenericPointerType<X>;

int main()
{
	//Create an instance x of class PointerType and give it a value.
	PointerType x(new X);
	x->val = 1;
	x->operator()();
	std::cout << "use count x: " << x.use_count() << std::endl;//1
	
	//Create a second instance x2 and atomically store it value in x.
	PointerType x2;
	std::atomic_store(&x2, x);
	x2->operator()();
	std::cout << "use count x: " << x.use_count() << std::endl;//2
	
	//Create an instance x3and exchange it with both x and x2.
	PointerType x3(new X);
	std::cout << "use count x3: " << x3.use_count() << std::endl;//1
	std::atomic_exchange(&x, x3);
	std::atomic_exchange(&x2, x3);
	x3->operator()();
	x->operator()();
	x2->operator()();
	std::cout << "use count x3: " << x3.use_count() << std::endl;//3

	//Why is atomic<std::shared_ptr> not possible?
	//If multiple threads of execution access the same std::shared_ptr without synchronization, a data race will occur

	std::cout << std::boolalpha << "Lock free? " << std::atomic_is_lock_free(&x) << std::endl;//false

}