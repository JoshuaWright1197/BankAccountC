#pragma once
#include"BankAccount.hpp"

class SavingAccount : public BankAccount
{
public:
	SavingAccount();
	SavingAccount(std::string name, std::string month, double balance);
	bool isAccountActive();
	int getnumberWithdrawals();
	int getnumberDeposits();
	double getBalance();
	double getINT_RATE();
	void deposit(double depositamount, int day);
	void withdrawal(double withdrawalamount, int day);
	void recordtransaction(std::string transaction, int day, double amount, double balance);
	void clacintrest();
	void printtrasaction();
	void monthlyProcess();
	std::string setAccontNumber();
	std::string tostring();

private:
	std::string AccountNumber = "";
	int numberWithdrawals = 0;
	int numberDeposits = 0;
	double Balance = 0;
	bool accountActive;
	double INT_RATE;
	std::vector<Transaction> record;
};