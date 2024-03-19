/* Program:
* Author: JAAR
* Date: 03/17/2024
* Bank Account Version 1
*/

#include <iostream>
#include <string>
#include "Customer.h"
#include "Account.h"
#include "Checking.h"
#include "Savings.h"

using namespace std;
using namespace customer;
using namespace account;

// Prints a menu with all the options the customer has.
void menu();

/* Asks the user for an input then verifies that the input stream was cleared
* before returning the user input.
* Param: T response, string Error
*/
template <typename T>
void getInput(T& response, string Error);

int main()
{
	int response;
	do
	{
		menu(); // Presents options
		try
		{
			getInput(response, "    Enter an Integer: "); // Get the user input
			if (response < 1 || response > 5)
			{
				throw out_of_range("Your input was out of range!");
			}
		}
		catch (const std::out_of_range & e)
		{
			system("cls");
			cout << e.what() << endl << endl;
			continue;
		}
		break;
	} while (true);

	switch (response)
	{
	case 1 :
		cout << "Opens Account!" << endl;
		break;
	case 2:
		cout << "View Account" << endl;
		break;
	case 3:
		cout << "Close Account" << endl;
		break;
	case 4:
		cout << "Make Deposit" << endl;
		break;
	case 5:
	default:
		cout << "Make Withdraw" << endl;
		break;
	}

	return 0;
}


void menu()
{
	cout << "What would you like to do?" << endl
		<< "    1. Open An Account" << endl <<
		"    2. View Account Information" << endl <<
		"    3. Close an Account" << endl <<
		"    4. Make A Deposit" << endl <<
		"    5. Make A Withdraw" << endl;
	cout << "Response: ";
}

template <typename T>
void getInput(T& response, string Error)
{
	while (true)
	{
		cin >> response;
		if (cin.peek() != '\n') {
			cin.clear();
			cout << "Your input was invalid!" << endl << Error;
			while (cin.peek() != '\n')
			{
				cin.ignore();
			}
			cin.ignore();
		}
		else
		{
			cin.ignore();
			break;
		}

	}
}
