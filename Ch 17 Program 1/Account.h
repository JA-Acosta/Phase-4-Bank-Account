/* Contains header for all methods in the account class.
* Author: JAAR
* Date: 03/17/2024
* Account V1
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H


namespace account
{
class Account 
{
	// Number of accounts
	static int Accounts;

protected:

	// ID based on the accounts.
	int AccountNumber;
	double balance,
		MonthlyInterest;
	double Penalty = 0,
		PenaltyThreshold = 0;
public:
	/* Constructor that sets the initial balance of the account. The Number of
	* Accounts is updated and current Accounts Number is set.
	* Param: double initialBalance
	*/
	Account(double initialBalance);

	/* Retrieves the account number.
	* Return: int AccountNumber
	*/
	int getAccountNumber() const
	{	return this->AccountNumber;	}

	/* Retrieve the current accounts balance.
	* Return: double balance
	*/
	double getBalance() const
	{	return this->balance;	}

	/* Adds the amount deposited to the balance total.
	* Param: double amount
	*/
	void deposit(double amount)
	{
		balance += amount;
	}

	/* Withdraws the amount deposited from the balance total.
	* Param: double amount
	*/
	virtual void withdraw(double amount)
	{
		balance -= amount;
	}

	// If I have time, overload the +,-,= operators;


	// Default Destructor
	~Account();
};
}
#endif // !ACCOUNT_H
