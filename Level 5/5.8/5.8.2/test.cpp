//test.cpp
//Author: TengxiaoFan
//This is a test function for stl priority queue
#include <queue>
#include <iostream>

void test_default()
{
	//Default priority queue
	std::priority_queue<int> q;
	//Input
	for (int i : { 10, 5, 20, 30, 25, 7, 40 })
	{
		q.push(i);
	}
	//Output
	while (!q.empty())
	{
		std::cout << q.top() << ",";
		q.pop();
	}
	std::cout << "\n";
}

void test_stdgreater()
{
	//priority queue with std::greater
	std::priority_queue<int,std::vector<int>,std::greater<int>> q;
	//Input
	for (int i : { 10, 5, 20, 30, 25, 7, 40 })
	{
		q.push(i);
	}
	//Output
	while (!q.empty())
	{
		std::cout << q.top() << ",";
		q.pop();
	}
	std::cout << "\n";
}

void test_lambda()
{
	//comparator
	auto cmp = [](int left, int right)->bool { return (left > right); };
	//Default priority queue
	std::priority_queue<int,std::vector<int>,decltype(cmp)> q(cmp);
	//Input
	for (int i : { 10, 5, 20, 30, 25, 7, 40 })
	{
		q.push(i);
	}
	//Output
	while (!q.empty())
	{
		std::cout << q.top() << ",";
		q.pop();
	}
	std::cout << "\n";
}


int main()
{
	test_default();
	test_stdgreater();
	test_lambda();
}
