#ifndef PLANSZA_H
#define PLANSZA_H
#include "pionek.h"

class plansza
{
	int pole[8][8];
	pionek plansza_pionkow[8][8];
public:
	void ustaw_pionek(pionek p, int x, int y);
	plansza();
	~plansza();

	void wyswietl_plansze();
	pionek zwroc_pionek(int x, int y);
	

	void ustaw_pole(int x, int y, int kolor);

	bool czy_puste_pole(int x, int y);
	bool czy_poprawny_ruch(pionek p, int _x, int _y);
};



#endif
