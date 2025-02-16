#include <iostream>
#include "Point.h"
using namespace std;
Point::Point() : x(0), y(0)
{
	cout << "Point Default Contructor is Called!!!" << "\t" << this <<endl;
}
Point::Point(int a, int b)
{
	cout << "Point OverLoaded Contructor is Called!!!" << "\t" << this << endl;
	x = a;
	y = b;
}
void Point::display()
{
	cout << "values are " << x << "  " << y << endl;
}
Point ::~Point()
{
	cout << "Point Destructor is called!!! \t" << this << endl;
}
Point::Point(const Point& rhs)
{
	cout << "Point Copy Constructor is called !!" << this << endl;
	x = rhs.x;
	y = rhs.y;
}
const Point & Point::operator = (const Point & rhs)
{
	cout << "Point Assigment operator is called !!" << this << endl;
	x = rhs.x;
	y = rhs.y;
	return *this;
}
void Point::setX(int a)
{
	x = a;
}
void Point::setY(int a)
{
	y = a;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
Point::Point(int a):x(a),y(a)
{
	cout << "Point 1 Parameter Contructor is Called!!!" << "\t" << this << endl;
}
