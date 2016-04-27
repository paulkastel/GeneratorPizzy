#include"rachunek.h"
#include"promocje.h"
#include<time.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

Rachunek::Rachunek(){}
Rachunek::~Rachunek(){}

double Rachunek::wystaw_rachunek(Ciasto placek, Pizza wszystko, Dodatki ekstrasy)
{
	if(placek.objetosc<=250)
		wszystko.cena_pizzy=25;
	else if(placek.objetosc<=500)
		wszystko.cena_pizzy=30;
	else if(placek.objetosc<=780)
		wszystko.cena_pizzy=35;
	else if(placek.objetosc<=1300)
		wszystko.cena_pizzy=40;
	else if(placek.objetosc<=2000)
		wszystko.cena_pizzy=60;
	else if(placek.objetosc>2000)
		wszystko.cena_pizzy=70;

	wszystko.cena_pizzy += wszystko.il;
	if(placek.ksztalt=="pieciokat" || placek.ksztalt=="szesciokat")
		wszystko.cena_pizzy *= (rand() % 4+2);

	fstream paragon;
	paragon.open("paragon.txt", ios::out);
	paragon<<"GENERATOR PIZZY C++\n"
		<<"ul. kompilator 1010\nNIP:0101001011\nPARAGON FISKALNY\n"
		<<__DATE__<<"\t"<<__TIME__
		<<"\n--------------------\n"<<wszystko.nazwa<<"\t"<<wszystko.cena_pizzy
		<<" PLN\n--------------------\n";
	
	if(ekstrasy.extra_napitka=="Whisky" || ekstrasy.extra_napitka=="Wodka")
	{
		paragon<<ekstrasy.extra_napitka<<"\t\t 50 PLN\n--------------------\n";
		wszystko.cena_pizzy += 50;
	}
	else if(!(ekstrasy.extra_napitka.empty()))
	{
		paragon<<ekstrasy.extra_napitka<<"\t\t 6 PLN\n--------------------\n";
		wszystko.cena_pizzy += 6;
	}

	if(!ekstrasy.extra_sos.empty())
	{
		paragon<<"sos "<<ekstrasy.extra_sos<<"\t  1 PLN\n--------------------\n";
		wszystko.cena_pizzy += 1;
	}

	cout<<"\nZAMOWIENIE: "<<wszystko.nazwa<<endl;
	placek.wypisz_parametry();
	cout<<"Skladniki: ";
	for(int i=0; i<wszystko.il; i++)
		cout<<wszystko.zawartosc[i]<<" ";
	if(!ekstrasy.extra_napitka.empty())
		cout<<"\nDo tego napoj: "<<ekstrasy.extra_napitka;
	if(!ekstrasy.extra_sos.empty())
		cout<<"\nSos: "<<ekstrasy.extra_sos;
	cout<<"\nCena do zaplaty: "<<wszystko.cena_pizzy<<" PLN"<<endl;

	Promocje znizka;
	double pom=wszystko.cena_pizzy;
	wszystko.cena_pizzy=znizka.obniz_rachunek(wszystko.cena_pizzy);
	double pom2=pom-wszystko.cena_pizzy;

	paragon<<"Znizka:\t\t-"<<pom2<<" PLN\n--------------------\n";
	paragon<<"RAZEM\t\t"<<wszystko.cena_pizzy<<" PLN";

	cout<<"\nPo obnizce do zaplaty masz:\t";
	cout<<wszystko.cena_pizzy<<" PLN\n\n";

	paragon.close();
	return wszystko.cena_pizzy;
}
