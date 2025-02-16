#include <iostream>
#include "OrderedPair.h"
using namespace std;
OrderedPair::OrderedPair(int n,int m)
{
	a = n;
	b = m;
}
int OrderedPair:: getA() const
{
	return a;
}
int OrderedPair:: getB() const
{
	return b;
}
void OrderedPair::setA(int n)
{
	a = n;
}
void OrderedPair::setB(int n)
{
	b = n;
}