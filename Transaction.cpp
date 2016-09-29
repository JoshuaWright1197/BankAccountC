#include"Transaction.hpp"

Transaction::Transaction()
{
	Month = "";
	transaction = "";
}

void Transaction::setMonth(std::string mon)
{
	Month = mon;
}

std::string Transaction::getMonth()
{
	return Month;
}

void Transaction::setransaction(std::string tran)
{
	transaction = tran;
}

std::string Transaction::gettransaction()
{
	return transaction;
}

void Transaction::setDay(int d)
{
	Day = d;
}

int Transaction::getDay()
{
	return Day;
}

void Transaction::setAmount(double a)
{
	Amount = a;
}

double Transaction::getAmount()
{
	return Amount;
}

void Transaction::setBalance(double b)
{
	Balacne = b;
}

double Transaction::getBalance()
{
	return Balacne;
}

std::string Transaction::tostring()
{
	std::stringstream fmt;
	fmt << Month << "  " << Day << "  " << transaction + ":  $" << std::setprecision(2) << std::fixed <<Amount 
		<< "  Balance :  $" << std::setprecision(2) << std::fixed << Balacne << std::endl;
	
	return fmt.str();;
}
