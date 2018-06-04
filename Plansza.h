
#ifndef PLANSZA_H
#define PLANSZA_H
#include "pionek.h"
#include <vector>

class plansza
{
	int pole[8][8];
	std::vector<pionek *> plansza_pionkow;
	int tab[8][8] = { { 4,0,4,0,4,0,4,0 },{ 0, 3, 0,3,0,3,0,4 },{ 4,0,2,0,2,0,3,0 },{ 0,3,0,1,0,2,0,4 },{ 4,0,2,0,1,0,3,0 } ,{ 0,3,0,2,0,2,0,4 },{ 4,0,3,0,3,0,3,0 },{ 0,4,0,4,0,4,0,4 } };
public:
	plansza();
	~plansza();

	void wyswietl_plansze();
	pionek* zwroc_pionek(int x, int y);
	pionek* zwroc_pionek(int x);


	void ustaw_pole(int x, int y, int kolor);
	int zwroc_pole(int x, int y);
	int zwroc_wartosc_pola(int x, int y);
	int zwroc_wartosc_tab(int x, int y);


	bool czy_puste_pole(int x, int y);
	bool czy_poprawny_ruch(pionek *p, int _x, int _y);
	int wartosc_planszy();
	bool czy_koniec();

	void plansza_porownaj(plansza* p);
	void wykonaj_ruch(int czyj_ruch, int x, int y, int x_pionka, int y_pionka);
	bool czy_bylo_bicie(plansza* szachownica);
};



#endif
