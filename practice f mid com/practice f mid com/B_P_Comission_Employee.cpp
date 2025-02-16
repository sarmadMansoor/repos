#include <iostream>
#include "B_P_Comission_Employee.h"
#include "Commission.h"
#include "String.h"
using namespace std;
Base_Plus_CommissionEmployee::Base_Plus_CommissionEmployee(const String& f, const String& l,
	const String& ssn, double sales, double rate, double salry):CommissionEmployee(f,l,ssn,sales,rate),salary(salry)
{

}
double Base_Plus_CommissionEmployee::getBaseSalary() const
{
	return salary;
}
void Base_Plus_CommissionEmployee::setBaseSalary(double sa)
{
	salary = sa;
}
double Base_Plus_CommissionEmployee::earnings() const// calculate earnings
{
	return salary + CommissionEmployee::earnings();
}
void Base_Plus_CommissionEmployee::print() const
{
	CommissionEmployee::print();
	cout << endl;
	cout << "Salary is : " << salary << endl;
}
