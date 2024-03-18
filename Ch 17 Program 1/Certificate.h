#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include "Account.h"
using namespace account;

class Certificate : protected Account
{
protected : 
	int MaturityTime;

public:
	// 
	Certificate(double initialBalance, int Months)
		: Account(initialBalance)
	{
		switch (Months)
		{
		case 3: MaturityTime = 3;
			this->MonthlyInterest = .025;
			this->Penalty = .10;
			break;
		case 6: MaturityTime = 6;
			this->MonthlyInterest = .03;
			this->Penalty = .20;
			break;
		case 12:
		default: MaturityTime = 12;
			this->MonthlyInterest = .05;
			this->Penalty = .50;
		}
	}

	virtual void withdraw(double amount) override
	{
		// Checks if the required number of moths have passed.
		// otherwise, there is a fee that is charged.
	}

	~Certificate() {}
};

#endif // !CERTIFICATE_H
