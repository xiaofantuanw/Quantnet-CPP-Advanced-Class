// Singleton.hpp
//
// Header file for modified Singleton pattern in which the destruction
// of the Singleton takes place in a Destroyer object, thus resolving
// a major problem in the classic Gamma Singleton pattern.
//
// The Destroyer class is templated while clients can create subclasses 
// of Singleton to suit their needs. 
//
// (C) Datasim Education BV 1998


#ifndef Singleton_hpp
#define Singleton_hpp
#include <memory>

// Forward reference for singleton
template<class TYPE> class Singleton; 

template<class TYPE> 
class Destroyer 
{ // Class which is responsible for the destruction of another type TYPE

	friend class Singleton<TYPE>;	// Singleton is friend of mine

private:
	std::shared_ptr<TYPE> doomed_object;			// The object that is to be destructed 
	
	// Prevent users doing funny things (e.g. double deletion)
//	Destroyer();													// Default constructor
	Destroyer(std::shared_ptr<TYPE> t);												// Constructor with a pointer to the doomed object
	Destroyer(const Destroyer<TYPE>& source);						// Copy constructor
	Destroyer<TYPE>& operator = (const Destroyer<TYPE>& source);	// Assignment operator

	// Modifier
	void doomed(std::shared_ptr<TYPE> t);

public:
	// Destructor 
	virtual ~Destroyer();	

	// Somehow the default constructor must be public else we got a compiler error in class ctype
	Destroyer();													// Default constructor
};


template<class TYPE> 
class Singleton
{ // Templated Singleton class

private:
	static std::shared_ptr<TYPE> ins;
	static Destroyer<TYPE> des;

protected:
	Singleton();
	Singleton(const Singleton<TYPE>& source);
	virtual ~Singleton();
	Singleton<TYPE>& operator = (const Singleton<TYPE>& source);

public:
	static std::shared_ptr<TYPE> instance();
};

#endif // Singleton_hpp
