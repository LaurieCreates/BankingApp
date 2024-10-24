#ifndef DISPLAY_H_
#define DISPLAY_H_

using namespace std;

class Display {
public:
    // DEFAULT
    Display();
    Display(double t_initalDeposit, double t_recurringMonthlyDep, double t_annualInterest, double t_months);
    double getInitialDeposit() const;
    double getRecurringMonthlyDep() const;
    double getAnnualInterest() const;
    double getMonths() const;
    void setInitialDeposit(double t_initialDeposit);
    void setRecurringMonthlyDep(double t_recurringMonthlyDep);
    void setAnnualInterest(double t_annualInterest);
    void setMonths(double t_months);
    void print();
private:
    double m_initialDeposit;
    double m_recurringMonthlyDep;
    double m_annualInterest;
    double m_months;
    void printStars(int t_num);
};
#endif
