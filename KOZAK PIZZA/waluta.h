#ifndef WALUTA_H_
#define WALUTA_H_
#include<iostream>

template<typename typ> class Waluta
{
//dokonczyc przeliczniki EUR, USD...
public:
	typ pieniadz;
	Waluta();
	~Waluta();
	
	typ przelicz();
};
#endif