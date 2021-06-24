#pragma once
#include <iostream>
#include <string>
using namespace std;


class GasCylinder_Adaptee
{
private:
	double volume_, molar_, mass_;
public:
	GasCylinder_Adaptee(double volume, double mass, double molar) 
	{
		volume_ = volume;
		mass_ = mass;
		molar_ = molar;
	}
	double GetPressure(int T)
	{
		return (AmountOfMatter() * 8.314 * T) / volume_;
	}
	void getParams(double& vol, double& mol, double& mas) // добавил свой метод, так как для операции изменения массы каким-то образом надо обратиться к privat mass_
	{
		vol = volume_;
		mol = molar_;
		mas = mass_;
	}
	double AmountOfMatter()
	{
		return mass_ / molar_;
	}
	string ToString()
	{
		return "Volume - " + to_string(volume_) + ", Mass - " + to_string(mass_) + ", Molar - " + to_string(molar_) + ".";
	}
};


class GasCylinder_Target
{
public:
	virtual double CalculateDp(int T0, int dT) = 0;
	virtual void ModifMass(double dm) = 0;
	virtual string GetData() = 0;
	virtual ~GasCylinder_Target() {}
};


class GasCylinder_Adapter : public GasCylinder_Target
{
private:
	GasCylinder_Adaptee* adaptee;
public:
	GasCylinder_Adapter(GasCylinder_Adaptee* tmp) { adaptee = tmp; }
	~GasCylinder_Adapter() { delete adaptee; }
	double CalculateDp(int T0, int dT)
	{
		return adaptee->GetPressure(T0) * dT / T0;
	}
	void ModifMass(double dm)
	{
		double volume, molar, mass;
		adaptee->getParams(volume, molar, mass);
		*adaptee = GasCylinder_Adaptee(volume, mass + dm, molar);
	}
	string GetData()
	{
		return adaptee->ToString();
	}
};