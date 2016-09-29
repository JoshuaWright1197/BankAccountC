#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Transaction.hpp"
#include<sstream>
#include <iomanip>
#include<cmath>
#include<ctime>

class BankAccount
{
public:
	// construcotrs
	BankAccount();
	BankAccount(std::string name, std::string type, std::string month);

	//utility fuctions
	void setcustName(std::string name);
	std::string getcustName();
	void setaccountType(std::string type);
	std::string getaccountType();
	void setMonth(std::string month);
	std::string getMonth();
	std::string tostring();
	
	//abstract functions
	virtual void deposit(double depositAmount, int  day)  = 0;
	virtual void withdrawal(double withdrawalAmount, int  day) = 0;
	virtual void clacintrest() = 0;
	virtual void recordtransaction(std::string  tranaction,int day, double amount, double  balance) = 0;
	virtual void monthlyProcess() = 0;
	virtual std::string setAccontNumber() = 0;

private:
	std::string custName, accountType, Month;
};


