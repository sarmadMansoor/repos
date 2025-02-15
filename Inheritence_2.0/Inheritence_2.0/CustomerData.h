#ifndef  CUSTOMER_DATA_CLASS
#define  CUSTOMER_DATA_CLASS
#include "PersonData.h"
class CustomerData : public PersonData
{
	int customerNumber;
	bool mailingList;
public:
	CustomerData();
	CustomerData(const char* lastN, const char* firstN, const char* ad,
		const char* cit, const char* st, int zip, const char* ph
		, int custNo, bool ml);
	const CustomerData& operator = (const CustomerData& rhs);
	CustomerData(const CustomerData& rhs);
	~CustomerData();
	void display();
};

#endif 

