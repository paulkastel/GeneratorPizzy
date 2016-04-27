#ifndef RACHUNEK_H_
#define RACHUNEK_H_
#include<iostream>
#include"ciasto.h"
#include"pizza.h"
#include"dodatki.h"
using namespace std;

class Rachunek
{
public:
	double wystaw_rachunek(Ciasto, Pizza, Dodatki);
	Rachunek();
	~Rachunek();
};

#endif
