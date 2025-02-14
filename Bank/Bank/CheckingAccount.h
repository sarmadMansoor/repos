#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNR_H
#include"Account.h"

class CheckingAccount :public Account
{
	double fee;
public:

	CheckingAccount(double = 0, double = 0);
	void credit(double);
	void debit(double);

};


#endif // !CHECKINGACCOUNT_H