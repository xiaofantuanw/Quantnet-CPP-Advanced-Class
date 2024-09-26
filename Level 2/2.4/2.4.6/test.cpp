//test.cpp
//Author: TengxiaoFan
//This is the test file for weak pointers
#include <memory>
#include <iostream>


int main()
{
	std::shared_ptr<double> sptr(new double(3.0));
	std::cout << sptr.use_count() << std::endl;//1
	std::weak_ptr<double> wptr = sptr;
	std::cout << sptr.use_count() << std::endl;//still 1, weak pointer has no ownership
	std::weak_ptr<double> wptr2 = wptr;//Assign a weak ptr to weak ptr
	std::cout << sptr.use_count() << std::endl;//still 1
	std::shared_ptr<double> sptr2 = wptr.lock();//Assign a weak ptr to shared ptr
	std::cout << sptr.use_count() << std::endl;//2

	//Prove that the weak ptr is not empty
	std::cout << "The value of weakptr: " << (*wptr.lock())<<std::endl;
	std::cout << sptr.use_count() << std::endl;//2

}