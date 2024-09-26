//test.cpp
//Author: TengxiaoFan
//This is the test file for some type conversion functions
#include <type_traits>
#include <iostream>
#include <tuple>
#include <vector>


template <typename T>
void SignedUnsigned()
{//Conversion between signed and unsigned types
	std::cout << std::boolalpha;
	using UnsignedType = typename std::make_unsigned<T>::type;//unsigned T type
	std::cout << "Is the type unsigned? " << std::is_unsigned<UnsignedType>::value << std::endl;//Check the conversion
	using SignedType = typename std::make_signed<UnsignedType>::type;//signed T type
	std::cout << "Is the type signed? " << std::is_signed<SignedType>::value << std::endl;//Check the conversion
}

template <typename T>
void AddMoveConst()
{//Add or move a const specifier to/from the type
	std::cout << std::boolalpha;
	using ConstType = typename std::add_const<T>::type;//const T type
	std::cout << "Is the type const? " << std::is_const<ConstType>::value << std::endl;//Check the conversion
	using NonConstType = typename std::remove_const<T>::type;//non const T type
	std::cout << "Is the type const? " << std::is_const<NonConstType>::value << std::endl;//Check the conversion
}

template <typename T>
void AddMovePointer()
{//Add or move a const specifier to/from the type
	std::cout << std::boolalpha;
	using PointerType = typename std::add_pointer<T>::type;// T* type
	std::cout << "Is the type pointer? " << std::is_pointer<PointerType>::value << std::endl;//Check the conversion
	using NonPointerType = typename std::remove_pointer<T>::type;//non pointer T type
	std::cout << "Is the type pointer? " << std::is_pointer<NonPointerType>::value << std::endl;//Check the conversion
}

template <typename T>
void AddMoveVolatile()
{//Add or move a const specifier to/from the type
	std::cout << std::boolalpha;
	using VolatileType = typename std::add_volatile<T>::type;//volatile T type
	std::cout << "Is the type volatile? " << std::is_volatile<VolatileType>::value << std::endl;//Check the conversion
	using NonVolatileType = typename std::remove_volatile<T>::type;//non volatile T type
	std::cout << "Is the type volatile? " << std::is_const<NonVolatileType>::value << std::endl;//Check the conversion
}

template <typename T>
class A
{
	//A simple user defined type
private:
	T data1;
public:
	A(T data) { data1 = data; }
	virtual ~A() {}
};

void CTAD()
{
	//Use CTAD to reduce verbosity
	//This function also investigate the applicability of decltype and std::is_same
	std::cout << std::boolalpha;
	std::tuple t(4, 2.5, "Mike");
	std::cout << "Is CTAD 1 successful? " << std::is_same<decltype(t), std::tuple<int, double, const char*>>::value << std::endl;
	//check the type of t

	A a(3);//test of user-defined type
	std::cout << "Is CTAD 2 successful? " << std::is_same<decltype(a), A<int>>::value << std::endl;
	//check the type of a

	//CTAD deduce the template automatically to reduce the verbosity of the code, so that we can omit the type.
}

void init()
{
	//test the initializers
	std::vector<int> obj1{ 1,2,3 };//direct list initializer
	std::vector<int> obj2 = { 1,2,3 };//copy list initializer
	//Difference: Direct list initializer initializes the object directly
	//Copy list initializer create a initializer list first and copy it to the object.

	auto a = { 1,2,3 };//Here auto is deduced to std::initializer_list
	std::cout << "Is auto deduced to std::initializer_list? " << std::is_same<decltype(a), std::initializer_list<int>>::value << std::endl;
	
	//Ill formed issue
	//decltype({ 1,2,3 });//ill-formed!!!

}

int main()
{
	//Test the functions with underlying int type
	SignedUnsigned<int>();
	AddMoveConst<int>();
	AddMovePointer<int>();
	AddMoveVolatile<int>();
	std::cout << std::endl;

	//Test the functions with underlying int[] type
	//SignedUnsigned<int[]>();//Not valid, error
	AddMoveConst<int[]>();
	AddMovePointer<int[]>();
	AddMoveVolatile<int[]>();
	std::cout << std::endl;

	//Test the functions with a user defined class
	//SignedUnsigned<A<double>>();//error. no such a type
	AddMoveConst<A<double>>();
	AddMovePointer<A<double>>();
	AddMoveVolatile<A<double>>();
	std::cout << std::endl;

	//Test CTAD, also test the applicability of decltype and std::is_same
	CTAD();
	std::cout << std::endl;

	//Test the list-initialization
	init();
}