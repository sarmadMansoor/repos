#include <iostream>
#include "Counter.h"
using namespace std;
Counter::Counter(int i) :value(i)
{}
void Counter::increment()
{
	value++;
}
void Counter::reset()
{
	value = 0;
}
void Counter::startAt(int i)
{
	value = i;
}
int Counter::getCounterValue()
{
	return value;
}