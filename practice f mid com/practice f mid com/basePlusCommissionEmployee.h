#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "Commission.h"
#include "String.h" // C++ standard string class
using namespace std;
class BasePlusCommissionEmployee 
{
public:
	BasePlusCommissionEmployee(const String &, const String &,
		const String &, double = 0.0, double = 0.0, double = 0.0);

	void setFirstName(const String &); // set first name
	String getFirstName() const; // return first name

	void setLastName(const String&); // set last name
	String getLastName() const; // return last name

	void setSocialSecurityNumber(const String&); // set SSN
	String getSocialSecurityNumber() const; // return SSN

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	void setCommissionRate(double); // set commission rate
	double getCommissionRate() const; // return commission rate
	double getBaseSalary() const;
	void setBaseSalary(double sa);

	double earnings() const; // calculate earnings
	void print() const; // print BasePlusCommissionEmployee object
private:
	double salary;
	CommissionEmployee cEmployee;
};

#endif