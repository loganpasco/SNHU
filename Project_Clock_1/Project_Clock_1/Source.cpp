//==============================================================================================================
// Name			:Project Clock_1
// Author		:Pasco Logan
// Version		:
// Copyright	:SNHU CS-210 
// Descripition	:Make a program that will ouput two clocks on showing 12 hours and other showing 24 hours 
//==============================================================================================================
#include<iostream>
#include<time.h>
#include<stdlib.h> 
#include<iomanip>

using namespace std;

// delclare function that will setup and print 12 hour clock using parameters hours, minute ,second 
void standardClock(int hour, int minute, int second) {
	
	string AmPm; // variable for the AM / PM of the clock 

	//If else statments for getting time of the 12 hour clock 
	if ((hour >= 1) && (hour <= 23)) { //setting a range of time from 1 - 23 hours 
		hour = hour;
		
		if (hour <= 11) {  //use to assign all numbers that are 11 and under to the AM 
			AmPm = "AM";
		}
		
		if (hour == 12) { 
			hour = hour;
			AmPm = "PM";
		}

		if (hour == 13) {
			hour = hour - 12; // use to convert military time to stanard time by subtracting 12
			AmPm = "PM";
		}
		
		if (hour == 14) {
			hour = hour - 12;
			AmPm = "PM";
		}
		
		if (hour == 15) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 16) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 17) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 18) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 19) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 20) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 21) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 22) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 23) {
			hour = hour - 12;
			AmPm = "PM";
		}
		if (hour == 24) {
			hour = hour - 12;
			AmPm = "PM";
		}

	}
	 if ((hour >= 13) && (hour <= 24)) { //use to assign all numbers that are 11 and under to the PM 
		hour = hour - 12;
		AmPm = "AM";
	}
	 if (hour > 13) {
		 hour = hour - 24;
		 AmPm = "AM";
	 }

	if ((minute >= 1) && (minute < 60)) { // set a range of 1 - 59 for minutes 
		minute = minute;
	}
	if (minute >= 60) {
		hour = hour + 1;
		minute = minute - 60;
	}

	if ((second >= 1) && (second < 60)) { // set a range of 1 -59 for seconds 
		second = second;
	}
	if (second >= 60) {
		minute = minute + 1;
		second = second - 60;
	}
	// output of 12 hour clock 
	cout << "************************************" << endl;
	cout << "*          12-Hour Clock           *" << endl;
	cout << "*           " <<std::setfill('0') << std::setw(2) << hour << ":" <<std::setfill('0') << std::setw(2) << minute << ":"<<std::setfill('0')<<std::setw(2) << second << " " << AmPm << "            *" << endl;
	cout << "************************************" << endl;
}

// delclare function that will setup and print 24 hour clock using parameters hours, minute ,second 
void militaryClock(int hour , int minute , int second) {

	string AmPm;
	 
	if ((hour >= 1) && (hour <= 23)) { //setting a range of time from 1 - 23 hours 
		hour = hour; 
		if (hour >= 12) {
			AmPm = "PM";
		}
		else {
			AmPm = "AM";
		}
	}
	if (hour > 23 ){
		hour = hour - 24;
		AmPm = "AM";
	}

	if ((minute >= 1) && (minute < 60)) {// set a range of 1 - 59 for minutes
		minute = minute;
	}
	if (minute >= 60) {
		hour = hour + 1;
		minute = minute - 60;
	}

	if ((second >= 1) && (second < 60)) { // set a range of 1 -59 for seconds 
		second = second;
	}
	if (second >= 60) {
		minute = minute + 1;
		second = second - 60;
	}

	// output of 24 hour clock 
	cout << "************************************" << endl;
	cout << "*          24-Hour Clock           *" << endl;
	cout << "*           " << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minute << ":" << std::setfill('0') << std::setw(2) << second << " " << AmPm << "            *" << endl;
	cout << "************************************" << endl;


}

int main() {
	int hour; //Variables that will store user input 
	int min;
	int sec;
	int user;

	cout << "What is the hour (HH-)" << endl; //getting user input for initial time 
	cin >> hour;
	cout << "What is the Minute (MM-)" << endl;
	cin >> min;
	cout << "What is the Second (SS-)" << endl;
	cin >> sec;

	militaryClock(hour, min , sec); //function call of 24 hour clock with user input 
	standardClock(hour, min , sec); //function call of 12 hour clock with user input 
	
	//user meun list to add time or quiting the program 
	cout << "************************************" << endl;
	cout << "*     1 - Add One Hour             *" << endl;
	cout << "*     2 - Add One Minute           *" << endl;
	cout << "*     3 - Add One Second           *" << endl;
	cout << "*     4 - Exit Program             *" << endl;
	cout << "************************************" << endl;
	
	cin >> user;

	//loop and switch statement to translate user input in to correct function  
	while (user != 4) {

	switch (user){
	case 1:                                 //case statemnt to add hours to both clocks 
		if (user == 1) {
			hour = hour + 1;
			militaryClock(hour, min, sec); 
			standardClock(hour, min, sec);
		}
		break;
	
	case 2:                                //case statment to add minutes to both clocks 
		if (user == 2) {
			min = min + 1;
			militaryClock(hour, min, sec);
			standardClock(hour, min, sec);
		}
		break;
	
	case 3:                                //case statment to add seconds to both clocks 
		if (user == 3) {
			sec = sec + 1;
			militaryClock(hour, min, sec);
			standardClock(hour, min, sec);
		}
		break;
		
	default:
		cout << "Invalid selection" << endl;
		break;
	}
	cout << "************************************" << endl;
	cout << "*     1 - Add One Hour             *" << endl;
	cout << "*     2 - Add One Minute           *" << endl;
	cout << "*     3 - Add One Second           *" << endl;
	cout << "*     4 - Exit Program             *" << endl;
	cout << "************************************" << endl;
	cin >> user;
	}
	cout << "Thanks for using my clock" << endl;
	

	return 0;
}