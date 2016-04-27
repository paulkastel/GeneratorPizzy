#include"global.h"
#include"pizza.h"
#include"ciasto.h"
#include"bledy.h"
#include"dodatki.h"
#include"rachunek.h"

#include<iostream>
using namespace std;

void menuglowne(int wybor)
{
	while(wybor != 0 )
	{
		cout<<"\n1. Zakup gotowej pizzy!\n"
			<<"2. Stworz wlasna pizze!\n\n"
			<<"0. EXIT!\n"
			<<"\nWybierz odpowiednia opcje: ";
		while(!(cin>>wybor))
		{
			cout<<"Musisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
		switch(wybor)
		{
		case 0:
			cout<<"Dzieki za wizyte! Zapraszamy ponownie!";
			break;

		case 1:
			{
				int wybor_pi=1;
				while(wybor_pi != 0 )
				{
					cout<<"\tOto pizze w naszym asortymencie:\n"
						<<"\t1. Margherita\n\t2. Funghi\n"
						<<"\t3. Neapolitana\n\t4. Dipollo\n"
						<<"\t5. Pepperoni\n\t6. Hawajska\n"
						<<"\t7. Amore\n\t8. Diabelska\n"
						<<"\t9. Rafaello\n\n\t0. EXIT \n"
						<<"\nWybierz odpowiednia opcje: ";

					while(!(cin>>wybor_pi))
					{
						cout<<"Musisz podac liczbe! ";
						cin.clear();
						cin.sync();
					}

					switch(wybor_pi)
					{
					case 0:
						cout<<"Powrot do menu glownego!"<<endl;
						break;

					case 1:
						{
							Pizza margherita;
							margherita.nazwa="Margherita";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(2);
							wegeherita.skladniki[1]=wegeherita.tekstenum(5);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(0);
							margherita(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							margherita.cena_pizzy=racherita.wystaw_rachunek(ciasherita, margherita, dodaherita);
							cout<<margherita;

							zaplac(margherita.cena_pizzy);
							break;
						}


					case 2:
						{
							Pizza funghi;
							funghi.nazwa="Funghi";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(7);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							funghi(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							funghi.cena_pizzy=racherita.wystaw_rachunek(ciasherita, funghi, dodaherita);
							cout<<funghi;

							zaplac(funghi.cena_pizzy);
							break;
						}


					case 3:
						{
							Pizza neapolitana;
							neapolitana.nazwa="Neapolitana";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(7);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							neapolitana(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							neapolitana.cena_pizzy=racherita.wystaw_rachunek(ciasherita, neapolitana, dodaherita);
							cout<<neapolitana;

							zaplac(neapolitana.cena_pizzy);
							break;
						}


					case 4:
						{
							Pizza dipollo;
							dipollo.nazwa="Dipollo";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(7);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							dipollo(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							dipollo.cena_pizzy=racherita.wystaw_rachunek(ciasherita, dipollo, dodaherita);
							cout<<dipollo;

							zaplac(dipollo.cena_pizzy);
							break;
						}


					case 5:
						{
							Pizza pepperoni;
							pepperoni.nazwa="Pepperoni";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(7);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							pepperoni(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							pepperoni.cena_pizzy=racherita.wystaw_rachunek(ciasherita, pepperoni, dodaherita);
							cout<<pepperoni;

							zaplac(pepperoni.cena_pizzy);
						}
						break;

					case 6:
						{
							Pizza hawajska;
							hawajska.nazwa="Hawajska";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(1);
							wegeherita.skladniki[1]=wegeherita.tekstenum(2);

							Mieso miesoherita;
							miesoherita.ilosc=1;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							hawajska(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							hawajska.cena_pizzy=racherita.wystaw_rachunek(ciasherita, hawajska, dodaherita);
							cout<<hawajska;

							zaplac(hawajska.cena_pizzy);
						}
						break;

					case 7:
						{
							Pizza amore;
							amore.nazwa="Amore";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=4;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(7);
							wegeherita.skladniki[2]=wegeherita.tekstenum(4);
							wegeherita.skladniki[3]=wegeherita.tekstenum(6);

							Mieso miesoherita;
							miesoherita.ilosc=2;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							miesoherita.skladniki[0]=miesoherita.tekstenum(2);
							amore(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							amore.cena_pizzy=racherita.wystaw_rachunek(ciasherita, amore, dodaherita);
							cout<<amore;

							zaplac(amore.cena_pizzy);
						}
						break;

					case 8:
						{
							Pizza diabelska;
							diabelska.nazwa="Diabelska";

							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(1);
							wegeherita.skladniki[1]=wegeherita.tekstenum(6);

							Mieso miesoherita;
							miesoherita.ilosc=2;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(1);
							miesoherita.skladniki[1]=miesoherita.tekstenum(4);
							diabelska(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							diabelska.cena_pizzy=racherita.wystaw_rachunek(ciasherita, diabelska, dodaherita);
							cout<<diabelska;

							zaplac(diabelska.cena_pizzy);
						}
						break;

					case 9:
						{
							Pizza rafaello;
							rafaello.nazwa="Rafaello";
							Ciasto ciasherita;
							ciasherita.nadaj_ksztalt();

							Wege wegeherita;
							wegeherita.ilosc=2;
							wegeherita.skladniki=new string[wegeherita.ilosc];

							wegeherita.skladniki[0]=wegeherita.tekstenum(3);
							wegeherita.skladniki[1]=wegeherita.tekstenum(2);

							Mieso miesoherita;
							miesoherita.ilosc=3;
							miesoherita.skladniki=new string[miesoherita.ilosc];
							miesoherita.skladniki[0]=miesoherita.tekstenum(5);
							miesoherita.skladniki[1]=miesoherita.tekstenum(1);
							miesoherita.skladniki[2]=miesoherita.tekstenum(3);
							rafaello(wegeherita, miesoherita);

							Dodatki dodaherita;
							dodaherita.dorzuc_do_zamowienia();
							Rachunek racherita;
							rafaello.cena_pizzy=racherita.wystaw_rachunek(ciasherita, rafaello, dodaherita);
							cout<<rafaello;

							zaplac(rafaello.cena_pizzy);
						}
						break;

					default:
						cout<<"Brak takiej opcji! Sproboj raz jeszcze!\n";
						break;
					};
				}
			}
			break;
			break;

		case 2:
			{
				cout<<"Wybrales stworzenie nowej pizzy!\n";
				Pizza stwor;
				cout<<"Podaj nazwe tworzonej przez siebie Pizzy: ";
				cin>>stwor.nazwa;
				stwor.tworzenie();
			}
			break;

		default:
			cout<<"Brak takiej opcji! Sproboj raz jeszcze!\n";
			break;
		}
	};
}

void zaplac(double cena)
{
	double zaplata=0;
	cout<<"Wpisz kwote do zaplaty: ";
	while(zaplata != cena || zaplata >cena)
	{
		while(!(cin>>zaplata))
		{
			cout<<"\nMusisz podac liczbe! ";
			cin.clear();
			cin.sync();
		};
		if(zaplata<0)
		{
			cout<<"Ty zartownisiu! Dla twojej wygody usunalem minus!\n";
			zaplata=-zaplata;
		}
		if(zaplata<cena)
		{
			cout<<"Szukaj jeszcze drobnych i doplac: "<<cena-zaplata<<" PLN\n";
			cena -= zaplata;
		}
		else
		{
			double napiwek=-(cena-zaplata)*0.15;
			cout<<"Odliczylem napiwek: "<<napiwek<<" PLN\n";
			cout<<"Reszta wynosi "<<-(cena-zaplata)-napiwek<<" PLN\n";
			break;
		}
	}
	cout<<"\nZamowienie bedzie gotowe za "<<rand() % 34+15<<" minut!"<<endl;
	cout<<"Zaplacono, dzieki wielkie, SMACZNEGO!"<<endl;
}
