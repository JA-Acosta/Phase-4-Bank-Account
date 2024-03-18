
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

	Customer::~Customer()
	{
	}
}