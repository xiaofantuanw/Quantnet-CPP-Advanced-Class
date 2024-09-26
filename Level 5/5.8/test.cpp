//test.cpp
//Author: TengxiaoFan
//This is a test function for stl heap
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec2{ 3,4,5,6,7,5,6,7,8,9,1,2,3,4 };
	
	
	//calling this function if the underlying container is not a heap, the result will be incorrect
	// since only some exchanges will be done, the vector is still not a heap
	//vec2.push_back(8);
	//std::push_heap(vec2.begin(), vec2.end());
	//std::pop_heap(vec2.begin(), vec2.end());
	//vec2.pop_back();
	//Print the results
	//for (auto it = vec2.begin();it != vec2.end();it++)
	//{
	//	std::cout << (*it) << ", ";
	//}
	//std::cout << "\n";

	std::make_heap(vec2.begin(), vec2.end());//make a heap
	//Print the results
	for (auto it = vec2.begin();it != vec2.end();it++)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << "\n";
	//				9
	//		  8		          6
	//	  7	      7	      5	      5
	//	3	6	4	1	2	3	4

	//Test pop
	std::pop_heap(vec2.begin(), vec2.end());//Actually put the number popped from the heap to the end of the heap, not deleting it
	vec2.pop_back();//Delete the element at the end of vector
	//Print the results
	for (auto it = vec2.begin();it != vec2.end();it++)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << "\n";

	//test push
	vec2.push_back(8);//Must first push it into the vector
	std::push_heap(vec2.begin(), vec2.end());//since push_heap doesn't change the heap
	//Print the results
	for (auto it = vec2.begin();it != vec2.end();it++)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << "\n";

	//largest element in the heap:
	std::cout << "Largest: " << vec2[0] << std::endl;


	//test sort
	std::sort_heap(vec2.begin(), vec2.end());//No longer a heap after that
	//Print the results
	for (auto it = vec2.begin();it != vec2.end();it++)
	{
		std::cout << (*it) << ", ";
	}
	std::cout << "\n";

}