#ifndef ISDE_HPP
#define ISDE_HPP

class ISDE
{// Standard one-factor SDE dX = a(X,t)dt + b(X,t)dW, X(0)given
// dX = mu(X,t)dt + sig(X,t)dW
public:
	virtual double Drift(double x, double t)=0; // a (mu)
	virtual double Diffusion(double x, double t)=0; // b (sig)

	// Some extra functions associated with the SDE
	virtual double DriftCorrected(double x, double t, double B)=0;
	virtual double DiffusionDerivative(double x, double t)=0;

	//Set/get functions
	virtual double InitialCondition() = 0;
	virtual void InitialCondition(double initcon) = 0;
	virtual double Expiry() = 0;
	virtual void Expiry(double expiry) = 0;
};

class GBM : public ISDE
{ // Simple SDE
private:
	double mu; // Drift
	double vol; // Constant volatility
	double d; // Constant dividend yield
	double ic; // Initial condition
	double exp; // Expiry
public:
	GBM(double driftCoefficient, double diffusionCoefficient,
		double dividendYield, double initialCondition, double expiry)
	{//Initialization of GBM
		mu = driftCoefficient;
		vol = diffusionCoefficient;
		d = dividendYield;
		ic = initialCondition;
		exp = expiry;
	}

	double Drift(double x, double t) override { return (mu - d) * x; }
	double Diffusion(double x, double t) override{ return vol * x; }
	double DriftCorrected(double x, double t, double B) override
	{
		return Drift(x, t) - B * Diffusion(x, t) * DiffusionDerivative(x, t);
	}
	double DiffusionDerivative(double x, double t) override
	{
		return vol;
	}
	// Property to set/get initial condition
	double InitialCondition() override
	{
		return ic;
	}
	void InitialCondition(double initcon) override
	{
		ic = initcon;
	}
	//Property to set/get expiry
	double Expiry() override
	{
		return exp;
	}
	void Expiry(double expiry) override
	{
		exp = expiry;
	}
};

#endif // !ISDE_HPP
