#ifndef  B_P_COMMISSION_EMPLOYEE
#define   B_P_COMMISSION_EMPLOYEE
#include "String.h"
#include "Commission.h"
class Base_Plus_CommissionEmployee :public CommissionEmployee
{
public:
	Base_Plus_CommissionEmployee(const String&, const String&,
		const String&, double = 0.0, double = 0.0, double = 0.0);

	double getBaseSalary() const;
	void setBaseSalary(double sa);

	double earnings() const; // calculate earnings
	void print() const; // print BasePlusCommissionEmployee object
private:
	double salary;

};
#endif // ! B_P_COMMISSION_EMPLOYEE
