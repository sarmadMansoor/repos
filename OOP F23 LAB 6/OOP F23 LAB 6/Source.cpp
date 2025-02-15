#include <iostream>
#include "BoundedInteger.h"
#include "Time.h"
using namespace std;
int main()
{
	Time a{20,59,59 };
	//a.incHour();
	a.incSec();
	a.printTwentyFourHourFormat();

	/*BoundedInteger b{ 5,12,12 };
	b.increment(1);
	cout<<b.getValue() << endl;*/
	/*b.increment(8);
	cout << b.getValue() << endl;*/

}