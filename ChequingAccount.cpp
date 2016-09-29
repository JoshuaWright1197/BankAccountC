#include"ChequingAccount.hpp"

ChequingAccount::ChequingAccount()
{
	AccountNumber = "";
	accountActive = false;
}

ChequingAccount::ChequingAccount(std::string name, std::string month, double balance) : BankAccount(name, "Chequing", month)
{
	Balance = balance;
	isAccountActive();
	INT_RATE = 0.025;
	SERVICE_FEE = 0.85;
	AccountNumber = setAccontNumber();
}

bool ChequingAccount::isAccountActive()
{
	if (Balance >= 25)
		accountActive = true;
	else
		accountActive = false;
	return accountActive;
}

int ChequingAccount::getnumberWithdrawals()
{
	return numberWithdrawals;
}

int ChequingAccount::getnumberDeposits()
{
	return numberDeposits;
}

double ChequingAccount::getBalance()
{
	return Balance;
}

double ChequingAccount::getINT_RATE()
{
	return INT_RATE;
}

double ChequingAccount::getSERVICE_FEE()
{
	return SERVICE_FEE;
}

void ChequingAccount::deposit(double depositamount, int day)
{
	isAccountActive();
	Balance += depositamount;
	numberDeposits++;
	recordtransaction("Desposit", day, depositamount, Balance);
}

void ChequingAccount::withdrawal(double withdrawalamount, int day)
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
	recordtransaction(transatcionmsg, day, withdrawalamount, Balance);
}

void ChequingAccount::recordtransaction(std::string transaction, int day, double amount, double balance)
{
	Transaction trans;
	trans.setransaction(transaction);
	trans.setAmount(amount);
	trans.setBalance(balance);
	trans.setDay(day);
	trans.setMonth(getMonth());
	record.push_back(trans);
}

void ChequingAccount::clacintrest()
{
	double MI = INT_RATE / 12;
	if (Balance > 1000)
	{
		Balance += MI;
	}
	recordtransaction("Intrest", 31, MI, Balance);
}

void ChequingAccount::printtrasaction()
{
	std::ostringstream fmt;
	std::string stars = "******************************************\n";
	std::cout << stars;
	std::cout << "Transaction Record for the Month of " + getMonth() << std::endl;
	std::cout << stars;

	for (int i = 0; i < (record.size()-2); i++)
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

void ChequingAccount::monthlyProcess()
{
	double amount = 0;
	if (numberWithdrawals > 4)
	{
		amount = numberWithdrawals*SERVICE_FEE;;
		Balance -= amount;
	}
	clacintrest();
	recordtransaction("Service fee", 31, amount, Balance);
	printtrasaction();
	numberDeposits = 0;
	numberWithdrawals = 0;
	record.clear();
	isAccountActive();
}

std::string ChequingAccount::setAccontNumber()
{
	char temp[5];
	std::string numberF;
	int generated = 0;

	for (int i = 0; i < 5; i++)
	{
		srand(4);
		generated = (int)rand % 9;
		temp[i] = generated;
	}

	std::string Mnumber = temp;
	numberF = "002-623490-" + Mnumber + "-550";
	return numberF;
}

std::string ChequingAccount::tostring()
{
	std::ostringstream fmt;

	fmt << BankAccount::tostring()
		<< "Account NUmber :  " << AccountNumber << "\n"
		<< "Number of Withdrawals :  "  << numberWithdrawals << "\n"
		<< "Number of Deposits : " << numberDeposits << "\n"
		<< "Balance :  " << std::setprecision(2) << std::fixed << "$" << Balance << "\n"
		<< "Account Active : " << std::boolalpha << accountActive << "\n"
		<< "Anual Intrest Rate :  " << std::setprecision(1) << std::fixed << INT_RATE << "\n"
		<< "Monthly Service fee :  " << "$" << SERVICE_FEE << " (applied to no. of withdrawals if withdrawals over 4)" << std::endl;

	return fmt.str();
}