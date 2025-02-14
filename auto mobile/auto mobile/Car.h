#ifndef CAR_H
#define  CAR_H
#include "AutoMobile.h"
class String;
class Car:public AutoMobile
{
	int doors;
public:
	Car();
	Car(const String&, int m, int mil, double p, int dor);
	int getDoors();
};
#endif


