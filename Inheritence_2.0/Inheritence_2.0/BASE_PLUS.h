#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ standard string class
#include "Commission.h" // Commission Employee class declaration

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee 
{
public:
	// constructor
	BasePlusCommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);

	// set base salary
	void setBaseSalary(double);

	// return base salary
	double getBaseSalary() const;

	// calculate earnings (overrides CommissionEmployee earnings())
	double earnings() const ;

	// print BasePlusCommissionEmployee object
	void print() const ;

private:
	double baseSalary; // base salary
};

#endif
