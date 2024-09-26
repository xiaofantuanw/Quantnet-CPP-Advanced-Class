//test.cpp
// Author: TengxiaoFan
//This is the test file for boost random
#include <boost/random.hpp>


int main()
{
	//A triangle distribution with lagged fibonacci engine
	boost::lagged_fibonacci1279 eng;
	boost::triangle_distribution<double> dist;
	double result = dist(eng);
	std::cout << "A triangle distribution random with lagged fibonacci engine: " << result << std::endl;
	
	//Use function generic generate_canonical
	boost::mt11213b eng2(7);
	double result8=boost::random::generate_canonical<double, 8, boost::mt11213b>(eng2);
	double result16 = boost::random::generate_canonical<double, 16, boost::mt11213b>(eng2);
	double result32 = boost::random::generate_canonical<double, 32, boost::mt11213b>(eng2);
	std::cout << "generate_canonical:\n8 digits: " << result8 << std::endl;
	std::cout << "16 digits: " << result16 << std::endl;
	std::cout << "32 digits: " << result32 << std::endl;


}