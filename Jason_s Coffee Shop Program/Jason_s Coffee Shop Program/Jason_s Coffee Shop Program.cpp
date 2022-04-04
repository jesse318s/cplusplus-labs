// Jason's Coffee Shop Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
int displayMenu();
void sellCoffee(const int smOz, const int mdOz, const int lgOz, const double smPrice, const double mdPrice, const double lgPrice, const double taxRate, int& totSmCups, int& totMdCups, int& totLgCups, int& totOzSold, double& totSales);
void displayTotCupsSold(int totSmCups, int totMdCups, int totLgCups);
void displayTotOzSold(int totOzSold);
void displayTotSales(double totSales);
void displayHelp();

int main()
{

	// declare constants
	const int smOz = 9;
	const int mdOz = 12;
	const int lgOz = 15;
	const double smPrice = 1.75;
	const double mdPrice = 1.90;
	const double lgPrice = 2.00;
	const double taxRate = 0.08;

	// declare variables
	int menuChoice = 0,
		totSmCups = 0,
		totMdCups = 0,
		totLgCups = 0,
		totOzSold = 0;
	double totSales = 0;

	// display menu and record choice
	menuChoice = displayMenu();

	// check menu choice for exit value
	while (menuChoice != 6) {

		// process menu choice
		switch (menuChoice) {

		case 1:
			sellCoffee(smOz, mdOz, lgOz, smPrice, mdPrice, lgPrice, taxRate, totSmCups, totMdCups, totLgCups, totOzSold, totSales);
			break;
		case 2:
			displayTotCupsSold(totSmCups, totMdCups, totLgCups);
			break;
		case 3:
			displayTotOzSold(totOzSold);
			break;
		case 4:
			displayTotSales(totSales);
			break;
		case 5:
			displayHelp();
			break;

		}

		system("pause");
		cout << "\n\n";

		// display menu and record choice after processing previous choice
		menuChoice = displayMenu();

	}

}

// function definitions
int displayMenu()
{

	// declare local variable
	int menuChoice = 0;

	// display maim menu
	cout << "Welcome to Jason's Coffee Shop.\n";
	cout << "Please choose from the menu below:\n\n";
	cout << "1. Make a Sale\n";
	cout << "2. Total Cups Sold\n";
	cout << "3. Total Ounces Sold\n";
	cout << "4. Total Amount of Sales\n";
	cout << "5. Help\n";
	cout << "6. Exit Program\n\n";
	cout << "Menu Choice: ";

	// record choice
	cin >> menuChoice;

	cout << endl;

	return menuChoice;

}

void sellCoffee(const int smOz, const int mdOz, const int lgOz, const double smPrice, const double mdPrice, const double lgPrice, const double taxRate, int& totSmCups, int& totMdCups, int& totLgCups, int& totOzSold, double& totSales)
{

	// declare local variables
	int menuChoice = 0,
		cupNum = 0,
		totCurSmCups = 0,
		totCurMdCups = 0,
		totCurLgCups = 0;
	double totCurSale = 0;

	// check for complete sale
	while (menuChoice != 4) {

		// display sales menu and record sales menu choice
		cout << right << setw(24) << "Coffe Sale Menu\n\n";
		cout << left << "1. Small Cup - 9oz.\n";
		cout << "2. Medium Cup - 12oz.\n";
		cout << "3. Large Cup - 16oz.\n";
		cout << "4. Complete Sale\n\n";
		cout << "Make a Selection: ";

		cin >> menuChoice;

		cout << endl;

		// process sales menu choice and make calculations
		switch (menuChoice) {

		case 1:
			cout << "How many small cups of coffee: ";

			cin >> cupNum;

			cout << endl;

			totCurSmCups += cupNum;
			totCurSale += cupNum * smPrice;
			totSmCups += cupNum;
			totOzSold += cupNum * smOz;
			totSales += cupNum * smPrice;
			break;
		case 2:
			cout << "How many medium cups of coffee: ";

			cin >> cupNum;

			cout << endl;

			totCurMdCups += cupNum;
			totCurSale += cupNum * mdPrice;
			totMdCups += cupNum;
			totOzSold += cupNum * mdOz;
			totSales += cupNum * mdPrice;
			break;
		case 3:
			cout << "How many large cups of coffee: ";

			cin >> cupNum;

			cout << endl;

			totCurLgCups += cupNum;
			totCurSale += cupNum * lgPrice;
			totLgCups += cupNum;
			totOzSold += cupNum * lgOz;
			totSales += cupNum * lgPrice;
			break;
		case 4:
			cout << fixed << showpoint << setprecision(2);
			cout << "Total Sale\n\n";
			cout << setw(4) << totCurSmCups << "small cups  = $" << right << setw(7) << totCurSmCups * smPrice << endl;
			cout << left << setw(4) << totCurMdCups << "medium cups = $" << right << setw(7) << totCurMdCups * mdPrice << endl;
			cout << left << setw(4) << totCurLgCups << "large cups  = $" << right << setw(7) << totCurLgCups * lgPrice << endl;
			cout << "---------------------------\n";
			cout << "Total Sales:      $" << setw(7) << totCurSale << endl;
			cout << "Tax:              $" << setw(7) << totCurSale * taxRate << endl;
			cout << "Total Due:        $" << setw(7) << totCurSale + totCurSale * taxRate << endl;
			cout << left << scientific << noshowpoint << setprecision(0);
			break;

		}

	}

}

void displayTotCupsSold(int totSmCups, int totMdCups, int totLgCups)
{

	cout << left << setw(30) << "Total number of small cups sold today:  " << right << setw(4) << totSmCups << endl;
	cout << left << setw(30) << "Total number of medium cups sold today: " << right << setw(4) << totMdCups << endl;
	cout << left << setw(30) << "Total number of large cups sold today:  " << right << setw(4) << totLgCups << endl;
	cout << left;

}

void displayTotOzSold(int totOzSold)
{

	cout << left << setw(20) << "Total ounces sold today: " << right << setw(7) << totOzSold << endl;
	cout << left;

}

void displayTotSales(double totSales)
{

	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(20) << "Total Amount earned today: $" << right << setw(7) << totSales << endl;
	cout << left << scientific << noshowpoint << setprecision(0);

}

void displayHelp()
{

	cout << "Instructions for Jason's Coffee Shop:\n";
	cout << "When prompted, make sure to enter a number that is on the list below.\n\n";
	cout << "1. Make a Sale (Displays a list of cup size options. For each cup size purchased, input the number that matches the size, and then the amount of cups purchased. Enter 4 to complete the sale and find its total)\n";
	cout << "2. Total Cups Sold (Displays total cups sold by size)\n";
	cout << "3. Total Ounces Sold (Displays total ounces sold)\n";
	cout << "4. Total Amount of Sales (Displays total sales)\n";
	cout << "5. Help (You selected this option, which displays these instructions)\n";
	cout << "6. Exit Program (Will terminate the program when selected)\n";

}