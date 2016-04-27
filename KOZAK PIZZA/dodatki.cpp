#include"dodatki.h"
#include<iostream>
using namespace std;

Dodatki::Dodatki(){}
Dodatki::~Dodatki(){}

const int napil = Dodatki::napoje::ENDD;
const int sosil = Dodatki::sos::END;

string Dodatki::tekstenum(int valenum)
{
	switch(valenum)
	{
	case Dodatki::sos::ostry:
		return "ostry";
		break;
	case Dodatki::sos::mieszany:
		return "mieszany";
		break;
	case Dodatki::sos::grillowy:
		return "barbecue";
		break;
	case Dodatki::sos::czosnkowy:
		return "czosnkowy";
		break;
	case Dodatki::sos::musztarda:
		return "musztarda";
		break;
	case Dodatki::sos::majonez:
		return "majonez";
		break;
	case Dodatki::sos::lagodny:
		return "lagodny";
		break;
	case Dodatki::sos::keczup:
		return "keczup";
		break;
	}
}

string Dodatki::napenum(int valenum)
{
	switch(valenum)
	{
	case Dodatki::napoje::pepsi:
		return "Pepsi";
		break;
	case Dodatki::napoje::cola:
		return "Coca-Cola";
		break;
	case Dodatki::napoje::kawa:
		return "Kawa";
		break;
	case Dodatki::napoje::herbata:
		return "Herbata";
		break;
	case Dodatki::napoje::woda:
		return "Woda";
		break;
	case Dodatki::napoje::piwko:
		return "Piwo";
		break;
	case Dodatki::napoje::wodeczka:
		return "Wodka";
		break;
	case Dodatki::napoje::lycha:
		return "Whisky";
		break;
	}
}

void Dodatki::dorzuc_do_zamowienia()
{
	cout<<"\nCzy chcesz zamowic dodatkowy sos? T/N ";
	char zgoda;
	int x;
	bool sukces=0;
	cin>>zgoda;
	if(zgoda == 'T' || zgoda == 't')
	{
		cout<<"Oto dostepne sosy: "<<endl;
		for(int i=0; i<sosil; i++)
			cout<<i+1<<". "<<tekstenum(i)<<endl;

		while(sukces == 0)
		{
			cout<<"Podaj numer sosu: ";

			while(!(cin>>x))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
			if(x>sosil || x<1)
			{
				cout<<"Nie ma takiego sosu w ofercie! Sproboj ponownie: ";
				sukces =0;
			}
			else
			{
				this->Dodatki::extra_sos=tekstenum(x-1);
				cout<<"Zamowiono: "<<extra_sos<<endl;
				sukces=1;
			}
		}
	}

	sukces=0;
	cout<<"\nCzy chcesz zamowic dodatkowy napoj? T/N ";
	cin>>zgoda;
	if(zgoda == 'T' || zgoda == 't')
	{
		cout<<"Oto napoje w ofercie: "<<endl;
		for(int i=0; i<napil; i++)
			cout<<i+1<<". "<<napenum(i)<<endl;
		while(sukces == 0)
		{
			cout<<"Podaj numer napoju: ";
			while(!(cin>>x))
			{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
			if(x>sosil || x<1)
			{
				cout<<"Nie ma takiego napoju w ofercie! Sproboj ponownie: ";
				sukces =0;
			}
			else
			{
				if (napenum(x-1)=="Piwo" || napenum(x-1)=="Wodka" || napenum(x-1)=="Whisky")
				{
					cout<<"Czy masz 18 lat? T/N ";
					cin>>zgoda;
					if(zgoda=='t' || zgoda=='T')
					{
						this->Dodatki::extra_napitka=napenum(x-1);
						cout<<"Zamowiono: "<<extra_napitka<<endl;
						sukces=1;
					}
					else
					{
						cout<<"Nieletnim alkoholu nie sprzedajemy! ";
						this->Dodatki::extra_napitka=napenum(4);
						cout<<"Zamowiono: "<<extra_napitka<<endl;
						sukces=1;
					}
				}
				else
				{
					this->Dodatki::extra_napitka=napenum(x-1);
					cout<<"Zamowiono: "<<extra_napitka<<endl;
					sukces=1;
				}
			}
		}
	}
}
