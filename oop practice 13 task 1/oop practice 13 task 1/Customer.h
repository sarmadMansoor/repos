#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "String.h"
class Customer
{
	int noOfHrs;
	float initialCost;
	String name;
	int diskSpace;
	double additionalCharge;
	double chargePerConnection;
protected:
	void setNoOfHrs(int a);
	void setIniatialCost(float a);
	void setName(const String & a);
	void setDiskSpace(int a);
	void  setAdditionalCharge(double a);
	void setChargePerConnection(double a);
public:
	Customer();
	int getNoOfHrs();
	float getIniatialCost();
	String getName();
	int getDiskSpace();
	double getAdditionalCharge();
	double getChargePerConnection();
	virtual double computeBill()=0;


};
#endif


