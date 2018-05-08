#include "stdafx.h"
#include "Savings.h"

Savings::Savings(int number, double balance) : Account(number, balance)
{
	// must calculate interest when created
	calculateInterest();
}

int Savings::depositFunds(double depositAmount)
{
	// Have to deposit ammount above 0, if it is above 0 then add to accountBalance.
	if (depositAmount > 0)
	{
		accountBalance += depositAmount;
		//CALCULATE INTEREST HERE AFTER DEPOSIT TO SEE IF RAISED A LEVEL
		calculateInterest();

		return 0;
	}
	// Cannot deposit negative numbers!
	else if (depositAmount <= 0)
	{
		return -1;
	}
}

int Savings::withdrawFunds(double withdrawAmount)
{
	//cannot withdraw funds from negative balance
	if ((accountBalance - withdrawAmount - WITHDRAWAL_FEE) < 0)
	{
		return -1;
	}
	else if ((accountBalance - (withdrawAmount + WITHDRAWAL_FEE)) >= 0)
	{
		accountBalance -= (withdrawAmount + WITHDRAWAL_FEE);
		calculateInterest();
		return 0;
	}
}

void Savings::calculateInterest()
{
	if (accountBalance <= 10000)
	{
		interestRate = ONE_PERCENT_APR;
	}
	else if (accountBalance >= 10000)
	{
		interestRate = TWO_PERCENT_APR;
	}
	//https://www.thecalculatorsite.com/articles/finance/compound-interest-formula.php
	accountBalance += ((accountBalance)*(interestRate / 12));
}

