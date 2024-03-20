
#include "Customer.h"

namespace customer {
	int Customer::Customers = 0;

	Customer::Customer(string First, string Last)
		: First(First), Last(Last)
	{
		// Adds a New Customer
		Customers += 1;

		// Assigns the customer ID based on the new customer that was added.
		CustomerID = Customers;
	}

	Account* Customer::makeAccount(double initialBalance, int type)
	{
		Account* tempA = nullptr;
		
		enum checkAccounts {
			checkings = 1, savings, market, certificate3, certificate6, certificate12
		};

		// creates a new instance of a child Account class based on type.
		// Updates the list for reference by type of accounts (accountTypes).
		switch (type)
		{
			case checkings :
				tempA = new Checking(initialBalance);
				accountTypes[tempA->getAccountNumber()] = "checkings";
				break;

			case savings :
				tempA = new Savings(initialBalance);
				accountTypes[tempA->getAccountNumber()] = "savings";
				break;

			case market :
				tempA = new MoneyMarket(initialBalance);
				accountTypes[tempA->getAccountNumber()] = "market";
				break;

			case certificate3 :
				tempA = new Certificate(initialBalance, 3);
				accountTypes[tempA->getAccountNumber()] = "certificate3";
				break;
		
			case certificate6 :
				tempA = new Certificate(initialBalance, 6);
				accountTypes[tempA->getAccountNumber()] = "certificate6";
				break;

			case certificate12 :
		default:
			tempA = new Certificate(initialBalance, 12);
			accountTypes[tempA->getAccountNumber()] = "certificate12";
			break;
		}

		// Updates the list containing all accounts by moving the account to the end of the list.
		allAccounts.push_back(move(*tempA));
		return &(allAccounts.back());
	}

	string Customer::listAccounts()
	{
		string allAccountType[] = { "checkings", "savings", "market", "certificate3",
			"certificate6", "certificate12" };
		string listOfAccounts = "";

		for (auto& type : allAccountType)
		{
			listOfAccounts += listAccounts(type);
		}
		return listOfAccounts;
	}

	string Customer::listAccounts(string accType)
	{
		string listOfAccounts;

		if (accType == "checkings")
		{
			listOfAccounts += "Checking Accounts:\n";
		}
		else if (accType == "savings")
		{
			listOfAccounts += "Savings Accounts:\n";
		}
		else if (accType == "market")
		{
			listOfAccounts += "Money Market Accounts:\n";
		}
		else if (accType == "certificate3")
		{
			listOfAccounts += "3 Month Certificates:\n";
		}
		else if (accType == "certificate6")
		{
			listOfAccounts += "6 Month Certificates:\n";
		}
		else if (accType == "certificate12")
		{
			listOfAccounts += "12 Month Certificates:\n";
		}

		for (auto& acc : this->accountTypes)
		{
			if (acc.second == accType)
			{
				listOfAccounts += "    Account ID: " + to_string(acc.first) + "\n";
			}
		}
		listOfAccounts += "\n";
		return listOfAccounts;
	}

	Account* Customer::getAccount(int accountNumber)
	{
		for (auto& acc : allAccounts)
		{
			if (accountNumber == acc.getAccountNumber())
			{
				return &acc;
			}
		}
		return nullptr;
	}

	Customer::~Customer()
	{
	}
}