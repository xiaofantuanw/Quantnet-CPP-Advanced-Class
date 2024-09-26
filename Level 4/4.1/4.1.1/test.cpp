#include "Proposition.hpp"
#include <iostream>

int main()
{
	Proposition p1(0), p2(1);
	//Test the operators
	//Since the proposition can be converted to bool, we can output directly
	std::cout << std::boolalpha;
	std::cout << "==: " << (p1 == p2) << std::endl;
	std::cout << "!=: " << (p1 != p2) << std::endl;
	std::cout << "&: " << (p1 & p2) << std::endl;
	std::cout << "|: " << (p1 | p2) << std::endl;
	std::cout << "^: " << (p1 ^ p2) << std::endl;
	std::cout << "!: " << (!p1) << std::endl;
	std::cout << "%: " << (p1 % p2) << std::endl;
	std::cout << "%=: " << (p1 %= p2) << std::endl;
	//Convert to bool
	bool a = p1;
	std::cout << "conversion: " << a << std::endl;

	//De Morgan¡¯s Laws
	std::cout << "\nDe Morgan's Laws" << std::endl;
	std::cout << "NOT (A OR B) == NOT(A) AND NOT(B): " << (!(p1 | p2) == ((!p1) & (!p2))) << std::endl;
	std::cout << "NOT (A AND B) == NOT(A) OR NOT(B): " << (!(p1 & p2) == ((!p1) | (!p2))) << std::endl<<std::endl;

	//Distributive Laws
	Proposition p3(1);
	std::cout << "Distributive Laws" << std::endl;
	std::cout << "A AND(B OR C) == (A AND B) OR (A OR C): " << ((p1 & (p2 | p3)) == ((p1 & p2) | (p1 & p3))) << std::endl;
	std::cout << "A OR(B AND C) == (A OR B) AND (A OR C): " << ((p1 | (p2 & p3)) == ((p1 | p2) & (p1 | p3)))<<std::endl;

	//[A -> (B -> C)] <-> [(A & B) -> C]
	std::cout << "\nTest Tautology: [A -> (B -> C)] <-> [(A & B) -> C]" << std::endl;
	for (auto i = 0;i <= 1;i++)
	{
		for (auto j = 0;j <= 1;j++)
		{
			for (auto k = 0;k <= 1;k++)
			{
				Proposition A(i), B(j), C(k);
				std::cout << "(A,B,C)=" << "(" << i << "," << j << "," << k << "): " << ((A % (B % C)) %= (A & B) % C)<<std::endl;
			}
		}
	}
}