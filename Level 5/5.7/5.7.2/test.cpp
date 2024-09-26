//test.cpp
// Author: TengxiaoFan
//This is a test file for boost bimap DNS
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <string>
#include <tuple>

//tags, better readability
struct IpAddress {};
struct DomainName {};
using namespace boost::bimaps;
using DNS = bimap<unordered_set_of<tagged<boost::uuids::uuid, DomainName>>, unordered_set_of<tagged<std::string, IpAddress>>>;

//Function to print the dns
void prtdns(const DNS& dns)
{
	for (auto it = dns.begin();it != dns.end();it++)
	{
		std::cout << "UUID: " << it->get_left() << "; Domain name: " << it->get_right()<<std::endl;
	}

}

int main()
{
	//generate uuid with random generators
	boost::uuids::basic_random_generator<boost::mt19937> gen;
	boost::uuids::uuid u1 = gen();
	boost::uuids::uuid u2 = gen();
	boost::uuids::uuid u3 = gen();
	//Insert some value into the DNS
	DNS d;
	d.insert(DNS::value_type(u1, "nga.178.com"));
	d.insert(DNS::value_type(u2, "chexie.net"));
	d.insert(DNS::value_type(u3, "treehole.pku.edu.cn"));
	//Find a domain name for a given IP address
	std::cout << "The domain name of u1 is: " << (d.by<DomainName>().find(u1))->get_right() << std::endl;
	//Find a IPAddress for a given domain name
	std::cout << "The IP Address of chexie.net is: " << (d.by<IpAddress>().find("chexie.net"))->get_left() << std::endl;

	//Print the information
	prtdns(d);
}