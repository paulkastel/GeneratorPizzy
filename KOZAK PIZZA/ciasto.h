#ifndef CIASTO_H_
#define CIASTO_H_
#include<iostream>
using namespace std;
class Ciasto
{
public:
	double srednica, grubosc, pole, objetosc, obwod;
	string ksztalt;
	void ulep();
	void nadaj_ksztalt();
	void nadaj_rozmiar(int);
	void wypisz_parametry();
	Ciasto();
	~Ciasto();
	
private:
	void majca(int, double srednica);
};

#endif