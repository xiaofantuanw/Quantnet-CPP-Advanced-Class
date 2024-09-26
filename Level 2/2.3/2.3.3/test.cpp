//test.cpp
//Author: TengxiaoFan
//This is the test file for mathematics high-order functions
#include <iostream>
#include <functional>
#include <cmath>

// Function maps Domain to Range 
template <typename R, typename D> 
using FunctionType = std::function<R (const D x)>;

// Working function type 
using ScalarFunction = FunctionType<double, double>;

//Operator +
template <typename R, typename D> 
FunctionType<R, D> operator + (const FunctionType<R, D>& f, const FunctionType<R, D>& g) 
{ 
	// Addition of functions
	return [=](const D& x)
	{
		return f(x) + g(x); 
	};
}

//Operator *
template <typename R, typename D>
FunctionType<R, D> operator * (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Multiplication of functions
	return [=](const D& x)
	{
		return f(x) * g(x);
	};
}

//Operator /
template <typename R, typename D>
FunctionType<R, D> operator / (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Division of functions
	return [=](const D& x)
	{
		return f(x) / g(x);
	};
}

//Operator -
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Subtraction of functions
	return [=](const D& x)
	{
		return f(x) - g(x);
	};
}

//Unary operator -
template <typename R, typename D>
FunctionType<R, D> operator - (const FunctionType<R, D>& f)
{
	// Additive inverse of functions
	return [=](const D& x)
	{
		return -f(x);
	};
}

//Scalar multiplication *
template <typename R, typename D>
FunctionType<R, D> operator * (double f, const FunctionType<R, D>& g)
{
	// scalar multiplication of functions
	return [=](const D& x)
	{
		return f*g(x);
	};
}

//Compose
template <typename R, typename D>
FunctionType<R, D> operator << (const FunctionType<R, D>& f, const FunctionType<R, D>& g)
{
	// Composition of functions
	return [=](const D& x)
	{
		return f(g(x));
	};
}


template <typename R, typename D> 
FunctionType<R, D> exp(const FunctionType<R, D>& f) 
{ // The exponential function
	return [=](const D& x) 
	{ 
		return std::exp(f(x)); 
	};
}

template <typename R, typename D>
FunctionType<R, D> sin(const FunctionType<R, D>& f)
{ // The sine function
	return [=](const D& x)
	{
		return std::sin(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> cos(const FunctionType<R, D>& f)
{ // The cosine function
	return [=](const D& x)
	{
		return std::cos(f(x));
	};
}


template <typename R, typename D>
FunctionType<R, D> log(const FunctionType<R, D>& f)
{ // The logarithm function
	return [=](const D& x)
	{
		return std::log(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> tan(const FunctionType<R, D>& f)
{ // The tangent function
	return [=](const D& x)
	{
		return std::tan(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> abs(const FunctionType<R, D>& f)
{ // The absolute value function
	return [=](const D& x)
	{
		return std::abs(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> sqrt(const FunctionType<R, D>& f)
{ // The square root function
	return [=](const D& x)
	{
		return std::sqrt(f(x));
	};
}

template <typename R, typename D>
FunctionType<R, D> min(const FunctionType<R, D>& f,const FunctionType <R,D> &g)
{ // The minimum function
	return [=](const D& x)
	{
		return f(x) > g(x) ? g(x) : f(x);
	};
}

template <typename R, typename D>
FunctionType<R, D> max(const FunctionType<R, D>& f, const FunctionType <R, D>& g)
{ // The maximum function
	return [=](const D& x)
	{
		return f(x) < g(x) ? g(x) : f(x);
	};
}

int main()
{
	// Scalar functions: double to double 
	ScalarFunction f = [](double x) {return x*x; }; 
	ScalarFunction g = [=](double x) { return x; }; 
	std::cout << g(2) << ", " << g(8) << "*";
// Set I: Arithmetic functions 
	double scale = 2.0; 
	auto fA = 2.0*(f + g); 
	auto fM = f - g; 
	auto fD = f / g; 
	auto fMul = f * g; 
	auto fC = g << g << 4.0*g; // Compose 
	auto fMinus = -(f + g);
	double x = 5.0; 
	std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", " << fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x);

	//Set II: cmath functions
	auto ftmp = log(g); 
	auto ftmp2 = cos(f); 
	auto f2 = (abs(exp(g)) * log(g) + sqrt(ftmp)) / ftmp2; 
	std::cout << f2(x) << std::endl;

	//Set III: minmax functions
	auto h1 = min(f, g); 
	auto h2 = max(f, g); 
	std::cout << "min(f,g): " << h1(2.0) << '\n'; 
	std::cout << "max(f,g): " << h2(2.0) << '\n';
	auto h3 = min(h1, max(2 * f, 3 * g)); 
	auto h4 = max(h2, max(-2 * f, 3 * g));
	std::cout << "min 3: " << h3(2.0) << '\n';
	std::cout << "max 4: " << h4(2.0) << '\n';
}