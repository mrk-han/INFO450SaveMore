#include "stdafx.h"
#include "CoD.h"

CoD::CoD(int number, double balance, int term) : Account(number, balance)
{
	if (term < 5)
	{
		// Less than 5 year rate for anything other than 5 year term (per requirements)
		interestRate = LESS_THAN_FIVE_YEAR_RATE;
	}
	else if (term >= 5)
	{
		// if term is 5 or greater, then give 5 year rate (per requirements)
		interestRate = FIVE_YEAR_RATE;
	}
	calculateInterest();
}

void CoD::calculateInterest()
{
	accountBalance += ((accountBalance)*(interestRate / 12));
}