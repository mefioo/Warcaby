
#ifndef PLANSZA_H
#define PLANSZA_H
#include "pionek.h"
#include <vector>

class plansza
{
	int pole[8][8];
	std::vector<pionek *> plansza_pionkow;
public:
	plansza();
	~plansza();

	void wyswietl_plansze();
	pionek* zwroc_pionek(int x, int y);
	pionek* zwroc_pionek(int x);


	void ustaw_pole(int x, int y, int kolor);
	int zwroc_pole(int x, int y);

	bool czy_puste_pole(int x, int y);
	bool czy_poprawny_ruch(pionek *p, int _x, int _y);
	bool czy_koniec();
};



#endif
