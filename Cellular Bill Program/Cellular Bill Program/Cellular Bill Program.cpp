#include <iostream>
#include <iomanip>
#include <string>



using namespace std;

int main()
{

	//declared variables
	int accountNumber = 0;
	int minutes = 0;
	int dayMinutes = 0;
	int nightMinutes = 0;
	double bill = 0;
	double dayBill = 0;
	double nightBill = 0;
	char serviceCode = 0;
	bool notValidMinutes = true;
	bool notValidDayMinutes = true;
	bool notValidNightMinutes = true;
	bool notValidCode = true;

	//the following code will get the user input for accountNumber
	cout << "Please enter an account number: ";
	cin >> accountNumber;
	cin.clear();           //this line takes the input stream out of fail state if they entered anything other than a number.
	cin.ignore(100, '\n');  //this empties the input stream and gets it ready for the new input.

	//the following code will test the user input to make sure they entered R/r or P/p
	while (notValidCode)
	{

		cout << "Please enter a service code: (R or P) ";
		cin >> serviceCode;
		cin.clear();           //this line takes the input stream out of fail state if they entered anything other than a char.
		cin.ignore(100, '\n');  //this empties the input stream and gets it ready for the new input.

		if (serviceCode == 'R' || serviceCode == 'r' || serviceCode == 'P' || serviceCode == 'p')      //if the user enters in anything other than R or P it will be stored as a 0
		{
			notValidCode = false; //if they enter a R or P, this will cause the while loop to stop and go to the next line of code.
		}
		else
		{
			cout << "Service code must be an 'R' or a 'P'.\n";
			cout << "Please try again.";
		}

	}

	//the following code will test the user input to see they entered R or r
	if (serviceCode == 'R' || serviceCode == 'r')
	{
		//the following code will test the user input to make sure they entered numbers, not characters
		while (notValidMinutes)
		{

			cout << "Please enter minutes: ";
			cin >> minutes;
			cin.clear();           //this line takes the input stream out of fail state if they entered anything other than a number.
			cin.ignore(100, '\n');  //this empties the input stream and gets it ready for the new input.

			if (minutes > 0)      //if the user enters in anything other than a number it will be stored as a 0
			{
				notValidMinutes = false; //if they enter an integer, this will cause the while loop to stop and go to the next line of code.
			}
			else
			{
				cout << "Minutes must be an integer greater than 0.\n";
				cout << "Please try again.";
			}

		}

		//perform calculations
		bill = 10;

		if (minutes > 50)
		{
			bill += ((minutes - 50) * .2);
		}

		//output results
		cout << "Account number: " << accountNumber;
		cout << "\nType of service: " << serviceCode;
		cout << "\nMinutes used: " << minutes;
		cout << showpoint << fixed << setprecision(2) << "\nAmount due: $" << bill;

	}

	//the following code will test the user input to see they entered P or p
	if (serviceCode == 'P' || serviceCode == 'p')
	{
		//the following code will test the user input to make sure they entered numbers, not characters
		while (notValidDayMinutes)
		{

			cout << "Please enter minutes used between 6:00 a.m. and 6:00 p.m.: ";
			cin >> dayMinutes;
			cin.clear();           //this line takes the input stream out of fail state if they entered anything other than a number.
			cin.ignore(100, '\n');  //this empties the input stream and gets it ready for the new input.

			if (dayMinutes > 0)      //if the user enters in anything other than a number it will be stored as a 0
			{
				notValidDayMinutes = false; //if they enter an integer, this will cause the while loop to stop and go to the next line of code.
			}
			else
			{
				cout << "Minutes must be an integer greater than 0.\n";
				cout << "Please try again.";
			}

		}

		//the following code will test the user input to make sure they entered numbers, not characters
		while (notValidNightMinutes)
		{

			cout << "Please enter minutes used between 6:00 p.m. and 6:00 a.m.: ";
			cin >> nightMinutes;
			cin.clear();           //this line takes the input stream out of fail state if they entered anything other than a number.
			cin.ignore(100, '\n');  //this empties the input stream and gets it ready for the new input.

			if (nightMinutes > 0)      //if the user enters in anything other than a number it will be stored as a 0
			{
				notValidNightMinutes = false; //if they enter an integer, this will cause the while loop to stop and go to the next line of code.
			}
			else
			{
				cout << "Minutes must be an integer greater than 0.\n";
				cout << "Please try again.";
			}

		}

		//perform calculations
		bill = 25;

		if (dayMinutes > 75)
		{
			dayBill += ((dayMinutes - 75) * .1);
		}

		if (nightMinutes > 100)
		{
			nightBill += ((nightMinutes - 100) * .05);
		}

		//output results
		cout << "Account number: " << accountNumber;
		cout << "\nType of service: " << serviceCode;
		cout << "\nMinutes used between 6:00 a.m and 6:00 p.m.: " << dayMinutes;
		cout << showpoint << fixed << setprecision(2) << "\nAmount due for minutes used between 6:00 a.m and 6:00 p.m.: $" << dayBill;
		cout << noshowpoint <<"\nMinutes used between 6:00 p.m. and 6:00 a.m.: " << nightMinutes;
		cout << showpoint << "\nAmount due for minutes used between 6:00 p.m. and 6:00 a.m.: $" << nightBill;
		cout << "\nTotal amount due: $" << bill + dayBill + nightBill;

	}

}
