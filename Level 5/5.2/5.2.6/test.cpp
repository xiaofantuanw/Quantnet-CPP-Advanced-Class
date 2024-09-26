//test.cpp
// Author: TengxiaoFan
//This is a test file for Ecmascript.
#include <regex>
#include <iostream>
#include <vector>
#include <string>


int main()
{
	//This ecma regex matches numbers with or without decimal point and exponent (double numbers)
	std::regex ecmaReg("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
	std::vector<std::string> strs{"3.5E3","3.1415","-9.8","1E10","0","Jack"};//Jack invalid
	std::cout << std::boolalpha;
	for (auto it = strs.begin();it != strs.end();it++)
	{
		bool tmp = std::regex_match((*it), ecmaReg);
		std::cout << (*it) << ": " << tmp;//Whether matches the regex
		if (tmp)
		{
			double num = stod(*it);
			std::cout << "; To number: " << num;//Convert to double
		}
		std::cout << "\n";
	}
	

}