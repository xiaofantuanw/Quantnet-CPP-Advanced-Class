//test.cpp
//Author: TengxiaoFan
//this is the comparison between multiset and unordered multiset
#include <iostream>
#include <unordered_set>
#include "Point.hpp"
#include <chrono>
#include <functional>
#include <set>
#include <boost/container_hash/hash.hpp>

template<>
struct std::hash<Point>
{
	std::size_t operator()(Point const& p) const noexcept
	{//Create std::hash<Point>
		std::size_t seed = 0;
		boost::hash_combine(seed, p.X());
		boost::hash_combine(seed, p.Y());
		return seed;
	}
};

struct myhash
{
	std::size_t operator()(Point const& p) const noexcept
	{//Create my hash function
		std::size_t seed = 0;
		boost::hash_combine(seed, p.X());
		boost::hash_combine(seed, p.Y());
		return seed;
	}
};

struct PointCmp
{//Point compare function
	bool operator()(const Point& lhs, const Point& rhs) const 
	{
		if (lhs.X() == rhs.X())
		{
			return lhs.Y() < rhs.Y();
		}
		else
		{
			return lhs.X() < rhs.X();
		}
	}
};


void test_default(int N)
{//Test for unordered multiset with default hash
	auto start = std::chrono::system_clock::now();
	std::unordered_multiset<Point> set1;//Create an instance of unordered multiset
	//Some executions
	set1.emplace(Point(2, 2));
	set1.insert(Point(1, 1));
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	for (auto it = set1.begin();it != set1.end();it++)
	{
		it = set1.erase(it);
	}
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	set1.clear();
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "Unordered Multiset of Point instances using default hash: " << dur << std::endl;
}

void test_my (int N)
{//Test for unordered multiset with my hash
	auto start = std::chrono::system_clock::now();
	std::unordered_multiset<Point, myhash> set1;//Create an instance of unordered multiset
	set1.emplace(Point(2, 2));
	set1.insert(Point(1, 1));
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	for (auto it = set1.begin();it != set1.end();it++)
	{
		it = set1.erase(it);
	}
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	set1.clear();
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "Unordered Multiset of Point instances using my hash: " << dur << std::endl;
}

void test_ordered(int N)
{//test of ordered set
	auto start = std::chrono::system_clock::now();
	std::multiset<Point,PointCmp> set1;//Create an instance of unordered multiset
	set1.emplace(Point(2, 2));
	set1.insert(Point(1, 1));
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	for (auto it = set1.begin();it != set1.end();it++)
	{
		it = set1.erase(it);
	}
	for (int i = 0;i < N;i++)
	{
		set1.emplace(Point(i, 0));
	}
	set1.clear();
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "Ordered Multiset of Point instances: " << dur << std::endl;
}



int main()
{
	test_default(10000);
	test_my(10000);
	test_ordered(10000);//Slower!
}