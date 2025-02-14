#ifndef  AUTO_MOBILE_H
#define  AUTO_MOBILE_H
#include "String.h"
class AutoMobile
{
	String make;
	int model;
	int mileage;
	double price;
public:
	AutoMobile();
	AutoMobile(const String&, int m, int mil, double p);
	String getMake();
	int getModel();
	int getMileage();
	double getPrice();
};
#endif // ! AUTO_MOBILE_H
