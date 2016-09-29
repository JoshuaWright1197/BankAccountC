#pragma once
#include"BankAccount.hpp"

class ChequingAccount : public BankAccount
{
public:
	//constructors
	ChequingAccount();
	ChequingAccount(std::string name, std::string month, double balance);

	//utiltiy functinos
	bool isAccountActive();
	int getnumberWithdrawals();
	int getnumberDeposits();
	double getBalance();
	double getINT_RATE();
	double getSERVICE_FEE();
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
	double SERVICE_FEE;
	std::vector<Transaction> record;
};