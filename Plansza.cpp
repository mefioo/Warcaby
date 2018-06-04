#include "Plansza.h"
#include <string>
#include <windows.h>


plansza::plansza()
{
	int i, j, pom = 1, index = 0;
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
				pionek *_pionek = new pionek(kolor, i, j, index);
				plansza_pionkow.push_back(_pionek);
				pole[i][j] = pom;
				index++;
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
	int i, j;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 100; i++)
		std::cout << " " << std::endl;
	SetConsoleTextAttribute(color, 6);
	std::cout << "  0   1   2   3   4   5   6   7  " << std::endl << std::endl << std::endl;
	SetConsoleTextAttribute(color, 7);
	
	for (i = 0; i < 8; i++)
	{
		std::cout << " --------------------------------" << std::endl;
		for (j = 0; j < 8; j++)
		{
			std::cout << "| ";
			if (pole[i][j] == 0)
				std::cout << "  ";
			else
			{
				if (pole[i][j] == 1)
				{
					SetConsoleTextAttribute(color, 10);
					if (zwroc_pionek(i, j)->czy_dama() == false)
						std::cout << "O ";
					else
						std::cout << "X ";
					SetConsoleTextAttribute(color, 7);
				}
				else
				{
					SetConsoleTextAttribute(color, 12);
					if (zwroc_pionek(i, j)->czy_dama() == false)
						std::cout << "O ";
					else
						std::cout << "X ";
					SetConsoleTextAttribute(color, 7);
				}
			}
		}
		std::cout << "|    ";
		SetConsoleTextAttribute(color, 6); 
		std::cout << i << std::endl;
		SetConsoleTextAttribute(color, 7);

	}
	std::cout << " --------------------------------" << std::endl;
}

pionek* plansza::zwroc_pionek(int x, int y)
{
	int index = 0;
	while (index < 24)
	{
		if (plansza_pionkow[index]->zwroc_x() == x && plansza_pionkow[index]->zwroc_y() == y)
			break;
		index++;
	}
	if (index < 24)
		return plansza_pionkow[index];
	else
		return NULL;
}

pionek * plansza::zwroc_pionek(int x)
{
	return plansza_pionkow[x];
}



void plansza::ustaw_pole(int x, int y, int kolor)
{
	pole[x][y] = kolor;
}

int plansza::zwroc_pole(int x, int y)
{
	return pole[x][y];
}

int plansza::zwroc_wartosc_pola(int x, int y)
{
	return tab[x][y];
}

int plansza::zwroc_wartosc_tab(int x, int y)
{
	return tab[x][y];
}

bool plansza::czy_puste_pole(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		if (pole[x][y] == 0)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool plansza::czy_poprawny_ruch(pionek *p, int _x, int _y)
{
	int x = p->zwroc_x(), y = p->zwroc_y(), kolor, i = 0, j = 0, licznik = 0, pom1, pom2;
	if (_x > 7 || _x < 0 || _y>7 || _y < 0)
	{
		wyswietl_plansze();
	//	std::cout << "Nieprawidlowy ruch, wybierz inne pole mieszczace sie w zaznaczonym zakresie." << std::endl;
		return false;
	}
	if (p->zwroc_kolor() == 'b')
		kolor = 1;
	else
		kolor = -1;
	if (p->czy_dama() == false)
	{
		if (abs(x - _x) != 1 || abs(y - _y) != 1)
			return false;
		if (czy_puste_pole(_x, _y) == true)
		{

			if ((_x == p->zwroc_x() + kolor) && ((_y == p->zwroc_y() + 1) || (_y == p->zwroc_y() - 1)))
				return true;
			else
			{
		//		wyswietl_plansze();
		//		std::cout << "Wybrany pionek nie moze przesunac sie w to miejsce. Wybierz inne lub zmien pionek, ktorym chcesz sie ruszyc." << std::endl;
				return false;
			}
		}
		else
		{
			if ((zwroc_pole(_x,_y) == 1 && p->zwroc_kolor() == 'b') || (zwroc_pole(_x, _y) == 2 && p->zwroc_kolor() == 'c'))
			{
		//		wyswietl_plansze();
		//		std::cout << "Tu stoi Twoj pionek, wybierz inne miejsce."<<std::endl;
				return false;
			}
			else
			{
				if (czy_puste_pole(_x + (_x - x), _y + (_y - y)) == true)
				{
					return true;
				}
				else
				{
			//		std::cout << "Nie mozna zbic tego pionka." << std::endl;
					return false;
				}
			}
		}
	}
	else
	{
		if ((p->zwroc_x() - _x != p->zwroc_y() - _y)&&(p->zwroc_x() - _x != (p->zwroc_y() - _y)*(-1)))
			return false;
		else
		{
			if (p->zwroc_x() < _x)
				i = 1;
			else
				i = -1;
			if (p->zwroc_y() < _y)
				j = 1;
			else
				j = -1;
			licznik = 0;
			pom2 = p->zwroc_y()+j;
			for (pom1 = p->zwroc_x()+i; pom1 != _x; pom1 += i)
			{
				if (czy_puste_pole(pom1, pom2) == false)
				{
					licznik = 1;
					break;
				}
				pom2 += j;
			}
			if (licznik)
				return false;
			else
			{
				if (czy_puste_pole(_x, _y) == true)
					return true;
				else
				{
					if (czy_puste_pole(_x + i, _y + j) == true)
						return true;
					else
						return false;
				}
			}
		}
	}
	return false;
}

int plansza::wartosc_planszy()
{
	int i = 0, j = 0, czarne = 0, biale = 0;
	for (i = 0; i < 12; i++)
	{
		if (zwroc_pionek(i)->czy_zbity() == false)
			biale += tab[zwroc_pionek(i)->zwroc_x()][zwroc_pionek(i)->zwroc_y()];
	}
	for (i = 12; i < 24; i++)
	{
		if (zwroc_pionek(i)->czy_zbity() == false)
			czarne += tab[zwroc_pionek(i)->zwroc_x()][zwroc_pionek(i)->zwroc_y()];
	}
	return czarne - biale;
}

bool plansza::czy_koniec()
{
	int pom1 = 0, pom2 = 0;
	for (pom1 = 12; pom1 < 24; pom1++)
	{
		if (zwroc_pionek(pom1)->czy_zbity() == true)
			pom2++;
	}
	if (pom2 == 12)
		return true;
	pom2 = 0;
	for (pom1 = 0; pom1 < 12; pom1++)
	{
		if (zwroc_pionek(pom1)->czy_zbity() == true)
			pom2++;
	}
	if (pom2 == 12)
		return true;
	else
		return false;
}

void plansza::plansza_porownaj(plansza * p)
{
	int i, j;
	for (i = 0; i < 24; i++)
	{
		plansza_pionkow[i] = p->zwroc_pionek(i);
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			pole[i][j] = p->zwroc_pole(i, j);
	}
}


void plansza::wykonaj_ruch(int czyj_ruch, int x, int y, int x_pionka, int y_pionka)
{
	bool koniec_gry = 0;
	std::vector<int> mozliwosci;
	int x1, y1, liczba_ruchow = 0, pom1 = 0, pom2 = 0, los1, los2, powtorz = 1;


	if ((zwroc_pole(x, y) == 1 && czyj_ruch == 2) || ((zwroc_pole(x, y) == 2 && czyj_ruch == 1)))
	{
		zwroc_pionek(x, y)->ustaw_zbicie();
		zwroc_pionek(x, y)->zmien_pozycje(-10, -10);
		zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
		ustaw_pole(x, y, czyj_ruch);
		ustaw_pole(x_pionka, y_pionka, 0);
		if (x_pionka < x)
			pom1 = 1;
		else
			pom1 = -1;
		if (y_pionka < y)
			pom2 = 1;
		else
			pom2 = -1;
		x_pionka = x; x += pom1;
		y_pionka = y; y += pom2;
	}

	zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
	if (((x == 0 && czyj_ruch == 2) || (x == 7 && czyj_ruch == 1)) && zwroc_pionek(x, y)->czy_dama() == false)
		zwroc_pionek(x, y)->ustaw_dame();
	ustaw_pole(x, y, czyj_ruch);
	ustaw_pole(x_pionka, y_pionka, 0);

	liczba_ruchow++;

}

bool plansza::czy_bylo_bicie(plansza* szachownica)
{
	int i, j, biale1 = 0, biale2 = 0, czarne1 = 0, czarne2 = 0;
	bool czy_zbicie = false;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (pole[i][j] == 1)
				biale1++;
			if (pole[i][j] == 2)
				czarne1++;
			if (szachownica->zwroc_pole(i, j) == 1)
				biale2++;
			if (szachownica->zwroc_pole(i, j) == 2)
				czarne2++;
		}
	}
	if (biale1 == biale2 && czarne1 == czarne2)
		return false;
	else
		return true;
}

