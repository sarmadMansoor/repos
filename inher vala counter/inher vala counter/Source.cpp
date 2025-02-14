#include <iostream>
using namespace std;
#include "FBCounter.h"
int main()
{
	FBCounter c{-4};
	c.increment();//-3
	c.increment();//-2
	c.decrement();//-3
	c.increment();//-2
	cout << c.getCounterValue() << endl;
	return 0;
}