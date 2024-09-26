//test.cpp
//This is the test file for the execution time of some parallel algorithms 
#include <chrono>
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <omp.h>
#include <execution>
#include <future>
#include <vector>
#include <thread>
#include <functional>

const int length = 1000000;
std::vector<double> testarray(length,1.0);


using Myiterator = std::vector<double>::iterator;

using BinaryOperator = std::function<double(double, double)>;
double parallel_sum_task(Myiterator begin, Myiterator end,double startvalue,BinaryOperator op)
{
	if (end-begin < 1000)
	{// caseA: size is small, accumulate directly
		return std::accumulate(begin, end, startvalue,op);
	}
	else 
	{
		//CaseB: size is big, partition
		Myiterator middle = begin + (end-begin) / 2;//Find the middle iterator
		std::future<double> partsum = std::async(std::launch::async,parallel_sum_task, middle, end,startvalue,op);//A new task async
		double sum = parallel_sum_task(begin, middle,startvalue,op);
		return op(sum,partsum.get());
	}
}

void parallel_sum_thread(Myiterator begin, Myiterator end,std::promise<double> promiseObj)
{
	if (end - begin < 1000)
	{// caseA: size is small, accumulate directly
		promiseObj.set_value(std::accumulate(begin, end, 0.0));
	}
	else
	{
		//CaseB: size is big, partition
		Myiterator middle = begin + (end - begin) / 2;//Find the middle iterator
		std::promise<double> partsum1_pro;
		std::future<double> partsum1_fut=partsum1_pro.get_future();
		std::promise<double> partsum2_pro;
		std::future<double> partsum2_fut = partsum2_pro.get_future();
		std::thread partsum1(parallel_sum_thread, middle, end,std::move(partsum1_pro));//A new thread
		parallel_sum_thread(begin, middle,std::move(partsum2_pro));
		promiseObj.set_value(partsum1_fut.get() + partsum2_fut.get());
		partsum1.join();
	}
}



int main()
{
	//1. std::accumulate
	//start the clock
	auto start = std::chrono::system_clock::now();
	//executions
	double result1 = std::accumulate(testarray.begin(), testarray.end(), 0.0);//accumulate
	//end the clock
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Result of std::accumulate: " << result1 << std::endl;
	std::cout << "Duration: " << dur << std::endl<<std::endl;

	//2. OpenMP
	//start the clock
	start = std::chrono::system_clock::now();
	//executions
	double result2 = 0.0;
	omp_set_num_threads(2); 
	#pragma omp parallel for reduction(+:sumParallel) 
	for (long i = 0; i < length; ++i) 
	{
		result2 += testarray[i]; 
	}
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Result of OpenMP: " << result2 << std::endl;
	std::cout << "Duration: " << dur << std::endl << std::endl;


	//3. My parallel using task
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	double result3 = parallel_sum_task(testarray.begin(), testarray.end(),0, [](double a, double b) {return a + b;});
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Result of My parallel function (task): " << result3 << std::endl;
	std::cout << "Duration: " << dur << std::endl << std::endl;


	//4. My parallel using thread
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::promise<double> result4_pro;
	std::future<double> result4 = result4_pro.get_future();
	parallel_sum_thread(testarray.begin(), testarray.end(),std::move(result4_pro));
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Result of My parallel function (thread): " << result4.get() << std::endl;
	std::cout << "Duration: " << dur << std::endl << std::endl;

	//5. My parallel using task (multiply)
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	double result5 = parallel_sum_task(testarray.begin(), testarray.end(),1.0, std::multiplies<double>());
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Result of My parallel function (task, multiply): " << result5 << std::endl;
	std::cout << "Duration: " << dur << std::endl << std::endl;

	//6. STL Algorithms-sort
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::sort(testarray.begin(), testarray.end());
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of std::sort: " << dur << std::endl;
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::sort(std::execution::par,testarray.begin(), testarray.end());
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of parallel sort: " << dur << std::endl<<std::endl;

	//7. STL Algorithms-transform
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::transform(testarray.begin(), testarray.end(), testarray.begin(), [](double a) {return 2 * a;});
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of std::transform: " << dur << std::endl;
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::transform(std::execution::par,testarray.begin(), testarray.end(), testarray.begin(), [](double a) {return 2 * a;});
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of parallel transform: " << dur << std::endl << std::endl;


	//8. STL Algorithms-find
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::find(testarray.begin(), testarray.end(), 0.0);
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of std::find: " << dur << std::endl;
	//start the clock
	start = std::chrono::system_clock::now();
	//execution
	std::find(std::execution::par,testarray.begin(), testarray.end(), 0.0);
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Time of parallel find: " << dur << std::endl << std::endl;
}

//Test results
// 1. OpenMP Parallel will perform better than std::accumulate only when the size is very large.
// 2. My Parallel performs badly because the recursive function use the STACK
// 3. Task is better than Thread in this case
// 4. std algorithms new parallel features performs better than original functions except for sort
//