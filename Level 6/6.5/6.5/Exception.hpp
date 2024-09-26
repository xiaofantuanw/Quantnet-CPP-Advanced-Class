//Exception.hpp
//Author: TengxiaoFan
//Header file for exception classes
#ifndef Exception_HPP
#define Exception_HPP
#include <string>

//Base exception class
class Exception
{
public:
	Exception() = default;
	~Exception() = default;
	virtual std::string what() const= 0;
};

//NoFundsException class, throw this exception when there are not enough funds to execute a withdraw.
class NoFundsException : public Exception
{
public:
	NoFundsException() = default;
	~NoFundsException() = default;
	virtual std::string what() const
	{
		std::string str = "No funds.";
		return str;
	}
};

//NoAccessException class, throw this exception when the client has no permission to access the GetBalance() method.
class NoAccessException : public Exception
{
public:
	NoAccessException() = default;
	~NoAccessException() = default;
	virtual std::string what() const
	{
		std::string str = "No Access.";
		return str;
	}
};

#endif // !Exception_HPP
