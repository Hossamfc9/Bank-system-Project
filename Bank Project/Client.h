#include"Person.h"
#include"Utility.h"
#include<fstream>
#include<string>

using namespace std;

#pragma once
class clsClient : public clsPerson
{
	string AccountNumber;
	string PinCode;
	double Balance = 0;
	static double TotalBalance;
protected:
	enum enMode { Empty = 0, Active = 1 };
	enMode Mode = (enMode)Empty;

	static clsClient EmptyClient()
	{
		clsClient Client(Empty, "", "", "", "", "", "", 0);
		return Client;
	}


	static bool IsEmpty(clsClient Client)
	{
		return (Client.Mode == 0);
	}

public:

	clsClient() {
		TotalBalance += Balance;
	}

	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		TotalBalance += Balance;
		this->Mode = Mode;
		this->AccountNumber = AccountNumber;
		this->PinCode = PinCode;
		this->Balance = Balance;
	}

	string GetAccountNumber()
	{
		return AccountNumber;
	}

	string GetPinCode()
	{
		return PinCode;
	}

	void SetPinCode(string PinCode)
	{
		this->PinCode = PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	double GetBalance()
	{
		return Balance;
	}

	void SetBalance(double Balance)
	{
		this->Balance = Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance)) double Balance;

	void Deposit(double Balance)
	{
		this->Balance += Balance;
	}

	bool WithDraw(double Balance)
	{
		if (this->Balance < Balance)
		{
			return false;
		}
		this->Balance -= Balance;
		return true;
	}

	static double GetToalBalance()
	{
		return TotalBalance;
	}

	void Print()
	{
		cout << "--------------------\n";
		cout << "\tClient\n";
		cout << "--------------------\n";
		cout << "FirstName: " << FirstName << '\n';
		cout << "LastName: " << LastName << '\n';
		cout << "Email: " << Email << '\n';
		cout << "Phone: " << Phone << '\n';
		cout << "AccountNumber: " << AccountNumber << '\n';
		cout << "Balance: " << Balance << '\n';
		cout << "--------------------\n";
	}
};

double clsClient::TotalBalance = 0;
