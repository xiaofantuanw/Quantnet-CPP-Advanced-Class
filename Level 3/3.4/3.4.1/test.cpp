//test.cpp
//Author: TengxiaoFan
//This is the test function for std::async with default,async and deffered status
#include <iostream>
#include <future>

//Test function 1
void func1() 
{ 
	std::cout << "Function 1; " <<"Thread id: "<<std::this_thread::get_id << std::endl;
} 

//Test function 2
double func2(double a, double b) 
{ 
	double c = a + b;
	std::cout << "Function 2: " << c << "; Thread id: " << std::this_thread::get_id << std::endl;
	return c;
}

int main()
{
	//Test 1 and 2: Async setting
	std::future<void> fut1(std::async(std::launch::async,func1));
	std::cout << std::boolalpha;
	std::cout << "Future 1 valid before get? " << fut1.valid() << std::endl;
	fut1.get();
	std::cout << "Future 1 valid after get? " << fut1.valid() << std::endl<<std::endl;

	std::future<double> fut2(std::async(std::launch::async,func2, 1.0, 2.0));
	std::cout << std::boolalpha;
	std::cout <<"Future 2 valid before get? "<< fut2.valid() << std::endl;
	std::cout << "Future 2 get: "<<fut2.get() << std::endl;
	std::cout << "Future 2 valid after get? " << fut2.valid() << std::endl<<std::endl;

	//std::cout << "Future get: " << fut2.get() << std::endl;
	//If we get the future twice, there will be a runtime error.

	//Test 3 and 4: default setting
	std::future<void> fut3(std::async(func1));
	std::cout << std::boolalpha;
	std::cout << "Future 3 valid before get? " << fut3.valid() << std::endl;
	fut3.get();
	std::cout << "Future 3 valid after get? " << fut3.valid() << std::endl << std::endl;

	std::future<double> fut4(std::async(func2, 1.0, 2.0));
	std::cout << std::boolalpha;
	std::cout << "Future 4 valid before get? " << fut4.valid() << std::endl;
	std::cout << "Future 4 get: " << fut4.get() << std::endl;
	std::cout << "Future 4 valid after get? " << fut4.valid() << std::endl << std::endl;

	//Test 5 and 6: deferred setting
	std::future<void> fut5(std::async(std::launch::deferred, func1));
	std::cout << std::boolalpha;
	std::cout << "Future 5 valid before get? " << fut5.valid() << std::endl;
	fut5.get();
	std::cout << "Future 5 valid after get? " << fut5.valid() << std::endl << std::endl;

	std::future<double> fut6(std::async(std::launch::deferred, func2, 1.0, 2.0));
	std::cout << std::boolalpha;
	std::cout << "Future 4 valid before get? " << fut6.valid() << std::endl;
	std::cout << "Future 4 get: " << fut6.get() << std::endl;
	std::cout << "Future 4 valid after get? " << fut6.valid() << std::endl << std::endl;

	//In async setting, the function and the main will be operated asynchronously,
	//In deffered setting, the function will not be operated until get() is called
	//In default setting, we cannot decide.
}