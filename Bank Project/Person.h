#include<iostream>
#include<iomanip>
using namespace std;

#pragma once
class clsPerson
{
protected:
	string FirstName, LastName, Phone, Email;
public:
	clsPerson() {}
	clsPerson(string FirstName, string LastName, string Phone, string Email)
	{
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->Phone = Phone;
		this->Email = Email;
	}

	string GetFirstName()
	{
		return this->FirstName;
	}
	void SetFirstName(string FirstName)
	{
		this->FirstName = FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	string GetLastName()
	{
		return this->LastName;
	}
	void SetLastName(string LastName)
	{
		this->LastName = LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	string GetFullName()
	{
		return FirstName + ' ' + LastName;
	}

	string GetPhone() {
		return this->Phone;
	}
	void SetPhone(string Phone)
	{
		this->Phone = Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string GetEmail()
	{
		return this->Email;
	}
	void SetEmail(string Email)
	{
		this->Email = Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void Print()
	{
		cout << "----------------- Card -----------------";
		cout << "\nFull Name: " << FirstName << ' ' << LastName << endl;
		cout << "Email: " << Email << endl;
		cout << "Phone Number: " << Phone << endl;
		cout << "----------------------------------------";
	}
};

