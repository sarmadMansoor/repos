
#include <iostream>
//#include "String.h"
//#include "Commission.h"
//#include "basePlusCommissionEmployee.h"
#include "B_P_Comission_Employee.h"
using namespace std;
int main()
{
	Base_Plus_CommissionEmployee
	employee("Bob", "Lewis", "333-33-3333", 5000, .04,300 );
	
		 // set floating-point output formatting
		// cout << fixed << setprecision(2);
	cout << "Employee information obtained by get functions: \n"
		 << "\nFirst name is " << employee.getFirstName()
	 << "\nLast name is " << employee.getLastName()
		 << "\nSocial security number is "
		 << employee.getSocialSecurityNumber()
		 << "\nGross sales is " << employee.getGrossSales()
		 << "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000); // set base salary
	cout << "\nUpdated employee information output by print function: \n" << endl;
	employee.print(); // display the new employee information
	 cout << "\n\nEmployee's earnings: $" <<employee.earnings() << endl;



}