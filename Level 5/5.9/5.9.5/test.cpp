//test.cpp
//Author: TengxiaoFan
//This is a test file for observer pattern
#include <boost\signals2.hpp>
#include <iostream>
#include <functional>
#include <list>
#include <numeric>

// Using std Function library 
typedef std::function<void (double)> FunctionType;
class Subject
{ // The notifier (Observable)in Publisher-Subscriber pattern 
private:
	boost::signals2::signal<void(double)> sig;
	//std::list<FunctionType> attentionList;
public:
	Subject()
	{
		//attentionList = std::list<FunctionType>();
	}
	void AddObserver(const FunctionType& ft)
	{
		sig.connect(ft);
		//attentionList.push_back(ft);
	}
	void ChangeEvent(double x)
	{
		//for (auto it = attentionList.begin(); it != attentionList.end(); ++it)
		//{
			//(*it)(x);
		//}
		sig(x);//Emit the signal
	}
};

void CPrint(double x)
{ //Free function slot
	std::cout << "C function: " << x << std::endl; 
}
struct Print 
{ //Function obj slot
	void operator() (double x) 
	{ 
		std::cout << "I am a printer " << x << std::endl; 
	} 
};

int main()
{
	// Create the notifier 
	Subject mySubject;
	// Connect to signal
	Print myPrint; 
	mySubject.AddObserver(myPrint);  
	mySubject.AddObserver(&CPrint);
	// Trigger the event 
	std::cout << "Give the value: "; 
	double val; 
	std::cin >> val;
	mySubject.ChangeEvent(val);
}