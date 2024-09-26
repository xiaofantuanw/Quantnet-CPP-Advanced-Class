//test.cpp
//Author: TengxiaoFan
//This is the test file for Propagator pattern
#include "Observer.hpp"
#include "Propagator.hpp"
#include <memory>
#include <iostream>

int main()
{//Four counters
	std::shared_ptr<Counter> count1(new Counter(10.0)), count2(new Counter(5.0)), count3(new Counter(1.0)), count4(new Counter(3.0));
	count1->Addob(count2);
	count2->Addob(count3);
	count2->Addob(count4);
	//1-2-(3,4)
	//Increase count2. this will update 3 and 4.
	count2->IncreaseCounter();
	std::cout << "Count1: " << count1->GetCounter() << std::endl;
	std::cout << "Count2: " << count2->GetCounter() << std::endl;
	std::cout << "Count3: " << count3->GetCounter() << std::endl;
	std::cout << "Count4: " << count4->GetCounter() << std::endl;
	//Decrease count1, this will update 2,3,4
	count1->DecreaseCounter();
	std::cout << "Count1: " << count1->GetCounter() << std::endl;
	std::cout << "Count2: " << count2->GetCounter() << std::endl;
	std::cout << "Count3: " << count3->GetCounter() << std::endl;
	std::cout << "Count4: " << count4->GetCounter() << std::endl;
}