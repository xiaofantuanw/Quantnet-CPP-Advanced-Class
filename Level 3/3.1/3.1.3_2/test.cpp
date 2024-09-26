//test.cpp
//Author: TengxiaoFan
//This is the test file for safe lock using std::unique_lock

#include <iostream>
#include <thread>
#include <string>
#include <functional>
#include <chrono>
#include <mutex>

std::mutex mtx;//a mutex
std::mutex mtx2;
std::timed_mutex t_mtx;//timed mutex

void Iprint1(const std::string& s, int count)
{//callable obj1: free function
	//test try_lock
	std::unique_lock<std::mutex> lock(mtx,std::defer_lock);//A unique_lock which is not locked
	std::unique_lock<std::mutex> lock2;
	std::unique_lock<std::mutex> lock3(mtx2);
	std::unique_lock<std::timed_mutex> t_lock(t_mtx);
	try
	{
		if (lock.try_lock())
		{
			std::cout << "Try Lock 1." << std::endl;//This will success
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		if (lock2.try_lock())
		{
			std::cout << "Try Lock 2." << std::endl;//operation not permitted
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		if (lock3.try_lock())
		{
			std::cout << "Try Lock 3." << std::endl;//resource deadlock would occur
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "Iprint 1: " << s << std::endl;
	std::cout << "Count: " << count << std::endl;
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl ;
	try {
		lock.unlock();
	}
	catch(std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try {
		lock2.unlock();//operation not permitted
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try {
		lock3.release();//release without unlock
		mtx2.unlock();//Unlock!
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try {
		t_lock.unlock();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "\n";
}

void Iprint2(const std::string& s, int count)
{//callable obj1: free function
	//test try_lock_for
	std::unique_lock<std::timed_mutex> lock(t_mtx, std::defer_lock);//A unique_lock which is not locked
	
	try
	{
		if (lock.try_lock_for(std::chrono::milliseconds(200)))
		{
			std::cout << "Try Lock for 200ms." << std::endl;//This will success
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
	std::cout << "Iprint 2: " << s << std::endl;
	std::cout << "Count: " << count << std::endl;
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl ;
	try {
		lock.unlock();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;;
	}
	std::cout<< std::endl;
}

void Iprint3(const std::string& s, int count)
{//callable obj1: free function
	//test try_lock_until
	std::unique_lock<std::timed_mutex> lock(t_mtx, std::defer_lock);//A unique_lock which is not locked

	try
	{
		if (lock.try_lock_until(std::chrono::steady_clock::now() + std::chrono::milliseconds(200)))
		{
			std::cout << "Try Lock until 200ms later." << std::endl;//This will success
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << "Iprint 2: " << s << std::endl;
	std::cout << "Count: " << count << std::endl;
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
	try {
		lock.unlock();
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;;
	}
	std::cout << std::endl;
}


int main()
{
	//time- system performance
	std::chrono::time_point <std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();


	std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
	
	std::thread th[6];//Array of threads
	//Build the threads
	th[0] = std::thread(Iprint1, "Free function", 1);
	th[1] = std::thread(Iprint2, "Free function", 2);
	th[2] = std::thread(Iprint3, "Free function", 3);
	
	for (int i = 0;i < 6;i++)
	{//join the threads
		try {
			if (th[i].joinable())
				th[i].join();
		}
		catch (std::exception ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}

	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return 0;

	//Result: The order of the output is not determined (but each blocks are together);
	//If we make a deadlock by commenting the unlock line, the program will wait at the point.
}
