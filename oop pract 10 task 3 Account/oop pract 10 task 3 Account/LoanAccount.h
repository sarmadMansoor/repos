#ifndef LOAN_ACCOUNT_H
#define LOAN_ACCOUNT_H
#include "String.h"
#include "Account.h"
class LoanAccount:public Account
{
public:
	LoanAccount();
	LoanAccount(const String& cust, double bal, double iRate, AccountType a);
	double calculateInterestRate(int months);
	void deposit();
};
#endif

