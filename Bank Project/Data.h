#include <unordered_map>
#include "Person.h"
#include "Client.h"
#include "Utility.h"

#pragma once
class clsClientsData : public clsClient, public clsUtility
{
private:

	static unordered_map<string, clsClient> ClientsData;
	static clsClient* ClientPass()
	{
		string AccountNumber, PinCode;
		cout << "\nPlease Enter your Account Number: ";
		AccountNumber = clsUtility::ReadText();
		cout << "\nPlease Enter your PinCode: ";
		PinCode = clsUtility::ReadText();
		clsClient FindObject = FindClient(AccountNumber, PinCode);
		while (IsEmpty(FindObject))
		{
			cout << "\nWrong Accout Number or PinCode, Try Again\n\n";
			cout << "Please Enter your Account Number: ";
			AccountNumber = clsUtility::ReadText();
			cout << "\nPlease Enter your PinCode: ";
			PinCode = clsUtility::ReadText();
			FindObject = FindClient(AccountNumber, PinCode);
		}
		clsClient* Client = &ClientsData[FindObject.GetAccountNumber()];
		Client->Print();
		return Client;
	}

	static string ReadClientData()
	{
		vector<string> RequiredInput{ "first name: ", "last name: ", "email: ", "phone: ", "PinCode: " };
		vector<string> ClientInput(5);
		string Input = "", Line = "";
		for (int i = 0; i < 5; ++i)
		{
			cout << "\nPlease enter your " << RequiredInput[i];
			Input = clsUtility::ReadText();
			Line += Input + '/';
		}
		Line.pop_back();
		return Line;
	}

	static clsClient ConvertDataToClient(string Line)
	{
		vector<string> ClientData;
		ClientData = clsUtility::SplitString(Line);
		clsClient Client((enMode)1, ClientData[0], ClientData[1], ClientData[3], ClientData[2], ClientData[4], ClientData[5], stod(ClientData[6]));
		return Client;
	}

	//for saving clientsdata at files
	static string ConvertClientToLine(clsClient Client)
	{
		string Line;
		Line += Client.GetFirstName() + '/';
		Line += Client.GetLastName() + '/';
		Line += Client.GetEmail() + '/';
		Line += Client.GetPhone() + '/';
		Line += Client.GetAccountNumber() + '/';
		Line += Client.GetPinCode() + '/';
		Line += to_string(Client.GetBalance());
		return Line;
	}

	static void WriteClientsData()
	{
		ofstream File("./TextFiles/Clients.txt", ios::out);
		if (File.is_open())
		{
			for (auto& it : ClientsData)
			{
				if (IsEmpty(it.second))
				{
					continue;
				}
				string Line = ConvertClientToLine(it.second);
				File << Line << endl;
			}
		}
		File.close();
	}



public:

	static void UpdateClient()
	{
		clsClient& Client = *ClientPass();
		vector<string> NewData(5);
		NewData = clsUtility::SplitString(ReadClientData());
		Client.SetFirstName(NewData[0]);
		Client.SetLastName(NewData[1]);
		Client.SetEmail(NewData[2]);
		Client.SetPhone(NewData[3]);
		Client.SetPinCode(NewData[4]);
		WriteClientsData();
		Client.Print();
		cout << '\n' << "Client Updated Successfully.";
	}

	static void AddNewClient()
	{
		string AccountNumber = "";
		do
		{
			AccountNumber = GenerateWord((enCharType)3, 4);
		} while (!IsEmpty(ClientsData[AccountNumber]));
		vector<string> NewData(5);
		NewData = clsUtility::SplitString(ReadClientData());
		clsClient Client((enMode)1, NewData[0], NewData[1], NewData[3], NewData[2], AccountNumber, NewData[4], 0.0);
		ofstream File("./TextFiles/Clients.txt", ios::app);
		File << ConvertClientToLine(Client) << endl;
		ClientsData[AccountNumber] = Client;
		Client.Print();
	}

	static void DeleteClient()
	{
		clsClient& Client = *ClientPass();
		cout << "\n Are you sure you want to delete your account? yes/no: ";
		string Choice = LowerString(clsUtility::ReadText());
		while (Choice != "yes" && Choice != "no")
		{
			cout << "Invalid Input please enter yes/no: ";
			Choice = LowerString(clsUtility::ReadText());
		}
		if (Choice == "no")
		{
			return;
		}
		Client = clsClient::EmptyClient();
		WriteClientsData();
	}

	static void FillData()
	{
		ifstream File("./TextFiles/Clients.txt", ios::in);
		string Line = "";
		if (File.is_open())
		{
			while (getline(File, Line))
			{
				if (Line == "")
				{
					continue;
				}
				clsClient Client = clsClientsData::ConvertDataToClient(Line);
				ClientsData[Client.GetAccountNumber()] = Client;
			}
		}
		File.close();
	}

	static void FindClient()
	{
		clsClient& Client = *ClientPass();
	}

	static clsClient FindClient(string AccountNumber, string PinCode)
	{
		if (!IsEmpty(ClientsData[AccountNumber]) && ClientsData[AccountNumber].GetPinCode() == PinCode)
		{
			return ClientsData[AccountNumber];
		}
		else
		{
			return EmptyClient();
		}
	}

	static void Deposit()
	{
		clsClient& Client = *ClientPass();
		cout << "Please enter the deposit amount: ";
		double Amount = ReadNumber<double>();
		Client.Deposit(Amount);
		cout << "Your Balance is: " << Client.GetBalance();
		WriteClientsData();
		return;
	}

	static void Withdraw()
	{
		clsClient& Client = *ClientPass();
		cout << "Please enter withdraw amount: ";
		double Amount = ReadNumber<double>();
		while (!Client.WithDraw(Amount))
		{
			cout << "No enough balance, please try again: ";
			Amount = ReadNumber<double>();
		}
		cout << "Your Balance is: " << Client.GetBalance();
		WriteClientsData();
		return;
	}

	static void PrintAllClients()
	{
		cout << "\n_______________________________________________________________________________________________________________\n";
		cout << left << setw(77) << "| \t\t\t\t\tALL Clients";
		cout << " |";
		cout << "\n_______________________________________________________________________________________________________________\n";

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(30) << "Email";
		cout << "| " << left << setw(13) << "Phone";
		cout << "| " << left << setw(8) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << " |";
		cout << "\n_______________________________________________________________________________________________________________\n";

		for (auto& it : ClientsData)
		{
			if (IsEmpty(it.second))
			{
				continue;
			}
			cout << "| " << setw(15) << left << it.second.GetAccountNumber();
			cout << "| " << setw(20) << left << it.second.GetFullName();
			cout << "| " << setw(30) << left << it.second.GetEmail();
			cout << "| " << setw(13) << left << it.second.GetPhone();
			cout << "| " << setw(8) << left << it.second.GetPinCode();
			cout << "| " << setw(12) << left << it.second.GetBalance();
			cout << " |\n";
		}
		cout << "_______________________________________________________________________________________________________________\n";
	}

};

unordered_map<string, clsClient> clsClientsData::ClientsData;
