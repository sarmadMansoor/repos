#include "BASE_PLUS.h"
#include <iostream>
 using namespace std;

 // constructor
 BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	 const string & first, const string & last, const string & ssn,
	 double sales, double rate, double salary)
	 // explicitly call base-class constructor
	 : CommissionEmployee(first, last, ssn, sales, rate)
	 {
	 setBaseSalary(salary); // validate and store base salary
	 } // end BasePlusCommissionEmployee constructor

 // set base salary
 void BasePlusCommissionEmployee::setBaseSalary(double salary)
 {
	 if (salary >= 0.0)
		 baseSalary = salary;
 }

 // return base salary
 double BasePlusCommissionEmployee::getBaseSalary() const
 {
	 return baseSalary;
	 } // end function getBaseSalary

 double BasePlusCommissionEmployee::earnings() const
 {
	return CommissionEmployee::earnings();

  }
  void BasePlusCommissionEmployee::print() const
 {
	  cout << "base-salaried ";
	  CommissionEmployee::print();
	   cout << "\nbase salary: " << getBaseSalary();

 }

