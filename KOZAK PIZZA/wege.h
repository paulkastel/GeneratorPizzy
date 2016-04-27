#ifndef WEGE_H_
#define WEGE_H_
#include"skladniki.h"
#include"mieso.h"
#include<iostream>
using namespace std;

class Wege: protected Skladniki
{
public:
	friend class Pizza;
	friend void menuglowne(int);
	Wege();
	~Wege();

	string *skladniki;
	enum
	{
		kukurydza,
		salata,
		ser,
		ananas,
		pomidor,
		papryka,
		oliwki,
		cebula,
		brokuly,
		fasola,
		END,
	};

private:
	string skladnikinaciasto(int ilosc);
	string tekstenum(int valenum);
};

#endif
