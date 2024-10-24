#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "reportNoAdditionalDep.h"
#include "display.h"

ReportNoAdditionalDeposit::ReportNoAdditionalDeposit() {
    m_months = 0;
    m_initialDeposit = 0;
    m_earnedInterest = 0;
}

ReportNoAdditionalDeposit::ReportNoAdditionalDeposit(int t_months, double t_initialDeposit, double t_earnedInterest) {
    this -> m_months = t_months;
    this -> m_initialDeposit = t_initialDeposit;
    this -> m_earnedInterest = t_earnedInterest;
}

int ReportNoAdditionalDeposit::getMonths() const {
    return m_months;
}

double ReportNoAdditionalDeposit::getinitialDeposit() const {
    return m_initialDeposit;
}

double ReportNoAdditionalDeposit::getEarnedInterest() const {
    return m_earnedInterest;
}

void ReportNoAdditionalDeposit::setMonths(int t_months) {
    m_months = t_months;
}

void ReportNoAdditionalDeposit::setinitialDeposit(double t_initialDeposit) {
    m_initialDeposit = t_initialDeposit;
}

void ReportNoAdditionalDeposit::setEarnedInterest(double t_earnedInterest) {
    m_earnedInterest = t_earnedInterest;
}

void ReportNoAdditionalDeposit::printSigns(int t_num, bool t_singleDash) {
    for (int i = 0; i < t_num; i++) {
        if (t_singleDash) {
            cout << "-";
        }
        else {
            cout << "=";
        }
    }
}

void ReportNoAdditionalDeposit::format(int t_ind, double t_totalBal, double t_earnedTotalInterest) {
    const int indWidth = 20;
    const int balanceWidth = 20;
    const int interestWidth = 20;

    cout << left << setw(indWidth) << t_ind << "$" << setw(balanceWidth) << fixed << setprecision(2) << t_totalBal << "$"
        << setw(interestWidth) << t_earnedTotalInterest << endl;
}

void ReportNoAdditionalDeposit::printSummary(int t_months, double t_initialDeposit, double t_interestRate) {
    // yearly or monthly
    double earnedInterest = 0;
    double earnedTotalInterest = 0;
    double totalBalance = t_initialDeposit;

    for (int i = 1; i <= t_months; i++) {
        // year or month end interest
        earnedInterest = totalBalance * t_interestRate;
        // total compounded interest
        earnedTotalInterest = earnedInterest;
        totalBalance += earnedTotalInterest;

        // print and format user dividends per month (or year)
        format(i, totalBalance, earnedTotalInterest);
    }
}

void ReportNoAdditionalDeposit::getBalances(int t_months, double t_initialDeposit, double t_interestRate) {
    int t_years = 0;
    bool isYear = true;
    // Print a yearly display
    print(isYear);

    //TO DO: Add check for when t_months = 0
    // display message for user, cannot earn interest in < 1 month

    // Print the yearly summary if months are greater than or equal to 12
    if (t_months >= 12) {
        // compute full years
        t_years = t_months / 12;
        printSummary(t_years, t_initialDeposit, t_interestRate);
    }

    // Print a monthly display
    isYear = false;
    print(isYear);
    // Print friendly UI monthly summary
    printSummary(t_months, t_initialDeposit, t_interestRate);
}


void ReportNoAdditionalDeposit::print(bool isYear) {
    const int indWidth = 20;
    const int balanceWidth = 20;
    const int interestWidth = 20;
    string yearOrMonthCap;
    string yearOrMonthLower;
    string endBal;
    string intBal;

    if (isYear) {
        yearOrMonthLower = "Year";
        yearOrMonthCap = "YEARLY";
        endBal = yearOrMonthLower + " End Balance";
        intBal = yearOrMonthLower + " End Earned Interest";
    }
    else {
        yearOrMonthLower = "Month";
        yearOrMonthCap = "MONTHLY";
        endBal = yearOrMonthLower + " End Balance";
        intBal = yearOrMonthLower + " End Earned Interest";
    }

    printSigns(62, true);
    cout << endl;
    cout << "                   " << yearOrMonthCap << " SUMMARY" << endl;
    printSigns(62, true);
    cout << endl;
    printSigns(62, false);
    cout << endl;
    cout << "  Balance and Interest Without Additional " << yearOrMonthLower << "ly Deposits    " << endl;
    printSigns(62, false);
    cout << endl;
    cout << left << setw(indWidth) << yearOrMonthLower << setw(balanceWidth) << endBal
        << setw(interestWidth) << intBal << endl;
    printSigns(62, false);
    cout << endl;
}
