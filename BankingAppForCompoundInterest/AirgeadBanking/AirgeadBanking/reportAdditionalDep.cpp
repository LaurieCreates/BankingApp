#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "reportAdditionalDep.h"
#include "display.h"

ReportAdditionalDeposit::ReportAdditionalDeposit() {
    m_months = 0;
    m_initialDeposit = 0;
    m_earnedInterest = 0;
    m_additionalMonthlyDeposit = 0;
}

ReportAdditionalDeposit::ReportAdditionalDeposit(int t_months, double t_initialDeposit, double t_additionalMonthlyDeposit, double t_earnedInterest) {
    this->m_months = t_months;
    this->m_initialDeposit = t_initialDeposit;
    this->m_earnedInterest = t_earnedInterest;
    this->m_additionalMonthlyDeposit = t_additionalMonthlyDeposit;
}

void ReportAdditionalDeposit::printSigns(int t_num, bool t_singleDash) {
    for (int i = 0; i < t_num; i++) {
        if (t_singleDash) {
            cout << "-";
        }
        else {
            cout << "=";
        }
    }
}

void ReportAdditionalDeposit::format(int t_ind, double t_totalBal, double t_earnedTotalInterest) {
    const int indWidth = 20;
    const int balanceWidth = 20;
    const int interestWidth = 20;

    cout << left << setw(indWidth) << t_ind << "$" << setw(balanceWidth) << fixed << setprecision(2) << t_totalBal << "$" 
        << setw(interestWidth) << t_earnedTotalInterest << endl;
}

void ReportAdditionalDeposit::printMonthlySummary(int t_months, double t_initialDeposit, double t_additionalMonthlyDeposit, double t_interestRate) {
    double monthlyInterestRate = t_interestRate / 12;
    double totalBalance = t_initialDeposit;
    double earnedMonthlyInterest = 0;

    for (int i = 1; i <= t_months; i++) {
        earnedMonthlyInterest = (totalBalance + t_additionalMonthlyDeposit) * monthlyInterestRate;
        totalBalance += (earnedMonthlyInterest + t_additionalMonthlyDeposit);
        format(i, totalBalance, earnedMonthlyInterest);
    }
}

void ReportAdditionalDeposit::printYearlySummary(int t_years, double t_initialDeposit, double t_additionalMonthlyDeposit, double t_interestRate) {
    int months = t_years * 12;
    double monthlyInterestRate = t_interestRate / 12;
    double totalBalance = t_initialDeposit;
    double earnedMonthlyInterest = 0;
    double accruedInterest = 0;

    for (int i = 1; i <= months; i++) {
        earnedMonthlyInterest = (totalBalance + t_additionalMonthlyDeposit) * monthlyInterestRate;
        accruedInterest += earnedMonthlyInterest;
        totalBalance += (earnedMonthlyInterest + t_additionalMonthlyDeposit);
        if (i % 12 == 0) {
            format(i, totalBalance, accruedInterest);
            accruedInterest = 0;
        }
    }

}

void ReportAdditionalDeposit::getBalances(int t_months, double t_initialDeposit, double t_additionalMonthlyDeposit, double t_interestRate) {
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
        printYearlySummary(t_years, t_initialDeposit, t_additionalMonthlyDeposit, t_interestRate);
    }

    // Print a monthly display
    isYear = false;
    print(isYear);
    // Print friendly UI monthly summary
    printMonthlySummary(t_months, t_initialDeposit, t_additionalMonthlyDeposit, t_interestRate);
}

void ReportAdditionalDeposit::print(bool isYear) {
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
    cout << "  Balance and Interest With Additional " << yearOrMonthLower << "ly Deposits    " << endl;
    printSigns(62, false);
    cout << endl;
    cout << left << setw(indWidth) << yearOrMonthLower << setw(balanceWidth) << endBal
        << setw(interestWidth) << intBal << endl;
    printSigns(62, false);
    cout << endl;
}
