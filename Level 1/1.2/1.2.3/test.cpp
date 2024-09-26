//Author: TengxiaoFan
//A test function for class C
#include "C.cpp"

int main()
{
	C<int> vec(5);//Build a vector with size
	//C<int> vec1(vec);//Error
	//C<int> vec2; vec2=vec;//Error
	std::cout << "Before moving construction:" << std::endl;
	vec.print();


	C<int> vec1(std::move(vec));//Use the move constructor (rvalue)
	//Output the information after moving construction
	std::cout << "After moving construction:" << std::endl << "vector 0: " << std::endl;
	vec.print();
	std::cout << "vector 1:" << std::endl;
	vec1.print();

	vec = std::move(vec1);//Use the move operator = to move the vector back.
	//Output the information after the move operator
	std::cout << "After moving operator =:" << std::endl << "vector 0: " << std::endl;
	vec.print();
	std::cout << "vector 1:" << std::endl;
	//vec1.print();

	//vec1 = vec;//If I use the lvalue as source, there will be a compile error.
	//Because the lvalue (copy) version has been deleted
	return 0;
}