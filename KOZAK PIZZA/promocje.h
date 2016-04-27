#ifndef PROMOCJE_H_
#define PROMOCJE_H_
#include<iostream>
#include<string>
using namespace std;

class Promocje
{
public:
	string na_haslo;
	double rabat, studencka;
	double obniz_rachunek(double);
	Promocje();
	~Promocje();
};

#endif
