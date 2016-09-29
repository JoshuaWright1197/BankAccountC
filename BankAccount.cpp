#include"BankAccount.hpp"

BankAccount::BankAccount()
{
	custName = "";
	accountType = "";
	Month = "";
}

BankAccount::BankAccount(std::string name, std::string type, std::string month)
{
	custName = name;
	accountType = type;
	Month = month;
}

void BankAccount::setcustName(std::string name)
{
	custName = name;
}

std::string BankAccount::getcustName()
{
	return custName;
}

void BankAccount::setaccountType(std::string type)
{
	accountType = type;
}

std::string BankAccount::getaccountType()
{
	return accountType;
}

void BankAccount::setMonth(std::string month)
{
	Month = month;
}

std::string BankAccount::getMonth()
{
	return Month;
}

std::string BankAccount::tostring()
{
	std::string stars = "**************************\n";
	return  stars + "Customer Name : " + custName +
		"\nAccount type : " + accountType +
		"\nCurrent Month : " + Month + "\n" + stars;
}
