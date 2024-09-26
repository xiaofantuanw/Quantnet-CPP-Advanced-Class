//Author: TengxiaoFan
//A test function for class C
#include "C.cpp"

int main()
{
	C<int> vec(5);//Build a vector with size
	//C<int> vec1(vec);//Error
	//C<int> vec2; vec2=vec;//Error
	vec.print();
	return 0;
}