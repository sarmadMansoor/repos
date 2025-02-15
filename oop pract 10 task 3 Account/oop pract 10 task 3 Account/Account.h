#ifndef ACOOUNT_CLASS_H
#define ACOOUNT_CLASS_H
#include "String.h"
enum AccountType { INDIVIDUAL, COMPANY };
class Account
{
	String customer;
	double balance;
	double interestRate;
	AccountType type;
public:
	Account();
	operator String ();
	Account(const String& cust, double bal, double iRate,AccountType a);
	String getCustomer();
	double getBalance();
	double getInterestRate();
	void setCustomer(const String& a);
	void setBalance(double bal);
	void setInterestRate(double iRate);
	AccountType getAccountType();
	virtual double calculateInterestRate(int months);
};
#endif


