#include "investment.h"
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
/****************************************************************************************************************************************************************
* Name			: Airgead Investment tool 
* Author		: Pasco Logan 
* Version		: 1
* Description	: This program will take user input for investing and return two reports showing the interest earn depending on deposit and length of time
*****************************************************************************************************************************************************************/

using namespace std;

int main() {

	Investment newAccount;

		newAccount.greeting();

		newAccount.setInitAmount();

		newAccount.setMonthContrib();

		newAccount.setInterestRate();

		newAccount.setNumYears();

		newAccount.calculateInvestments();

		newAccount.staticReport();






	return 0;
};

