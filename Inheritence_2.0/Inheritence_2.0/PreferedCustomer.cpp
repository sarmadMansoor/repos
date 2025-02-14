#include <iostream>
#include "PreferedCustomer.h"
using namespace std;

void PreferedCustomer::setDiscount()
{
	if (purchaseAmount <= 500)
	{
		discountLevel = (purchaseAmount * 0.05);
	}
	else if (purchaseAmount <= 1000)
	{
		discountLevel = purchaseAmount * 0.06;
	}
	else if (purchaseAmount <= 1500)
	{
		discountLevel = purchaseAmount * 0.07;
	}
	else
	{
		discountLevel = purchaseAmount * 0.1;
	}
}
PreferedCustomer::PreferedCustomer() :CustomerData(), purchaseAmount(0), discountLevel(0)
{
	cout << " Prefered default constructor called\n";
}

PreferedCustomer::PreferedCustomer(const char* lastN, const char* firstN, const char* ad,
	const char* cit, const char* st, int zip, const char* ph
	, int custNo, bool ml, double purchaseAm, double discount ) :
	CustomerData(lastN, firstN, ad, cit, st, zip, ph, custNo, ml)
{
	cout << "Prefered overloaded constructor is called\n";
	purchaseAmount = purchaseAm;
	discountLevel = discount;
}
PreferedCustomer::~PreferedCustomer()
{
	cout << "prefered destructor called \n";
}
PreferedCustomer::PreferedCustomer(const PreferedCustomer& rhs) :CustomerData(rhs), purchaseAmount(rhs.purchaseAmount),
discountLevel(rhs.discountLevel)
{
	cout << "prefered copy constructor is called \n";
	/*purchaseAmount = rhs.purchaseAmount;
	discountLevel = rhs.discountLevel;*/
}
const PreferedCustomer& PreferedCustomer::operator = (const PreferedCustomer& rhs)
{
	if (this != &rhs)
	{
		CustomerData::operator=(rhs);
		purchaseAmount = rhs.purchaseAmount;
		discountLevel = rhs.discountLevel;
	}
	return *this;
}
void PreferedCustomer::display()
{
	CustomerData::display();
	cout << "The Purchase of  " << getFirstName() << " " << getLastName() << " is : " << purchaseAmount << endl;
	cout << "The discount he will get is : " << discountLevel << endl;
}

