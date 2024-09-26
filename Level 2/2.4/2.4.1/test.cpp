//test.cpp
//Author: TengxiaoFan
//This is the test file for unique pointer, and its advantages towards raw pointer
#include "Point.hpp"
#include <iostream>
#include <memory>

//Alias template
template<typename T>
using uptr = std::unique_ptr<T>;

using uptr_Pt = uptr<Point>;

int main()
{
	{ // Block with raw pointer lifecycle
		try
		{
			double* d = new double(1.0); 
			Point* pt = new Point(1.0, 2.0); // Two-d Point class
			// Dereference and call member functions 
			*d = 2.0; 
		
			(*pt).X(3.0); // Modify x coordinate 
			(*pt).Y(3.0); // Modify y coordinate
			// Can use operators for pointer operations 
			pt->X(3.0); // Modify x coordinate 
			pt->Y(3.0); // Modify y coordinate
			throw - 1;
			// Explicitly clean up memory (if you have not forgotten) 
			//If the exception is thrown, when using raw pointer, there will be a memory leak
			delete d;
			delete pt;
		}
		catch (int a)
		{
			std::cout << "Exception -1 caught!" << std::endl;
		}
	}

	{ // Block with std::unique_ptr lifecycle
		try
		{
			uptr<double> d(new double(1.0));
			uptr_Pt pt(new Point(1.0, 2.0)); // Two-d Point class
			// Dereference and call member functions 
			*d = 2.0;

			(*pt).X(3.0); // Modify x coordinate 
			(*pt).Y(3.0); // Modify y coordinate
			// Can use operators for pointer operations 
			pt->X(3.0); // Modify x coordinate 
			pt->Y(3.0); // Modify y coordinate
			throw - 1;
			// No need to Explicitly clean up memory 
			//If the exception is thrown, when using unique pointer, the destructor will be called
			
		}
		catch (int a)
		{
			std::cout << "Exception -1 caught!" << std::endl;
		}

		//initialising two unique pointers to the same pointer
		Point* pt0 = new Point(2.0, 3.0);
		uptr_Pt pt1(pt0);
		//std::unique_ptr<Point> pt2(pt0);
		std::cout << "(" << pt1->X() << ", " << pt1->Y() <<")"<< std::endl;//Output sth
		//Memory will be unsafe
		//assigning a unique pointer to another unique pointers
		//pt2 = pt1;//We cannot assign a unique pointer like this.
		uptr_Pt pt3 = std::move(pt1);//We can only move the unique ptr
		//std::cout << pt1->X() << std::endl;//Error, pt2 is moved
		std::cout << pt3->X() << std::endl;
	}
}