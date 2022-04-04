// Loan Amortization Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	// Variables
	int mcount = 0;

	double
		loanAmt = 0,
		intRate = 0,
		minPay = 0,
		monthPay = 0,
		intPay = 0,
		princPay = 0,
		totIntPay = 0;


	cout << "Please enter the amount of the loan: ";

	// Tests user input for the loan amount
	while (!(cin >> loanAmt))
	{

		cin.clear();
		cin.ignore(100, '\n');
		cout << "Must be a number, try again.\n";

	}

	cout << "Please enter the interest rate: ";

	// Tests user input for the interest rate
	while (!(cin >> intRate))
	{

		cin.clear();
		cin.ignore(100, '\n');
		cout << "Must be a number, try again.\n";

	}

	// Calculates and outputs minimum payment amount
	intRate /= 100;
	minPay = loanAmt * (intRate/12) + 1;
	cout << fixed << showpoint << setprecision(2);
	cout.imbue(locale("American"));
	cout << showbase;
	cout << "In order to pay off this loan you must pay at least " << put_money(minPay * 100) << " per month.\n";


	cout << "Please enter the monthly payment amount: ";

	// Tests user input for the monthly pay
	while (!(cin >> monthPay) || monthPay <= minPay)
	{

		cin.clear();
		cin.ignore(100, '\n');
		cout << "Must be a number and must be greater than the minimum payment, try again.\n";

	}

	cout << left << setw(20) << "Payment Number" << setw(20) << "Interest Paid" << setw(20) << "Principal Paid" << setw(20) << "Current Balance" << endl;

	// Calculates and outputs payments and interest
	while (loanAmt > 0)
	{

		mcount++;
		intPay = (intRate * loanAmt) / 12;
		princPay = monthPay - intPay;

		if (loanAmt > (intPay + princPay))
		{

			loanAmt -= princPay;

		}
		else
		{

			princPay = loanAmt;
			loanAmt -= princPay;

		}

		totIntPay += intPay;

		cout << right << setw(8) << mcount;
		cout << setw(21) << put_money(intPay * 100);
		cout << setw(21) << put_money(princPay * 100);
		cout << setw(21) << put_money(loanAmt * 100) << endl;

	}

	cout << "The last payment was " << put_money((princPay + intPay) * 100) << endl;
	cout << "Total Interest Paid: " << put_money(totIntPay * 100);

}