//test.cpp
//Author: Tengxiao Fan
//This is the test file for atomic operations
#include <iostream>
#include <atomic>

int main()
{
	//Create atomic objects
	std::atomic_bool atm_bool(true);//atomic boolean
	std::atomic_int atm_int(3);//atomic int
	std::atomic_llong atm_llong(5);//atomic long long
	
	//Lock free?
	std::cout << std::boolalpha;
	std::cout <<"Atomic Boolean: "<< atm_bool <<"; Lock free? "<<atm_bool.is_lock_free() << std::endl;//true
	std::cout << "Atomic Int: " << atm_int << "; Lock free? " << atm_int.is_lock_free() << std::endl;//true
	std::cout << "Atomic long long: " << atm_llong << "; Lock free? " << atm_llong.is_lock_free() << std::endl;//true

	std::atomic_bool atm_bool2(false);//atomic boolean
	atm_bool.exchange(atm_bool2);//Atomically replace the value of one atomic object by another atomic object
	std::cout << "Atomic replaced: "<<atm_bool << std::endl;

	std::cout << "Atomic load: " << atm_int.load() << std::endl;//Atomically load an atomic object and return its current value.

}