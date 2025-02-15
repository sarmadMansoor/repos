#ifndef PREFERED_CUSTOMER_CLASS
#define PREFERED_CUSTOMER_CLASS
#include "CustomerData.h"
#include <iostream>
using namespace std;
class PreferedCustomer :public CustomerData
{
	double purchaseAmount;
	double discountLevel;
	
public:
	PreferedCustomer();
	void setDiscount();

	PreferedCustomer(const char* lastN, const char* firstN, const char* ad,
		const char* cit, const char* st, int zip, const char* ph
		, int custNo, bool ml, double purchaseAm, double discount = 0);
	~PreferedCustomer();
	PreferedCustomer(const PreferedCustomer& rhs);
	const PreferedCustomer & operator = (const PreferedCustomer& rhs);
	void display();

};
#endif 
