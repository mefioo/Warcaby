#include "Plansza.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Wezel.h"
#include "Drzewo.h"

using namespace std;


void wyswietl_menu()
{
	cout << "GRA W WARCABY" << endl << endl;
	cout << "m - wyswietl menu" << endl;
	cout << "k - koniec programu" << endl;
	cout << "p - gracz vs gracz" << endl;
	cout << "o - gracz vs komputer (niedostepne)" << endl;
}

void wyczysc_ekran()
{
	for (int i = 0; i < 100; i++)
		cout << " " << endl;
}

void zasady()
{
	cout << "ZASADY GRY:" << endl << endl;
	cout << "- dama porusza sie po przekatnej" << endl;
	cout << "- dama po zbiciu ustawiana jest zaraz za zbitym pionkiem" << endl;
	cout << "- bicie jest obowiazkowe" << endl;
	cout << "- bic mozna do tylu i do przodu" << endl;
	cout << "- zbicie realizujemy poprzez wprowadzenie wspolrzednych pionka, ktory chcemy zbic" << endl;
	cout << "- nie ma podwojnych zbic" << endl;
	cout << "- gra konczy sie w momencie, gdy ktorys z graczy nie bedzie mial juz pionkow" << endl;
}


bool czy_pat(plansza *szachownica, int ruch)
{
	int pat = 0, i, j = 0, licznik, pom1, pom2 = 0, pom3 = 0;
	if (ruch % 2 == 0)
		licznik = 0;
	else
		licznik = 12;
	pom1 = licznik;
	for (licznik; licznik < pom1 + 12; licznik++)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j = j + 2)
			{
				if (i % 2 == 1)
					j++;
				if (szachownica->zwroc_pionek(licznik)->czy_zbity() == false)
				{
					if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(licznik), i, j) == false)
					{
						pom2++;
						break;
					}
				}
				if (i % 2 == 1)
					j--;
				pom3++;
			}
		}
	}
	if (pom2 == pom3)
		pat = 1;
	if (pat)
		return true;
	else
		return false;

}



void losowanie()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	char los;
	int los1, los2;
	cout << endl << endl << "Gra gracz vs gracz" << endl << endl << "Wcisnij dowolny przycisk zeby wylosowac liczbe: ";
	cin >> los;
	los1 = rand() % 100 + 1;
	cout << "Twoja liczba to: ";
	SetConsoleTextAttribute(color, 14);
	cout << los1 << endl;
	SetConsoleTextAttribute(color, 7);
	cout << "Wcisnij dowolny przycisk zeby wylosowac druga liczbe: ";
	cin >> los;
	los2 = rand() % 100 + 1;
	cout << "Twoja liczba to: ";
	SetConsoleTextAttribute(color, 14);
	cout << los2 << endl;
	SetConsoleTextAttribute(color, 7);
	while (los2 == los1)
		los2 = rand() % 100 + 1;
	if (los2 > los1)
		los1 = los2;
	cout << "Gracz ktory wylosowal liczbe ";
	SetConsoleTextAttribute(color, 14);
	cout << los1;
	SetConsoleTextAttribute(color, 7);
	cout << " ma zielone pionki i zaczyna gre." << endl << "By kontynuowac wcisnij dowolny przycisk: " << endl;
	cin >> los;
}


bool czy_wszystkie_zbite(plansza *szachownica, int ruch)
{
	if (ruch % 2 == 0)
		ruch = 0;
	else
		ruch = 12;
	int i = ruch, licznik = 0;
	for (i; i < ruch + 12; i++)
	{
		if (szachownica->zwroc_pionek(i)->czy_zbity() == true)
		{
			licznik++;
		}
	}
	if (licznik == 12)
		return true;
	else
		return false;
}

bool czy_zmienic_pionek(plansza *szachownica, int czyj_ruch, int x_pionka, int y_pionka)
{
	vector<int> mozliwosci;
	int x1, y1, pom1, pom2, los1, los2;
	if (czyj_ruch == 1)
	{
		for (pom1 = 0; pom1 < 12; pom1++)
		{
			if (szachownica->zwroc_pionek(pom1)->czy_zbity() == false)
			{
				x1 = szachownica->zwroc_pionek(pom1)->zwroc_x();
				y1 = szachownica->zwroc_pionek(pom1)->zwroc_y();
				if (szachownica->zwroc_pole(x1 + 1, y1 + 1) == 2)
				{
					if (szachownica->zwroc_pole(x1 + 2, y1 + 2) == 0)
					{
						if (x1 + 2 > -1 && x1 + 2 < 8 && y1 + 2 > -1 && y1 + 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 + 1, y1 - 1) == 2)
				{
					if (szachownica->zwroc_pole(x1 + 2, y1 - 2) == 0)
					{
						if (x1 + 2 > -1 && x1 + 2 < 8 && y1 - 2 > -1 && y1 - 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 - 1, y1 + 1) == 2)
				{
					if (szachownica->zwroc_pole(x1 - 2, y1 + 2) == 0)
					{
						if (x1 - 2 > -1 && x1 - 2 < 8 && y1 + 2 > -1 && y1 + 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 - 1, y1 - 1) == 2)
				{
					if (szachownica->zwroc_pole(x1 - 2, y1 - 2) == 0)
					{
						if (x1 - 2 > -1 && x1 - 2 < 8 && y1 - 2 > -1 && y1 - 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pionek(pom1)->czy_dama() == true)
				{
					los1 = x1;
					los2 = y1;
					while (los1 < 6 && los2 < 6)
					{
						los1++; los2++;
						if (szachownica->zwroc_pole(los1, los2) == 2)
						{
							if (szachownica->zwroc_pole(los1 + 1, los2 + 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 < 6 && los2 > 1)
					{
						los1++; los2--;
						if (szachownica->zwroc_pole(los1, los2) == 2)
						{
							if (szachownica->zwroc_pole(los1 + 1, los2 - 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 > 1 && los2 < 6)
					{
						los1--; los2++;
						if (szachownica->zwroc_pole(los1, los2) == 2)
						{
							if (szachownica->zwroc_pole(los1 - 1, los2 + 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 > 1 && los2 > 1)
					{
						los1--; los2--;
						if (szachownica->zwroc_pole(los1, los2) == 2)
						{
							if (szachownica->zwroc_pole(los1 - 1, los2 - 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}

				}
			}
		}
	}
	else
	{
		for (pom1 = 12; pom1 < 24; pom1++)
		{
			if (szachownica->zwroc_pionek(pom1)->czy_zbity() == false)
			{
				x1 = szachownica->zwroc_pionek(pom1)->zwroc_x();
				y1 = szachownica->zwroc_pionek(pom1)->zwroc_y();
				if (szachownica->zwroc_pole(x1 + 1, y1 + 1) == 1)
				{
					if (szachownica->zwroc_pole(x1 + 2, y1 + 2) == 0)
					{
						if (x1 + 2 > -1 && x1 + 2 < 8 && y1 + 2 > -1 && y1 + 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 + 1, y1 - 1) == 1)
				{
					if (szachownica->zwroc_pole(x1 + 2, y1 - 2) == 0)
					{
						if (x1 + 2 > -1 && x1 + 2 < 8 && y1 - 2 > -1 && y1 - 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 - 1, y1 + 1) == 1)
				{
					if (szachownica->zwroc_pole(x1 - 2, y1 + 2) == 0)
					{
						if (x1 - 2 > -1 && x1 - 2 < 8 && y1 + 2 > -1 && y1 + 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pole(x1 - 1, y1 - 1) == 1)
				{
					if (szachownica->zwroc_pole(x1 - 2, y1 - 2) == 0)
					{
						if (x1 - 2 > -1 && x1 - 2 < 8 && y1 - 2 > -1 && y1 - 2 < 8)
						{
							mozliwosci.push_back(x1);
							mozliwosci.push_back(y1);
						}
					}
				}
				if (szachownica->zwroc_pionek(pom1)->czy_dama() == true)
				{
					los1 = x1;
					los2 = y1;
					while (los1 < 6 && los2 < 6)
					{
						los1++; los2++;
						if (szachownica->zwroc_pole(los1, los2) == 1)
						{
							if (szachownica->zwroc_pole(los1 + 1, los2 + 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 < 6 && los2 > 1)
					{
						los1++; los2--;
						if (szachownica->zwroc_pole(los1, los2) == 1)
						{
							if (szachownica->zwroc_pole(los1 + 1, los2 - 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 > 1 && los2 < 6)
					{
						los1--; los2++;
						if (szachownica->zwroc_pole(los1, los2) == 1)
						{
							if (szachownica->zwroc_pole(los1 - 1, los2 + 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}
					los1 = x1;
					los2 = y1;
					while (los1 > 1 && los2 > 1)
					{
						los1--; los2--;
						if (szachownica->zwroc_pole(los1, los2) == 1)
						{
							if (szachownica->zwroc_pole(los1 - 1, los2 - 1) == 0)
							{
								mozliwosci.push_back(x1);
								mozliwosci.push_back(y1);
								break;
							}
							break;
						}
					}

				}
			}
		}

	}

	if (mozliwosci.empty() == false)
	{
		pom2 = 0;
		for (pom1 = 0; pom1 < mozliwosci.size(); pom1++)
		{
			if (x_pionka == mozliwosci[pom1] && y_pionka == mozliwosci[pom1+1])
				pom2 = 1;
			if (pom2 == 1)
				break;
			pom1++;
		}
	}
	else
		return false;

	if (pom2 == 1)
		return false;
	else 
		return true;

	mozliwosci.clear();
}

bool czy_zmienic_pole(plansza *szachownica, int czyj_ruch, int x, int y, int x_pionka, int y_pionka)
{
	vector<int> mozliwosci;
	int los1, los2;
	
	{
		if (czyj_ruch == 1)
		{
			if (szachownica->zwroc_pionek(x_pionka, y_pionka)->czy_dama() == false)
			{
				if (szachownica->zwroc_pole(x_pionka + 1, y_pionka + 1) == 2)
				{
					if (szachownica->zwroc_pole(x_pionka + 2, y_pionka + 2) == 0)
					{
						if (x_pionka + 2 > -1 && x_pionka + 2 < 8 && y_pionka + 2 > -1 && y_pionka + 2 < 8)
						{
							mozliwosci.push_back(x_pionka + 1);
							mozliwosci.push_back(y_pionka + 1);
						}
					}
				}
				if (szachownica->zwroc_pole(x_pionka + 1, y_pionka - 1) == 2)
				{
					if (szachownica->zwroc_pole(x_pionka + 2, y_pionka - 2) == 0)
					{
						if (x_pionka + 2 > -1 && x_pionka + 2 < 8 && y_pionka - 2 > -1 && y_pionka - 2 < 8)
						{
							mozliwosci.push_back(x_pionka + 1);
							mozliwosci.push_back(y_pionka - 1);
						}
					}
				}
				if (szachownica->zwroc_pole(x_pionka - 1, y_pionka + 1) == 2)
				{
					if (szachownica->zwroc_pole(x_pionka - 2, y_pionka + 2) == 0)
					{
						if (x_pionka - 2 > -1 && x_pionka - 2 < 8 && y_pionka + 2 > -1 && y_pionka + 2 < 8)
						{
							mozliwosci.push_back(x_pionka - 1);
							mozliwosci.push_back(y_pionka + 1);
						}
					}
				}
				if (szachownica->zwroc_pole(x_pionka - 1, y_pionka - 1) == 2)
				{
					if (szachownica->zwroc_pole(x_pionka - 2, y_pionka - 2) == 0)
					{
						if (x_pionka - 2 > -1 && x_pionka - 2 < 8 && y_pionka - 2 > -1 && y_pionka - 2 < 8)
						{
							mozliwosci.push_back(x_pionka - 1);
							mozliwosci.push_back(y_pionka - 1);
						}
					}
				}
			}
			else
			{
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 < 6 && los2 < 6)
				{
					los1++; los2++;
					if (szachownica->zwroc_pole(los1, los2) == 2)
					{
						if (szachownica->zwroc_pole(los1 + 1, los2 + 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 < 6 && los2 > 1)
				{
					los1++; los2--;
					if (szachownica->zwroc_pole(los1, los2) == 2)
					{
						if (szachownica->zwroc_pole(los1 + 1, los2 - 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 > 1 && los2 < 6)
				{
					los1--; los2++;
					if (szachownica->zwroc_pole(los1, los2) == 2)
					{
						if (szachownica->zwroc_pole(los1 - 1, los2 + 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 > 1 && los2 > 1)
				{
					los1--; los2--;
					if (szachownica->zwroc_pole(los1, los2) == 2)
					{
						if (szachownica->zwroc_pole(los1 - 1, los2 - 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}

			}
		}
		else
		{
			if (szachownica->zwroc_pionek(x_pionka, y_pionka)->czy_dama() == false)
			{
				if (szachownica->zwroc_pole(x_pionka + 1, y_pionka + 1) == 1)
				{
					if (szachownica->zwroc_pole(x_pionka + 2, y_pionka + 2) == 0)
					{
						mozliwosci.push_back(x_pionka + 1);
						mozliwosci.push_back(y_pionka + 1);
					}
				}
				if (szachownica->zwroc_pole(x_pionka + 1, y_pionka - 1) == 1)
				{
					if (szachownica->zwroc_pole(x_pionka + 2, y_pionka - 2) == 0)
					{
						mozliwosci.push_back(x_pionka + 1);
						mozliwosci.push_back(y_pionka - 1);
					}
				}
				if (szachownica->zwroc_pole(x_pionka - 1, y_pionka + 1) == 1)
				{
					if (szachownica->zwroc_pole(x_pionka - 2, y_pionka + 2) == 0)
					{
						mozliwosci.push_back(x_pionka - 1);
						mozliwosci.push_back(y_pionka + 1);
					}
				}
				if (szachownica->zwroc_pole(x_pionka - 1, y_pionka - 1) == 1)
				{
					if (szachownica->zwroc_pole(x_pionka - 2, y_pionka - 2) == 0)
					{
						mozliwosci.push_back(x_pionka - 1);
						mozliwosci.push_back(y_pionka - 1);
					}
				}
			}
			else
			{
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 < 6 && los2 < 6)
				{
					los1++; los2++;
					if (szachownica->zwroc_pole(los1, los2) == 1)
					{
						if (szachownica->zwroc_pole(los1 + 1, los2 + 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 < 6 && los2 > 1)
				{
					los1++; los2--;
					if (szachownica->zwroc_pole(los1, los2) == 1)
					{
						if (szachownica->zwroc_pole(los1 + 1, los2 - 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 > 1 && los2 < 6)
				{
					los1--; los2++;
					if (szachownica->zwroc_pole(los1, los2) == 1)
					{
						if (szachownica->zwroc_pole(los1 - 1, los2 + 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}
				los1 = x_pionka;
				los2 = y_pionka;
				while (los1 > 1 && los2 > 1)
				{
					los1--; los2--;
					if (szachownica->zwroc_pole(los1, los2) == 1)
					{
						if (szachownica->zwroc_pole(los1 - 1, los2 - 1) == 0)
						{
							mozliwosci.push_back(los1);
							mozliwosci.push_back(los2);
							break;
						}
						break;
					}
				}

			}
		}

		if (mozliwosci.empty() == false)
		{
			los2 = 0;
			for (los1 = 0; los1 < mozliwosci.size(); los1++)
			{
				if (x == mozliwosci[los1] && y == mozliwosci[los1+1])
					los2 = 1;
				if (los2 == 1)
					break;
				los1++;
			}
			
		}
		else
			return false;

		if (los2 == 1)
			return false;
		else
			return true;

		mozliwosci.clear();

	}
}


void wykonaj_ruch(plansza *szachownica, int czyj_ruch)
{
	bool koniec_gry = 0;
	std::vector<int> mozliwosci;
	int x, y, x1, y1, liczba_ruchow = 0, pom1 = 0, pom2 = 0, x_pionka, y_pionka, los1, los2, powtorz = 1;

	while (powtorz)
	{

		cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc: " << endl;
		cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
		while (szachownica->zwroc_pionek(x_pionka, y_pionka) == NULL)
		{
			cout << "Wczytales niepoprawny indeks pionka. Wpisz prawidlowy numer rzedu i kolumny: " << endl;
			cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc. " << endl;
			cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
		}
		while (czy_zmienic_pionek(szachownica, czyj_ruch, x_pionka, y_pionka) == true)
		{
			cout << "Wybierz pionek, ktorym mozesz dokonac bicia." << endl;
			cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc: " << endl;
			cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
			if (czy_zmienic_pionek(szachownica, czyj_ruch, x_pionka, y_pionka) == false)
				break;
		}

		cout << "Wczytaj pole, na ktore ma sie przesunac pionek: " << endl;
		cout << "Rzad: "; cin >> x; cout << "Kolumna: "; cin >> y;


		if (x != 0 && x != 7 && y != 0 && y != 7)
		{
			while (czy_zmienic_pole(szachownica, czyj_ruch, x, y, x_pionka, y_pionka) == true)
			{
				cout << "Wybierz pole, na ktorym znajduje sie pionek przeciwnika do zbicia." << endl;
				cout << "Wczytaj pole, na ktore ma sie przesunac pionek: " << endl;
				cout << "Rzad: "; cin >> x; cout << "Kolumna: "; cin >> y;
			}
		}



		if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(x_pionka, y_pionka), x, y) == true)
		{
			if ((szachownica->zwroc_pole(x, y) == 1 && czyj_ruch == 2) || ((szachownica->zwroc_pole(x, y) == 2 && czyj_ruch == 1)))
			{
				szachownica->zwroc_pionek(x, y)->ustaw_zbicie();
				szachownica->zwroc_pionek(x, y)->zmien_pozycje(-10, -10);
				szachownica->zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
				szachownica->ustaw_pole(x, y, czyj_ruch);
				szachownica->ustaw_pole(x_pionka, y_pionka, 0);
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

			szachownica->zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
			if (((x == 0 && czyj_ruch == 2) || (x == 7 && czyj_ruch == 1)) && szachownica->zwroc_pionek(x, y)->czy_dama() == false)
				szachownica->zwroc_pionek(x, y)->ustaw_dame();
			szachownica->ustaw_pole(x, y, czyj_ruch);
			szachownica->ustaw_pole(x_pionka, y_pionka, 0);

			wyczysc_ekran();
			liczba_ruchow++;
			powtorz = 0;
		}
		else
		{
			szachownica->wyswietl_plansze();
			cout << "Nieprawidlowy ruch, wybierz jeszcze raz. " << endl;
		}
	}
		
	
	
}


void wykonaj_ruch(plansza *szachownica, int czyj_ruch, int x, int y, int x_pionka, int y_pionka)
{
	bool koniec_gry = 0;
	std::vector<int> mozliwosci;
	int x1, y1, liczba_ruchow = 0, pom1 = 0, pom2 = 0, los1, los2, powtorz = 1;

	
	if ((szachownica->zwroc_pole(x, y) == 1 && czyj_ruch == 2) || ((szachownica->zwroc_pole(x, y) == 2 && czyj_ruch == 1)))
	{
		szachownica->zwroc_pionek(x, y)->ustaw_zbicie();
		szachownica->zwroc_pionek(x, y)->zmien_pozycje(-10, -10);
		szachownica->zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
		szachownica->ustaw_pole(x, y, czyj_ruch);
		szachownica->ustaw_pole(x_pionka, y_pionka, 0);
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

	szachownica->zwroc_pionek(x_pionka, y_pionka)->zmien_pozycje(x, y);
	if (((x == 0 && czyj_ruch == 2) || (x == 7 && czyj_ruch == 1)) && szachownica->zwroc_pionek(x, y)->czy_dama() == false)
		szachownica->zwroc_pionek(x, y)->ustaw_dame();
	szachownica->ustaw_pole(x, y, czyj_ruch);
	szachownica->ustaw_pole(x_pionka, y_pionka, 0);

	wyczysc_ekran();
	liczba_ruchow++;

}



int minmax(wezel* _wezel, int glebokosc, bool czy_max)
{
	int wartosc, i, pom;
	if (glebokosc == 0 || _wezel->czy_sa_dzieci() == false)
	{
		return _wezel->zwroc_wartosc();
	}

	if (czy_max)
	{
		wartosc = -500;
		for (i = 0; i < _wezel->ilosc_dzieci(); i++)
		{
			pom = minmax(_wezel->zwroc_dziecko(i), glebokosc - 1, false);
			if (pom > wartosc)
				wartosc = pom;
		}
	
		return wartosc;
	}
	else
	{
		wartosc = 500;
		for (i = 0; i < _wezel->ilosc_dzieci(); i++)
		{
			pom = minmax(_wezel->zwroc_dziecko(i), glebokosc - 1, true);
			if (pom < wartosc)
				wartosc = pom;
		}
		return wartosc;
	}

	
	
	
	


}

void dzialaj()
{
	
	char opcja;
	bool wlaczony = 1;
	int koniec_gry = 0, liczba_ruchow = 0, ruch, pat = 0;
	while (wlaczony)
	{
		wyswietl_menu();
		cout << "Wczytaj opcje: " << endl;
		cin >> opcja;
		switch (opcja)
		{
		case 'm':
			wyswietl_menu();
			break;
		case 'k':
			wlaczony = 0;
			break;
		case 'p':
		{
			liczba_ruchow = 0;
			plansza * szachownica = new plansza;
			wyczysc_ekran();
			zasady();
			losowanie();
			while (!koniec_gry)
			{
				szachownica->wyswietl_plansze();
				if (liczba_ruchow % 2 == 0)
				{
					ruch = 1;
					cout << "RUCH ZIELONYCH!" << endl;
				}
				else
				{
					ruch = 2;
					cout << "RUCH CZERWONYCH!" << endl;
				}


				wykonaj_ruch(szachownica, ruch);


				if (czy_wszystkie_zbite(szachownica, (liczba_ruchow++) % 2) == true)
				{
					if (ruch == 1)
						cout << "Gracz czerwony nie ma pionkow, wygrywa gracz ZIELONY!" << endl;
					else
						cout << "Gracz zielony nie ma pionkow, wygrywa gracz CZERWONY!" << endl;
					koniec_gry = 1;
				}
				if (czy_pat(szachownica, (liczba_ruchow % 2) == true))
				{
					koniec_gry = 1;
					pat = 1;
					cout << "Gracz nie moze wykonac nastepnego ruchu, gra zakonczona remisem." << endl;
				}

			}
			break;
		}
		case 'o':
		{
			liczba_ruchow = 0;        
			plansza * szachownica = new plansza;
			plansza * kopia = new plansza;
			vector <int> mozliwosci;
			
			int algorytm, i, x, y, x_pionka, y_pionka, pom;
			char xd;
			wyczysc_ekran();
			zasady();
			cout << endl << "GRACZ VS KOMPUTER" << endl << endl;
			cout << "Zaczyna gracz." << endl;
			while (!koniec_gry)
			{
				szachownica->wyswietl_plansze();
				if (liczba_ruchow % 2 == 0)
				{
					ruch = 1;
					cout << "RUCH ZIELONYCH!" << endl;
					wykonaj_ruch(szachownica, ruch);
				}
				else
				{
					drzewo * _drzewo = new drzewo;
					kopia->plansza_porownaj(szachownica);
					_drzewo->zwroc_korzen()->ustaw_wartosc(kopia->wartosc_planszy());
					ruch = 2;
					
					cout << "RUCH CZERWONYCH!" << endl;
					_drzewo->buduj_drzewo(kopia, _drzewo->zwroc_korzen(), 1);
					algorytm = minmax(_drzewo->zwroc_korzen(), 1, true);
					for (i = 0; i < _drzewo->zwroc_korzen()->ilosc_dzieci(); i++)
					{
						if (_drzewo->zwroc_korzen()->zwroc_dziecko(i)->zwroc_wartosc() == algorytm)
						{
							wykonaj_ruch(szachownica, ruch, _drzewo->zwroc_korzen()->zwroc_dziecko(i)->zwroc_x(),
															_drzewo->zwroc_korzen()->zwroc_dziecko(i)->zwroc_y(), 
															_drzewo->zwroc_korzen()->zwroc_dziecko(i)->zwroc_xpionka(), 
															_drzewo->zwroc_korzen()->zwroc_dziecko(i)->zwroc_ypionka());
							break;
						}
					}
					delete _drzewo;
				//	cout << "Wynik: " << algorytm << endl;
				}


				if (czy_wszystkie_zbite(szachownica, (liczba_ruchow++) % 2) == true)
				{
					if (ruch == 1)
						cout << "Gracz czerwony nie ma pionkow, wygrywa gracz ZIELONY!" << endl;
					else
						cout << "Gracz zielony nie ma pionkow, wygrywa gracz CZERWONY!" << endl;
					koniec_gry = 1;
				}
				if (czy_pat(szachownica, (liczba_ruchow % 2) == true))
				{
					koniec_gry = 1;
					pat = 1;
					cout << "Gracz nie moze wykonac nastepnego ruchu, gra zakonczona remisem." << endl;
				}
			}
			break;
		}
		default:
			cout << "Niedozwolona opcja." << endl;
			break;
		}
	}
}

int main()
{
	int a, x = 0, y = 0;

	dzialaj();

	cin >> a;
	return 0;
}