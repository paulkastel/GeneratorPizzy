#include"pizza.h"
#include"ciasto.h"
#include"wege.h"
#include"mieso.h"
#include"rachunek.h"
#include"string"
#include"dodatki.h"
#include"global.h"
#include<iostream>
using namespace std;

Pizza::Pizza(){}
Pizza::~Pizza(){}

void Pizza::tworzenie()
{
	cout<<"Bedzie robiona pizza: "<<this->nazwa<<endl<<endl;

	Ciasto aktualna_pizza;
	aktualna_pizza.nadaj_ksztalt();

	Wege zielone;
	if(aktualna_pizza.srednica<=30)
		zielone.ilosc=2;
	else if(aktualna_pizza.srednica<=45)
		zielone.ilosc=4;
	else if(aktualna_pizza.srednica<=60)
		zielone.ilosc=5;
	else
		zielone.ilosc=6;

	cout<<"\nWARZYWA!"<<endl;
	zielone.skladnikinaciasto(zielone.ilosc);

	cout<<"\nMIESO!"<<endl;
	Mieso czerwone;
	czerwone.ilosc=zielone.ilosc;
	czerwone.skladnikinaciasto(czerwone.ilosc);

	Pizza A;
	this->il=A.il=zielone.ilosc+czerwone.ilosc;
	A.nazwa=this->nazwa;
	this->zawartosc=A(zielone, czerwone);

	cout<<"\nWszystkie skladniki na pizzy:\n";
	for(int i=0; i<this->il; i++)
		cout<<this->zawartosc[i]<<"   ";
	cout<<endl;

	Dodatki dodatek;
	dodatek.dorzuc_do_zamowienia();

	Rachunek znizka;
	A.cena_pizzy=znizka.wystaw_rachunek(aktualna_pizza, A, dodatek);

	cout<<A;

	zaplac(A.cena_pizzy);
}

string *Pizza::operator()(Wege warzywka, Mieso miesko)
{
	il=warzywka.ilosc+miesko.ilosc;
	int licznik=warzywka.ilosc;
	zawartosc=new string[il];

	for(int i=0; i<warzywka.ilosc; i++)
		zawartosc[i]=warzywka.skladniki[i];

	for(int i=0; i<miesko.ilosc; i++, licznik++)
		zawartosc[licznik]=miesko.skladniki[i];

	return zawartosc;
}

ostream& operator<<(ostream &ekran, Pizza danie)
{
	cout<<"\nNazwa pizzy: "<<danie.nazwa<<endl;
	cout<<"Cena pizzy: "<<danie.cena_pizzy<<endl;
	cout<<"Skladniki: ";
	for(int i=0; i<danie.il; i++)
		cout<<danie.zawartosc[i]<<" ";
	cout<<endl;
	return ekran;
}
