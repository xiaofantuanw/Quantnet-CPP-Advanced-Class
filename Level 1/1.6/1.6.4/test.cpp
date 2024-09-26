//test.cpp
//Test file for the alias template
#include "Client.hpp"

int main()
{
	int n = 10; 
	int val = 2; 
	Client<int> myClient(n, val); 
	myClient.print();//Outputs are the same
}