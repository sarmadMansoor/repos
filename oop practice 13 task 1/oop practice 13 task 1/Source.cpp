#include <iostream>
#include "Customer.h"
#include "Hacker.h"
using namespace std;
int main()
{
	Hacker a{ 22,"Sarmad Mansoor" };
	cout<<a.computeBill();
	return 0;
}