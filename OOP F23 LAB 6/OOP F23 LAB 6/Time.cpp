////#include "Time.h"
////#include <iostream>
////using namespace std;
////Time::Time(int h, int m, int s) :hour(0, 23), minute(0, 59), second(0, 59)
////{
////	setHour(h);
////	setMinute(m);
////	setSecond(s);
////}
////void Time::setHour(int h)
////{
////	hour.setValue(h);
////}
////void Time::setMinute(int m)
////{
////	minute.setValue(m);
////}
////void Time::setSecond(int s)
////{
////	second.setValue(s);
////}
////void Time::setTime(int h, int m, int s)
////{
////	setHour(h);
////	setMinute(m);
////	setSecond(s);
////}
////int Time::getHour() const
////{
////	return hour.getValue();
////}
////int Time::getMinute() const
////{
////	return minute.getValue();
////}
////int Time::getSecond() const
////{
////	return second.getValue();
////}
////
////void Time::printTwentyFourHourFormat() const
////{
////	cout << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue();
////}
////
////void Time::printTwelveFourHourFormat() const
////{
////	if (hour.getValue() == 0)
////		cout << 12 << ":" << minute.getValue() << ":" << second.getValue() << " AM";
////	else if (hour.getValue() < 12)
////		cout << hour.getValue() << ":" << minute.getValue() << ":" << second.getValue() << " AM";
////	else if (hour.getValue() == 12)
////		cout << 12 << ":" << minute.getValue() << ":" << second.getValue() << " PM";
////	else
////		cout << hour.getValue() % 12 << ":" << minute.getValue() << ":" << second.getValue() << " PM";
////}
////
////void Time::incSec(int inc)
////{
////	hour.increment(inc / 3600);
////	minute.increment(inc % 3600 / 60);
////	second.increment(inc % 3600 % 60);
////}
////
////void Time::incMin(int inc)
////{
////	int total = inc + minute.getValue();
////	if (total > 59)
////	{
////		hour.increment(total / 60);
////	}
////	minute.increment(total );
////	/*int num = inc / 60;
////	hour.increment(inc / 60);
////	minute.increment(inc % 60);*/
////}
////
////void Time::incHour(int inc)
////{
////	hour.increment(inc);
////}
////
////void Time::decSec(int dec)
////{
////	hour.decrement(dec / 3600);
////	minute.decrement(dec % 3600 / 60);
////	second.decrement(dec % 3600 % 60);
////}
////
////void Time::decMin(int dec)
////{
////	hour.decrement(dec / 60);
////	minute.decrement(dec % 60);
////}
////
////void Time::decHour(int dec)
////{
////	hour.decrement(dec);
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
//



#include<iostream>
#include<iomanip>
#include "Time.h"
using namespace std;
Time::Time(int h, int m, int s) :hour(0, 23, h), minute(0, 59, m), second(0, 59, s)
{
}

void Time::setHour(int h)
{
	hour.setValue(h);
}
void Time::setMinute(int m)
{
	minute.setValue(m);
}
void Time::setSecond(int s)
{
	second.setValue(s);
	
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}
int Time::getHour() const
{
	return hour.getValue();
}
int Time::getMinute() const
{
	return minute.getValue();
}
int Time::getSecond() const
{
	return second.getValue();
}
void Time::incHour(int inc)
{
	hour.increment(inc);;
}
void Time::incMin(int inc)
{
	hour.increment(inc / 60);
	minute.increment(inc % 60);
}
void Time::incSec(int inc)
{
	hour.increment(inc / 3600);
	minute.increment(inc % 3600 / 60);
	second.increment(inc % 3600 % 60);
}
void Time::decHour(int h)
{
	hour.decrement(h);
}
void Time::decMin(int dec)
{
	hour.decrement(dec / 60);
	minute.decrement(dec % 60);
}
void Time::decSec(int dec)
{
	hour.decrement(dec / 3600);
	minute.decrement(dec % 3600 / 60);
	second.decrement(dec % 3600 % 60);
}
void Time::printTwentyFourHourFormat() const
{
	cout << setw(2) << setfill('0') << hour.getValue() << ":";
	cout << setw(2) << minute.getValue() << ":";
	cout << setw(2) << second.getValue();
}
void Time::printTwelveHourFormat() const
{
	int hrs = hour.getValue();

	char bound = 'A';
	if (hour.getValue() > 12)
	{
		hrs = hrs - 12;
		bound = 'P';
	}
	else if (hour.getValue() == 12)
	{
		bound = 'P';
	}
	else if (hour.getValue() == 0)
	{
		hrs = 12;
	}
	cout << setw(2) << setfill('0') << hrs << ":";
	cout << setw(2) << minute.getValue() << ":";
	cout << setw(2) << second.getValue() << " " << bound << "M";
}
