// Fractions Math Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function prototypes
int displayMenu();
void getFractions(int& numer1, int& denom1, int& numer2, int& denom2);
void addFracs(int numer1, int denom1, int numer2, int denom2);
void subtFracs(int numer1, int denom1, int numer2, int denom2);
void multFracs(int numer1, int denom1, int numer2, int denom2);
void diviFracs(int numer1, int denom1, int numer2, int denom2);
void reduFrac(int& numer, int& denom);

int main()
{

	// declare enumeration
	enum mathOperation { ADD = 1, SUBTRACT, MULTIPLY, DIVIDE };

	// declare variables
	int menuChoice = 0;
	int numer1 = 0;
	int denom1 = 0;
	int numer2 = 0;
	int denom2 = 0;

	// display menu
	menuChoice = displayMenu();

	// process menu choice
	while (menuChoice != 5) {

		getFractions(numer1, denom1, numer2, denom2);

		switch (menuChoice)
		{

		case ADD:
			addFracs(numer1, denom1, numer2, denom2);
			break;
		case SUBTRACT:
			subtFracs(numer1, denom1, numer2, denom2);
			break;
		case MULTIPLY:
			multFracs(numer1, denom1, numer2, denom2);
			break;
		case DIVIDE:
			diviFracs(numer1, denom1, numer2, denom2);
			break;

		}

		// display menu in loop
		menuChoice = displayMenu();

	}

}

// function definitions 
int displayMenu()
{

	// declare local variable
	int menuChoice;

	cout << "\nWelcome to the Fractions Math Program.\n";
	cout << "Please choose from the menu below:\n\n";
	cout << "1. Addition\n";
	cout << "2. Subtraction\n";
	cout << "3. Multiplication\n";
	cout << "4. Division\n";
	cout << "5. Exit\n";
	cout << "\nMenu Choice: ";

	// get menu choice
	cin >> menuChoice;

	cout << endl;

	return menuChoice;

}

void getFractions(int& numer1, int& denom1, int& numer2, int& denom2)
{

	// declare local variables
	string frac1 = "";
	string frac2 = "";

	cout << "Please enter the first fraction in fraction format (numerator/denominator): ";

	// get fraction
	cin >> frac1;

	// convert input to integers and store results
	numer1 = stoi(frac1.substr(0));
	denom1 = stoi(frac1.substr(2));

	// test input for 0 denominator
	while (denom1 == 0)
	{

		cout << "\nFraction cannot have a denominator of 0, please try again: ";

		cin >> frac1;

		numer1 = stoi(frac1.substr(0));
		denom1 = stoi(frac1.substr(2));

	}

	cout << "\nPlease enter the second fraction in fraction format (numerator/denominator): ";

	// get fraction
	cin >> frac2;

	// convert input to integers and store results
	numer2 = stoi(frac2.substr(0));
	denom2 = stoi(frac2.substr(2));

	// test input for 0 denominator
	while (denom2 == 0)
	{

		cout << "\nFraction cannot have a denominator of 0, please try again: ";

		cin >> frac2;

		numer2 = stoi(frac2.substr(0));
		denom2 = stoi(frac2.substr(2));

	}

}

void addFracs(int numer1, int denom1, int numer2, int denom2)
{

	// declare local variables
	int resultNumer = 0;
	int resultDenom = 0;

	// calculate sum
	resultNumer = numer1 * denom2 + numer2 * denom1;
	resultDenom = denom1 * denom2;

	// reduce result
	reduFrac(resultNumer, resultDenom);

	cout << "The sum of " << numer1 << "/" << denom1 << " + " << numer2 << "/" << denom2 << " = " << resultNumer << "/" << resultDenom << endl;

}

void subtFracs(int numer1, int denom1, int numer2, int denom2)
{

	// declare local variables
	int resultNumer = 0;
	int resultDenom = 0;

	// calculate difference
	resultNumer = (numer1 * denom2) - (numer2 * denom1);
	resultDenom = denom1 * denom2;

	// reduce result
	reduFrac(resultNumer, resultDenom);

	cout << "The difference of " << numer1 << "/" << denom1 << " - " << numer2 << "/" << denom2 << " = " << resultNumer << "/" << resultDenom << endl;

}

void multFracs(int numer1, int denom1, int numer2, int denom2)
{

	// declare local variables
	int resultNumer = 0;
	int resultDenom = 0;

	// calculate product
	resultNumer = numer1 * numer2;
	resultDenom = denom1 * denom2;

	// reduce result
	reduFrac(resultNumer, resultDenom);

	cout << "The product of " << numer1 << "/" << denom1 << " x " << numer2 << "/" << denom2 << " = " << resultNumer << "/" << resultDenom << endl;

}

void diviFracs(int numer1, int denom1, int numer2, int denom2)
{

	// declare local variables
	int resultNumer = 0;
	int resultDenom = 0;

	// calculate quotient
	resultNumer = numer1 * denom2;
	resultDenom = denom1 * numer2;

	// reduce result
	reduFrac(resultNumer, resultDenom);

	cout << "The quotient of " << numer1 << "/" << denom1 << " % " << numer2 << "/" << denom2 << " = " << resultNumer << "/" << resultDenom << endl;

}

void reduFrac(int& numer, int& denom)
{

	// reduce fraction
	for (int i = denom * numer; i > 1; i--)
	{

		if ((denom % i == 0) && (numer % i == 0))
		{

			denom /= i;
			numer /= i;

		}

	}

}