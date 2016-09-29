#include"SavingAccount.hpp"

SavingAccount::SavingAccount()
{
	AccountNumber = "";
	accountActive = false;
}

SavingAccount::SavingAccount(std::string name, std::string month, double balance) : BankAccount(name, "Saving", month)
{
	Balance = balance;
	isAccountActive();
	INT_RATE = 0.025;
	AccountNumber = setAccontNumber();
}

bool SavingAccount::isAccountActive()
{
	if (Balance >= 25)
		accountActive = true;
	else
		accountActive = false;
	return accountActive;
}

int SavingAccount::getnumberWithdrawals()
{
	return numberWithdrawals;
}

int SavingAccount::getnumberDeposits()
{
	return numberDeposits;
}

double SavingAccount::getBalance()
{
	return Balance;
}

double SavingAccount::getINT_RATE()
{
	return INT_RATE;
}

void SavingAccount::deposit(double depositamount, int day)
{
	isAccountActive();
	Balance += depositamount;
	numberDeposits++;
	recordtransaction("Desposit", day, depositamount, Balance);
}

void SavingAccount::withdrawal(double withdrawalamount, int day)
{
	std::string transatcionmsg = "";

	if (Balance - withdrawalamount > 0.0 && isAccountActive() == true)
	{
		transatcionmsg = "Withdrawal";
		Balance -= withdrawalamount;
		numberWithdrawals++;
	}
	else if (isAccountActive() == false)
	{
		transatcionmsg = "Transaction cancelled. Account is inactive.";
	}
	else
	{
		transatcionmsg = "Transaction cancelled. Insufficient funds";
	}
	isAccountActive();
	numberWithdrawals++;
	recordtransaction(transatcionmsg, day, withdrawalamount, Balance);
}

void SavingAccount::recordtransaction(std::string transaction, int day, double amount, double balance)
{
	Transaction trans;
	trans.setransaction(transaction);
	trans.setAmount(amount);
	trans.setBalance(balance);
	trans.setDay(day);
	trans.setMonth(getMonth());
	record.push_back(trans);
}

void SavingAccount::clacintrest()
{
	double MI = INT_RATE / 12;
	if (isAccountActive()== true)
	{
		Balance += MI;
	}
	recordtransaction("Intrest", 31, MI, Balance);
}

void SavingAccount::printtrasaction()
{
	std::ostringstream fmt;
	std::string stars = "******************************************\n";
	std::cout << stars;
	std::cout << "Transaction Record for the Month of " + getMonth() << std::endl;
	std::cout << stars;

	for (int i = 0; i < (record.size() - 2); i++)
	{
		std::cout << record.at(i).tostring();
	}

	fmt << "\nTotal Deposits: " << numberDeposits << "\n" 
		<< "Total Withdrawals: " << numberWithdrawals << std::endl;

	std::cout << fmt.str();
	for (int i = (record.size() - 2); i < record.size(); i++)
	{
		std::cout << record.at(i).tostring();
	}
}

void SavingAccount::monthlyProcess()
{
	clacintrest();
	printtrasaction();
	numberDeposits = 0;
	numberWithdrawals = 0;
	record.clear();
	isAccountActive();
}

std::string SavingAccount::setAccontNumber()
{
	char temp[5];
	std::string numberF;
	int generated = 0;

	for (int i = 0; i < 5; i++)
	{
		srand(9);
		generated = (int)rand % 9;
		temp[i] = generated;
	}

	std::string Mnumber = temp;
	numberF = "002-623490-" + Mnumber + "-550";
	return numberF;
}


std::string SavingAccount::tostring()
{
	std::ostringstream fmt;

	fmt << BankAccount::tostring()
		<< "Account NUmber :  " << AccountNumber << "\n"
		<< "Number of Withdrawals :  " << numberWithdrawals << "\n"
		<< "Number of Deposits : " << numberDeposits << "\n"
		<< "Balance :  " << std::setprecision(2) << std::fixed << "$" << Balance << "\n"
		<< "Account Active : " << std::boolalpha << accountActive << "\n"
		<< "Anual Intrest Rate :  " << std::setprecision(1) << std::fixed << INT_RATE << "\n";

	return fmt.str();;
}
