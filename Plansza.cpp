#include "Plansza.h"

void plansza::ustaw_pionek(pionek p, int x, int y)
{
	plansza_pionkow[x][y] = p;
}

plansza::plansza()
{
	int i, j, pom=1;
	char kolor = 'b';
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			pole[i][j] = 0;
		}
	}

	for (i = 0; i < 8; i++)
	{
		if (i > 4)
		{
			kolor = 'c';
			pom = 2;
		}
		if (i < 3 || i>4)
		{
			for (j = 0; j < 8; j = j + 2)
			{
				if (i % 2 == 1)
					j++;
				ustaw_pionek(pionek(kolor, i, j), i, j);
		//		pionek *_pionek = new pionek(kolor, i, j);
				pole[i][j] = pom;
				if (i % 2 == 1)
					j--;
			}
		}
	}
}

plansza::~plansza()
{

}

void plansza::wyswietl_plansze()
{
	std::cout << "  0   1   2   3   4   5   6   7  " << std::endl << std::endl << std::endl;
	int i, j;
	for (i = 0; i < 8; i++)
	{
		std::cout << " --------------------------------"<<std::endl;
		for (j = 0; j < 8; j++)
		{
			std::cout << "| ";
			if (pole[i][j] == 0)
				std::cout << "  ";
			else
			{
				if (pole[i][j] == 1)
					std::cout << "O ";
				else
					std::cout << "X ";
			}
		}
		std::cout << "|    " << i <<std::endl;
			
	}
	std::cout << " --------------------------------" << std::endl;
}

pionek plansza::zwroc_pionek(int x, int y)
{
	return plansza_pionkow[x][y];
}



void plansza::ustaw_pole(int x, int y, int kolor)
{
	pole[x][y] = kolor;
}

bool plansza::czy_puste_pole(int x, int y)
{
	if (pole[x][y] == 0)
		return true;
	else
		return false;
}

bool plansza::czy_poprawny_ruch(pionek p, int _x, int _y)
{
	int x = p.zwroc_x(), y = p.zwroc_y(), kolor;
	if (_x > 7 || _x < 0 || _y>7 || _y < 0)
	{
		std::cout << "Nieprawidlowy ruch." << std::endl;
		return false;
	}
	if (p.zwroc_kolor() == 'b')
		kolor = 1;
	else
		kolor = -1;
	if (p.czy_dama() == false)
	{
		if (czy_puste_pole(_x,_y)==true)
		{

			if ((_x == p.zwroc_x() + kolor) && ((_y == p.zwroc_y() + 1) || (_y == p.zwroc_y() - 1)))
				return true;
			else
				return false;
		}
		else
		{
			std::cout << "Na razie nic " << std::endl;
		}
	}
	return false;
}

