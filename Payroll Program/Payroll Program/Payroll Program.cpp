#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    // Declare variables
    int hoursWorked = 0;
    int regularHours = 0;
    int overtimeHours = 0;

    double payRate = 0;
    double overtimePayRate = 0;
    double regularPay = 0;
    double overtimePay = 0;
    double grossPay = 0;
    double pensionPay = 0;
    double insurancePay = 0;
    double taxPay = 0;
    double netPay = 0;

    char pensionPlan = 0;
    char insurancePlan = 0;

    string employeeName = "";

    ofstream outFile ("payroll.txt");

    // Get input
    cout << "Enter Employee Name: ";
    getline(cin, employeeName);
    cout << endl;

    cout << "Enter total number of hours worked: ";
    cin >> hoursWorked;
    cout << endl;

    cout << "Enter hourly pay wage:$ ";
    cin >> payRate;
    cout << endl;

    cout << "Is the employee on a pension plan: ";
    cin >> pensionPlan;
    cout << endl;

    cout << "Does the employee have insurance: ";
    cin >> insurancePlan;
    cout << endl;

    // Perform calculations
    overtimePayRate = payRate * 1.5;
 
    if (hoursWorked > 40)
    {

        overtimeHours = hoursWorked - 40;
        regularHours = 40;

    }
    else
    {

        regularHours = hoursWorked;

    }


    if (insurancePlan == 'y' || insurancePlan == 'Y')
    {

        insurancePay += 75;

    }

    regularPay = regularHours * payRate;
    overtimePay = overtimeHours * overtimePayRate;
    grossPay = regularPay + overtimePay;

    if (pensionPlan == 'y' || pensionPlan == 'Y')
    {

        pensionPay = grossPay * 0.06;

    }

    taxPay = (grossPay-(pensionPay + insurancePay)) * 0.23;
    netPay = grossPay - (pensionPay + insurancePay + taxPay);

    // Output results
    cout << setfill('.') << fixed << setprecision(2);
    cout << left << setw(32) << "Employee Name: " << right << " " << employeeName << endl;
    cout << left << setw(32) << "Total hours worked: " << right << " " << hoursWorked << endl;
    cout << left << setw(32) << "Gross pay for regular hours: " << right << " $"<< setw(8) << regularPay << endl;
    cout << left << setw(32) << "Gross pay for overtime hours: " << right << " $"<< setw(8) << overtimePay << endl;
    cout << left << setw(32) << "Total gross pay: " << right << " $" << setw(8) << grossPay << endl;
    cout << left << setw(32) << "Retirement plan deduction: " << right << " $" << setw(8) << pensionPay << endl;
    cout << left << setw(32) << "Insurance deduction: " << right << " $" << setw(8) << insurancePay << endl;
    cout << left << setw(32) << "FICA taxes: " << right << " $" << setw(8) << taxPay << endl;
    cout << left << setw(32) << "Net pay: " << right << " $"<< setw(8) << netPay << endl;

    outFile << setfill('.') << fixed << setprecision(2);
    outFile << left << setw(32) << "Employee Name: " << right << " " << employeeName << endl;
    outFile << left << setw(32) << "Total hours worked: " << right << " " << hoursWorked << endl;
    outFile << left << setw(32) << "Gross pay for regular hours: " << right << " $" << setw(8) << regularPay << endl;
    outFile << left << setw(32) << "Gross pay for overtime hours: " << right << " $" << setw(8) << overtimePay << endl;
    outFile << left << setw(32) << "Total gross pay: " << right << " $" << setw(8) << grossPay << endl;
    outFile << left << setw(32) << "Retirement plan deduction: " << right << " $" << setw(8) << pensionPay << endl;
    outFile << left << setw(32) << "Insurance deduction: " << right << " $" << setw(8) << insurancePay << endl;
    outFile << left << setw(32) << "FICA taxes: " << right << " $" << setw(8) << taxPay << endl;
    outFile << left << setw(32) << "Net pay: " << right << " $" << setw(8) << netPay << endl;

    outFile.close();

}
