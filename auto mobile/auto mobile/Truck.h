#ifndef TRUCK_H
#define TRUCK_H
#include "AutoMobile.h"
#include "String.h"
using namespace std;

// The Truck class represents a truck.
class Truck : public AutoMobile
{
private:
	String driveType;

public:
	// Default constructor
	Truck() : AutoMobile()
	{
		driveType = "";
	}
	// Constructor #2
	Truck(String truckMake, int truckModel, int truckMileage,
		double truckPrice, String truckDriveType) :
		AutoMobile(truckMake, truckModel, truckMileage, truckPrice)
	{
		driveType = truckDriveType;
	}

	// Accessor for driveType attribute
	String getDriveType()
	{
		return driveType;
	}
};
#endif