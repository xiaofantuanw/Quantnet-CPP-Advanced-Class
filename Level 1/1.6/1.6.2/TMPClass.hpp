//TMPClass.hpp
//Author: TengxiaoFan
//header file for TMPClass
#ifndef TMPCLASS_HPP
#define TMPCLASS_HPP
#include <functional>
#include <vector>


using InputFunction = std::function<double()>; 
using OutputFunction = std::function<void(const std::vector<double>&)>;
class TMPClass
{
private://Data members
	std::vector<double> vec;
	InputFunction IDevice;
	OutputFunction ODevice;
public://Member functions
	//Constructors
	TMPClass();//Default constructor
	TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction);
	TMPClass(const TMPClass& source);//Copy constructor
	TMPClass(TMPClass&& source);//Move constructor

	//Destructor
	~TMPClass();

	//Algorithm: Containing Preprocessing, Computing and Postprocessing
	void Alg();
};



#endif // !TMPCLASS_HPP
