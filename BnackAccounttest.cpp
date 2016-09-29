#include<iostream>
#include"ChequingAccount.hpp"
#include"SavingAccount.hpp"

using std::cout;
using std::endl;

int main()
{
	ChequingAccount account1("Bethany Anderson", "March", 2345);

	cout << account1.tostring();

	account1.deposit(25.98, 5);
	account1.withdrawal(1300, 6);
	account1.withdrawal(1700, 10);
	account1.deposit(1050, 11);
	account1.withdrawal(1700, 11);
	account1.deposit(25.98, 25);
	account1.withdrawal(400, 26);
	account1.withdrawal(27.0, 28);
	account1.withdrawal(7.50, 28);
	account1.monthlyProcess();

	cout << account1.tostring();

	cout << "\n" <<  endl;

	SavingAccount account2("Bethany Anderson", "March", 6100);

	cout << account2.tostring();

	account2.deposit(500, 3);
	account2.withdrawal(1000, 6);
	account2.deposit(250, 15);
	account2.withdrawal(3000, 21);
	account2.withdrawal(825, 28);
	account2.deposit(250, 29);
	account2.monthlyProcess();

	cout << account2.tostring();



}