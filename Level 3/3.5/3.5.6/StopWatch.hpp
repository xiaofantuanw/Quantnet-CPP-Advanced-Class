//StopWatch.cpp
//Author: TengxiaoFan
//This is the header file for class StopWatch, which gives the time of a program
#ifndef StopWatch_HPP
#define StopWatch_HPP
#include <chrono>

class StopWatch 
{
public:
	//Member functions
	StopWatch() { finished = 0; }//Default creator
	void StartStopWatch()
	{//start the stopwatch
		start_time = std::chrono::system_clock::now();
	}
	void StopStopWatch()
	{//finish the stopwatch
		end_time = std::chrono::system_clock::now();
		finished = 1;
	}
	void Reset()
	{//reset the stopwatch to be unused
		finished = 0;
	}
	double GetTime() const
	{//get the time(second) of the stopwatch
		if (finished)
		{
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
			return double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
		}
		else
		{
			return -1;//Unfinished
		}
	}
private: 
//Member data
	std::chrono::time_point<std::chrono::system_clock> start_time;
	std::chrono::time_point<std::chrono::system_clock> end_time;
	bool finished;//to show whether the execution is finished
//Private member functions
	StopWatch(const StopWatch& source):start_time(source.start_time),end_time(source.end_time),finished(source.finished) {}
	StopWatch& operator=(const StopWatch& source) = default;
};

#endif