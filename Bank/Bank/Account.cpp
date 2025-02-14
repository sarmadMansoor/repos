#include <iostream>
#include "Account.h"
using namespace std;
Account::Account()
{
	balance = 0;
}
Account::Account(double bal):Account()
{
	if (bal >= 0.0)
	{
		balance = bal;
	}
	else
	{
		cout << "Intial Balance was invalid\n";
		exit(0);
	}
}
bool Account::credit(double bal)
{
	if (bal >= 0)
	{
		balance += bal;
		return true;
	}
	return false;
}
bool Account::debit(double bal)
{
	if (bal <= balance)
	{
		balance -= bal;
		return true;
	}
	else
	{
		cout << "Debit amount exceeded account balance\n";
		return false;
	}
}
double Account::getBalance()
{
	return balance;
}
