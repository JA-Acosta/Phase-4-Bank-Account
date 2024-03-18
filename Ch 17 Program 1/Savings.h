#ifndef SAVINGS_H
#define SAVINGS_H
#include "Checking.h"
using namespace account;

class Savings : public Checking
{

public:
	
	/* Constructor that sets the initial balance for the savings account. The
	* Number of Accounts is updated and current Accounts Number is set. The
	* Monthly interest for the account is also updated.
	* Param: double initialBalance
	*/
	Savings(double initialBalance = 0)
		: Checking(initialBalance)
	{	this->MonthlyInterest = .0105;	
		this->Penalty = 50;
		this->PenaltyThreshold = 1000;
	}

	/* Checks if the customers account is less than 1000 and if it is, the customer
	* is charged a 50 dollar withdraw fee. Otherwise, no fee is applied.
	*/
	virtual void withdraw(double amount) override
	{
		balance -= amount;

		// After deducting the amount, checks if a penalty needs to be applied.
		if (balance < PenaltyThreshold)
			balance -= Penalty;
	}

	~Savings() {}
};

#endif // !SAVINGS_H
