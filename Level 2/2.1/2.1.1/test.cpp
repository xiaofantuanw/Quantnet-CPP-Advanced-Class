//test.cpp
//Author: TengxiaoFan
//This is the test function for basic type traits
#include <type_traits>
#include <iostream>
#include <memory>

class A 
{
	//This is a class to test the member pointers
public:
	void member_function() { }
	int data_member;
};

template <typename T> 
void IsPointer(const T& t) 
{ // Example of type_traits;check if t is a pointer
	// Return type is std::true_type or std::false_type 
	if (std::is_pointer<T>::value) 
	{ 
		std::cout << "This is a pointer type argument\n"; 
	} 
	else 
	{ 
		std::cout << "_not_ a pointer type argument\n"; 
	} 
}

template <typename T>
void IsNullPointer(const T& t)
{ // Example of type_traits;check if t is a null pointer
	// Return type is std::true_type or std::false_type 
	if (std::is_null_pointer<T>::value)
	{
		std::cout << "This is a null pointer type argument\n";
	}
	else
	{
		std::cout << "_not_ a null pointer type argument\n";
	}
}

template <typename T>
void IsLvalueReference(T&& t)
{ // Example of type_traits;check if t is a lvalue refernece
	// Return type is std::true_type or std::false_type 
	if (std::is_lvalue_reference<T>::value)
	{
		std::cout << "This is a lvalue reference type argument\n";
	}
	else
	{
		std::cout << "_not_ a lvalue reference type argument\n";
	}
}

template <typename T>
void IsRvalueReference(T&& t)
{ // Example of type_traits;check if t is a rvalue refernece
	// Return type is std::true_type or std::false_type 
	if (std::is_rvalue_reference<T>::value)
	{
		std::cout << "This is a rvalue reference type argument\n";
	}
	else
	{
		std::cout << "_not_ a rvalue reference type argument\n";
	}
}

template <typename T>
void IsMemberFuncPointer(const T& t)
{ // Example of type_traits;check if t is a member function pointer
	// Return type is std::true_type or std::false_type 
	if (std::is_member_function_pointer<T>::value)
	{
		std::cout << "This is a member function pointer\n";
	}
	else
	{
		std::cout << "_not_ a member function pointer\n";
	}
}

template <typename T>
void IsMemberObjPointer(const T& t)
{ // Example of type_traits;check if t is a member object pointer
	// Return type is std::true_type or std::false_type 
	if (std::is_member_object_pointer<T>::value)
	{
		std::cout << "This is a member object pointer\n";
	}
	else
	{
		std::cout << "_not_ a member object pointer\n";
	}
}

int main()
{
	auto a = nullptr;//null pointer
	int* b = new(int);//pointer
	void* d=nullptr;//void* nullptr
	int c = 10;//lvalue
	int& c1 = c;//lvalue reference
	std::shared_ptr<int> shared_p1;
	A myA;//Build an example of class A
	int A::* p = &A::data_member;
	auto q = &A::member_function;

	IsPointer(a);//false;nullptr is not pointer
	IsNullPointer(a);//true
	IsPointer(b);//true
	IsPointer(d);//true
	IsNullPointer(d);//void* type nullptr is false
	IsLvalueReference(c1);//true
	IsRvalueReference(std::move(c1));//false; the deduction of rvalue

	//Test the shared_ptr
	IsPointer(shared_p1);//false for sharedptr
	IsPointer(shared_p1.get());//true for the raw pointer of it
	IsNullPointer(shared_p1.get());//false

	//Test the member ptr
	IsMemberFuncPointer(p);//false
	IsMemberObjPointer(p);//true
	IsMemberFuncPointer(q);//true
	IsMemberObjPointer(q);//false

}