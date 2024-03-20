/* Program:
* Author: JAAR
* Date: 03/17/2024
* Bank Account Version 1
*/

#include <iostream>
#include <string>
#include <cctype>
#include "Customer.h"
#include <vector>

using namespace std;
using namespace customer;

const int TOTALCUSTOMERS = 34;

// Prints a menu with all the options the customer has.
void menu();

/* Asks the user for an input then verifies that the input stream was cleared
* before returning the user input.
* Param: T response, string Error
*/
template <typename T>
void getInput(T& response, string Error = "");

/* Asks the user for a string and then prompts them with a question to validate
* their input was correct.
* Param: string& str, string question
*/
void getInput(string& str, string question);

/* Presents the list of Accounts to the user with a prompt preceding it if
* needed.
* Param: string s
*/
void accountTypes(string s = "");

/* Asks the user a yes/no question, then takes their input and converts it to a
* bool which can be tested.
* Param: string question
* Return: bool response
*/
bool verifyInput(string question = "");

/* Asks the user questions pertaining to opening a new account; first verifies
* if the user is a current customer. Otherwise, opens a new customer account
* before proceeding.
*/
void openAccount(vector<Customer>& customerList);

/* Asks the user for their account information then prompts them to verify which
* account they want to access. They will then be able to view the account details
* for that specific account.
* Param: vector<Customer>& customerList
*/
void viewAccount(vector<Customer>& customerList);

/* Takes a list of customers and verifies the user based on their last name and
* their customer ID. If the user fails verification 3 times, a null pointer will
* be returned.
* Param: vector<Customer> customerList
* Return: temp
*/
Customer* verifyUser(vector<Customer>& customerList);

/* Prints the list of all accounts the customer currently has, then retrieves the
* account based on user input. If the user doesn't have any accounts, will return
* a nullptr and will prompt the user. Otherwise, will prompt the user until they
* enter a valid response.
* Param: Customer& customer
* Return: Account* accSelected
*/
Account* selectAccount(Customer& customer);

int main()
{
	// Represents a dummy list of customers.
	vector<Customer> customerList;
	Customer Customer1("First1", "Last1"); Customer1.setAddress("Address1"); Customer1.setPhone("Number1");
	Customer Customer2("First2", "Last2"); Customer2.setAddress("Address2"); Customer2.setPhone("Number2");
	Customer1.makeAccount(3000,3);
	Customer1.makeAccount(2000, 1);
	Customer1.makeAccount(3500, 1);
	Customer1.makeAccount(2500, 2);
	Customer1.makeAccount(3500, 2);
	customerList.push_back(move(Customer1));
	customerList.push_back(move(Customer2));
	
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
		openAccount(customerList); 
		break;

	case 2:
		viewAccount(customerList);
		break;

	case 3:
		cout << "Close Account" << endl;
		// ask if they want to close an individual account or all accounts.
		// if et all, will close all accounts and give the ammount to be returned.
		// will always return the money to the account holder; can then deposit.
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
	cout << "What would you like to do?" << endl <<
		"    1. Open An Account" << endl <<
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
		else if (response <= 0)
		{
			cout << "Enter a positive number!" << endl;
			cin.ignore();
		}
		{
			cin.ignore();
			break;
		}
	}
}

void getInput(string& str, string question)
{
	do
	{
		cout << question;
		getline(cin, str);
	} while (!verifyInput("Is your input \"" + str + "\" correct yes/no: "));
}

void accountTypes(string s)
{
	cout << s <<
		"    1. Checkings" << endl <<
		"    2. Savings" << endl <<
		"    3. Money Marketing" << endl <<
		"    4. Certificate of Deposit (3 Months)" << endl <<
		"    5. Certificate of Deposit (6 Months)" << endl <<
		"    6. Certificate of Deposit (12 Months)";
}

bool verifyInput(string question)
{
	cout << question;
	string verify;
	bool response = true;
	// Checks if the user already has an account:
	while (true)
	{
		try
		{
			getline(cin, verify);
			for (auto& ch : verify)
			{
				ch = tolower(ch);
			}
			if (verify != "yes" && verify != "no")
			{
				system("cls");
				throw invalid_argument("Your input was invalid.\n    Enter either yes/no: ");
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what();
			continue;
		}
		break;
	}
	if (verify == "no")
	{
		response = false;
	}
	return response;
}

void openAccount(vector<Customer>& customerList)
{
	Customer* customerAccount;
	string verify;
	if (verifyInput("Do you have a current account?: "))
	{
		customerAccount = verifyUser(customerList);
		if (customerAccount == nullptr)
		{
			cout << "You've exceeded the access attempts for your account." << endl;
			return;
		}
	}
	else
	{
		string last,
			first,
			address,
			phone;
		getInput(last, "What is your last name: ");
		getInput(first, "What is your first name: ");
		Customer* temp = new Customer(first, last);
		getInput(address, "What is your address: ");
		getInput(phone, "What is your phone number: ");
		temp->setAddress(address);
		temp->setPhone(phone);
		customerList.push_back(move(*temp));
		customerAccount = &customerList.back();
	}

	// Clear screen; display customer account info after customer account is opened:
	system("cls");
	cout << "Your Customer Account Information Is:\n\n";
	cout << "    Customer ID:  " << customerAccount->getCustomerID() << endl <<
		"    Name:         " << customerAccount->getName() << endl <<
		"    Address:      " << customerAccount->getAddress() << endl <<
		"    Phone Number: " << customerAccount->getPhone() << endl << endl;

	int response;
	// Asks the user to verify what type of account they want to open.
	do
	{
		accountTypes("Account Type List:\n\n");
		cout << endl << "Your Selection: ";
		try
		{
			getInput(response, "    Enter an Integer: "); // Get the user input
			if (response < 1 || response > 6)
			{
				throw out_of_range("Your input was out of range!");
			}
		}
		catch (const std::out_of_range& e)
		{
			system("cls");
			cout << e.what() << endl << endl;
			continue;
		}
		break;
	} while (true);

	// Ask for the initial balance:
	double initialBalance;
	cout << "What is your initial deposit?: $";
	getInput(initialBalance, "Please enter a valid deposit amount: $");

	// Points to the account that was just created then prints all of the account information
	Account* newAcc;
	newAcc = customerAccount->makeAccount(initialBalance, response);
	cout << newAcc->getAccountInfo();
}

void viewAccount(vector<Customer>& customerList)
{	
	// Set a try catch if the customer account was null.
	// Set a try catch if there is a nullptr returned
	// which would only happen if there is no account for
	// the current customer.
	Account* accSelected;
	Customer* customerAccount = verifyUser(customerList);
	accSelected = selectAccount(*customerAccount);
	system("cls");
	cout << accSelected->getAccountInfo();
}

Customer* verifyUser(vector<Customer>& customerList)
{
	// Counts the number of times the user has tried to get their account.
	int userAttempts = 0;
	// ref to customer.
	Customer* temp = nullptr;

	string last;
	int customerID;
	bool idExists = false;

	while (!idExists && userAttempts < 3)
	{
		// UPDATE: WARNING STATEMENT TO LET THE USER THEY HAVE 3 ATTEMPTS.
		// Increments the attempts counter by 1.
		userAttempts++;
	
		try
		{
			getInput(last, "What is your last name: ");
			cout << "What is your CustomerID: ";
			getInput(customerID, "Enter a valid CustomerID: ");

			// Checks if the customer exist within the range fo customer ID's.
			if (customerID < 1 || customerID > Customer::getTotalCustomer())
			{
				system("cls");
				throw out_of_range("Your Customer ID was invalid!\n    ");
			}

			// Checks if the last name matches the customer ID.
			for (auto& customer : customerList)
			{
				if (customerID == customer.getCustomerID() && last == customer.getLast())
				{
					idExists = true;
					temp = &customer;
				}
			}

			if (!idExists)
			{
				throw invalid_argument("The Customer ID and Last Name don't match! Try again!\n");
			}
		}
		catch (const std::out_of_range& e)
		{
			cout << e.what();
			continue;
		}
		catch (const std::invalid_argument& e)
		{		
			cout << e.what();
			continue;
		}
		break;
	}

	// UPDATE: WARNING STATEMENT IF THE USER FAILS ALL 3 ATTEMPTS.
	return temp;
}

Account* selectAccount(Customer& customer)
{
	// WILL RECURSIVELY REPEAT TILL THE USER ENTERS A VALID
	// ACCOUNT ID IF ONE EXIST. UPDATE TO ONLY GIVE 3 TRIES.
	system("cls");
	if (!customer.hasAccounts())
	{
		cout << "You have no Accounts!" << endl;
		return nullptr;
	}

	cout << customer.listAccounts();
	Account* accSelected = nullptr;
	while (true)
	{
		try
		{
			cout << "Enter the Account ID: ";
			int accID;
			getInput(accID);
			accSelected = customer.getAccount(accID);
			if (accSelected == nullptr)
			{
				throw invalid_argument("Invalid Account Selection!");
			}
		}
		catch (const std::invalid_argument& e)
		{
			cout << e.what();
			continue;
		}	
		return accSelected;
	}
}
