#ifndef MIESO_H_
#define MIESO_H_
#include"skladniki.h"
#include<iostream>
using namespace std;

class Mieso: protected Skladniki
{
public:
	friend void menuglowne(int);
	friend class Pizza;
	Mieso();
	~Mieso();
	enum
	{
		szynka,
		wolowina,
		kurczak,
		bekon,
		salami,
		kielbasa,
		kabanos,
		END,
	};

private:
	string skladnikinaciasto(int ilosc);
	string tekstenum(int valenum);

protected:
	string *skladniki;
};

#endif