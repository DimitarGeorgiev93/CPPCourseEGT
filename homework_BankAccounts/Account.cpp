#include "Account.h"

Account::Account(double balance)
{
	if (balance >= 0)
	{
		this->balance = balance;
	}
	else {
		this->balance = 0;
		cerr << "Invalid initial balance" << endl; // cerr: if there is an error, it highlights it
	}
}

void Account::credit(double amount)
{
	if (amount > 0)
	{
		this->balance = this->balance + amount; //to add an amount to the balance
	}
	else
	{
		cerr << "Invalid initial balance" << endl;
	}
}

void Account::debit(double amount)
{
	if (amount <= this->balance)
	{
		this->balance = this->balance - amount;
	}
	else
	{
		cerr << "Debit amount exceeded amount balance" << endl;
	}
}

double Account::getBalance()
{
	cout << "The balance on the account is BGN ";
	return this->balance;
}
