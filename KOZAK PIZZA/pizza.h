#ifndef PIZZA_H_
#define PIZZA_H_
#include<iostream>
#include"wege.h"
#include"mieso.h"
using namespace std;


class Pizza
{
public:
	string nazwa;
	string *zawartosc;
	double cena_pizzy;
	double kosztowanie();
	int il;
	void tworzenie();
	Pizza();
	~Pizza();
	friend ostream& operator<<(ostream&, Pizza);
	string *operator()(Wege, Mieso);
};

#endif