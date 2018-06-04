#ifndef WEZEL_H
#define WEZEL_H
#include <vector>
#include "Plansza.h"

class wezel
{
	int wartosc;
	std::vector<wezel *> dzieci;
	int x_pionka, y_pionka, x, y;
public:
	wezel();
	wezel(int wart, int x_pionka, int y_pionka, int x, int y);
	wezel(int x);
	~wezel();
	void ustaw_wartosc(int x);
	void dodaj_dziecko(wezel *_w);


	int zwroc_wartosc();
	int zwroc_x();
	int zwroc_y();
	int zwroc_xpionka();
	int zwroc_ypionka();
	wezel* zwroc_dziecko(int i);
	wezel* zwroc_ostatnie();
	bool czy_sa_dzieci();
	int ilosc_dzieci();


};








#endif 

