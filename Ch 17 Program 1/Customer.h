#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <map>
#include <string>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "MoneyMarket.h"
#include "Certificate.h"
#include <iostream>

namespace customer {
	using namespace account;
	using std::string; using std::to_string; using std::vector;
	using std::map; using std::find; using std::move;
	class Customer
	{
		// If I have time create a person class.
		// Used to determine the customer ID for each customer.
		static int Customers;
		map<int, string> accountTypes; // [int accountNumber: string "Type"]
		vector<Account> allAccounts;
		string First;
		string Last;
		string Address;
		string Phone;
		int CustomerID;
	
	public:
		/* Default constructor that sets the customers first and last name. The number
		* of Customers is updated and the CustomerID is set.
		* Param: string First, string Last
		*/
		Customer(string First, string Last);

		/* Retrieves the customer ID.
		* Return: int customerID
		*/
		int getCustomerID() const
		{	return CustomerID;	}

		/* Retrieves the customers full name in the for "Last, First".
		* Return: string Full Name
		*/
		string getName() const
		{	return this->Last + ", " + this->First;	}

		/* Retrieves the customers last name.
		* Return: string last
		*/
		string getLast() const
		{	return this->Last;	}

		/* Sets the address for the customer account.
		* Param: string Address
		*/
		void setAddress(string Address)
		{	this->Address = Address;	}

		/* Retrieves the customer address.
		* Return: string Address
		*/
		string getAddress() const
		{	return this->Address;	}

		/* Sets the primary phone number for the customers account.
		* Param: string Phone
		*/
		void setPhone(string Phone)
		{	this->Phone = Phone;	}

		/* Retrieves the customers phone number.
		* Return: string Phone
		*/
		string getPhone() const
		{	return this->Phone;	}


		/* Takes the initial balance passed and the account type passed and then creates
		* an instance of an account of that type with the initial balance. Afterwards,
		* a pointer to the account is returned so the account can be accessed immediately.
		* Param: double initialBalance, int type
		* Return: Account* acc
		*/
		Account* makeAccount(double initialBalance, int type);
		
		/* Prints the list of all accounts the user currently grouped by account types.
		* Checks all types and if the user doesn't have an account of a specific type,
		* the category is left blank.
		* All accounts will be represented by their accountID.
		* Return: string listOfAccounts
		*/
		string listAccounts();

		/*Prints the list of all accounts based on a specific account type. If the
		* customer doesn't have an account of that type, returns the account title.
		* Param: str accType
		*	[checkings, savings, market, certificate3, certificate6, certificate12]
		* return: string listOfAccounts
		*/
		string listAccounts(string accType);

		/* Checks if a user has any accounts in their account list. If true returns 1
		* otherwise, returns 0.
		* Return: allAccounts.size();
		*/
		bool hasAccounts() {	return allAccounts.size();	}

		/* Retrieves a users account based on the account number. If there isn't an
		* account, returns a nullptr.
		* Param: int accountNumber
		* Return: Account acc
		*/
		Account* getAccount(int accountNumber);

		/* Retrieves the total number of customers that currently have accounts in the bank.
		* Return: int Customer
		*/
		static int getTotalCustomer() {	return Customers;	}

		~Customer();
	};
}
#endif // !CUSTOMER_H