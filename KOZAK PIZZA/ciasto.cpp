#include"ciasto.h"
#include"global.h"
#include"bledy.h"
#include<iostream>
#include<cmath>
#include<time.h>
#include<string>
using namespace std;

Ciasto::Ciasto(){}
Ciasto::~Ciasto(){}

void Ciasto::wypisz_parametry()
{
	cout<<"\nZamowione ciasto ma nastepujace wymiary:"<<endl
		<<"KSZTALT:\t"<<this->ksztalt<<endl
		<<"SREDNICA:\t"<<this->srednica<<" [cm]"<<endl
		<<"GRUBOSC:\t"<<this->grubosc<<" [cm]"<<endl
		<<"OBWOD:  \t"<<this->obwod<<" [cm]"<<endl
		<<"POLE:   \t"<<this->pole<<" [cm2]"<<endl
		<<"OBJETOSC:\t"<<this->objetosc<<" [cm3]\n"<<endl;
}

void Ciasto::nadaj_ksztalt()
{
	bool jest=false;
	int const il_ksztaltow=7;
	string ksztalty[il_ksztaltow]
	={"kolo", "trojkat", "kwadrat", "romb", "prostokat", "pieciokat", "szesciokat" };
	
	
	cout<<"Wpisz (uzywajac tylko malych znakow) ksztalt w jakim ma byc pizza.";
	cout<<"\nDostepne ksztalty: "<<endl;
	for(int i=0; i<il_ksztaltow; i++)
		cout<<i+1<<". "<<ksztalty[i]<<endl;

	cout<<"Wpisz: ";
	cin>>this->ksztalt;

	for(int i=0; i<il_ksztaltow; i++)
	{
		if(this->ksztalt == ksztalty[i])
		{
			jest=true;
			nadaj_rozmiar(i);
			break;
		}	
	}

	if(!jest)
	{
		cout<<"Kucharz nie potrafi ulepic takiego ksztaltu!\n"
			<<"Probojemy raz jeszcze? T/N ";

		char zgoda;
		cin>>zgoda;

		if( zgoda == 't'  || zgoda == 'T')
			nadaj_ksztalt();
		else
		{
			Bledy wyjatek;
			throw wyjatek;
		}
	}
}

void Ciasto::nadaj_rozmiar(int licz)
{
	srand(time(0));
	int wybor=1;
	Bledy wyjatek;
	while(wybor != 0)
	{	
		cout<<"\nWybierz grubosc ciasta:\n"
			<<"\t1. Cienkie:\t0.3 [cm]\n"
			<<"\t2. Grube:\t0.7 [cm]\n"
			<<"\t3. Custom:\t x  [cm]\n"
			<<"\t4. Los kucharza: random [cm]\n"
			<<"\t0. Rozmyslilem sie!\nPodaj numer: ";
		cin>>wybor;
		switch(wybor)
		{
		case 0:
			throw wyjatek;
			break;
		case 1:
			this->grubosc=0.3;
			break;
		case 2:
			this->grubosc=0.7;
			break;
		case 3:
			cout<<"Wpisz grubosc ciasta w [cm]: ";
			cin>>this->grubosc;
			if(this->grubosc<=0)
				cout<<"\nBadz powazny i nie zawracaj kucharzowi glowy!\n";
			break;
		case 4:
			this->grubosc=(rand() % 13+1)*0.1;
			cout<<"Kucharz wymyslil ze grubosc bedzie miala: "<<this->grubosc<<" [cm]\n\n";
			break;
		default:
			cout<<"\nBrak takiej opcji! Wybierz raz jeszcze!"<<endl;
			break;
		}
		if(wybor > 0 && wybor < 5 && grubosc>0)
			break;
	}

	while(wybor != 0)
	{

		cout<<"\n\tWybierz rozmiar:\n"
			<<"\t1. Mala:\t30 [cm]\n"
			<<"\t2. Medium:\t45 [cm]\n"
			<<"\t3. Gigant:\t60 [cm]\n"
			<<"\t4. Los kucharza: random [cm]\n"
			<<"\t5. Custom:\t x [cm]\n"			
			<<"\t0. Rozmyslilem sie!\nPodaj numer: ";
		cin>>wybor;

		switch(wybor)
		{
		case 0:
			throw wyjatek;
			break;
		case 1: 
			majca(licz, 30);
			break;
		case 2:
			majca(licz, 45);
			break;
		case 3:
			majca(licz, 60);
			break;
		case 4:
			this->srednica=rand() % 87+15;
			cout<<"Kucharz wymyslil ze srednica bedzie miala: "<<this->srednica<<" [cm]\n";
			majca(licz, this->srednica);
			break;
		case 5:
			cout<<"Podaj srednice (podstawe figury) pizzy: ";
			cin>>this->srednica;
			if(this->srednica <=0)
				cout<<"\nBadz powazny i nie zawracaj kucharzowi glowy!\n";
			else
				majca(licz, this->srednica);
			break;
		default:
			cout<<"\nBrak takiej opcji! Wybierz raz jeszcze\n";
			break;
		}
		if(wybor > 0 && wybor < 6 && srednica>0)
			break;
	}
}

void Ciasto::majca(int licz, double wymiar)
{
	this->srednica=wymiar;
	double const pi=3.14159265;
	double h;

	switch(licz)
	{
	case 0: //kolo
		this->pole=(pow((wymiar/2), 2)*pi);
		this->objetosc=pole*(grubosc);
		this->obwod=2*pi*(wymiar/2);
		break;
	case 1: //trojkat
		this->pole=(pow(wymiar, 2)*sqrt(3.0))/4;
		this->obwod=3*wymiar;
		this->objetosc=pole*grubosc;
		break;
	case 2: //kwadrat
		this->pole=pow(wymiar,2);
		this->objetosc=pole*grubosc;
		this->obwod=4*wymiar;
		break;
	case 3: //romb
		cout<<"Podaj sinus "<<this->ksztalt<<"u : ";
		while(!(cin>>h))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
		h=sin((h*pi)/180);
		this->pole=pow(wymiar, 2)*h;
		this->objetosc=pole*grubosc;
		this->obwod=4*wymiar;
		break;
	case 4: //prostokat
		cout<<"Podaj drugi bok prostokatu: ";
		while(!(cin>>h))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
		this->pole=wymiar*h;
		this->obwod=2*(wymiar+h);
		this->objetosc=pole*grubosc;
		break;
	case 5: //pieciokat
		this->pole=((5*pow(wymiar, 2))/4)*(1/tan((36*pi)/180));
		this->obwod=5*wymiar;
		this->objetosc=pole*grubosc;
		break;
	case 6: //szeciokat
		this->pole=(3*pow(wymiar, 2)*sqrt(3.0))/2;
		this->obwod=6*wymiar;
		this->objetosc=pole*grubosc;
		break;
	}
	//wypisz_parametry();
}
