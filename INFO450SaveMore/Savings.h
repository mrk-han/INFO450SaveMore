#pragma once
# include "Account.h"

class Savings : public Account
{
private:
	const double WITHDRAWAL_FEE = 2.00;
	const double ONE_PERCENT_APR = 0.01;
	const double TWO_PERCENT_APR = 0.02;


public:
	Savings(int number, double balance);
	int depositFunds(double depositAmount);
	int withdrawFunds(double withdrawAmount);
	void calculateInterest();


};