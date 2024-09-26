//test.cpp
//Author: TengxiaoFan
//This is the test file for mutex and thread lock
#include <iostream>
#include <thread>
#include <string>
#include <functional>
#include <chrono>
#include <mutex>

std::mutex mtx;//a mutex

void Iprint1(const std::string& s, int count)
{//callable obj1: free function
	//mtx.lock();
	int fail = 0;
	while (1)
	{
		if (mtx.try_lock())
		{
			std::cout << "Iprint 1: " << s << std::endl;
			std::cout << "Count: " << count << std::endl;
			std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
			std::cout << "Fail time: " << fail << std::endl << std::endl;
			mtx.unlock();
			break;
		}
		else
		{
			fail++;
		}
	}
}

class Ip4
{//Class for callable obj4
private:
	std::string m_s;
	int m_count;
public:
	Ip4(const std::string s, int count)
	{
		m_s = s;
		m_count = count;
	}

	void operator () ()
	{//callable obj4: function object
		//mtx.lock();
		int fail = 0;
		while (1)
		{
			if (mtx.try_lock())
			{
				std::cout << "Iprint 4: " << m_s << std::endl;
				std::cout << "Count: " << m_count << std::endl;
				std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
				std::cout << "Fail time: " << fail << std::endl << std::endl;
				mtx.unlock();
				break;
			}
			else
			{
				fail++;
			}
		}
	}
};

class Ip5
{
	//Class for callable obj5
public:
	void Iprint5(const std::string& s, int count)
	{//callable obj5: binded member function
		//mtx.lock();
		int fail = 0;
		while (1)
		{
			if (mtx.try_lock())
			{
				std::cout << "Iprint 5: " << s << std::endl;
				std::cout << "Count: " << count << std::endl;
				std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
				std::cout << "Fail time: " << fail << std::endl << std::endl;
				mtx.unlock();
				break;
			}
			else
			{
				fail++;
			}
		}
	}
};

class Ip6
{
	//Class for callable obj 6
public:
	static void Iprint6(const std::string& s, int count)
	{//callable obj6: static member function
		//mtx.lock();
		int fail = 0;
		while (1)
		{
			if (mtx.try_lock())
			{
				std::cout << "Iprint 6: " << s << std::endl;
				std::cout << "Count: " << count << std::endl;
				std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
				std::cout << "Fail time: " << fail << std::endl << std::endl;
				mtx.unlock();
				break;
			}
			else
			{
				fail++;
			}
		}
	}
};

int main()
{
	//time- system performance
	std::chrono::time_point <std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();


	std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
	auto Iprint2 = [](const std::string& s, int count)
	{//callable obj2: stored lambda function
		//mtx.lock();
		int fail = 0;
		while (1)
		{
			if (mtx.try_lock())
			{
				std::cout << "Iprint 2: " << s << std::endl;
				std::cout << "Count: " << count << std::endl;
				std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
				std::cout << "Fail time: " << fail << std::endl << std::endl;
				mtx.unlock();
				break;
			}
			else
			{
				fail++;
			}
		}
	};
	std::thread th[6];//Array of threads
	//Build the threads
	th[0] = std::thread(Iprint1, "Free function", 1);
	th[1] = std::thread(Iprint2, "Stored lambda function", 2);
	th[2] = std::thread([](const std::string& s, int count)
		{//callable obj3: lambda function
			//mtx.lock();
			int fail = 0;
			while (1)
			{
				if (mtx.try_lock())
				{
					std::cout << "Iprint 3: " << s << std::endl;
					std::cout << "Count: " << count << std::endl;
					std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
					std::cout << "Fail time: " << fail << std::endl << std::endl;
					mtx.unlock();
					break;
				}
				else
				{
					fail++;
				}
			}
		}, "Lambda function", 3);
	Ip4 Iprint4("Function object", 4);
	Ip5 ip5;
	th[3] = std::thread(Iprint4);
	th[4] = std::thread(std::bind(&Ip5::Iprint5, ip5, "Binded member function", 5));
	th[5] = std::thread(&Ip6::Iprint6, "Static member function", 6);

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