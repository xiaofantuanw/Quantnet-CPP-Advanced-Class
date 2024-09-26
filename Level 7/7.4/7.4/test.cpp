//test.cpp
//TengxiaoFan
//This is the test function for template class TmpProcessor.
#include "TmpProcessor.hpp"
#include <iostream>
#include <future>

// Function categories 
template <typename T> using FactoryFunction = std::function<T()>;
template <typename T> using ComputeFunction = std::function<T(const T& t)>;
template <typename T> using DispatchFunction = std::function<void(T& t)>;
#include <chrono>

//Some functions to be paralleled
//f1 to f4
template <typename T>
T f1(const T& a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return a + 1;
}

template <typename T>
T f2(const T& a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return a + 2;
}

template <typename T>
T f3(const T& c)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return c + 3;
}

template <typename T>
T f4(const T& b, const T& d)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return b + d + 4;
}


//Sequential and Parallel Compute functions
template <typename T>
T Sequentialcf(const T& a)
{//Sequentially
	auto b = f1(a);
	auto c = f2(a);
	auto d = f3(c);
	auto f = f4(b, d);
	return f;
}

template<typename T>
T Parallelcf(const T& a)
{//Use future to do async
	std::future<T> b = (std::async(std::launch::async, f1<T>, a));
	std::future<T> c = (std::async(std::launch::async, f2<T>, a));
	std::future<T> d = (std::async(std::launch::async, f3<T>, c.get()));
	std::future<T> f = (std::async(std::launch::async, f4<T>, b.get(), d.get()));
	return f.get();
}

int main()
{
	//Simple functions
	FactoryFunction<int> ff = []() {return 1;};
	ComputeFunction<int> cf = [](const int& t) {return 2 * t;};
	DispatchFunction<int> df = [](int& t) {std::cout << "Number: " << t << std::endl;};
	//Test the template class
	TmpProcessor<int> tp(ff, cf, df);
	tp.algorithm();

	//Test the sequential and parallel approaches
	TmpProcessor<int> tpSeq(ff, Sequentialcf<int>, df);
	TmpProcessor<int> tpPar(ff, Parallelcf<int>, df);
	//Test the time

	//Sequential
	auto start = std::chrono::system_clock::now();
	// Sequential algo
	tpSeq.algorithm();
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Sequential: "
		<< double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den
		<< " seconds" << std::endl;
	//Parallel
	start = std::chrono::system_clock::now();
	// Parallel algo
	tpPar.algorithm();
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Parallel: "
		<< double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den
		<< " seconds" << std::endl;
}