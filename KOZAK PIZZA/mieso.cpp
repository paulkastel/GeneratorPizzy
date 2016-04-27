#include"mieso.h"
#include<iostream>
#include<string>
using namespace std;

Mieso::Mieso(){}
Mieso::~Mieso(){}

const int miesoil = Mieso::END;

string Mieso::tekstenum(int valenum)
{
	switch(valenum)
	{
	case Mieso::szynka:
		return "szynka";
		break;
	case Mieso::wolowina:
		return "wolowina";
		break;
	case Mieso::kurczak:
		return "kurczak";
		break;
	case Mieso::bekon:
		return "bekon";
		break;
	case Mieso::salami:
		return "salami";
		break;
	case Mieso::kielbasa:
		return "kielbasa";
		break;
	case Mieso::kabanos:
		return "kabanos";
		break;
	default:
		return "Brak skladnika!\n";
	}
}

string Mieso::skladnikinaciasto(int ilosc)
{
	cout<<"Oto dostepne skladniki: "<<endl;
	for(int i=0; i<miesoil; i++)
		cout<<i+1<<". "<<tekstenum(i)<<endl;

	Mieso::skladniki=new string[this->Mieso::ilosc];

	for (int i=0; i<ilosc; i++)
	{
		cout<<"Podaj numery skladnikow ktore maja byc na pizzy: ";
		int x;
		while(!(cin>>x))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};

		if(x>miesoil || x<1)
		{
			cout<<"Brak takiego skladnika! Sprobuj raz jeszcze!";
			i--;
		}
		else
		{
			cout<<"Dodano: "<<tekstenum(x-1)<<". ";
			Mieso::skladniki[i]=tekstenum(x-1);
			cout<<"Zostalo ci jeszcze: "<<ilosc-i<<" skladnikow do dodania!\n";
		}
	}

	cout<<"\nTo twoje miesne skladniki:\n";
	for (int i=0; i<ilosc; i++)
		cout<<Mieso::skladniki[i]<<" ";
	cout<<"\nCzy chcesz cos zmienic? T/N ";
	char zgoda;
	cin>>zgoda;
	if( zgoda == 't'  || zgoda == 'T')
	{
		cout<<"\nKtory skladnik chcesz zmienic? "<<endl;
		for (int i=0; i<ilosc; i++)
			cout<<i+1<<". "<<Mieso::skladniki[i]<<"\n";
		cout<<"Podaj numer: ";
		int x, y;
		while(!(cin>>x))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		}
		cout<<"\nKtory skladnik chcesz zamiast "<<Mieso::skladniki[x-1]<<"?\n";
		for(int i=0; i<miesoil; i++)
			cout<<i+1<<". "<<tekstenum(i)<<endl;
		cout<<"Podaj numer: ";
		while(!(cin>>y))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
		while(y>miesoil || y<1)
		{
			cout<<"\nBrak takiego skladnika! Sprobuj raz jeszcze: ";
			while(!(cin>>y))
			{
				cout<<"\nMusisz podac liczbe! ";
				cin.clear();
				cin.sync();
			}
		}
		cout<<"\nZamieniono "<<Mieso::skladniki[x-1]<<" na "<<tekstenum(y-1)<<"!";
		Mieso::skladniki[x-1]=tekstenum(y-1);
	}
	return *skladniki;
}
