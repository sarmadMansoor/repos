#include<iostream>
#include"CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(double bal, double f) :Account(bal)
{
	if (f >= 0)
		fee = f;
	else
	{
		cout << "invalid fee";
		fee = 0;
	}
}
void CheckingAccount::credit(double bal)
{
	if (Account::credit(bal))
	{
		Account::credit(fee);
	}
}
void CheckingAccount::debit(double bal)
{
	if (Account::debit(bal))
	{
		Account::debit(fee);
	}
}
