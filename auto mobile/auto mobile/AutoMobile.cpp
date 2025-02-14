#include <iostream>
#include "AutoMobile.h"
using namespace std;
AutoMobile::AutoMobile()
{
	make = "";
	model = 0;
	price = 0;
	mileage = 0;
}
AutoMobile::AutoMobile(const String& mak, int m, int mil, double p)
{
	make = mak;
	model = m;
	mileage = mil;
	price = p;
}
String AutoMobile::getMake()
{
	return make;
}
int AutoMobile::getModel()
{
	return model;
}
int AutoMobile::getMileage()
{
	return mileage;
}
double AutoMobile::getPrice()
{
	return price;
}
