#ifndef TIME_H
#define TIME_H
#include "BoundedInteger.h"

class Time
{
private:
    BoundedInteger hour;
    BoundedInteger minute;
    BoundedInteger second;
public:
    Time(int h = 0, int m = 0, int s = 0);
    void setMinute(int n);
    void setSecond(int s);
    void setHour(int h);
    void setTime(int h, int n, int s);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printTwentyFourHourFormat() const;
    void printTwelveHourFormat() const;

    void incSec(int inc = 1);
    void incMin(int inc = 1);
    void incHour(int inc = 1);

    void decSec(int dec = 1);
    void decMin(int dec = 1);
    void decHour(int dec = 1);
};

#endif
