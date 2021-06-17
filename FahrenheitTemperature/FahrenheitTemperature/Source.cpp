#include<iostream>
#include<fstream>			//use to work with txt file
#include<string>
#include<cstring>
/*********************************************************************************
* Name			: NewTemperature.txt
* Author		: Pasco Logan
* Version		: 1
* Description	: Change the degress from Celsius to Fahrenheit using a txt file 
* ********************************************************************************/

using namespace std;


int main() {
	ifstream celsius;		 // variable for input txt file 
	ofstream newTemps;		 //	name of output txt file 
	string city;			 // data string from txt file  
	int temp;				 // date int from txt file
	double newTemp;

	cout << "Opening file FahrenheitTemperature.txt" << endl;
	
	celsius.open("FahrenheitTemperature.txt");		// Txt file to open with the original temperatures assigned to variable celsius
	
	newTemps.open("NewTemperature.txt");			// Txt file that will have the new temperatures new file will be called NewTemperature.txt
	
	// error check to make sure file celsius is opening 
	if (!celsius.is_open()){
		cout << "Could not open file FahrenheitTemperature.txt " << endl;
		return 1;
	}

	cout <<"\n" << "Reading City's and Temperatures." << endl;

	cout << "\n" << "Convert Temperatures to Celsius" << endl;
	
	celsius >> city;
	
	celsius >> temp;

	//error checking loop to get data from file 
	while (!celsius.fail()) {
		newTemp = (temp - 32) * 0.5556;		// convert Fahrenheit to Celsius
		cout.width(10); cout << left << city << "  " << newTemp << "c" << endl; // print statment for complier 
		newTemps << city << "  " << newTemp << "c" << endl; // print to txt NewTemperature
		celsius >> city;
		celsius >> temp;
	}

		// if statment if file does not reach end of file 
	if (!celsius.eof()) {
		cout << "Input failed before reaching end of file" << endl;	
		return 2;
	}

	newTemps.close();	 // close file NewTemperature.txt 
	celsius.close();	 //	close file FahrenheitTemperature.txt


	return 0;
}