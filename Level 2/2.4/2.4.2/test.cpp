//test.cpp
// //Author: TengxiaoFan
//This is the test file for shared ptr
#include <memory>
#include <iostream>
#include <type_traits>
#include "Point.hpp"

class C1 
{
	//A class with shared_ptr as member
private: 
	//double* d; OLD WAY 
	std::shared_ptr<double> d; 
public: 
	C1(std::shared_ptr<double> value) : d(value) {} 
	virtual ~C1() { std::cout << "\nC1 destructor\n";} 
	void print() const { std::cout << "Value " << *d<<std::endl; } 
};

class C2
{//A class with shared_ptr as member
private:
	//double* d; OLD WAY 
	std::shared_ptr<double> d;
public:
	C2(std::shared_ptr<double> value) : d(value) {}
	virtual ~C2() { std::cout << "\nC2 destructor\n"; }
	void print() const { std::cout << "Value " << *d<<std::endl; }
};

class C3
{//A class with shared_ptr as member
private:
	//double* d; OLD WAY 
	std::shared_ptr<Point> d;
public:
	C3(std::shared_ptr<Point> value) : d(value) {}
	virtual ~C3() { std::cout << "\nC3 destructor\n"; }
	void print() const { std::cout << "Value (" << (*d).X() <<", "<<(*d).Y() << ")"<<std::endl; }
};
class C4
{//A class with shared_ptr as member
private:
	//double* d; OLD WAY 
	std::shared_ptr<Point> d;
public:
	C4(std::shared_ptr<Point> value) : d(value) {}
	virtual ~C4() { std::cout << "\nC4 destructor\n"; }
	void print() const { std::cout << "Value (" << (*d).X() << ", " << (*d).Y() <<")"<< std::endl; }
};

void testdouble()
{//This block tests the shared_ptr<double>
	std::shared_ptr<double> sp1;
	std::cout << sp1.use_count() << std::endl;//0
	sp1 = std::make_shared<double>(2.0);//Create a shared ptr
	std::cout << sp1.use_count() << std::endl;//1
	C1 c1(sp1);
	std::cout << sp1.use_count() << std::endl;//2
	C2 c2(sp1);
	std::cout << sp1.use_count() << std::endl;//3
	c1.print();c2.print();//Print the value
	auto sp2 = std::make_shared<double>(1.0);
	C1 c10(sp2);C2 c20(sp2);
	c1 = c10;c2 = c20;//Assign the new shared_pointer to objects
	std::cout << sp1.use_count() << std::endl;//1

	//Assignment of shared_ptr
	sp1 = sp2;
	std::cout << sp1.use_count() << std::endl;//6
	//Copy of shared_ptr
	std::shared_ptr<double> sp3(sp2);
	std::cout << sp1.use_count() << std::endl;//7
	//Compare of shared_ptr
	std::cout << std::boolalpha << "sp1 and sp2 the same? " << (sp1 == sp2)<<std::endl;
	//Transfer ownership
	sp2 = std::move(sp1);
	//Determine only owner
	std::cout << "sp2 unique owner? "<<(sp2.use_count()==1) << std::endl;//unique is removed in C++20
	//Swap the two pointers.
	sp1 = nullptr;//reinitialize with nullptr
	sp1.swap(sp2);
}//Now use_count goes to 0.

void testPoint()
{//This block tests the shared_ptr<double>
	std::shared_ptr<Point> sp1;
	std::cout << sp1.use_count() << std::endl;//0
	sp1 = std::make_shared<Point>(Point(1.0,3.0));//Create a shared ptr
	std::cout << sp1.use_count() << std::endl;//1
	C3 c3(sp1);
	std::cout << sp1.use_count() << std::endl;//2
	C4 c4(sp1);
	std::cout << sp1.use_count() << std::endl;//3
	c3.print();c4.print();//Print the value
	auto sp2 = std::make_shared<Point>(Point(1.0,1.0));
	C3 c30(sp2);C4 c40(sp2);
	c3 = c30;c4 = c40;//Assign the new shared_pointer to objects
	std::cout << sp1.use_count() << std::endl;//1

	//Assignment of shared_ptr
	sp1 = sp2;
	std::cout << sp1.use_count() << std::endl;//6
	//Copy of shared_ptr
	std::shared_ptr<Point> sp3(sp2);
	std::cout << sp1.use_count() << std::endl;//7
	//Compare of shared_ptr
	std::cout << std::boolalpha << "sp1 and sp2 the same? " << (sp1 == sp2) << std::endl;
	//Transfer ownership
	sp2 = std::move(sp1);
	//Determine only owner
	std::cout << "sp2 unique owner? " << (sp2.use_count() == 1) << std::endl;//unique is removed in C++20
	//Swap the two pointers.
	sp1 = nullptr;//reinitialize with nullptr
	sp1.swap(sp2);
}//Now use_count goes to 0. Also Point destructor is called.

int main()
{
	//Test
	testdouble();
	std::cout << "-------------------" << std::endl;
	testPoint();
}
