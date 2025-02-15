#include <iostream>
#include "Vehicle.h" 
using namespace std;
Vehicle::Vehicle():model(2020),wheels(4)
{
	cout << "Vehicle Default constructor called \n";
}
Vehicle::Vehicle(int m, int w)
{
	bool status = true;
	while (status)
	{
		if (m >= 2020 && w >= 4)
		{
			cout << "Vehicle Overloaded constructor called \n";
			model = m;
			wheels = w;
			status = false;
		}
		else
		{
			cout << "plz enter model greater than 2020 and wheels > 4 : ";
			cin >> m >> w;
		}
	}
}
Vehicle::~Vehicle()
{
	cout << "Vehicle Destructor called \n";
}
void Vehicle::setModel(int m)
{
	model = m;
}
void Vehicle::setWheels(int w)
{
	wheels = w;
}
int Vehicle::getModel() const
{
	return model;
}
int Vehicle::getWheels() const
{
	return wheels;
}
Vehicle::Vehicle(const Vehicle& rhs) :model(rhs.model), wheels(rhs.wheels)
{
	cout << "Vehicle Copy Constructor is called \n";
}
const Vehicle& Vehicle:: operator = (const Vehicle& rhs)
{
	cout << "Vehicle = operator is called\n";
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		setModel(rhs.getModel());
		setWheels(rhs.getWheels());
		return *this;
	}
}
void Vehicle::display() const
{
	cout << "--------Vehicle Display----------\n";
	cout<<"Values of Model is : " << getModel() << "\n" << "Number of Wheels are : " << getWheels() << endl;
}