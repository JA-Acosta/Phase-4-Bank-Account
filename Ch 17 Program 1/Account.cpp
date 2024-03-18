#include "Account.h"

namespace account
{
	int Account::Accounts = 0;

	Account::Account(double initialBalance = 0)
		: balance(initialBalance)
	{
		Accounts += 1;
		this->AccountNumber = Accounts;
	}

	// Default Destructor
	Account::~Account(){}
}