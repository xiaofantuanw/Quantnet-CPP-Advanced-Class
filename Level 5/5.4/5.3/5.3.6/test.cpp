//test.cpp
//Author: TengxiaoFan
//This is the test function for the full monte
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <boost/container_hash/hash.hpp>

struct S 
{
	std::string f; 
	std::string s;
	S(const std::string& s1, const std::string& s2) : f(s1), s(s2) {}
};

class SHash // Hash for class S 
{ 
public: 
	std::size_t operator() (const S& s) const 
	{ 
		std::size_t seed = 0;
		boost::hash_combine(seed, s.s);
		boost::hash_combine(seed, s.f);
		return seed;
	} 
};
	
class SEqual // Equality for S 
{ 
public: 
	bool operator ()(const S& lhs, const S& rhs) const 
	{ 
		return (rhs.f == lhs.f && rhs.s == lhs.s); 
	} 
};

template <typename Key, typename Hash, typename EqPred>
void BucketInformation(const std::unordered_set<Key, Hash, EqPred>& c)
{//examine the bucket structure of an unordered set
	std::cout << "Number of buckets: " << c.bucket_count() << std::endl;
	std::cout << "Maximum number of buckets: " << c.max_bucket_count() << std::endl;
	std::cout << "Load factor: " << c.load_factor() << std::endl;
	std::cout << "Maximum load factor: " << c.max_load_factor() << std::endl;
	for (int i = 0;i < c.bucket_count(); i++)
	{//Show the size of each bucket
		std::cout << "Bucket size " << i << ": " << c.bucket_size(i) << std::endl;
	}
}

int main()
{
	std::unordered_set<S, SHash, SEqual> mySet;
	//Insert some instances
	mySet.insert(S("Jack", "1"));
	mySet.insert(S("Mike", "3"));
	mySet.insert(S("Jane", "2"));
	mySet.insert(S("Ben", "12"));
	mySet.insert(S("Alice", "2"));
	mySet.insert(S("Carol", "134"));
	//show bucket information
	BucketInformation(mySet);
}