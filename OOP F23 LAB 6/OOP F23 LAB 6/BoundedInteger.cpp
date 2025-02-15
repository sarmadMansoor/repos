////#include "BoundedInteger.h"
////#include "BoundedInteger.h"
////#include <stdexcept>
////#include <iostream>
////using namespace std;
////bool BoundedInteger::isValidBound(int lowerBound, int upperBound) const
////{
////    return lowerBound <= upperBound;
////}
////
////BoundedInteger::BoundedInteger()
////{
////    lowerBound = INT_MIN;
////    upperBound = INT_MAX;
////    value = lowerBound;
////}
////
////BoundedInteger::BoundedInteger(int lb, int ub) : lowerBound(lb), upperBound(ub) 
////{
////    if (!isValidBound(lowerBound, upperBound)) 
////    {
////        return;
////    }
////    value = lowerBound;
////}
////
////BoundedInteger::BoundedInteger(int lb, int ub, int val) : lowerBound(lb), upperBound(ub) 
////{
////    if (!isValidBound(lowerBound, upperBound)) 
////    {
////        return;
////    }
////    if (!isValidValue(val))
////    {
////        value = lowerBound;
////    }
////    else
////    {
////        value = val;
////    }
////}
////
////void BoundedInteger::setValue(int val) 
////{
////    if (!isValidValue(val)) 
////    {
////        return;
////    }
////    value = val;
////}
////
////int BoundedInteger::getValue() const
////{
////    return value;
////}
////
////int BoundedInteger::getLowerBound()const
////{
////    return lowerBound;
////}
////
////int BoundedInteger::getUpperBound()const
////{
////    return upperBound;
////}
////
////void BoundedInteger::increment(int inc)
////{
////    int diff = upperBound - lowerBound+1;
////    int newValue = inc + value;
////    if (newValue > upperBound)
////    {
////        newValue = newValue % diff;
////        if (newValue < lowerBound)
////            newValue += diff;
////    }
////    value = newValue; 
////}
////
////void BoundedInteger::decrement(int dec) 
////{
////    int newValue = value - dec;
////    if (newValue < lowerBound)
////    {
////        newValue = upperBound - (lowerBound - newValue - 1);
////    }
////    value = newValue;
////}
////
////bool BoundedInteger::isValidValue(int val) const
////{
////    return (lowerBound <= val) && (val <= upperBound);
////}
//#include "Time.h"
//#include <iostream>
//using namespace std;
//Time::Time(int h, int m, int s) : hour(0, 23, h), minute(0, 59, m), second(0, 59, s)
//{}
//
//void Time::setHour(int h)
//{
//    hour.setValue(h);
//}
//
//void Time::setMinute(int m)
//{
//    minute.setValue(m);
//}
//
//void Time::setSecond(int s)
//{
//    second.setValue(s);
//}
//
//void Time::setTime(int h, int m, int s)
//{
//    hour.setValue(h);
//    minute.setValue(m);
//    second.setValue(s);
//}
//
//int Time::getHour() const
//{
//    return hour.getValue();
//}
//
//int Time::getMinute() const
//{
//    return minute.getValue();
//}
//
//int Time::getSecond() const
//{
//    return second.getValue();
//}
//
//void Time::printTwentyFourHourFormat() const
//{
//    cout << "Time: " << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue() << endl;
//}
//
//void Time::printTwelveFourHourFormat() const
//{
//    int h = hour.getValue();
//    char period[3] = { 'A', 'M', '\0' };
//    if (h >= 12)
//    {
//        period[0] = 'P';
//        h = (h == 12) ? 12 : h % 12;
//    }
//    else
//    {
//        h = (h == 0) ? 12 : h;
//    }
//    cout << "Time: " << h << ":" << minute.getValue() << ":" << second.getValue() << " " << period << endl;
//}
//
//
//void Time::incSec(int inc)
//{
//    second.increment(inc);
//    minute.increment(second.getValue() / 60);
//    second.setValue(second.getValue() % 60);
//    hour.increment(minute.getValue() / 60);
//    minute.setValue(minute.getValue() % 60);
//}
//
//void Time::incMin(int inc)
//{
//    minute.increment(inc);
//    if (minute.getValue() >= 60)
//    {
//        hour.increment(1);
//        minute.setValue(minute.getValue() % 60);
//    }
//}
//
//
//void Time::incHour(int inc)
//{
//    hour.increment(inc);
//    hour.setValue(hour.getValue() % 24);
//}
//
//void Time::decSec(int dec)
//{
//    second.decrement(dec);
//    if (second.getValue() < 0)
//    {
//        minute.decrement(1);
//        second.increment(60);
//    }
//}
//
//void Time::decMin(int dec)
//{
//    minute.decrement(dec);
//    if (minute.getValue() < 0)
//    {
//        hour.decrement(1);
//        minute.increment(60);
//    }
//}
//
//void Time::decHour(int dec)
//{
//    hour.decrement(dec);
//    if (hour.getValue() < 0)
//    {
//        hour.increment(24);
//    }
//}





#include"BoundedInteger.h"
#include  "stdexcept"
bool BoundedInteger::isValidBound(int lb, int ub) const
{
	return lowerBound <= upperBound;
}
BoundedInteger::BoundedInteger()
{
	lowerBound = INT_MIN;
	upperBound = INT_MAX;
	value = lowerBound;
}
BoundedInteger::BoundedInteger(int lb, int ub) :BoundedInteger()
{
	if (!isValidBound(lb, ub))
		return;
	lowerBound = lb;
	upperBound = ub;
	value = lb;
}
BoundedInteger::BoundedInteger(int lb, int ub, int val) :BoundedInteger(lb, ub)
{
	setValue(val);
}

void BoundedInteger::setValue(int val)
{
	if (isValidValue(val))
		value = val;
}

int BoundedInteger::getValue() const
{
	return value;
}

int BoundedInteger::getUpperBound() const
{
	return upperBound;
}

int BoundedInteger::getLowerBound() const
{
	return lowerBound;
}

bool BoundedInteger::isValidValue(int val) const
{
	return (val >= lowerBound && val <= upperBound);
}

void BoundedInteger::increment(int inc)
{
	value =value + inc;
	if (value > upperBound)
	{
		value = value % upperBound + lowerBound - 1;
	}
}

void BoundedInteger::decrement(int dec)
{
	value =value - dec;
	if (value < lowerBound)
	{
		int totalValue = upperBound - lowerBound + 1;
		value = upperBound - ((lowerBound - value - 1) % totalValue);
	}
}
