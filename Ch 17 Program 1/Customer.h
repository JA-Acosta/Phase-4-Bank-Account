#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

namespace customer {
	using std::string;
	class Customer
	{

		// Used to determine the customer ID for each customer.
		static int Customers;
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
		* return string Full Name
		*/
		string getName() const
		{
			return this->Last + ", " + this->First;
		}

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

		~Customer();
	};
}
#endif // !CUSTOMER_H