#include "pionek.h"


pionek::pionek(char _kolor, int x, int y, int _index)
{
	kolor = _kolor;
	pozycja_x = x;
	pozycja_y = y;
	index = _index;
	dama = false;
	zbicie = false;
}

pionek::pionek()
{
	dama = false;
	zbicie = false;
}

pionek::~pionek()
{
}

int pionek::zwroc_x()
{
	return pozycja_x;
}

int pionek::zwroc_y()
{
	return pozycja_y;
}

char pionek::zwroc_kolor()
{
	return kolor;
}


int pionek::zwroc_index()
{
	return index;
}

void pionek::zmien_pozycje(int x, int y)
{
	pozycja_x = x;
	pozycja_y = y;
}

void pionek::ustaw_dame()
{
	dama = true;
}

void pionek::ustaw_zbicie()
{
	zbicie = true;
}

bool pionek::czy_dama()
{
	if (dama == true)
		return true;
	else
		return false;
}

bool pionek::czy_zbity()
{
	if (zbicie == true)
		return true;
	else
		return false;
}