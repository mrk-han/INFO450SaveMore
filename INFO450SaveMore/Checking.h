#pragma once
# include "Account.h"

class Checking : public Account
{
private:
	const double LOW_BALANCE_FEE = 5.00;
	const double PURCHASE_CHECK_PRICE = 15.00;

public:
	Checking(int number, double balance); //Constructor
	int withdrawFunds(double withdrawAmount); // Needs to be overridden. 
	int orderChecks(); 	// for checking account
};
