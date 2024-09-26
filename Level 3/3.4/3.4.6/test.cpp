#include <future>
#include <iostream>
#include <thread>
#include <chrono>

//f1 to f4
template <typename T>
T f1(T a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return a+1;
}

template <typename T>
T f2(T a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return a+2;
}

template <typename T>
T f3(T c)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return c+3 ;
}

template <typename T>
T f4(T b,T d)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return b+d+4;
}


//f1 to f4 with promise
template <typename T>
void f1pro(T a,std::promise<T>& promiseobj)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	promiseobj.set_value(a + 1);
}

template <typename T>
void f2pro(T a, std::promise<T>& promiseobj)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	promiseobj.set_value(a+2);
}

template <typename T>
void f3pro(T c, std::promise<T>& promiseobj)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	promiseobj.set_value(c + 3);
}

template <typename T>
void f4pro(T b, T d,std::promise<T>& promiseobj)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	promiseobj.set_value( b + d + 4);
}

template <typename T>
T test_sequence(T a)
{//Sequentially
	auto b = f1(a);
	auto c = f2(a);
	auto d = f3(c);
	auto f = f4(b, d);
	return f;
}

template<typename T>
T test_async(T a)
{//Use future to do async
	std::future<T> b=(std::async(std::launch::async, f1<T>, a));
	std::future<T> c = (std::async(std::launch::async, f2<T>, a));
	std::future<T> d = (std::async(std::launch::async, f3<T>, c.get()));
	std::future<T> f = (std::async(std::launch::async, f4<T>, b.get(),d.get()));
	return f.get();
}

template <typename T>
T test_promise(T a)
{//Use promise to deliver data
	//Build promise and future
	std::promise<T> bpro;
	std::future<T> bfut=bpro.get_future();
	std::promise<T> cpro;
	std::future<T> cfut = cpro.get_future();
	std::promise<T> dpro;
	std::future<T> dfut = dpro.get_future();
	std::promise<T> fpro;
	std::future<T> ffut = fpro.get_future();
	//Do these things in threads
	std::thread bth(f1pro<T>, a, std::ref(bpro));
	std::thread cth(f2pro<T>, a, std::ref(cpro));
	std::thread dth(f3pro<T>, cfut.get(), std::ref(dpro));
	std::thread fth(f4pro<T>, bfut.get(), dfut.get(), std::ref(fpro));
	//join the thread
	bth.join();
	cth.join();
	dth.join();
	fth.join();
	return ffut.get();
}

template <typename T>
T test_packaged_task(T a)
{
	//Packaged tasks
	std::packaged_task<T(T)> task1(f1<T>);
	auto b = task1.get_future();
	std::packaged_task<T(T)> task2(f2<T>);
	auto c = task2.get_future();
	std::packaged_task<T(T)> task3(f3<T>);
	auto d = task3.get_future();
	std::packaged_task<T(T,T)> task4(f4<T>);
	auto f = task4.get_future();
	//Put the packaged tasks into threads
	std::thread th1(std::move(task1),a);
	std::thread th2(std::move(task2), a);
	std::thread th3(std::move(task3), c.get());
	std::thread th4(std::move(task4), b.get(),d.get());
	//Join the threads
	th1.join();th2.join();th3.join();th4.join();
	return f.get();
}

int main()
{
	//1. sequential
	//start the clock
	auto start = std::chrono::system_clock::now();
	//executions
	auto result1=test_sequence<int>(1);
	//end the clock
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Sequence, Result: " <<result1<< std::endl;
	std::cout << "Time: " << dur << std::endl << std::endl;

	//2. async
	//start the clock
	start = std::chrono::system_clock::now();
	//executions
	auto result2 = test_async<int>(1);
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Async, Result: " << result2 << std::endl;
	std::cout << "Time: " << dur << std::endl << std::endl;

	//3. promise
	//start the clock
	start = std::chrono::system_clock::now();
	//executions
	auto result3 = test_promise<int>(1);
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Promise, Result: " << result3 << std::endl;
	std::cout << "Time: " << dur << std::endl << std::endl;

	//4. packaged task
	//start the clock
	start = std::chrono::system_clock::now();
	//executions
	auto result4 = test_packaged_task<int>(1);
	//end the clock
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	//Output
	std::cout << "Packaged task, Result: " << result4 << std::endl;
	std::cout << "Time: " << dur << std::endl << std::endl;
}
//Result: for heavyweight functions, we can see that the three parallel methods have significant improvement compared with sequential
//These parallel methods performs almost equally well