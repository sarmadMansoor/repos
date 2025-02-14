#ifndef COMMISSION_H
#define COMMISSION_H
#include "String.h"
using namespace std;

class CommissionEmployee
{
	String lastName;
	String firstName;
	String socialSecurityNumber;
	double grossSales;
	double commissionRate;
public:
	CommissionEmployee(const String&, const String&, const String&,
		double = 0.0, double = 0.0);
	void setFirstName(const String&); // set first name
	string getFirstName() const; // return first name

	void setLastName(const String&); // set last name
	string getLastName() const; // return last name

	void setSocialSecurityNumber(const String&); // set SSN
	string getSocialSecurityNumber() const; // return SSN

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	void setCommissionRate(double); // set commission rate (percentage)
	double getCommissionRate() const; // return commission rate

	double earnings() const; // calculate earnings
	void print() const; // print CommissionEmployee object
};

#endif // !COMMISSION_H
