//test.cpp
// Author: TengxiaoFan
//This is a test file for boost bimap: a mapping between a domain D and a range (or co-domain) R.
#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <iostream>
#include <string>
#include <tuple>

using namespace boost::bimaps;

void test1()
{//D=set(unique); R=list(not unique)
	typedef bimap<set_of<std::string>, list_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 1: D=set, R=list\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right()<<std::endl;
	}
	std::cout << "\n";
}

void test2()
{//D=set(unique); R=set(unique)
	typedef bimap<set_of<std::string>, set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 2: D=set, R=set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test3()
{//D=set(unique); R=unordered set(unique)
	typedef bimap<set_of<std::string>, unordered_set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 3: D=set, R=unordered set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test4()
{//D=Multiset(not unique); R=list(not unique)
	typedef bimap<multiset_of<std::string>, list_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 4: D=multiset, R=list\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test5()
{//D=Multiset(not unique); R=set(unique)
	typedef bimap<multiset_of<std::string>, set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 5: D=multiset, R=set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test6()
{//D=Multiset(not unique); R=unordered set(unique)
	typedef bimap<multiset_of<std::string>, unordered_set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 6: D=multiset, R=unordered set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test7()
{//D=Unordered set(unique); R=list(not unique)
	typedef bimap<unordered_set_of<std::string>, list_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 7: D=unordered set, R=list\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test8()
{//D=Unordered set(unique); R=set(unique)
	typedef bimap<unordered_set_of<std::string>, set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 8: D=unordered set, R=set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test9()
{//D=Unordered set(unique); R=Unordered set(unique)
	typedef bimap<unordered_set_of<std::string>, unordered_set_of<int>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 9: D=unordered set, R=unordered set\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}


void test2b()
{//D=set(unique); R=set(unique), comparitor=std::greater<>
	typedef bimap<set_of<std::string,std::greater<>>,set_of<int,std::greater<>>>BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 2b: D=set, R=set, comp=std::greater<>\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

void test5b()
{//D=Multiset(not unique); R=set(unique); comparitor=std::greater<>
	typedef bimap<multiset_of<std::string,std::greater<>>, set_of<int,std::greater<>>> BMType;
	BMType bm;
	//Insert some instances
	bm.insert(BMType::value_type("one", 1));
	bm.insert(BMType::value_type("one", 2));
	bm.insert(BMType::value_type("one", 3));

	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 1));
	bm.insert(BMType::value_type("two", 2));

	bm.insert(BMType::value_type("three", 2));
	bm.insert(BMType::value_type("three", 8));
	bm.insert(BMType::value_type("three", 9));

	//Print the instances
	std::cout << "Test 5b: D=multiset, R=set, comp=std::greater<>\n";
	for (auto it = bm.begin();it != bm.end();it++)
	{
		std::cout << it->get_left() << "->" << it->get_right() << std::endl;
	}
	std::cout << "\n";
}

int main()
{
	//Tests
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();

	//Tests for different comparitors
	test2b();
	test5b();
}