#ifndef SUV_H
#define SUV_H
#include "AutoMobile.h"
#include "String.h"
using namespace std;

// The SUV class represents a SUV.
class SUV : public AutoMobile
{
private:
	int passengers;

public:
	// Default constructor
	SUV() : AutoMobile()
	{
		passengers = 0;
	}

	// Constructor #2
	SUV(String SUVMake, int SUVModel, int SUVMileage,
		double SUVPrice, int SUVPassengers) :
		AutoMobile(SUVMake, SUVModel, SUVMileage, SUVPrice)
	{
		passengers = SUVPassengers;
	}

	// Accessor for passengers attribute
	int getPassengers()
	{
		return passengers;
	}
};
#endif