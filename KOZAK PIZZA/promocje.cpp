#include"promocje.h"
#include<iostream>
using namespace std;

Promocje::Promocje(){}
Promocje::~Promocje(){}

double Promocje::obniz_rachunek(double dozaplaty)
{
	int wybor;
	cout<<"\nWybierz znizke (promocje nie lacza sie):\n"
		<<"1. Wpisz haslo znizkowe\n2. Jestem studentem AGH\n"
		<<"3. Przy zakupach powyzej 100 zl dostajesz 30%\nWybierz numer: ";
	while(!(cin>>wybor))
	{
		cout<<"\nMusisz podac liczbe! ";
		cin.clear();
		cin.sync();
	}
	switch(wybor)
	{
	case 1:
		{
			string proba;
			this->na_haslo="RABAT";
			cin>>proba;
			if(proba==na_haslo)
			{
				cout<<"Dostales znizke 10%!\n";
				return dozaplaty*0.9;
			}
			else
			{
				cout<<"Nie dostales znizki!\n";
				return dozaplaty;
			}
			break;
		}
	case 2:
		cout<<"Z racji tego zaszczytu dostajesz -10 PLN\n";
		this->studencka=10;
		return dozaplaty-studencka;
		break;
	case 3:
		if(dozaplaty>=100)
		{
			cout<<"Poniewaz tyle wydales dostajesz -30%\n";
			return dozaplaty*0.7;
		}
		else
		{
			cout<<"Poniewaz chciales oszukac, cena zostaje zwiekszona o 30%!!\n";
			return dozaplaty*1.3;
		}
		break;
	default:
		cout<<"Nie skorzystales z zadnej znizki!";
		return dozaplaty;
		break;
	}
}
