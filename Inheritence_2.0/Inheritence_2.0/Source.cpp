#include <iostream>
#include "PreferedCustomer.h"
using namespace std;
#include "BASE_PLUS.h"
int main()
{
	// instantiate BasePlusCommissionEmployee object
	BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	// set floating-point output formatting
	// << fixed << setprecision(2);

	// get commission employee data
	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is " << employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000); // set base salary

	cout << "\nUpdated employee information output by print function: \n"
		<< endl;
	employee.print(); // display the new employee information

	// display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
	/*CustomerData c1("Mansoor", "Sarmad", "Plot number 392 Housing colony 3 layyah", "Layyah", "Punjab", 2233, "0311-0524867", 1, true);
	cout << "*********************************************************************\n";
	c1.display();
	cout << "*********************************************************************\n";*/
	//char lat[20] , ft[20], ct[20], st[20], ph[20], ad[100];
	//cout << "Enter your first Name : ";
	//cin >> ft;
	//cout << "Enter your last Name : ";
	//cin >> lat;
	//cout << "Enter your city Name : ";
	//cin >> ct;
	//cout << "Enter your state Name : ";
	//cin >> st;
	//cout << "Enter your phone Name : ";
	//cin >> ph;
	//cin.ignore();
	//cout << "Enter your address Name : ";
	//cin.getline(ad, 100, '\n');
	////cin.ignore();
	//int zip,cusN;
	//cout << "Enter your zip code : ";
	//cin >> zip;
	//cout << "Enter your customer number : ";
	//cin >> cusN;
	//bool ml;
	//cout << "Are your in mailing list: ";
	//cin >> ml;
	//double pr;
	//cout << "Write your total purchase: ";
	//cin >> pr;
	//cout << "----------------------------------------------------------------\n";
	//PreferedCustomer c1(lat,ft,ad,ct,st,zip,ph,cusN,ml,pr);
	//cout << "----------------------------------------------------------------\n";
	//c1.setDiscount();
	//c1.display();

	//cout << "----------------------------------------------------------------\n";
	

}