#ifndef Proposition_HPP
#define Proposition_HPP
#include <bitset>

class Proposition 
{ // A class representing true/false
private:
	//Member data
	std::bitset<1> m_data; 
public:
	//Member functions
	//Constructors
	Proposition() { m_data = 1; }
	Proposition(std::bitset<1> data):m_data(data){}
	Proposition(bool data) { m_data = data; }
	//Destructor
	virtual ~Proposition() = default;
	//Operators
	bool operator== (const Proposition& b) const
	{//Equality
		return this->m_data == b.m_data;
	}
	bool operator!= (const Proposition& b) const
	{//Inequality
		return this->m_data != b.m_data;
	}
	Proposition operator& (const Proposition& b) const
	{//conjunction, and
		return Proposition(this->m_data & b.m_data);
	}
	Proposition operator| (const Proposition& b) const
	{//disjunction, or
		return Proposition(this->m_data | b.m_data);
	}
	Proposition operator^ (const Proposition& b) const
	{//exclusive or, xor
		return Proposition(this->m_data ^ b.m_data);
	}
	Proposition operator!() const
	{//Negation
		auto dat = this->m_data;
		return Proposition(dat.flip());
	}
	friend Proposition operator%(const Proposition& a, const Proposition& b) 
	{//Condition ->
		return Proposition(((!a) | b).m_data);
	}
	friend Proposition operator%=(const Proposition& a, const Proposition& b)
	{//Biconditional <->
		return Proposition(((a % b) & (b % a)).m_data);
	}
	operator bool()
	{//conversion to bool
		return (m_data==1);
	}
};



#endif // !Proposition_HPP
