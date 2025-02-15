#include <iostream>
#include "Car.h" 
using namespace std;
Car::Car() :capacity(5)
{
	cout << "Car Default constructor called \n";
}
Car::Car(int m, int w, int c) :Vehicle(m, w)
{
	cout << "Car Overloaded constructor called \n";
	capacity = c;
}
Car::~Car()
{
	cout << "Car Destructor called \n";
}
void Car::setCapacity(int m)
{
	capacity = m;
}

int Car::getCapacity() const
{
	return capacity;

}
//this is how we call copy constructor in inheritance topic;
// basically we are calling copy constructor of base class(Vehicle) by 
// standing in derived Class (Car) 
Car::Car(const Car& rhs) :Vehicle(rhs), capacity(rhs.getCapacity())
{
	cout << "Car copy constructor  is called \n";
}
const Car& Car::operator=(const Car& rhs)
{
	Vehicle::operator=(rhs); //call = operator of base class;
	cout << "Car = operator is  called \n";
	if (this == &rhs)
	{
		return *this;
	}
	else
	{
		setCapacity(rhs.getCapacity());
		return *this;
	}
}
void Car::display() const
{
	Vehicle::display();
	cout << "--------Car Display----------\n";
	cout << "Passengers are " << getCapacity() << endl;
}