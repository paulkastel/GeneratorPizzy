#ifndef SKLADNIKI_H_
#define SKLADNIKI_H_
#include<iostream>
#include<string>
using namespace std;

class Skladniki
{
protected:
	int ilosc;
	virtual string skladnikinaciasto(int ilosc)=0;
	virtual string tekstenum(int valenum)=0;
};

#endif
