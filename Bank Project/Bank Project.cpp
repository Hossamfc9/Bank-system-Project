#include"MainMenu.h"
#include"Utility.h"
#include"Person.h"
#include"Client.h"
#include"LogIn.h"
#include"Data.h"
#include <iostream>
#include<iterator>
#include<fstream>
#include<limits>

using namespace std;

int main()
{
	clsClientsData::FillData();
	clsLogIn::Mode();
}