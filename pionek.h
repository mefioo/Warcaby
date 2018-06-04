#ifndef PIONEK_H
#define PIONEK_H
#include <iostream>
#include <cstdlib>
#include <cstdio>

class pionek
{
	char kolor;
	int pozycja_x;
	int pozycja_y;
	bool zbicie;
	bool dama;
	int index;
public:
	pionek(char _kolor, int x, int y, int _index);
	pionek();
	~pionek();

	int zwroc_x();
	int zwroc_y();
	char zwroc_kolor();
	int zwroc_index();
	void zmien_pozycje(int x, int y);
	void ustaw_dame();
	void ustaw_zbicie();
	void ustaw_niezbity();
	bool czy_dama();
	bool czy_zbity();
	void ustaw_pozycje(int x, int y);

};




#endif