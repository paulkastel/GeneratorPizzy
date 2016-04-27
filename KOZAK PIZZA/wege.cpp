#include"wege.h"
#include"bledy.h"
#include<iostream>
#include<string>
using namespace std;

Wege::Wege(){}
Wege::~Wege(){}

const int warzywkail = Wege::END;

string Wege::tekstenum(int valenum)
{
	switch(valenum)
	{
	case Wege::kukurydza:
		return "kukurydza";
		break;
	case Wege::salata:
		return "salata";
		break;
	case Wege::ser:
		return "ser";
		break;
	case Wege::ananas:
		return "ananas";
		break;
	case Wege::pomidor:
		return "pomidor";
		break;
	case Wege::papryka:
		return "papryka";
		break;
	case Wege::oliwki:
		return "oliwki";
		break;
	case Wege::cebula:
		return "cebula";
		break;
	case Wege::brokuly:
		return "brokuly";
		break;
	case Wege::fasola:
		return "fasola";
		break;
	default:
		return "Brak skladnika!\n";
	}
}

string Wege::skladnikinaciasto(int ilosc)
{
	cout<<"Oto dostepne skladniki: "<<endl;
	for(int i=0; i<warzywkail; i++)
		cout<<i+1<<". "<<tekstenum(i)<<endl;

	Wege::skladniki=new string[this->Wege::ilosc];

	for (int i=0; i<ilosc; i++)
	{
		cout<<"Podaj numery skladnikow ktore maja byc na pizzy: ";
		int x;
		while(!(cin>>x))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		}
		if(x>warzywkail || x<1)
		{
			cout<<"\nBrak takiego skladnika! Sprobuj raz jeszcze!";
			i--;
		}
		else
		{
			cout<<"Dodano: "<<tekstenum(x-1)<<". ";
			Wege::skladniki[i]=tekstenum(x-1);
			cout<<"Zostalo ci jeszcze: "<<ilosc-i-1<<" skladnikow do dodania!\n";
		}
	}		

	cout<<"\nTo twoje warzywne skladniki:\n";
	for (int i=0; i<ilosc; i++)
		cout<<Wege::skladniki[i]<<" ";
	cout<<"\nCzy chcesz cos zmienic? T/N ";
	char zgoda;
	cin>>zgoda;
	if( zgoda == 't'  || zgoda == 'T')
	{
		cout<<"\nKtory skladnik chcesz zmienic? "<<endl;
		for (int i=0; i<ilosc; i++)
			cout<<i+1<<". "<<Wege::skladniki[i]<<"\n";
		cout<<"Podaj numer: ";
		int x, y;
		while(!(cin>>x))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		}
		cout<<"\nKtory skladnik chcesz zamiast "<<Wege::skladniki[x-1]<<"?\n";
		for(int i=0; i<warzywkail; i++)
			cout<<i+1<<". "<<tekstenum(i)<<endl;
		cout<<"Podaj numer: ";
		while(!(cin>>y))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		}
		while(y>warzywkail || y<1)
		{
			cout<<"Brak takiego skladnika! Sprobuj raz jeszcze: ";
			while(!(cin>>y))
			{
				cout<<"\nMusisz podac liczbe! ";
				cin.clear();
				cin.sync();
			}
		}
		cout<<"\nZamieniono "<<Wege::skladniki[x-1]<<" na "<<tekstenum(y-1)<<"!\n";
		Wege::skladniki[x-1]=tekstenum(y-1);
	}
	return *skladniki;
}
