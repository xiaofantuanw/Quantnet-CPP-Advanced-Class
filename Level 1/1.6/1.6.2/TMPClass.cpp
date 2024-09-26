//TMPClass.cpp
//Author: TengxiaoFan
//source file for TMPClass
#include "TMPClass.hpp"
#include <iostream>
#include <algorithm>

//Default constructor
TMPClass::TMPClass()
{
	vec = std::vector<double>(5, 0.0);
	IDevice = []() {return 1.0;};
	ODevice = [](const std::vector<double>& v) //range iteration
	{
		for (auto elem : v)
		{
			std::cout << elem << ", ";
		}
		std::cout << std::endl;
	};
}

//Constructor with initialization
TMPClass::TMPClass(std::size_t n, double startValue, InputFunction iFunction, OutputFunction oFunction)
{
	vec = std::vector<double>(n, startValue);
	IDevice = iFunction;
	ODevice = oFunction;
}

//Copy constructor
TMPClass::TMPClass(const TMPClass& source)
{

	vec = source.vec;
	IDevice = source.IDevice;
	ODevice = source.ODevice;
}

//Move constructor
TMPClass::TMPClass(TMPClass&& source)
{
	vec = std::move(source.vec);
	IDevice = std::move(source.IDevice);
	ODevice = std::move(source.ODevice);
}

//Destructor
TMPClass::~TMPClass()
{

}


void TMPClass::Alg()
{
	//Preprocess
	double value = IDevice();
	std::vector<double> result(vec.size());
	//Calculate
	std::transform(vec.begin(), vec.end(), result.begin(), [&](double n) {return n * value;});
	//Postprocess
	ODevice(result);
}