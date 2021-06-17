#include "investment.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;


	void Investment::setInitAmount() {	

		cout << "\nStep 1: Initial Investment" << endl;
		
		cout << "How much do you plan to invest ? ";
		
		cin >> initAmount;											// set investment amount with user input 
		
		while (initAmount < 0) {									// error checking for negative numbers
			cout << "Invalid Input Please Try Again" << endl;
			cout << "How much do you plan to invest ? ";
			cin >> initAmount;										
		}
	}


	void Investment::setMonthContrib() {

		cout << "\nStep 2: Contribute " << endl;
		
		cout << "How much do you plan to contribute each month? ";
		
		cin >> monthContrib;										// set Monthly contribution with user input 
		
		while (monthContrib < 0) {									// error checking for negative numbers
			cout << "Invalid Input Please Try Again" << endl;
			cout << "How much do you plan to contribute each month? ";
			cin >> monthContrib;
		}
	}



	void Investment::setInterestRate() {	
		
		cout << "\nStep 3: Interest Rate" << endl;

		cout << "What is the estimated interest rate? "; 
		
		cin >> interestRate;										// set interest rate with user input 
		
		while (interestRate < 0) {                                 // error checking for negative numbers
			cout << "Invalid Input Please Try Again" << endl;
			cout << "What is the current interst rate? ";
			cin >> interestRate;
		}
	}


	void Investment::setNumYears() {	
		
		cout << "\nStep 4: Length of Time in Years" << endl;

		cout << "How many years do you plan to invest? ";
		
		cin >> numYears;											// set years with user input
		
		numMonths = numYears * 12;									// set months (user input * 12)
		
		while (numYears < 0) {                                      // error checking for negative numbers
			cout << "Invalid Input Please Try Again" << endl;
			cout << "How many years do you plan to invest? ";
			cin >> numYears;											
			numMonths = numYears * 12;
		}
	}


	void Investment::greeting()
	{
		cout << "================================================================" << endl;
		cout << "\t Welcome to Airgead Investment Tool" << endl;
		cout << "================================================================" << endl;
	}

	void Investment::additional() // Report with additional monthly deposits 
	{
		unsigned int i;
		cout << "\n==============================================================" << endl;
		cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "==============================================================" << endl;;
		cout << "Year\tYear End Balance\tTotal Interest Earned" << endl;
		cout << "--------------------------------------------------------------" << endl;;
		
		for (i = 1; i <= numYears; i++) {	// loop for printing out report Year, month close , totatInterest (monthly Contribution set to user input) 

				cout << fixed << setprecision(2) << i << "\t" << m_monthClose.at((i * 12) - 1) << "\t\t\t" <<
				m_totalInterest.at((i * 12) - 1) << endl;
		}
	}

	void Investment::noAdditional() // Report without additional monthly deposits 
	{
		unsigned int i;
		cout << "==============================================================" << endl;
		cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
		cout << "==============================================================" << endl;;
		cout << "--------------------------------------------------------------" << endl;;
		cout << "Year\tYear End Balance\tTotal Interest Earned:" << endl;
		cout << "--------------------------------------------------------------" << endl;;
		
		for (i = 1; i <= numYears; i++) {	// loop for printing out report Year, month close , totatInterest (monthly Contribution set to 0)
				
				cout << fixed << setprecision(2) << i << "\t" << m_monthClose.at((i * 12) - 1) << "\t\t\t" <<
				m_totalInterest.at((i * 12) - 1) << endl;
		}
	}

	void Investment::calculateInvestments() {

		int i;
		double interest;
		double openingBal;
		double closingBal;
		double totalInterest = 0;
		
		openingBal = initAmount + monthContrib;	//opening balance set before loop
		for (i = 0; i < numMonths; ++i) {
	
			m_monthOpen.push_back(openingBal);				// add the opening balance into the vector
			
			interest = ((openingBal) * ((interestRate / 100) / 12));	// monthly interest rate 
		
			totalInterest += interest;		
			
			m_totalInterest.push_back(totalInterest);	//interest each month put into added to vector
			
			m_monthinterest.push_back(interest);	// balance at the end of the month added to vector
			
			closingBal = (openingBal + interest);	//	closingBal = (openingBal + interest + monthlyContrib);
			
			m_monthClose.push_back(closingBal);		// monthly closing balance added to the vector
		
			openingBal = closingBal + monthContrib;
			
			closingBal = 0;							// set closeBal to O to prevent errors

		}

	}

	// This will print both reports one with monthly contributions and one without
	void Investment::staticReport() {
		{
			additional();		// print statment with monthly contribution
			//clear all vectors
			m_monthClose.clear();
			
			m_totalInterest.clear();
			
			m_monthinterest.clear();
			
			m_monthOpen.clear();
			
			monthContrib = 0;	// set Monthly contribution to 0
			
			calculateInvestments();		// call to recalculate 
			
			noAdditional();		// print statement without monthly contribution 
		}
	}

		

	


