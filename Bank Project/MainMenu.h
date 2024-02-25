#include <iostream>
#include "Data.h"
#include <iomanip>
#include "Utility.h"
//#include"LogIn.h"

using namespace std;

#pragma once

class clsTransactions
{
	enum enTransactionsOP
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalance = 3,
		eExit = 4
	};

	static enTransactionsOP ReadTransactionsOP()
	{
		cout << setw(25) << left << ' ' << "Please choose an option [1/4]: ";
		int Choice = clsUtility::ReadNumberBetween<int>(1, 4);
		return (enTransactionsOP)Choice;
	}

	static void ScDeposit()
	{
		clsUtility::ScHeader("Deposit", 20, 34);
		clsClientsData::Deposit();
	}

	static void ScWithdraw()
	{
		clsUtility::ScHeader("WithDraw", 20, 34);
		clsClientsData::Withdraw();
	}

	static void ScTotalBalance()
	{
		clsUtility::ScHeader("Total Balance", 20, 34);
		clsClientsData::PrintAllClients();
		cout << "\nTotal Balance is: " << clsClient::GetToalBalance();
	}

public:

	static void TransactionsMenuScreen(int Permissions)
	{
		while (true)
		{
			system("cls");

			clsUtility::ScHeader("Transactions", 20, 34);

			cout << setw(35) << left << ' ' << "1. Deposit\n";
			cout << setw(35) << left << ' ' << "2. Withdraw\n";
			cout << setw(35) << left << ' ' << "3. Total Balance\n";
			cout << setw(35) << left << ' ' << "4. Exit\n";
			cout << setw(20) << left << ' ' << "_________________________________________\n\n";
			enTransactionsOP Option = ReadTransactionsOP();
			switch (Option)
			{
			case eDeposit:
				system("cls");
				ScDeposit();
				break;

			case eWithdraw:
				system("cls");
				ScWithdraw();
				break;

			case eTotalBalance:
				if (Permissions == 0)
				{
					cout << setw(20) << left << ' ' << "You are not allowed to view Total Balance\n";
					system("pause>0");
					break;
				}
				system("cls");
				ScTotalBalance();
				break;

			case eExit:
				return;
			}
		}

	}

};

class clsMainMenu : public clsClientsData
{
	enum enMainMenuOP {
		eShowClientsList = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLogout = 8
	};

	static enMainMenuOP ReadMainMenuOP()
	{
		cout << setw(33) << left << ' ' << "Please choose an option [1/8]: ";
		int Choice = clsUtility::ReadNumberBetween<int>(1, 8);
		return (enMainMenuOP)Choice;
	}

	static void	ScShowClientsList()
	{
		clsUtility::ScHeader("Clients List", 27, 43);
		PrintAllClients();
	}

	static void ScAddNewClient()
	{
		clsUtility::ScHeader("New Client", 27, 43);
		AddNewClient();
	}

	static void ScDeleteClient()
	{
		clsUtility::ScHeader("Delete Client", 27, 43);
		DeleteClient();
	}

	static void ScUpdateClient()
	{
		clsUtility::ScHeader("Update Client", 27, 43);
		UpdateClient();
	}

	static void ScFindClient()
	{
		clsUtility::ScHeader("Find Client", 27, 43);
		FindClient();
	}

	static void ScTransactions()
	{
		clsTransactions::TransactionsMenuScreen(1);
	}

	/*static void ScManageUsers()
	{

	}*/

	//static void ScLogout()
	//{

	//}

public:

	static void MainMenuScreen()
	{
		while (true)
		{
			system("cls");

			clsUtility::ScHeader("Admin Screen", 27, 43);
			cout << setw(37) << left << ' ' << " 1. Show Clients List\n";
			cout << setw(37) << left << ' ' << " 2. Add New Client\n";
			cout << setw(37) << left << ' ' << " 3. Delete Client\n";
			cout << setw(37) << left << ' ' << " 4. Update Client\n";
			cout << setw(37) << left << ' ' << " 5. Find Client\n";
			cout << setw(37) << left << ' ' << " 6. Transactions\n";
			//cout << setw(37) << left << ' ' << " 7. Manage Users\n";
			cout << setw(37) << left << ' ' << " 8. Logout\n";
			cout << setw(27) << left << ' ' << "_________________________________________\n\n";
			enMainMenuOP Option = ReadMainMenuOP();
			system("cls");
			switch (Option)
			{
			case eShowClientsList:
				ScShowClientsList();
				break;

			case eAddNewClient:
				ScAddNewClient();
				break;

			case eDeleteClient:
				ScDeleteClient();
				break;

			case eUpdateClient:
				ScUpdateClient();
				break;

			case eFindClient:
				ScFindClient();
				break;

			case eTransactions:
				ScTransactions();
				break;

				/*case eManageUsers:
					ScManageUsers();*/

			case eLogout:
				return;

			}
			cout << "press any key to go back to admin menu";
			system("pause>0");
		}
	}
};
