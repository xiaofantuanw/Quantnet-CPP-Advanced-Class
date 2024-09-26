//test.cpp
//Author: TengxiaoFan
//This is the test file for class StopWatch
#include "StopWatch.hpp"
#include <iostream>
#include <thread>

int main()
{
	//Test the stopwatch
	StopWatch sw{};
	sw.StartStopWatch();//start
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));//sleep for 3000 ms
	sw.StopStopWatch();//stop
	std::cout << "Time 1: " << sw.GetTime() << std::endl;

	sw.Reset();//Reset the watch
	sw.StartStopWatch();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));//Sleep for 500ms
	sw.StopStopWatch();
	std::cout << "Time 2: " << sw.GetTime() << std::endl;
}