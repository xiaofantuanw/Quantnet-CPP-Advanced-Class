//Account.hpp
//Author: TengxiaoFan
//This is the header file for some account classes
#ifndef Account_HPP
#define Account_HPP
#include "Exception.hpp"
#include <string>

//Base Account class
class Account
{
public:
	//Virtual function to withdraw money and get the balance
	virtual void Withdraw(double amount) = 0;
	virtual double GetBalance() const= 0;
	virtual bool GetAccess(std::string mypsw) = 0;
};

//Real Account: underlying data for Protected account
class RealAccount: public Account
{
private:
	double Balance;
	bool GetAccess(std::string mypsw) { return true;}//no need to get access
public:
	//Constructors & Destructors
	RealAccount()
	{
		Balance = 0.0;
	}
	RealAccount(double b)
	{
		Balance = b;
	}
	RealAccount(const RealAccount& source) = default;
	~RealAccount() {}
	//Assignment Op
	RealAccount& operator = (const RealAccount& source) = default;
	//Withdraw and getbalance
	void Withdraw(double amount)
	{
		if (Balance < amount)
		{
			throw NoFundsException{};
		}
		else
		{
			Balance -= amount;
		}
	}
	double GetBalance() const
	{
		return Balance;
	}
	
};

//Protected account, check access to the account
class ProtectedAccount :public Account
{
private:
	Account* ac;
	std::string correct_password;
	bool access;//access to the account, will be true after correct password entered
public:
	//Constructors and destructors
	ProtectedAccount()
	{
		ac = new RealAccount(0.0);
		correct_password = "123456";//Default password
		access = false;
	}
	ProtectedAccount(double b,std::string psw)
	{
		ac = new RealAccount(b);
		correct_password = psw;//My password
		access = false;
	}
	ProtectedAccount(const ProtectedAccount& source) = default;
	~ProtectedAccount(){}
	//Assignment op
	ProtectedAccount& operator= (const ProtectedAccount& source) = default;
	//Get access by entering my password
	bool GetAccess(std::string mypsw)
	{
		if (mypsw == correct_password)
			access = true;
		else
			access = false;
		return access;
	}
	//Withdraw and GetBalance
	void Withdraw(double amount)
	{
		if (access == false)
		{
			throw NoAccessException{};
		}
		//Call the withdraw function of real account
		ac->Withdraw(amount);
	}
	double GetBalance() const
	{
		if (access == false)
		{
			throw NoAccessException{};
		}
		//Call the balance function of real account
		return ac->GetBalance();
	}


};



#endif // ! Account_HPP
