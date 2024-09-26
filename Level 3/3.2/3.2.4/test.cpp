//This code took the code in the slides for refrence
//test.cpp
//Author: TengxiaoFan
//This is the test file for worker and master thread, using atomic_flag

#include <mutex>
#include <string>
#include <atomic>
#include <iostream>

// Types and data needed
//mutex and lock and cv are no longer needed
std::string data; // Shared data between master and worker
//std::mutex m; // Ensures no race condition
// Synchronisation between master and worker
//std::condition_variable cv;

//Boolean state variables
std::atomic_flag workerReady = ATOMIC_FLAG_INIT; //initial status of worker
std::atomic_flag masterReady = ATOMIC_FLAG_INIT;//initial status of master

void WorkerThread()
{//This is the worker thread
	std::cout << "Worker is called...\n";
	// False state: wait until master sends data
	//std::unique_lock<std::mutex> myLock(m);//No lock is needed
	workerReady.wait(false);
	// Now in True state
	std::cout << "Worker is processing data\n";
	data += "addition from worker";
	// Notify master
	masterReady.test_and_set();
	// Postprocess
	masterReady.notify_one();
	std::cout << "Worker is exited...\n";
}

int main()
{//This is the main program and master thread
	std::cout << "Master is called...\n";
	std::thread worker(WorkerThread);
	data = "Master data";
	// Transition into True state
	{
		//std::lock_guard<std::mutex> myLock(m);//no need for lock
		workerReady.test_and_set();
	}
	std::cout << "Master has notified worker, wait for response...\n";
	workerReady.notify_one();
	{
		//std::unique_lock<std::mutex> myLock(m);//no need for lock
		masterReady.wait(false);//wait for the master to be ready
	}
	std::cout << "Master back again...\n";
	worker.join();
}