//test.cpp
//Author: TengxiaoFan
//This is the test file for a race of threads with smart pointers
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;
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

void Modify(PointerType &p, double newVal) 
{
	// Wait a while, long enough to trigger the race 
	//Generate a random time to wait
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(100, 1000);
	int sleep_time = distr(eng);
	//Sleep for the amount
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
	p->val = newVal; //modify the value
	std::lock_guard<std::mutex> lock(mtx);//make the safe lock
	std::cout << "Value modified to " << newVal << " after waiting for " << sleep_time << " ms by thread " << std::this_thread::get_id() << std::endl;
}

int main()
{
	PointerType x(new(X));//An instance of PointerType
	std::thread th[100];
	for (int i = 0;i < 100;i++)
	{
		th[i] = std::thread(&Modify,std::ref(x), i);//fire each of the thread up
	}
	for (int i = 0;i < 100;i++)
	{
		th[i].join();
	}
	std::cout << "Final result of x: " << (x->val) << std::endl;
	//The result will be the last thread which completes the modification
	//Actually, every thread modifies the value once.
}