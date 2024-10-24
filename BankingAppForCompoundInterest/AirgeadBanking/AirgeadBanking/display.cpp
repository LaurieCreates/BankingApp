#include <iostream>
#include <string>
using namespace std;

#include "display.h"

Display::Display() {
    m_initialDeposit = 0;
    m_recurringMonthlyDep = 0;
    m_annualInterest = 0;
    m_months = 0;
}

Display::Display(double t_initalDeposit, double t_recurringMonthlyDep, double t_annualInterest, double t_months) {
    this -> m_initialDeposit = t_initalDeposit;
    this-> m_recurringMonthlyDep = t_recurringMonthlyDep;
    this-> m_annualInterest = t_annualInterest;
    this-> m_months = t_months;
}

double Display::getInitialDeposit() const {
    return m_initialDeposit;
}

double Display::getRecurringMonthlyDep() const {
    return m_recurringMonthlyDep;
}

double Display::getAnnualInterest() const {
    return m_annualInterest;
}

double Display::getMonths() const {
    return m_months;
}

void Display::setInitialDeposit(double t_initalDeposit) {
    m_initialDeposit = t_initalDeposit;
}

void Display::setRecurringMonthlyDep(double t_recurringMonthDep) {
    m_recurringMonthlyDep = t_recurringMonthDep;
}

void Display::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void Display::setMonths(double t_months) {
    m_months = t_months;
}

void Display::printStars(int t_num) {
    for (int i = 0; i < t_num; i++) {
        cout << "*";
    }
}

void Display::print() {
    // this can access private members
    printStars(34);
    cout << endl;
    printStars(10);
    cout << " Data Input ";
    printStars(12);
    cout << endl;
    cout << "Initial Deposit Amount: " << "    $" <<  m_initialDeposit << endl;
    cout << "Monthly Deposit: " << "           $" << m_recurringMonthlyDep << endl;
    cout << "Annual Interest: " << "           " << m_annualInterest << endl;
    cout << "Number of Months: " << "          " << m_months << endl;
    printStars(34);
    cout << endl;
    printStars(34);
    cout << endl;
}
