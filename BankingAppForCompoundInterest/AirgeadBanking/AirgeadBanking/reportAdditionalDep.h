#ifndef REPORT_ADDITIONAL_DEP_H_
#define REPORT_ADDITIONAL_DEP_H_

#include <string>
using namespace std;

class ReportAdditionalDeposit {

public:
    // DEFAULT
    ReportAdditionalDeposit();
    ReportAdditionalDeposit(int t_months, double t_initalDeposit, double t_additionalMonthlyDeposit, double t_earnedInterest);

    void getBalances(int t_months, double t_initialDeposit, double t_additionalMonthlyDeposit, double t_interestRate);

private:
    int m_months;
    double m_initialDeposit;
    double m_earnedInterest;
    double m_additionalMonthlyDeposit;
    void printSigns(int t_num, bool t_singleDash);
    void format(int t_ind, double t_totalBal, double t_earnedTotalInterest);
    void printMonthlySummary(int t_months, double t_initalDeposit, double t_additionalMonthlyDeposit, double t_interestRate);
    void printYearlySummary(int t_years, double t_initalDeposit, double t_additionalMonthlyDeposit, double t_interestRate);
    void print(bool t_isYear);
};
#endif
