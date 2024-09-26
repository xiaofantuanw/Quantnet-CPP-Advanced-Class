//test.cpp
//Author: TengxiaoFan
//This is the test file for type forward_list
#include <iostream>
#include <forward_list>

template <typename T>
int forward_list_size(std::forward_list<T> l)
{//A function that returns the size of a forward list
	return std::distance(l.begin(), l.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::forward_list<T>& v) 
{//operator << to output the list
	for (const auto& elem : v) {
		s << elem<<", ";
	}
	return s ;
}

int main()
{
	std::forward_list<double> l1{};//Default list
	std::forward_list<double> l2(10, 3.14);//a list with n elements and a given value
	std::forward_list<double> l3{ 1.0,1.1,1.2,1.3,1.4,1.5 };//a list that is built from an initialiser list
	//test the function of size
	std::cout<<"Size of list 1: "<<forward_list_size<double>(l1) << std::endl;
	std::cout << "Size of list 2: " << forward_list_size<double>(l2) << std::endl;
	std::cout << "Size of list 3: " << forward_list_size<double>(l3) << std::endl;
	//test insert (using list 3)
	auto beginIt = l3.begin();
	l3.insert_after(beginIt, 2.0);// insert after a given position based on value
	std::cout << "List 3: " << l3 << std::endl;
	auto AnotherIt=l3.insert_after(++beginIt, 2, 2.5);//insert after a given position based on value and count, return the last positon
	std::cout << "List 3: " << l3 << std::endl;
	l3.insert_after(AnotherIt, l3.begin(), l3.end());//insert after a given position based on two iterators
	std::cout << "List 3: " << l3 << std::endl;
	l3.insert_after(++AnotherIt, {1.14,5.1});//insert after a given position based on initialization list
	std::cout << "List 3: " << l3 << std::endl;

	//test erase
	l3.erase_after(AnotherIt);//Erase one
	std::cout << "List 3: " << l3 << std::endl;
	l3.erase_after(AnotherIt, l3.end());//Erase from one to another
	std::cout << "List 3: " << l3 << std::endl;

	//test splice
	l3.splice_after(l3.begin(), l2, l2.begin());//move an element from l2 to l3.
	std::cout << "List 3: " << l3 << std::endl;
	std::cout << "Size of list 2: " << forward_list_size(l2)<<std::endl;

	beginIt = l2.begin();
	++beginIt;++beginIt;++beginIt;
	l3.splice_after(l3.before_begin(), l2, l2.begin(), beginIt);//move some elements from l2 to l3 (insert at first).
	std::cout << "List 3: " << l3 << std::endl;
	std::cout << "Size of list 2: " << forward_list_size(l2)<<std::endl;

	//test merge
	//l3.merge(l2);//We cannot merge unsorted lists
	l3.sort();l2.sort();//Sort the forward lists
	l3.merge(l2);//Merge
	std::cout << "List 3: " << l3 << std::endl;//l2 will be empty

}