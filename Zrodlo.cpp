#include "Plansza.h"
#include <ctime>
#include <cstdlib>
#include <windows.h>

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


void gracz_vs_gracz()
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	bool koniec_gry = 0;
	std::vector<int> mozliwosci;
	plansza * szachownica = new plansza;
	char los;
	int x, y, x1, y1, liczba_ruchow = 0, czyj_ruch, pom1 = 0, pom2 = 0, x_pionka, y_pionka, los1, los2, pat = 0;
	zasady();
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

	szachownica->wyswietl_plansze();

	while (!koniec_gry)
	{
		if (liczba_ruchow % 2 == 0)
		{
			pom2 = 0;
			czyj_ruch = 1;
			cout << "RUCH ZIELONYCH!" << endl;
			for (pom1 = 0; pom1 < 12; pom1++)
			{
				if (szachownica->zwroc_pionek(pom1)->czy_zbity() == false)
				{
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() < 6 && szachownica->zwroc_pionek(pom1)->zwroc_y() < 6)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() + 1, szachownica->zwroc_pionek(pom1)->zwroc_y() + 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() < 6 && szachownica->zwroc_pionek(pom1)->zwroc_y() > 1)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() + 1, szachownica->zwroc_pionek(pom1)->zwroc_y() - 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() > 1 && szachownica->zwroc_pionek(pom1)->zwroc_y() < 6)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() - 1, szachownica->zwroc_pionek(pom1)->zwroc_y() + 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() > 1 && szachownica->zwroc_pionek(pom1)->zwroc_y() > 1)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() - 1, szachownica->zwroc_pionek(pom1)->zwroc_y() - 1) == true)
						{
							pom2 = 1;
							break;
						}
				}
			}
			if (pom2 == 0)
			{
				cout << "Gracz zielony nie moze wykonac ruchu, gra zakonczona remisem." << endl;
				koniec_gry = 1;
				pat = 1;
			}
		}
		else
		{
			pom2 = 0;
			czyj_ruch = 2;
			cout << "RUCH CZERWONYCH!" << endl;
			for (pom1 = 12; pom1 < 24; pom1++)
			{
				if (szachownica->zwroc_pionek(pom1)->czy_zbity() == false)
				{
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() < 6 && szachownica->zwroc_pionek(pom1)->zwroc_y() < 6)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() + 1, szachownica->zwroc_pionek(pom1)->zwroc_y() + 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() < 6 && szachownica->zwroc_pionek(pom1)->zwroc_y() > 1)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() + 1, szachownica->zwroc_pionek(pom1)->zwroc_y() - 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() > 1 && szachownica->zwroc_pionek(pom1)->zwroc_y() < 6)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() - 1, szachownica->zwroc_pionek(pom1)->zwroc_y() + 1) == true)
						{
							pom2 = 1;
							break;
						}
					if (szachownica->zwroc_pionek(pom1)->zwroc_x() > 1 && szachownica->zwroc_pionek(pom1)->zwroc_y() > 1)
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom1), szachownica->zwroc_pionek(pom1)->zwroc_x() - 1, szachownica->zwroc_pionek(pom1)->zwroc_y() - 1) == true)
						{
							pom2 = 1;
							break;
						}
				}
			}
			if (pom2 == 0)
			{
				cout << "Gracz czerwony nie moze wykonac ruchu, gra zakonczona remisem." << endl;
				koniec_gry = 1;
				pat = 1;
			}
		}

		///////////////CZY MOZNA WYKONAC RUCH///////////////////////////



		////////////////////////////////////////////////////////////////
		if (!koniec_gry)
		{
			cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc: " << endl;
			cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
			while (szachownica->zwroc_pionek(x_pionka, y_pionka) == NULL)
			{
				cout << "Wczytales niepoprawny indeks pionka. Wpisz prawidlowy numer rzedu i kolumny: " << endl;
				cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc. " << endl;
				cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
			}
			
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
					while (true)
					{
						for (pom1 = 0; pom1 < mozliwosci.size(); pom1++)
						{
							if (x_pionka == mozliwosci[pom1] && y_pionka == mozliwosci[pom1 + 1])
								pom2 = 1;
							pom1++;
						}
						if (pom2 == 1)
							break;
						cout << "Musisz wybrac pionek, ktory ma opcje bicia!" << endl;
						cout << "Wczytaj pozycje pionka, ktorym chcesz zbic: " << endl;
						cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;

					}
				}

				mozliwosci.clear();

				cout << "Wczytaj pole, na ktore ma sie przesunac pionek: " << endl;
				cout << "Rzad: "; cin >> x; cout << "Kolumna: "; cin >> y;

				////////////////////////////////////  SPRAWDZANIE CZY JEST KONIECZNE BICIE /////////////////////////////////////



				//////

				if (x != 0 && x != 7 && y != 0 && y != 7)
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
						pom2 = 0;
						while (true)
						{
							for (pom1 = 0; pom1 < mozliwosci.size(); pom1++)
							{
								if (x == mozliwosci[pom1] && y == mozliwosci[pom1 + 1])
									pom2 = 1;
								pom1++;
							}
							if (pom2 == 1)
								break;
							cout << "Musisz zbic pionek!" << endl;
							cout << "Wczytaj pozycje pionka, ktory chcesz zbic: " << endl;
							cout << "Rzad: "; cin >> x; cout << "Kolumna: "; cin >> y;

						}
					}
					mozliwosci.clear();

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
				szachownica->wyswietl_plansze();
				liczba_ruchow++;
			}
			else
			{
				szachownica->wyswietl_plansze();
				cout << "Nieprawidlowy ruch, wybierz jeszcze raz. " << endl;
			}
			
			if (szachownica->czy_koniec() == true)
				koniec_gry = 1;
		}
	}
	if (koniec_gry)
	{
		if (!pat)
		{
			cout << "Koniec gry! Zwyciezaja ";
			if (czyj_ruch == 1)
				cout << "ZIELONI!" << endl;
			else
				cout << "CZERWONI!" << endl;
			cout << "Aby zakonczyc wcisnij dowolny klawisz.";
			cin >> los;
		}
		else
		{
			cout << "Aby zakonczyc wcisnij dowolny klawisz.";
			cin >> los;
		}
	}
}

void dzialaj()
{
	
	char opcja;
	bool wlaczony = 1;
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
			wyczysc_ekran();
			gracz_vs_gracz();
			break;
		default:
			cout << "Niedozwolona opcja.";
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