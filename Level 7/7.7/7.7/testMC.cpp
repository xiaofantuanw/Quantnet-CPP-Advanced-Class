// TestMC.cpp
// C++ code to price an option, essential algorithms.
// We take Geometric Brownian Motion (GBM) model and the Euler method.
// We compute option price.
// 2012-2-26 Update using std::vector<double> as data storage structure.
// 2016-4-3 DD using C++11 syntax, new example.
//2017-8-2 DD version 1 for book
// (C) Datasim Education BV 2008-2021


#include "OptionData.hpp" // in local directory
#include <random>
#include <memory>
#include <cmath>
#include <iostream>
#include "StopWatch.hpp"
#include "SDE_DriftDiffusion.hpp"

class SDE
{ // Defines drift + diffusion + data
private:
    std::shared_ptr<OptionData> data; // The data for the option
public:
    SDE(const OptionData& optionData) : data(new OptionData(optionData)) {}
    double drift(double t, double S)
    { // Drift term
        return (data->r - data->D) * S; // r - D
    }
    double diffusion(double t, double S)
    { // Diffusion term
        return data->sig * S;
    }
};

int main()
{
    std::cout << "1 factor MC with explicit Euler\n";
    OptionData myOption{ 65.0, 0.25, 0.08, 0.3, 0.0, -1 };
    /* myOption.K = 65.0;
    myOption.T = 0.25;
    myOption.r = 0.08;
    myOption.sig = 0.3;
    myOption.D = 0.0;
    myOption.type = -1; // Put -1, Call +1*/
    /*myOption.K = 100.0;
    myOption.T = 1.0;
    myOption.r = 0.0;
    myOption.sig = 0.2;
    myOption.D = 0.0;
    myOption.type = -1; // Put -1, Call +1
    */
    SDE_DriftDiffusion<SDE,double> sde(myOption);//Use abstract SDE class
    // Initial value of SDE
    double S_0 = 60;
    sde.solve(S_0, myOption);
    return 0;
}