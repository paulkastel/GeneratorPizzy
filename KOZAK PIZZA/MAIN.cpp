#include"global.h"
#include"bledy.h"
#include<string>
#include<fstream>
#include<time.h>
#include<iostream>
#include<Windows.h>
using namespace std;

//====================================================================
int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout<<"WITAJ W KOZACKIM GENERATORZE PIZZY!\n###################################"<<endl;
	
	int wybor=1;
	try
	{
		menuglowne(wybor);
	}
	catch(Bledy wyjatek)
	{
		wyjatek.komunikat="ZAMOWIENIE ANULOWANO!";
		cout<<wyjatek.komunikat<<endl;
		menuglowne(1);
	}

	cout<<endl;
	system("pause");
}