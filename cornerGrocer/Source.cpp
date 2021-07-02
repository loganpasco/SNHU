#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>

/******************************************************************************************************************************************************************
* Name			: Corner Grocer inventory tool
* Author		: Pasco Logan
* Version		: 1
* Description	: This program use both C++ and python and will take inforamtion from a text file and put it into a list that will display depending on user input 
*******************************************************************************************************************************************************************/


using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("cornerGrocer");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"cornerGrocer");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"cornerGrocer");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

int histogram(){

	ifstream listOfItems;		 // variable for input txt file  
	string products;			 // data string from txt file  
	int quantity;				 // date int from txt file
	char amount = '*';

	cout << "Opening file frequency_dat.txt" << endl;

	listOfItems.open("frequency_dat.txt");		// Txt file to open with the original temperatures assigned to variable celsius

	// error check to make sure file celsius is opening 
	if (!listOfItems.is_open()) {
		cout << "Could not open file frequency_dat.txt" << endl;
		return 1;
	}

	cout << "Reading the names of items..." << endl;
	listOfItems >> products;

	cout << "Reading the number of items..." << endl << endl;
	listOfItems >> quantity;

	cout << "\n" << "Histogram List of all purchased Items" << endl;
	cout << "===========================================================" << endl << endl;

	//error checking loop to get data from file 
	while (!listOfItems.fail()) {

		cout << products << " " << string(quantity, amount) << endl; /* print statment using a feature the takes the quantity as the number of times
																		we want to print and amount as the character "*" */		
		listOfItems >> products;
		
		listOfItems >> quantity;
	}

	// if statment if file does not reach end of file 
	if (!listOfItems.eof()) {
		
		cout << "Input failed before reaching end of file" << endl;
		
		return 2;
	}

	listOfItems.close();  //close file frequency_dat.txt 

}

bool isLetters(string input) { // error checking for anything that is not a letter 

	for (int i = 0; i < input.size(); i++) { // loop to check every letter in the word

		int uppercaseChar = toupper(input[i]); // convert character to upper case version of character

		if (uppercaseChar < 'A' || uppercaseChar > 'z') { // if statement if character is not A - z

			return false; // false if character is not a letter 
		}
	}
	return true; // true if all characters are letters 

}




int main()
{
	
	int choice; // user input 

	CallProcedure("displayMenu"); // display menu for user  

	while (cin >> choice) { 

		if (choice == 4) // break loop if user input is 4 
			break;

		if (choice >= 5) { // error checking for user input of 5 and over 
			cout << "\n*Invalid input please try again*" << endl;
		}

		switch (choice) { 

		case 1:
			if (choice == 1) { 
				cout << "\nList of Purchased Items" << endl;
				cout << "============================================================" << endl;
				CallProcedure("soldItems"); // call to python method "solditems" that will produce a list of sold items and quantity
			}
			break;

		case 2:
			if (choice == 2) {
				cout << endl;
				string name; 
				cout << "Please select an item." << endl;
				cin >> name; // user input is now a string instead of an int 

				if (!isLetters(name)) { // error checking making sure user input is all letters
					cout << "\n*Invalid input please try again*" << endl;
					break;
				}
				
				if (!name.empty()) { // if statment using algorithm to change first letter to upper case of user input 
					transform(name.begin(), name.end(), name.begin(), ::tolower);
					name[0] = toupper(name[0]);
				}

				callIntFunc("itemQuantity", name); // call to python method using user input as argument 
				
				cout << "\nPurchased item and Quantity" << endl;
				
				cout << "=============================================================" << endl;
				
				cout << name << ": " << callIntFunc("itemQuantity", name) << endl; // print results out to C++ screen 
			}
			break;

		case 3:
			if (choice == 3) {

				cout << endl;
				
				histogram(); // display a histogram of sold items 
				
				break;
			}
			break;

		
		}
		cout << endl;
		CallProcedure("displayMenu");
	
	}
	cout << "\nThank you for using the program. Goodbye!" << endl; // if user input is 4 this will print on the screen 

}

	
