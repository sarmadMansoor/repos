#include <iostream>
#include "Hacker.h"
using namespace std;
Hacker::Hacker(int noOfH, String na)
{
	setNoOfHrs(noOfH);
	setIniatialCost(20);
	setName(na);
	setDiskSpace(50);
	setAdditionalCharge(2.50);
	setChargePerConnection(0);
}
 double Hacker::computeBill()
{
	 if (getNoOfHrs() < 11)
	 {
		 return getNoOfHrs() * getIniatialCost();
	 }
	 else
	 {
		 int rem = getNoOfHrs() - 10;
		 double tempPrices= getIniatialCost()*10;
		 tempPrices = tempPrices + (getAdditionalCharge() * rem);
		 return tempPrices;
	 }
}
