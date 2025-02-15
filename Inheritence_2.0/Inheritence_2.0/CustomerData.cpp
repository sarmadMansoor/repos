#include <iostream>
#include "CustomerData.h"
//#include "PersonData.h"
using namespace std;
CustomerData::CustomerData(): PersonData(),customerNumber(0),mailingList(false)
{
	cout << "Customer dafault constructor callled\n";
}


/*
this is how we call overloaded constructor of base call from derived class

we can also call default constructor of base class from derived class overloaded constructor 


if we do not call default constructor of base class in constructor of derived class
then compile will call it
but not this happen in aggregration...............

*/
CustomerData::CustomerData(const char* lastN, const char* firstN, const char* ad,
	const char* cit, const char* st, int zip, const char* ph
	,int custNo,bool ml): PersonData (lastN, firstN, ad, cit, st, zip, ph),
	customerNumber(custNo), mailingList(ml)
{
	cout << "Customer dafault constructor callled\n";
	
}
CustomerData::~CustomerData()
{
	cout << "Customer Destructor is called\n";
}
CustomerData::CustomerData(const CustomerData& rhs)
	:PersonData(rhs),customerNumber(rhs.customerNumber),mailingList(rhs.mailingList)
{
	cout << "Customer copy constructor called\n";
}
const CustomerData& CustomerData::operator = (const CustomerData& rhs)
{
	cout << "Customer = operator is called\n";
	if (this != &rhs)
	{
		PersonData::operator=(rhs);
		customerNumber=rhs.customerNumber;
		mailingList = rhs.mailingList;
	}
	return *this;
}
void CustomerData::display()
{
	PersonData::display();
	cout << "Customer Number is : " << customerNumber << "\t" << "The mailing list is :  " << mailingList << endl;
}