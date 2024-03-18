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

// Presents the menu of potential options for the user.
void menu();

int main()
{
	// menu();
	Checking acc1(50);
	Savings	acc2(35);
	cout << endl << acc1.getBalance() << endl << acc2.getBalance() << endl;
	acc1.withdraw(50);
	acc2.deposit(50);

	cout << endl << acc1.getBalance() << endl << acc2.getBalance() << endl;
	acc2.withdraw(20);
	cout << endl << acc1.getBalance() << endl << acc2.getBalance() << endl;

	cout << "ACC1: " << acc1.getAccountNumber() << endl;
	cout << "ACC2: " << acc2.getAccountNumber() << endl;

	

	

	// Need to put a try catch in the actual bank account.


	// Take an input and verify it.

	// Do the task associated with the input.
	return 0;
}


void menu()
{
	cout << "What would you like to do?" << endl
		<< "    1. Open an Account"
		"    2. View Account Information"
		"    3. Make a Deposit"
		"    4. Make a Withdraw";
}