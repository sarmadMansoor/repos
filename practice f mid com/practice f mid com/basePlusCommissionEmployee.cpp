#include <iostream>
#include "basePlusCommissionEmployee.h"
#include "String.h"
using namespace std;
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const String& f, const String& l,
	const String& ssn, double sal, double rat, double salry ):cEmployee(f,l,ssn,sal,rat),salary(salry)
{}

void BasePlusCommissionEmployee::setFirstName(const String& f) // set first name
{
	cEmployee.setFirstName(f);
}
String BasePlusCommissionEmployee::getFirstName() const // return first name
{
	return cEmployee.getFirstName();
}

void BasePlusCommissionEmployee::setLastName(const String& l) // set last name
{
	cEmployee.setLastName(l);
}
String BasePlusCommissionEmployee::getLastName() const // return last name
{
	return cEmployee.getLastName();
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const String& ssn) // set SSN
{
	cEmployee.setSocialSecurityNumber(ssn);
}
String BasePlusCommissionEmployee::getSocialSecurityNumber() const // return SSN
{
	return cEmployee.getSocialSecurityNumber();
}

void BasePlusCommissionEmployee::setGrossSales(double s) // set gross sales amount
{
	cEmployee.setGrossSales(s);
}
double BasePlusCommissionEmployee::getGrossSales() const // return gross sales amount
{
	return cEmployee.getGrossSales();
}

void BasePlusCommissionEmployee::setCommissionRate(double cr)// set commission rate
{
	cEmployee.setCommissionRate(cr);
}
double BasePlusCommissionEmployee::getCommissionRate() const // return commission rate
{
	return cEmployee.getCommissionRate();
}
double BasePlusCommissionEmployee::earnings() const // calculate earnings
{
	return salary + cEmployee.earnings();
}
void BasePlusCommissionEmployee::print() const // print BasePlusCommissionEmployee object
{
	cEmployee.print();
	cout << "\n";
	cout << "Salary : " << salary << endl;
}
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return salary;
}
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
		salary = salary;
}