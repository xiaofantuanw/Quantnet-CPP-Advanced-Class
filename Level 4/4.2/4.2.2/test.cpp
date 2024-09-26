#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

const int N = 100000000;
std::vector<double> bigvec(N);//A big vector (sorted)
std::vector<double> bigvec2(N);//A big vector (unsorted)


int main()
{
	bigvec2[N / 2] = 1.0;
	auto comp = [](double x, double y) {return x < y;};//Comparison
	auto comp2 = [](double x, double y) {return x > y;};//Comparison
	std::vector<double> vec8{ 1.0, 2.0, 3.0, -4.0, 10.0 }; // Not ordered

	//Four algorithms
	//Test of is_sorted_until (default)
	auto pos = std::is_sorted_until(vec8.begin(), vec8.end()); 
	if (pos != vec8.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	//Test of is_sorted (default)
	bool sort = std::is_sorted(vec8.begin(), vec8.end());
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;
	//Test of is_sorted_until (with comparison)
	pos = std::is_sorted_until(vec8.begin(), vec8.end(),comp);
	if (pos != vec8.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	//Test of is_sorted (with comparison)
	sort = std::is_sorted(vec8.begin(), vec8.end(),comp);
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;

	//Test with different predicate arguments
	std::vector<double> vec1{ 1.0, 2.0, 3.0, 4.0, 10.0 };//ordered from small to big
	//Test of is_sorted_until (with comparison)
	pos = std::is_sorted_until(vec1.begin(), vec1.end(), comp);
	if (pos != vec1.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	//Test of is_sorted (with comparison)
	sort = std::is_sorted(vec1.begin(), vec1.end(), comp);
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;
	//Test of is_sorted_until (with comparison)
	pos = std::is_sorted_until(vec1.begin(), vec1.end(), comp2);
	if (pos != vec1.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	//Test of is_sorted (with comparison)
	sort = std::is_sorted(vec1.begin(), vec1.end(), comp2);
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;

	std::cout << std::endl;

	//Test the efficiency using sorted big vector
	std::cout << "Test efficiency (sorted): " << std::endl;
	auto start = std::chrono::system_clock::now();
	pos = std::is_sorted_until(bigvec.begin(), bigvec.end(), comp2);
	if (pos != bigvec.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	double dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "is_sorted_until: " << dur <<"s"<< std::endl;

	//Test the efficiency using sorted big vector
	std::cout << "Test efficiency (sorted): " << std::endl;
	start = std::chrono::system_clock::now();
	sort = std::is_sorted(bigvec.begin(), bigvec.end(), comp);
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "is_sorted: " << dur << "s" << std::endl;

	//Test the efficiency using unsorted big vector
	std::cout << "Test efficiency (unsorted): " << std::endl;
	start = std::chrono::system_clock::now();
	pos = std::is_sorted_until(bigvec2.begin(), bigvec2.end(), comp2);
	if (pos != bigvec2.end())
		std::cout << "bad value: " << *pos << std::endl;
	else
		std::cout << "Sorted" << std::endl;
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "is_sorted_until: " << dur << "s" << std::endl;

	//Test the efficiency using unsorted big vector
	std::cout << "Test efficiency (unsorted): " << std::endl;
	start = std::chrono::system_clock::now();
	sort = std::is_sorted(bigvec2.begin(), bigvec2.end(), comp);
	std::cout << std::boolalpha << "Sorted? " << sort << std::endl;
	end = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	dur = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "is_sorted: " << dur << "s" << std::endl;

	//Efficiency: Almost the same!
}