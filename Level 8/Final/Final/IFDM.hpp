#ifndef IFDM_HPP
#define IFDM_HPP
#include "ISDE.hpp"
#include <memory>
#include <cmath>
#include <vector>

class IFDM
{
public:
	// Choose which SDE model to use
	virtual std::shared_ptr<ISDE> StochasticEquation()=0;
	virtual void StochasticEquation(std::shared_ptr<ISDE> se)=0;

	// Advance solution from level t[n] to level t[n+1]
	virtual double advance(double xn, double tn, double dt,double WienerIncrement, double WienerIncrement2)=0;
};


class FdmBase : public IFDM
{
protected:
	std::shared_ptr<ISDE> sde;
private:
	int NT; // Number of subdivisions
	std::vector<double> x; // The mesh array
	double k; // Mesh size
public:
	FdmBase(std::shared_ptr<ISDE> stochasticEquation, int numSubdivisions)
	{
		sde = stochasticEquation;
		NT = numSubdivisions;
		k = sde->Expiry() / (double)NT;
		// Create the mesh array
		x.push_back(0.0);
		for (int n = 1; n < NT + 1; n++)
		{
			x.push_back(x[n-1] + k);
		}
	}
	std::shared_ptr<ISDE> StochasticEquation() override
	{
		return sde;
	}
	void StochasticEquation(std::shared_ptr<ISDE> se) override
	{
		sde = se;
	}
	virtual double advance(double xn, double tn, double dt,
		double WienerIncrement, double WienerIncrement2)=0;
};

class EulerFdm : public FdmBase
{
public:
	EulerFdm(std::shared_ptr<ISDE> stochasticEquation, int numSubdivisions)
		: FdmBase(stochasticEquation, numSubdivisions) { }
	double advance(double xn, double tn, double dt,
		double normalVar, double normalVar2) override
	{
		return xn + sde->Drift(xn, tn) * dt
			+ sde->Diffusion(xn, tn) * std::sqrt(dt) * normalVar;
	}
};

class MilsteinFdm :public  FdmBase
{
public:
	MilsteinFdm(std::shared_ptr<ISDE> stochasticEquation, int numSubdivisions)
		: FdmBase(stochasticEquation, numSubdivisions) { }
	double advance(double xn, double tn, double dt,
		double normalVar, double normalVar2) override
	{
		return xn + sde->Drift(xn, tn) * dt
			+ sde->Diffusion(xn, tn) * std::sqrt(dt) * normalVar
			+ 0.5 * dt * sde->Diffusion(xn, tn)
			* sde->DiffusionDerivative(xn, tn) * (normalVar * normalVar - 1.0);
	}
};

#endif // !IFDM_HPP
