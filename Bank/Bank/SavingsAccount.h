#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"
class SavingsAccount :public Account
{
	double interestRate;
public:
	SavingsAccount();
	SavingsAccount(double bal,double intRate );
	double calculateInterest();

};
#endif // !SAVINGS_ACCOUNT_H



