//independent_bits_engine.hpp
//Author: TengxiaoFan
//This is a class to make a bitset with some random algorithm
#ifndef independent_bits_engine_HPP
#define independent_bits_engine_HPP
#include <cmath>
#include <random>
#include <bitset>

template<class Engine, std::size_t W, class UIntType>
class independent_bits_engine
{//This class generates a bitset with given engine and seed
private://Private value
	UIntType value;
public:
	//constructor
	independent_bits_engine()
	{
		Engine eng;
		std::uniform_int_distribution<UIntType> dist(0, (UIntType)std::exp2(W) - 1);
		value = dist(eng);
	}
	independent_bits_engine(int seed)
	{
		Engine eng(seed);
		std::uniform_int_distribution<UIntType> dist(0, (UIntType)std::exp2(W) - 1);
		value = dist(eng);
	}
	independent_bits_engine(std::random_device&& rd)
	{
		Engine eng(rd());
		std::uniform_int_distribution<UIntType> dist(0, (UIntType)std::exp2(W) - 1);
		value = dist(eng);
	}
	//destructor
	virtual ~independent_bits_engine() {}
	//Get value
	UIntType get()
	{
		return value;
	}
	//Get bitset value
	std::bitset<W> getbit()
	{
		std::bitset<W> result(value);
		return result;
	}
};


#endif // !independent_bits_engine_HPP
