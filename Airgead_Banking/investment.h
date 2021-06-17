#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Investment {

private:
	
	vector<double> m_monthOpen = vector<double>();			// month open vector 
	vector<double> m_monthClose = vector<double>();			// month close vector 
	vector<double> m_monthinterest = vector<double>();		// month interest vector 	
	vector<double> m_totalInterest = vector<double>();		// total interest vector

public:
	// mutator functions
	void setInitAmount();
	double initAmount;
	
	void setMonthContrib();
	double monthContrib;
	
	void setInterestRate();
	double interestRate;

	void setNumYears();
	int numYears;
	
	unsigned int numMonths; // variable for number of months 
	
	void greeting();

	void calculateInvestments();

	void additional();

	void noAdditional();

	void staticReport();

};
#endif
