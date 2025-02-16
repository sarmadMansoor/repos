#include <iostream>
#include "Circle.h"
using namespace std;
Circle::Circle()//:center(0,0)
{
	center;
	cout << "Circle Default Constructor is called !!" << this << endl;
	radius = 0;
}
Circle::Circle(int a, int b, int c)
{
	cout << "Circle Overloaded Constructor is called !!" << this << endl;
	center.setX(a);
	center.setY(b);
	radius = c;
}
Circle::~Circle()
{
	cout << "Circle Destructor is called!!! " << this << endl;
}