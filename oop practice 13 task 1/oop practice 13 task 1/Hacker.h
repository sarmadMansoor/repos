#ifndef HACKER_H
#define HACKER_H
#include "Customer.h"
#include "String.h"
class Hacker:public Customer
{
public:
	Hacker();
	Hacker(int noOfH, String na);
	virtual double computeBill();
};
#endif 

