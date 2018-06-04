#include "Wezel.h"

wezel::wezel()
{
}

wezel::wezel(int wart, int _x_pionka, int _y_pionka, int _x , int _y)
{
	wartosc = wart;
	x_pionka = _x_pionka;
	y_pionka = _y_pionka;
	x = _x;
	y = _y;
}

wezel::wezel(int x)
{
}

wezel::~wezel()
{
}

void wezel::ustaw_wartosc(int x)
{
	wartosc = x;
}

void wezel::dodaj_dziecko(wezel * _w)
{
	dzieci.push_back(_w);
}

int wezel::zwroc_wartosc()
{
	return wartosc;
}

int wezel::zwroc_x()
{
	return x;
}

int wezel::zwroc_y()
{
	return y;
}

int wezel::zwroc_xpionka()
{
	return x_pionka;
}

int wezel::zwroc_ypionka()
{
	return y_pionka;
}

wezel * wezel::zwroc_dziecko(int i)
{
	return dzieci[i];
}

wezel * wezel::zwroc_ostatnie()
{
	return dzieci.back();
}

bool wezel::czy_sa_dzieci()
{
	if (dzieci.empty())
		return false;
	else
		return true;
}

int wezel::ilosc_dzieci()
{
	return dzieci.size();
}
