#ifndef FB_COUNTER_H
#define FB_COUNTER_H
#include "Counter.h"
class FBCounter:public Counter
{
public:
	FBCounter(int i = 0);
	void decrement();
};
#endif



