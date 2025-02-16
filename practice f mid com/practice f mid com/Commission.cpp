#include <iostream>
#include "Commission.h"
#include "String.h"
using namespace std;
CommissionEmployee::CommissionEmployee(
	const String& first, const String& last, const String& ssn,
	double sal, double rte) :lastName(last), firstName(first), socialSecurityNumber(ssn)
{
	grossSales = sal;
	commissionRate = rte;
}
// set first name
void CommissionEmployee::setFirstName(const String& first)
{
	firstName = first; // should validate
} // end function setFirstName

// return first name
String CommissionEmployee::getFirstName() const
{
	return firstName;
} // end function getFirstName

// set last name
void CommissionEmployee::setLastName(const String& last)
{
	lastName = last; // should validate
} // end function setLastName

// return last name
String CommissionEmployee::getLastName() const
{
	return lastName;
} // end function getLastName
// set social security number
void CommissionEmployee::setSocialSecurityNumber(const String& ssn)
{
	socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
String CommissionEmployee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
}
double CommissionEmployee::getGrossSales() const // return gross sales amount
{
	return grossSales;
}
void CommissionEmployee::setGrossSales(double sales)// set commission rate (percentage)
{
	if (sales >= 0.0)
	{
		grossSales = sales;
	}
	return;
}
void  CommissionEmployee::setCommissionRate(double rate) // return commission rate
{
	if (rate > 0.0 && rate < 1.0)
		commissionRate = rate;
	else
		return;
}
double CommissionEmployee::getCommissionRate() const // return commission rate
{
	return commissionRate;
}
double CommissionEmployee::earnings() const // calculate earnings
{
	return commissionRate * grossSales;
}
void CommissionEmployee::print() const // print CommissionEmployee object
{
	cout << "commission employee: " << firstName << ' ' << lastName
		<< "\nsocial security number: " << socialSecurityNumber
		<< "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate;
}