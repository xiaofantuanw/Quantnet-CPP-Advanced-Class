#include "Exception.hpp"
#include "Account.hpp"
#include <memory>
#include <iostream>

int main()
{
	//Try to withdraw money and get balance from real account
	std::shared_ptr<Account> ac1(new RealAccount(1000.0));
	//Account* ac1 = new RealAccount(1000.0);
	try
	{
		ac1->Withdraw(300.0);
		std::cout << "Balance: " << ac1->GetBalance() << std::endl;
	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		ac1->Withdraw(1000.0);
		std::cout << "Balance: " << ac1->GetBalance() << std::endl;
	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	//delete ac1;

	//Try to withdraw money and get balance from protected account
	std::shared_ptr<Account> ac2 (new ProtectedAccount(1000.0,"My123456"));
	try
	{
		ac2->GetAccess("His123456");//Wrong pswd
		ac2->Withdraw(300.0);
		std::cout << "Balance: " << ac2->GetBalance() << std::endl;
	}
	catch (Exception& ex)
	{//NoAccessException
		std::cout << ex.what() << std::endl;
	}
	try
	{
		ac2->GetAccess("My123456");//Correct pswd
		ac2->Withdraw(300.0);
		std::cout << "Balance: " << ac2->GetBalance() << std::endl;
	}
	catch (Exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		//ac2->GetAccess("My123456");//Correct pswd
		//Already have access
		ac2->Withdraw(1000.0);
		std::cout << "Balance: " << ac2->GetBalance() << std::endl;
	}
	catch (Exception& ex)
	{//NoFundsException
		std::cout << ex.what() << std::endl;
	}
	//delete ac2;
}