#include "stdafx.h"
#include "Checking.h"

Checking::Checking(int number, double balance) : Account(number, balance)
{
	interestRate = 0;
}

int Checking::withdrawFunds(double withdrawAmount)
{
	//cannot withdraw funds from negative balance
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) >= 0)
	{
		accountBalance -= withdrawAmount;
		
		// If the account balance is less than 500 after withdrawal, we subtract the low balance fee of 15 dollars per the requirements
		if (accountBalance < 500)
		{
			accountBalance -= LOW_BALANCE_FEE;
			
			// Balance can never be negative per the requirements. 
			// If the user withdraws anything over 485 dollars when they have 500 dollars, then they can go in negative.
			// This prevents going negative.
			if (accountBalance < 0)
			{
				accountBalance = 0;
			}
		}

		return 0;
	}
}

int Checking::orderChecks()
{
	if (accountBalance > PURCHASE_CHECK_PRICE)
	{
		accountBalance -= PURCHASE_CHECK_PRICE;

		//Checks to see if low balance fee needed when applying checks
		if (accountBalance < 500)
		{
			accountBalance -= LOW_BALANCE_FEE;
		}
		return 0;
	}
	else if (accountBalance < PURCHASE_CHECK_PRICE)
	{
		return -1;
	}
}