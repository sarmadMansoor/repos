#include <iostream>
#include "String.h"
#include "Account.h"
using namespace std;
Account::operator String ()
{
	cout << "Account ka type cast operator\n";
	return String{};
}

AccountType Account::getAccountType()
{
	return type;
}
Account::Account():customer(""),balance(0),interestRate(0),type(INDIVIDUAL)
{

}
Account::Account(const String& cust, double bal, double iRate,AccountType a):customer(cust),balance(bal)
,interestRate(iRate),type(a)
{

}
String Account::getCustomer()
{
	return customer;
}
double Account::getBalance()
{
	return balance;
}
double Account::getInterestRate()
{
	return interestRate;
}
void Account::setCustomer(const String& a)
{
	customer = a;
}
void Account::setBalance(double bal)
{
	balance = bal;
}
void Account::setInterestRate(double iRate)
{
	interestRate = iRate;
}
double Account::calculateInterestRate(int months)
{
	return balance * (1 + interestRate * months);
}
