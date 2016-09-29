#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
#include<sstream>
#include <iomanip>

class Transaction
{
public:
	// constructor
	Transaction();

	//utility functions
	void setMonth(std::string mon);
	std::string getMonth();
	void setransaction(std::string tran);
	std::string gettransaction();
	void setDay(int d);
	int getDay();
	void setAmount(double a);
	double getAmount();
	void setBalance(double b);
	double getBalance();
	std::string tostring();

private:
	std::string Month, transaction;
	int Day = 0;
	double Amount = 0, Balacne = 0;
};