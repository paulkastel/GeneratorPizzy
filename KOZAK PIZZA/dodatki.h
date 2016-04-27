#ifndef DODATKI_H_
#define DODATKI_H_
#include<iostream>
#include<string>
using namespace std;

class Dodatki
{
public:
	string tekstenum(int);
	string napenum(int);
	string extra_sos;
	string extra_napitka;
	Dodatki();
	~Dodatki();

	void kosztowanie();
	void dorzuc_do_zamowienia();
	enum sos
	{
		ostry,
		mieszany,
		grillowy,
		czosnkowy,
		musztarda,
		majonez,
		lagodny,
		keczup,
		END,
	};
	enum napoje
	{
		pepsi,
		cola,
		kawa,
		herbata,
		woda,
		piwko,
		wodeczka,
		lycha,
		ENDD,
	};
};

#endif
