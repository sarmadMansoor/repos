#ifndef  ACCOUNT_H
#define   ACCOUNT_H
class Account
{
	double balance;
public:
	Account();
	Account(double bal);
	bool credit(double bal);
	bool debit(double bal);
	double getBalance();
};
#endif // ! ACCOUNT_H
