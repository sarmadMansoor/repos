#include <iostream>
#include "FBCounter.h"
using namespace std;
FBCounter::FBCounter(int i ):Counter(i)
{

}
void FBCounter::decrement()
{
	int val =getCounterValue();
	val--;
	startAt(val);
}