#include <iostream>
#include "SavingsAccount.h"
#include "Account.h"
using namespace std;
SavingsAccount::SavingsAccount():Account()
{
	interestRate = 0;
}
SavingsAccount::SavingsAccount(double bal, double intRate):Account(bal),interestRate(intRate)
{
}
double SavingsAccount::calculateInterest()
{
	return (interestRate /100.0) * getBalance();
}
