//test.cpp
//Author: TengxiaoFan
//This is the test function for examine the bucket structure of an unordered set
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <boost/container_hash/hash.hpp>

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
	std::unordered_set<std::string> s1{ "Apple","Banana","Pear","Grape" };
	BucketInformation(s1);
	//Rehash the container so that it has a bucket size of at least some given size.
	s1.rehash(16);
	BucketInformation(s1);
}