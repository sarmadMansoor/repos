#include <iostream>
#include "Car.h"
using namespace std;
#include "AutoMobile.h"
#include "String.h"
Car::Car() :AutoMobile()
{
	doors = 0;
}
Car::Car(const String & s, int m, int mil, double p, int dor):AutoMobile(s,m,mil,p),doors(dor)
{

}
int Car::getDoors()
{
	return doors;
}
