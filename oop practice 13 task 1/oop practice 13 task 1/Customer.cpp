#include <iostream>
#include "Customer.h"
using namespace std;
Customer::Customer():name(""),initialCost(0),noOfHrs(0),diskSpace(0),additionalCharge(0),
chargePerConnection(0)
{

}
int Customer::getNoOfHrs()
{
	return noOfHrs;
}
void Customer::setNoOfHrs(int a)
{
	noOfHrs = a;
}
float Customer::getIniatialCost()
{
	return initialCost;
}
void Customer::setIniatialCost(float a)
{
	initialCost = a;
}
String Customer::getName()
{
	return name;
}
void Customer::setName(const String& a)
{
	name =a;
}
int Customer::getDiskSpace()
{
	return diskSpace;
}
void Customer::setDiskSpace(int a)
{
	diskSpace = a;
}
double Customer::getAdditionalCharge()
{
	return additionalCharge;
}
void  Customer::setAdditionalCharge(double a)
{
	additionalCharge = a;
}
double Customer::getChargePerConnection()
{
	return chargePerConnection;
}
void Customer::setChargePerConnection(double a)
{
	chargePerConnection = a;
}
