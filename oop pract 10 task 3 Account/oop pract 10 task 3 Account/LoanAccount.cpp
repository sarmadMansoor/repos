#include <iostream>
#include "String.h"
#include "LoanAccount.h"
#include "Account.h"
LoanAccount::LoanAccount()
{

}
LoanAccount::LoanAccount(const String & cust, double bal, double iRate, AccountType a):Account (cust,bal,iRate,a)
{

}
double LoanAccount::calculateInterestRate(int months)
{
	if (months > 3 && getAccountType() == INDIVIDUAL)
	{
		return Account::calculateInterestRate(months - 3);
	}
	if (months > 2 && getAccountType() == COMPANY)
	{
		return Account::calculateInterestRate(months - 2);
	}
	return 0;
}

//void deposit();
