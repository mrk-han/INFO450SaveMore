#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Account
{
protected:
	int accountNumber;
	double interestRate;
	double accountBalance;
	char accountOpenDate;

public:
	
	Account(int number, double balance);

	//Virtual functions --- to be overriden by the derived classes
	virtual int depositFunds(double depositAmount);
	virtual int withdrawFunds(double withdrawAmount);

	virtual int orderChecks(); 	// for checking account
	virtual void calculateInterest(); 	//for anything with interest

	void displayInformation();
};