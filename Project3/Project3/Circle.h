#ifndef CIRCLE_CLASS
#define CIRCLE_CLASS
#include "Point.h"
class Circle
{
	Point center;
	int radius;
public:
	Circle();
	Circle(int, int, int);
	~Circle();
	//Circle(int, int, double);
};
#endif 