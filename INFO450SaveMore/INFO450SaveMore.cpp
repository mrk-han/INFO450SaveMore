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
	int accountInputCin = 0; //User decides what type of account to control (Checking, Savings, CoD)
	int actionInputCin = 0; //User decides what they want to do with account (Deposit/Withdraw)
	int answerForChecks = 0;
	int term = NULL;

	// variables for account stats
	int userAccountNumber = NULL;
	double userBalance = NULL;
	double userDeposit = NULL;
	double userWithdraw = NULL;

	// Run Time Polymorphism achieved through class pointer.
	Account *checkingAccount = NULL;
	Account *savingsAccount = NULL;
	Account *codAccount = NULL;

	instructions();

	while ((accountInputCin != 4) && (accountInputCin != 4)) // 4 is the quit number
	{
		cout << "You can manage 3 accounts.\n Enter 1 for Checking \n Enter 2 for Savings \n Enter 3 for CoD\n Enter 4 to Exit\n";
		cin >> accountInputCin;

		// CASE ONE OF CHECKING ACCOUNT
		if (accountInputCin == 1)
		{
			cout << endl;
			cout << "Please enter the Account Number for your Checking Account." << endl;
			cout << "Account Number : ";
			cin >> userAccountNumber;
			do
			{
				cout << "This is a new account. Please enter a starting balance. $";
				cin >> userBalance;
				if (userBalance <= 1)
				{
					cout << "Please enter a number greater than 0" << endl;
				}
			} while (userBalance <= 1);

			checkingAccount = new Checking(userAccountNumber, userBalance);
			cout << "If your checking balance is below $500, a fee will occur." << endl;
			cout << endl;
			cout << "Would you like to order checks for this account? There is a $15 fee." << endl;
			cout << "Type 1 for Yes, Type 2 for No" << endl;
			cin >> answerForChecks;
			if (answerForChecks == 1)
			{
				checkingAccount->orderChecks();
			}

			do
			{
				cout << "Would you like to (1)Deposit, (2)Withdraw, or (3)Quit" << endl;
				cin >> actionInputCin;
				if (actionInputCin == 1)
				{
					cout << "How much would you like to deposit?" << endl;
					cin >> userDeposit;
					checkingAccount->depositFunds(userDeposit);
				}
				else if (actionInputCin == 2)
				{
					cout << "How much would you like to withdraw?" << endl;
					cin >> userWithdraw;
					checkingAccount->withdrawFunds(userWithdraw);
				}
			} while (actionInputCin != 3);
		}
		// SAVINGS ACCOUNT FLOW STARTS HERE
		else if (accountInputCin == 2)
		{
			cout << endl;
			cout << "Please enter the Account Number for your Savings Account." << endl;
			cin >> userAccountNumber;
			do
			{
				cout << "This is a new account. Please enter a starting balance. $";
				cin >> userBalance;
				if (userBalance <= 1)
				{
					cout << "Please enter a number greater than 0" << endl;
				}
			} while (userBalance <= 1);
			savingsAccount = new Savings(userAccountNumber, userBalance);
			cout << endl;
			do
			{
				cout << "Would you like to (1)Deposit, (2)Withdraw, or (3)Quit" << endl;
				cin >> actionInputCin;
				if (actionInputCin == 1)
				{
					cout << "How much would you like to deposit?" << endl;
					cin >> userDeposit;
					savingsAccount->depositFunds(userDeposit);
				}
				else if (actionInputCin == 2)
				{
					cout << "How much would you like to withdraw?" << endl;
					cout << "You will be charged $2 for this withdrawel" << endl;
					cin >> userWithdraw;
					savingsAccount->withdrawFunds(userWithdraw);
				}
			} while (actionInputCin != 3);
		}
		else if (accountInputCin == 3)
		{
			cout << endl;
			cout << "Please enter the Account Number for your CoD Account." << endl;
			cin >> userAccountNumber;
			do
			{
				cout << "This is a new account. Please enter a starting balance. $";
				cin >> userBalance;
				if (userBalance <= 1)
				{
					cout << "Please enter a number greater than 0" << endl;
				}
			} while (userBalance <= 1);
			cout << "What is the term in years for this CoD?" << endl;
			cout << "A term under 5 years gets 5 percent APR" << endl;
			cout << "A term 5 years or above gets 10 percent APR" << endl;
			cin >> term;
			codAccount = new CoD(userAccountNumber, userBalance, term);
			do
			{
				cout << "Would you like to (1)Deposit, (2)Withdraw, or (3)Quit" << endl;
				cin >> actionInputCin;
				if (actionInputCin == 1)
				{
					cout << "How much would you like to deposit?" << endl;
					cin >> userDeposit;
					codAccount->depositFunds(userDeposit);
				}
				else if (actionInputCin == 2)
				{
					cout << "How much would you like to withdraw?" << endl;
					cin >> userWithdraw;
					codAccount->withdrawFunds(userWithdraw);
				}
			} while (actionInputCin != 3);

		}
	}



	cout << "Checking:";
	checkingAccount->displayInformation();
	cout << endl;


	cout << "Savings:";
	savingsAccount->displayInformation();
	cout << endl;


	cout << "CoD:";
	codAccount->displayInformation();
	cout << endl;


	//deallocate memory
	delete checkingAccount;
	delete savingsAccount;
	delete codAccount;

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
