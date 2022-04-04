// Airplane Seating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// function prototypes
void displayMenu(int&);
void displayClassMenu(int&);
void displaySeats(bool[13][6]);
void inputSeat(bool[13][6], int&, string&, int&, int&, int&);
void testClass(bool[13][6], int&, string&, int&, int&, int&, int&, int&, double&,
	double&);
void printReceipt(int&, int&, int&);

int main()
{

	// declare variables
	int menuChoice = 0;
	int classChoice = 0;
	int firstClassTickets = 0;
	int businessClassTickets = 0;
	int economyClassTickets = 0;

	string seatChoice = "";

	// declare array
	bool seats[13][6] = { 0 };

	// display menus and process menu choices
	displayMenu(menuChoice);

	while (menuChoice != 2)
	{

		while (menuChoice == 1)
		{

			displayClassMenu(classChoice);

			if (classChoice != 4)
			{

				displaySeats(seats);
				inputSeat(seats, classChoice, seatChoice, firstClassTickets, businessClassTickets, economyClassTickets);

			}

			if (classChoice == 4)
			{

				// prints receipt on checkout
				printReceipt(firstClassTickets, businessClassTickets, economyClassTickets);
				displayMenu(menuChoice);

			}

		}

	}

}

// declare functions
void displayMenu(int& menuChoice)
{

	// retrieve menu choice
	cout << "\nAimless Airways\n1. Purchase Tickets\n2. Exit Program\n";

	cin >> menuChoice;

}

void displayClassMenu(int& classChoice)
{

	// retrieve class choice
	cout << "\nPurchase Tickets\n1. First Class\n2. Business Class\n3. Economy Class\n4. Checkout\n";

	cin >> classChoice;

}

void displaySeats(bool seats[13][6])
{

	// display seats
	cout << left << "\n         A    B    C    D    E    F\n";

	for (int i = 0; i < 13; i++)
	{

		cout << "Row " << setw(5) << i + 1;

		for (int j = 0; j < 6; j++)
		{

			if (seats[i][j] == 1)
			{

				cout << setw(5) << "X";

			}
			else
			{

				cout << setw(5) << "*";

			}

		}

		cout << endl;

	}

	cout << right;

}

void inputSeat(bool seats[13][6], int& classChoice, string& seatChoice, int& firstClassTickets, int& businessClassTickets, int& economyClassTickets)
{

	// declare local variables
	int row = 0;
	int column = 0;

	double priceOld = 0;
	double priceNew = 0;

	char columnChar = 0;

	// retrieve input
	cout << "\nPlease enter your desired seat in the form of \"1A\": ";

	cin >> seatChoice;

	// convert input
	if (seatChoice.length() == 2)
	{

		row = stoi(seatChoice.substr(0, 1)) - 1;

	}
	else if (seatChoice.length() == 3)
	{

		row = stoi(seatChoice.substr(0, 2)) - 1;

	}

	columnChar = toupper(seatChoice.back());

	switch (columnChar)
	{

	case 'A':
		column = 0;
		break;
	case 'B':
		column = 1;
		break;
	case 'C':
		column = 2;
		break;
	case 'D':
		column = 3;
		break;
	case 'E':
		column = 4;
		break;
	case 'F':
		column = 5;
		break;

	}

	// check seat availability
	while (seats[row][column])
	{

		// retrieve new input
		cout << "\nSeat is already taken. Please choose another.";

		displaySeats(seats);

		cout << "\nPlease enter your desired seat in the form of \"1A\": ";

		cin >> seatChoice;

		// convert input
		if (seatChoice.length() == 2)
		{

			row = stoi(seatChoice.substr(0, 1)) - 1;

		}
		else if (seatChoice.length() == 3)
		{

			row = stoi(seatChoice.substr(0, 2)) - 1;

		}

		columnChar = toupper(seatChoice.back());

		switch (columnChar)
		{

		case 'A':
			column = 0;
			break;
		case 'B':
			column = 1;
			break;
		case 'C':
			column = 2;
			break;
		case 'D':
			column = 3;
			break;
		case 'E':
			column = 4;
			break;
		case 'F':
			column = 5;
			break;

		}

	}

	// set old ticket price
	switch (classChoice)
	{

	case 1:
		priceOld = 250;
		break;
	case 2:
		priceOld = 175;
		break;
	case 3:
		priceOld = 95;
		break;

	}

	// set new ticket price
	if (row == 0 || row == 1)
	{

		priceNew = 250;

	}

	if (row > 1 && row < 8)
	{

		priceNew = 175;

	}

	if (row >= 8 && row < 13)
	{

		priceNew = 95;

	}

	// test ticket class
	testClass(seats, classChoice, seatChoice, firstClassTickets, businessClassTickets, economyClassTickets, row, column, priceOld, priceNew);

}

void testClass(bool seats[13][6], int& classChoice, string& seatChoice, int& firstClassTickets, int& businessClassTickets, int& economyClassTickets, int& row, int& column, double& priceOld,
	double& priceNew)
{

	// declare local variable
	char reassignChoice = 0;

	// test ticket rows and class
	if ((row == 0 || row == 1) && classChoice == 1)
	{

		seats[row][column] = 1;
		firstClassTickets += 1;

	}
	else if ((row > 1 && row < 8) && classChoice == 2)
	{

		seats[row][column] = 1;
		businessClassTickets += 1;

	}
	else if ((row >= 8 && row < 13) && classChoice == 3)
	{

		seats[row][column] = 1;
		economyClassTickets += 1;

	}
	// handle different ticket class
	else if (row >= 0 && row < 13)
	{

		cout << "\nTicket is in a different class. The difference in price is $" << fixed << showpoint << setprecision(2) << priceNew - priceOld
			<< "\nDo you wish to change the class of your ticket? (Enter \"Y/y\" or \"N/n\"): \n" << scientific << noshowpoint;

		cin >> reassignChoice;

		// change class
		if (reassignChoice == 'y' || reassignChoice == 'Y')
		{

			if (row == 0 || row == 1)
			{

				classChoice = 1;
				firstClassTickets += 1;

			}

			if (row > 1 && row < 8)
			{

				classChoice = 2;
				businessClassTickets += 1;

			}

			if (row >= 8 && row < 13)
			{

				classChoice = 3;
				economyClassTickets += 1;

			}

			seats[row][column] = 1;

		}

		// use same class
		if (reassignChoice == 'n' || reassignChoice == 'N')
		{

			displaySeats(seats);
			inputSeat(seats, classChoice, seatChoice, firstClassTickets, businessClassTickets, economyClassTickets);

		}

	}

}

void printReceipt(int& firstClassTickets, int& businessClassTickets, int& economyClassTickets)
{

	// display receipt
	cout << "\nFirst class tickets: " << firstClassTickets << " - $" << fixed << showpoint << setprecision(2) << firstClassTickets * 250.0
		<< "\nBusiness class tickets: " << businessClassTickets << " - $" << businessClassTickets * 175.0
		<< "\nEconomy class tickets: " << economyClassTickets << " - $" << economyClassTickets * 95.0
		<< "\nTotal ticket cost: $" << (firstClassTickets * 250.0) + (businessClassTickets * 175.0) + (economyClassTickets * 95.0) << "\nTax: 7.5%"
		<< "\nGrand total (With tax): $" << 1.075 * ((firstClassTickets * 250.0) + (businessClassTickets * 175.0) + (economyClassTickets * 95.0)) << endl << scientific << noshowpoint;

	// reset receipt variables
	firstClassTickets = 0;
	businessClassTickets = 0;
	economyClassTickets = 0;

}
