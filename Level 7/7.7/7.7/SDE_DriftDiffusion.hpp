#ifndef  SDE_DriftDiffusion_HPP
#define SDE_DriftDiffusion_HPP
#include "StopWatch.hpp"

// Interface contract specification
//Must support diffusion
template<typename T, typename Data>
concept IDiffusion = requires (T c, Data t, Data x)
{
	c.diffusion(t, x);
};


//Must support drift
template<typename T, typename Data>
concept IDrift = requires (T c, Data t, Data x)
{
	c.drift(t, x);
};

//Must support jump
template<typename T, typename Data>
concept IJump = requires (T c, Data t, Data x)
{
    c.jump(t, x);
};

//Support diffusion and drift
template<typename T, typename Data>
concept IDriftDiffusion = IDiffusion<T, Data>&& IDrift<T, Data>;

//Support jump and diffusion
template<typename T, typename Data>
concept IJumpDiffusion = IDiffusion<T, Data>&& IJump<T, Data>;

//Definition of abstract class SDEAbstract
template <typename T, typename Data> requires IDriftDiffusion<T, Data>
class SDE_DriftDiffusion
{ // System under discussion, using composition
// Really a Bridge pattern
private:
	T _t;
public:
	SDE_DriftDiffusion(const T& t) : _t(t) {}
	Data diffusion(Data t, Data x)
	{
		return _t.diffusion(t, x);
	}
	Data drift(Data t, Data x)
	{
		return _t.drift(t, x);
	}

    //Function to solve the sde
    void solve(Data S_0, OptionData myOption)
	{
        // Variables for underlying stock
        double x;
        double VOld = S_0;
        double VNew;
        long NT = 100;
        std::cout << "Number of time steps: ";
        std::cin >> NT;
        // V2 mediator stuff
        long NSIM = 50000;
        std::cout << "Number of simulations: ";
        std::cin >> NSIM;
        double M = static_cast<double>(NSIM);
        double dt = myOption.T / static_cast<double> (NT);
        double sqrdt = std::sqrt(dt);
        // Normal random number
        double dW;
        double price = 0.0; // Option price
        double payoffT;
        double avgPayoffT = 0.0;
        double squaredPayoff = 0.0;
        double sumPriceT = 0.0;
        // #include <random>

        // Normal (0,1) rng
        std::default_random_engine dre;
        std::normal_distribution<double> nor(0.0, 1.0);
        // Create a random number
        dW = nor(dre);
        StopWatch sw;
        sw.StartStopWatch();
        for (long i = 1; i <= M; ++i)
        {
            // Calculate a path at each iteration
            if ((i / 10000) * 10000 == i)
            {
                // Give status after each 10000th iteration
                std::cout << i << "\n";
            }
            VOld = S_0;
            x = 0.0;
            for (long index = 0; index <= NT; ++index)
            {
                // Create a random number
                dW = nor(dre);
                // The FDM (in this case explicit Euler)
                VNew = VOld + (dt * (this->drift)(x, VOld)) + (sqrdt * (this->diffusion)(x, VOld) * dW);
                VOld = VNew;
                x += dt;
            }
            // Assemble quantities (postprocessing)
            payoffT = myOption.myPayOffFunction(VNew);
            sumPriceT += payoffT;
            avgPayoffT += payoffT / M;
            avgPayoffT *= avgPayoffT;
            squaredPayoff += (payoffT * payoffT);
        }

        // Finally, discounting the average price
        price = std::exp(-myOption.r * myOption.T) * sumPriceT / M;
        std::cout << "Price, after discounting: " << price << ", " << std::endl;
        double SD = std::sqrt((squaredPayoff / M) - sumPriceT * sumPriceT / (M * M));
        std::cout << "Standard Deviation: " << SD << ", " << std::endl;
        double SE = SD / std::sqrt(M);
        std::cout << "Standard Error: " << SE << ", " << std::endl;
        sw.StopStopWatch();
        std::cout << "Elapsed time in seconds: " << sw.GetTime() << '\n';
	}
};

//Definition of abstract class SDEAbstract
template <typename T, typename Data> requires IJumpDiffusion<T, Data>
class SDE_JumpDiffusion
{ // System under discussion, using composition
// Really a Bridge pattern
private:
    T _t;
public:
    SDE_JumpDiffusion(const T& t) : _t(t) {}
    Data diffusion(Data t, Data x)
    {
        return _t.diffusion(t, x);
    }
    Data drift(Data t, Data x)
    {
        return _t.drift(t, x);
    }

    //Function to solve the sde
    void solve(Data S_0, OptionData myOption)
    {//I cannot solve such SDE.

    }
};

#endif // ! SDEAbstract_HPP



//Advantages of Abstract SDE class:
//It can adapt to different SDE with diffusion and drift.