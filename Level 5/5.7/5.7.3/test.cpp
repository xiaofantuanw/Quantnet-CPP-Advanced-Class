//test.cpp
// Author: TengxiaoFan
//This is a test file for boost bimap Book information
#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <iostream>
#include <string>
#include <tuple>

using namespace boost::bimaps;
//A book type with information of abstract and price
using BookType = bimap <
	multiset_of<std::string>,//author
	set_of<std::string>,//title
	with_info<std::tuple<std::string, double>>>;//abstract and price

int main()
{
	BookType b;
	//insert some instances
	b.insert(BookType::value_type("J.K. Rowling", "Harry Porter 1", std::make_tuple("A child book.", 30)));
	b.insert(BookType::value_type("J.K. Rowling", "Harry Porter 2", std::make_tuple("Another child book.", 35)));
	b.insert(BookType::value_type("Daniel J. Duffy", "Introduction to the Boost C++ Libraries", std::make_tuple("Indroduce boost C++.", 99.99)));
	//Print the price of a book with given author (only the first book)
	std::cout << "Price: " << std::get<1>(b.left.find("J.K. Rowling")->info) << std::endl;
	std::cout << "Price: " << std::get<1>(b.left.find("Daniel J. Duffy")->info) << std::endl;
}