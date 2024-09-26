//test.cpp
//Author: TengxiaoFan
//This is a test file for shared future
#include <iostream>
#include <future>
#include <chrono>
#include <atomic>


std::atomic_bool flag= true;
std::atomic_bool flag2 = true;
//Test function 2
double func2(double a, double b)
{
	double c = a + b;
	std::cout << "Function 2: " << c << "; Thread id: " << std::this_thread::get_id << std::endl;
	return c;
}

double func_inf()
{//An infinite loop
	while (true)
	{
		std::cout << "*" ;
		if (!flag) break;
	}
	return 3.14;
}

double func_inf2()
{//An infinite loop
	while (true)
	{
		std::cout << "#";
		if (!flag2) break;
	}
	return 1.1;
}

int main()
{
	//Test of shared_future constructors and valid()
	std::cout << std::boolalpha;
	//Default constructor. Constructs an empty shared future, that doesn't refer to a shared state
	std::shared_future<double> sh_fut1;
	std::cout << "Default share future valid? " << sh_fut1.valid() << std::endl;

	//Transfer shared state from a ¡®normal¡¯ future to a shared future.
	std::future<double> fut1(std::async(std::launch::async, func2, 1.0, 2.0));//A future instance
	std::shared_future<double> sh_fut2(std::move(fut1));
	std::cout << "Normal future transferred to shared future.\nNormal future valid? "  << fut1.valid() << std::endl;
	std::cout << "Shared future valid? " << sh_fut2.valid()<<std::endl;

	//Transfer shared state from a shared future to a shared future.
	std::shared_future<double> sh_fut3(std::move(sh_fut2));
	std::cout << "Shared future transferred to shared future.\nThe first future valid? "  << sh_fut2.valid() << std::endl;
	std::cout << "The second future valid? " << sh_fut3.valid()<<std::endl;

	//a shared future that shares the same state as another shared state
	std::shared_future<double> sh_fut4(sh_fut3);
	std::cout << "Sharing the same state.\nThe first future valid? "  << sh_fut3.valid() << std::endl;
	std::cout << "The second future valid? " << sh_fut4.valid() << std::endl;

	//Test the member functions of shared state
	sh_fut3.wait();
	//get functions can get multiple times
	std::cout << "Get once: " << sh_fut3.get()<<std::endl;
	std::cout << "Get twice: " << sh_fut3.get() << std::endl;
	std::cout << "Get another: " << sh_fut4.get() << std::endl;

	//Test of wait_for and wait_until using infinite loop
	std::shared_future<double> sh_inf(std::async(std::launch::async, func_inf));
	auto status=sh_inf.wait_for(std::chrono::milliseconds(100));
	if (status == std::future_status::timeout)//Find the timeout
	{
		std::cout << "Wait_for timeout!" << std::endl;
		flag = false;
		std::cout << "Loop stopped: "<<sh_inf.get() << std::endl;
	}


	std::shared_future<double> sh_inf2(std::async(std::launch::async, func_inf2));
	auto t1 = std::chrono::system_clock::now();
	auto status2 = sh_inf2.wait_until(t1+std::chrono::milliseconds(100));
	if (status2 == std::future_status::timeout)//Find the timeout
	{
		std::cout << "Wait_until timeout!" << std::endl;
		flag2 = false;
		std::cout << "Loop stopped: " << sh_inf2.get() << std::endl;
	}
}