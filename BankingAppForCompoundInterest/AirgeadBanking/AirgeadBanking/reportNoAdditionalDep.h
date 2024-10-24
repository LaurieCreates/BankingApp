#ifndef REPORT_NO_ADDITIONAL_DEP_H_
#define REPORT_NO_ADDITIONAL_DEP_H_

#include <string>
using namespace std;

class ReportNoAdditionalDeposit {

public:
    // DEFAULT
    ReportNoAdditionalDeposit();
    ReportNoAdditionalDeposit(int t_months, double t_initalDeposit, double t_earnedInterest);
 
    int getMonths() const;
    double getinitialDeposit() const;
    double getEarnedInterest() const;

    void setMonths(int t_months);
    void setinitialDeposit(double t_monthEndBalance);
    void setEarnedInterest(double t_earnedInterest);

    void getBalances(int t_months, double t_initalDeposit, double t_interestRate);

private:
    int m_months;
    double m_initialDeposit;
    double m_earnedInterest;
    void printSigns(int t_num, bool t_singleDash);
    void format(int t_ind, double t_totalBal, double t_earnedTotalInterest);
    void printSummary(int t_months, double t_initalDeposit, double t_interestRate);
    void print(bool isYear);
};
#endif
