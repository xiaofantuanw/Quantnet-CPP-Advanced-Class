//Process.ixx
//Author TengxiaoFan
//This is the process module


export module Process;//Export declaration

//Single Responsibility Principle
export 
class Proc
{//Process class
private:
	double m_data;//underlying data
public:
	//Ctors and Dtors
	Proc();
	Proc(double data);
	virtual ~Proc()=default;
	//Processor
	double do_stuff();
};

//Support for Information Hiding.
module :private;
//Everything beyond this point is not available for importers of module process
//Definition of functions
Proc::Proc ():m_data(0) {}
Proc::Proc (double data) :m_data(data) {}
double Proc::do_stuff()
{//Multiply by 2.0
	m_data *= 2.0;
	return m_data;
}