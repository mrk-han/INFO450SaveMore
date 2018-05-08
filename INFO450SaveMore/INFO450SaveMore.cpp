// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "CoD.h"

void instructions();


int main()
{
	// variables for user input
	char accountInputCin = NULL; //User decides what type of account to control (Checking, Savings, CoD)
	char actionInputCin = NULL; //User decides what they want to do with account (Deposit/Withdraw)
	char answer; //User wants to continue or not (Y or y)
	char answerForBuyingCheck;

	// variables for account stats
	int userAccountNumber = NULL;
	double userBalance = NULL;
	double userDeposit = NULL;
	double userWithdraw = NULL;

	// Run Time Polymorphism achieved through class pointer.
	Account *Checking = NULL;
	Account *Savings = NULL;
	Account *CoD = NULL;

	instructions();

	do {} while ((answer == 'y') || (answer == 'Y'));



    return 0;
}

void instructions()
{
	cout << "**" << " ********************* " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "        Hello!         " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "  Welcome to VCU Bank  " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << " - Maintain 3 accounts " << "**" << endl;
	cout << "**" << " - Withdraw Money      " << "**" << endl;
	cout << "**" << " - Deposit Money       " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << "   1 for Checking      " << "**" << endl;
	cout << "**" << "   2 for Saving        " << "**" << endl;
	cout << "**" << "   3 for CoD           " << "**" << endl;
	cout << "**" << "                       " << "**" << endl;
	cout << "**" << " ********************* " << "**" << endl;
	cout << endl;
	cout << endl;
}
