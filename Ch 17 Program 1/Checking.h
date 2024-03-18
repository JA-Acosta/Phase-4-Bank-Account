#ifndef CHECKING_H
#define CHECKING_H
#include "Account.h"
using namespace account;

class Checking : public Account {

public:

	/* Constructor that sets the initial balance of the checking account. The 
	* Number of Accounts is updated and current Accounts Number is set.
	* Param: double initialBalance
	*/
	Checking(double initialBalance = 0)
		: Account(initialBalance)
	{	this->MonthlyInterest = .0002;	}

	~Checking() {}
};
#endif // !CHECKING_H
