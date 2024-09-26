//test.cpp
//Author: TengxiaoFan
//This is the test file for priority queue
#include <iostream>
#include <queue>

int main()
{
	//Test of Priority queue 1
	std::priority_queue<long long> q1;//Type: long long, other settings default
	std::cout << "Priority queue 1" << std::endl;
	q1.push(66);
	q1.push(22);
	q1.push(44);
	std::cout << q1.top() << std::endl;//66
	q1.pop();//delete 66
	q1.push(11);
	q1.push(22);
	q1.push(33);
	q1.pop();//delete 44
	while (!q1.empty())
	{
		std::cout << q1.top() << std::endl;
		q1.pop();//33,22,22,11
	}

	//Test of Priority queue 2
	std::priority_queue<long long,std::deque<long long>, std::greater<long long>> q2;
	//Type: long long, Container: deque, Compare: Greater
	std::cout << "Priority queue 2" << std::endl;
	q2.push(66);
	q2.push(22);
	q2.push(44);
	std::cout << q2.top() << std::endl;//2
	q2.pop();//delete 22
	q2.push(11);
	q2.push(22);
	q2.push(33);
	q2.pop();//delete 11
	while (!q2.empty())
	{
		std::cout << q2.top() << std::endl;
		q2.pop();//22,33,44,66
	}

	//Test of Priority queue 3
	auto cmp = [](long long a, long long b) {return (a > b);};//Compare function
	std::priority_queue<long long, std::deque<long long>, decltype(cmp) > q3(cmp);
	//Type: long long, Container: deque, Compare: Greater
	std::cout << "Priority queue 3" << std::endl;
	q3.push(66);
	q3.push(22);
	q3.push(44);
	std::cout << q3.top() << std::endl;//2
	q3.pop();//delete 22
	q3.push(11);
	q3.push(22);
	q3.push(33);
	q3.pop();//delete 11
	while (!q3.empty())
	{
		std::cout << q3.top() << std::endl;
		q3.pop();//22,33,44,66
	}
}
