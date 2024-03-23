/*
* This is a Utility Library used for the Bank System projct
* This Library contains tools that would be helpful in the project.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

#pragma once
class clsUtility
{
public:
	enum enCharType {
		UpperCase = 0, LowerCase = 1,
		Number = 2, Mix = 3,
		SpecialChar = 4
	};


	static void SeedRand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To) {
		int RandomNo = rand() % (To - From + 1) + From;
		return RandomNo;
	}

	static char RandomCharacter(enCharType Type) {
		if (Type == enCharType::Mix) {
			Type = (enCharType)RandomNumber(0, 2);
		}

		char RandomChar;

		switch (Type) {
		case enCharType::LowerCase:
		{
			RandomChar = RandomNumber('a', 'z');
			break;
		}

		case enCharType::UpperCase:
		{
			RandomChar = RandomNumber('A', 'Z');
			break;
		}

		case enCharType::Number:
		{
			RandomChar = RandomNumber('0', '9');
			break;
		}

		case enCharType::SpecialChar:
		{
			RandomChar = RandomNumber('!', '.');
			break;
		}

		default:
		{
			RandomChar = RandomNumber('A', 'Z');
			break;
		}
		}

		return RandomChar;
	}

	static char RandomCharacter() {
		enCharType Type = (enCharType)RandomNumber(0, 4);
		return RandomCharacter(Type);
	}

	static string GenerateWord(enCharType Type, int Length) {
		string Word = "";
		for (int Character = 0; Character < Length; Character++)
		{
			Word += RandomCharacter(Type);
		}
		return Word;
	}

	static string GenerateWord(int Length)
	{
		enCharType CharactersType = (enCharType)RandomNumber(0, 1);
		string Word = GenerateWord(CharactersType, Length);
		return Word;
	}


	static string LowerString(string Text)
	{
		for (int i = 0; i < Text.size(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}

	//caesar cipher
	static string Encrypt(string Word, int EncryptionKey)
	{
		EncryptionKey %= 26;
		for (int idx = 0; idx < Word.size(); ++idx)
		{
			int Character;
			if (Word[idx] >= 'a' && Word[idx] <= 'z')
			{
				Character = Word[idx] - 'a';
				Character = (Character + EncryptionKey) % 26 + 'a';
				Word[idx] = (char)Character;
			}
			else if (Word[idx] >= 'A' && Word[idx] <= 'Z')
			{
				Character = Word[idx] - 'A';
				Character = (Character + EncryptionKey) % 26 + 'A';
				Word[idx] = (char)Character;
			}
			else if (Word[idx] >= '0' && Word[idx] <= '9')
			{
				Character = Word[idx] - '0';
				Character = (Character + EncryptionKey) % 10 + '0';
				Word[idx] = (char)Character;
			}
		}
		return Word;
	}
	static string Decrypt(string Word, int DecryptionKey)
	{
		DecryptionKey %= 26;
		for (int idx = 0; idx < Word.size(); ++idx)
		{
			int Character;
			if (Word[idx] >= 'a' && Word[idx] <= 'z')
			{
				Character = Word[idx] - 'a';
				Character = (Character - DecryptionKey) % 26 + 'a';
				Word[idx] = (char)Character;
			}
			else if (Word[idx] >= 'A' && Word[idx] <= 'Z')
			{
				Character = Word[idx] - 'A';
				Character = (Character - DecryptionKey) % 26 + 'A';
				Word[idx] = (char)Character;
			}
			else if (Word[idx] >= '0' && Word[idx] <= '9')
			{
				Character = Word[idx] - '0';
				Character = (Character - DecryptionKey) % 10 + '0';
				Word[idx] = (char)Character;
			}
		}
		return Word;
	}

	static int ReadInt()
	{
		int Number;
		cout << "Please enter a number: ";
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore((int)numeric_limits<streamsize>::max, '\n');
			cout << "\nInput is not valid, Please try again: ";
		}
		return Number;
	}

	template <typename T>
	static T ReadNumber()
	{
		T Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid number: \n";
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(int l, int r)
	{
		T Number = ReadNumber<T>();
		while (Number < l || Number > r)
		{
			cout << "Wrong, Please enter a number between" << l << "and " << r << '\n';
			Number = ReadNumber<T>();
		}
		return Number;
	}

	static string ReadText()
	{
		string Text;
		getline(cin >> ws, Text);
		return Text;
	}

	static vector<string> SplitString(string Line)
	{
		vector<string> Data;
		int position = (int)Line.find("/");
		while (position != string::npos)
		{
			Data.push_back(Line.substr(0, position));
			Line.erase(0, position + 1);
			position = Line.find("/");
		}
		if (!Line.empty())
		{
			Data.push_back(Line.substr(0, Line.size()));
		}
		return Data;
	}

	static void ScHeader(string Title, int Border, int TitlePosition)
	{
		cout << setw(Border) << left << ' ' << "_________________________________________\n";
		cout << setw(TitlePosition) << left << ' ' << Title << "\n";
		cout << setw(Border) << left << ' ' << "_________________________________________\n";
	}

};

