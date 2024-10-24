// AirgeadBanking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "display.h"
#include "reportNoAdditionalDep.h"
#include "reportAdditionalDep.h"

int main()
{
    double initialDeposit;
    double recurringDeposit = 0;
    double annualInterest;
    double numberOfmonths;
    Display display;
    ReportNoAdditionalDeposit reportNoAdditionalDeposit;
    ReportAdditionalDeposit reportAdditionalDeposit;

    // Display inital display
    cout << "Welcome to Airgead Banking!" << endl;
    display.print();

    cout << "Please enter your initial investment amount." << endl;
    cin >> initialDeposit;
    cout << "Please enter your recurring deposit amount." << endl;
    cout << "Please enter 0 if you do not wish to make a recurring deposit." << endl;
    cin >> recurringDeposit;
    cout << "Please enter your annual interest amount." << endl;
    cout << "Note: For 5%, enter 0.05" << endl;
    cout << "Note: For 25%, enter 0.25" << endl;
    cout << "Note: For 100%, enter 1 or 1.00, etc.." << endl;
    cin >> annualInterest;
    cout << "Please enter the number of months for your investment." << endl;
    cin >> numberOfmonths;

    // Display user entered values
    Display userEnteredInfo(initialDeposit, recurringDeposit, annualInterest, numberOfmonths);
    userEnteredInfo.print();

    //Prints inital deposit and month end earned interest per month
    reportNoAdditionalDeposit.getBalances(numberOfmonths, initialDeposit, annualInterest);

    //Prints inital deposit and month end earned interest per month
    reportAdditionalDeposit.getBalances(numberOfmonths, initialDeposit, recurringDeposit, annualInterest);
    
    cout << endl;
    cout << "Thank you for banking with Airgead Banking!" << endl; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
