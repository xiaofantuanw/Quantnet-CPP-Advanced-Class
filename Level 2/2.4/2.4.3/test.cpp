//test.cpp
//Author: TengxiaoFan
//This is a test file for deprecated auto_ptr. Now we use unique_ptr instead
#include <iostream>
#include <memory>


int main()
{
	//using std::auto_ptr;
	// Define auto_ptr pointers instead of raw pointers 
	//std::auto_ptr <double> d(new double (1.0));
	// Dereference 
	//*d = 2.0;
	// Change ownership of auto_ptr 
	// (after assignment, d is undefined) 
	//auto_ptr <double> d2 = d; 
	//*d2 = 3.0;
	//std::cout << "Auto values: " << *d.get() << ", " << *d2.get();
	
	//There will be a runtime error because we cannot visit *d if d is undefined

	//Using unique_ptr
	// Define auto_ptr pointers instead of raw pointers 
	std::unique_ptr <double> d(new double (1.0));
	// Dereference 
	*d = 2.0;
	// Change ownership of auto_ptr 
	// (after assignment, d is undefined) 
	std::unique_ptr <double> d2 = std::move(d); //We have to use std::move for assignment
	*d2 = 3.0;
	//std::cout << "Auto values: " << *d.get() << ", " << *d2.get();//Still Runtime error
	std::cout << "Auto values: "  << *d2.get()<<std::endl;
}