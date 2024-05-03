#include<iostream>
#include"Utility.h"
#include"MainMenu.h"
#include"Client.h"
#include"Data.h"

#pragma once

class clsClientLogIn
{
	enum enClientOP
	{
		Transactions = 1, ClientInfo = 2,
		UpdateAccount = 3, DeleteAccount = 4, SignUp = 5, Exit = 6
	};

	static enClientOP ReadClientOP()
	{
		cout << setw(23) << left << ' ' << "Please choose an option[1/6] ";
		int Option = clsUtility::ReadNumberBetween<int>(1, 6);
		return (enClientOP)Option;
	}

public:
	static void ClientScreen()
	{
		while (true)
		{
			system("cls");
			clsUtility::ScHeader("Client Menu", 23, 42);

			cout << setw(30) << left << ' ' << "1. Transactions\n";
			cout << setw(30) << left << ' ' << "2. Client Info\n";
			cout << setw(30) << left << ' ' << "3. Update Account\n";
			cout << setw(30) << left << ' ' << "4. Delete Account\n";
			cout << setw(30) << left << ' ' << "5. Sign Up\n";
			cout << setw(30) << left << ' ' << "6. Exit\n";
			cout << setw(23) << left << ' ' << "_________________________________________\n";

			enClientOP Choice = ReadClientOP();
			switch (Choice)
			{
			case Transactions:
				clsTransactions::TransactionsMenuScreen(0);
				break;
			case ClientInfo:
				clsClientsData::FindClient();
				break;
			case UpdateAccount:
				clsClientsData::UpdateClient();
				break;
			case DeleteAccount:
				clsClientsData::DeleteClient();
				break;
			case SignUp:
				clsClientsData::AddNewClient();
				break;
			case Exit:
				return;
			}
			system("pause>0");
		}
	}
};

class clsAdminLogIn
{
	static string UserName, Password;

	static void AdminLogIn()
	{
		string _UserName, _Password;
		cout << setw(23) << left << ' ' << "Please enter user name: ";
		_UserName = clsUtility::ReadText();
		cout << setw(23) << left << ' ' << "Please enter password: ";
		_Password = clsUtility::ReadText();
		while (_UserName != UserName || _Password != Password)
		{
			cout << "Wrong user name or password, Please try again \n";
			cout << setw(23) << left << "Please enter user name: ";
			_UserName = clsUtility::ReadText();
			cout << setw(23) << left << "Please enter password: ";
			_Password = clsUtility::ReadText();
		}
	}

public:

	static void AdminScreen()
	{
		system("cls");
		AdminLogIn();
		clsMainMenu::MainMenuScreen();

	}
};

string clsAdminLogIn::UserName = "Admin";
string clsAdminLogIn::Password = "Admin";

class clsLogIn
{
	enum enModeOP
	{
		Admin = 1, Client = 2, Exit = 3
	};

	static enModeOP ReadModeOP()
	{
		cout << setw(23) << left << ' ' << "Please choose an option[1/3] ";
		int Option = clsUtility::ReadNumberBetween<int>(1, 3);
		return (enModeOP)Option;
	}

	static void BackToLogInScreen()
	{
		cout << '\n';
		cout << setw(30) << left << ' ' << "Press any key to go back";

		system("pause>0");
		Mode();
	}

public:
	static void Mode()
	{
		while (true)
		{
			system("cls");
			clsUtility::ScHeader("Welcome", 23, 40);

			cout << setw(30) << left << ' ' << "Please choose a mode\n";
			cout << setw(30) << left << ' ' << "1. Admin\n";
			cout << setw(30) << left << ' ' << "2. Client\n";
			cout << setw(30) << left << ' ' << "3. Exit\n";
			cout << setw(23) << left << ' ' << "_________________________________________\n";

			enModeOP Choice = ReadModeOP();
			switch (Choice)
			{
			case Admin:
				clsAdminLogIn::AdminScreen();
				break;
			case Client:
				clsClientLogIn::ClientScreen();
				break;
			case Exit:
				return;
				break;
			}
		}
	}
};