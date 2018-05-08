#pragma once
#include "Account.h"

class CoD : public Account
{
private:
	const double FIVE_YEAR_RATE = 0.10;
	const double LESS_THAN_FIVE_YEAR_RATE = 0.05;
	int term; // CANNOT BE CHANGED AFTER CREATION (per requirements)

public:
	CoD(int number, double balance, int term);
	void calculateInterest();
};