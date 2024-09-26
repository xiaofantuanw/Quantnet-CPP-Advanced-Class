//test.cpp
// Author: TengxiaoFan
//This is a test file for boost bimap
#include <boost/bimap.hpp>
#include <iostream>
#include <string>
#include <tuple>

using Persons = boost::bimap<std::string, int>;

int main()
{
	Persons p;
	//insert some values
	p.insert(Persons::value_type("Mike", 18));
	p.insert(Persons::value_type("Jack", 19));
	p.insert(Persons::value_type("Mary", 21));
	p.insert(Persons::value_type("Carol", 25));
	p.left.insert(std::make_pair("June", 11));//left insert
	p.right.insert(std::make_pair(29, "Tom"));//right insert
	//p.emplace can't be used here
	//Print the left and right maps of the bimap (first and second views)
	//left map
	for (auto it = p.left.begin();it != p.left.end();it++)
	{
		std::cout << it->first << "->" << it->second << std::endl;//Output
	}
	std::cout << "\n";
	//right map
	for (auto it = p.right.begin();it != p.right.end();it++)
	{
		std::cout << it->first << "->" << it->second << std::endl;//Output
	}
	std::cout << "\n";
	//Search for age based on name and search for name based on age
	try
	{
		std::cout << "Whose age is 29? " << p.right.at(29) << std::endl;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "Whose age is 31? " << p.right.at(31) << std::endl;//throw an exception
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "How old is Mike? " << p.left.at("Mike") << std::endl;
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		std::cout << "How old is Jessica? " << p.left.at("Jessica") << std::endl;//throw an exception
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "\n";
	//Iterate in the bimap using the third view
	for (auto it = p.begin();it != p.end();it++)
	{
		std::cout << it->left << " is " << it->right << " years old." << std::endl;
	}
}
