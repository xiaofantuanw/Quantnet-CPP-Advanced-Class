//main.cpp
//Author: TengxiaoFan
//Advantages of using C++ module:
//1) Modular design and Single Responsibility Principle (SRP).
//     There should never be more than one reason for a class to change. One module is a single responsibility unit.
//2) C++ modules and header files living side by side.
//      C++ modules and header files can appear in one file
//3) Support for Information Hiding.
//     allows components to conceal internal structure, while still enforcing type safety across components.
//4) Less dependencies than using header files.
//		header file dependency will make compile slower, since one header file depends on the file it includes.


//Less dependencies than using header files
import Input;
import Process;
import Output;

int main()
{
	//Input
	double x=Ip();
	//Processing
	Proc processor1(x);
	x = processor1.do_stuff();
	//Output
	Op(x);
}