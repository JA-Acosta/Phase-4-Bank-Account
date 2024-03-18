#ifndef MONEYMARKET_H
#define MONEYMARKET_H
#include "Savings.h"
using namespace account;

class MoneyMarket : public Savings
{
public:
	MoneyMarket(double initialBalance)
		: Savings(initialBalance)
	{
		this->MonthlyInterest = .0125;
		this->PenaltyThreshold = 10000;
		this->Penalty = 200;
	}
	
	~MoneyMarket() {}
};

#endif // !MONEYMARKET_H
