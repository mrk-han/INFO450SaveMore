#include "stdafx.h"
#include "Account.h"

Account::Account(int number, double balance)
{
	accountNumber = number;
	accountBalance = balance;
}

int Account::depositFunds(double depositAmount)
{
	// Have to deposit ammount above 0, if it is above 0 then add to accountBalance.
	if (depositAmount > 0)
	{
		accountBalance += depositAmount;
		return 0;
	}
	// Cannot deposit negative numbers!
	else if (depositAmount <= 0)
	{
		return -1;
	}
}

int Account::withdrawFunds(double withdrawAmount)
{
	//cannot withdraw funds from negative balance
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) >= 0)
	{
		accountBalance -= withdrawAmount;
		return 0;
	}
}

int Account::orderChecks()
{
}

void Account::calculateInterest()
{

}

void Account::displayInformation()
{
	cout << endl;
	cout << "(Account Number) " << accountNumber << endl;
	cout << "(Account Balance) " << accountBalance << endl;
	cout << "(Interest Rate) " << interestRate << endl;
}