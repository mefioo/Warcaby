#include "Plansza.h"

using namespace std;

void wyswietl_menu()
{
	cout << "m - wyswietl menu" << endl;
	cout << "k - koniec programu" << endl;
	cout << "p - gracz vs gracz" << endl;
	cout << "o - gracz vs komputer" << endl;
}

void wyczysc_ekran()
{
	for (int i = 0; i < 100; i++)
		cout << " " << endl;
}

void dzialaj()
{
	wyswietl_menu();
	char opcja;
	bool wlaczony = 1, koniec_gry=0;
	plansza * szachownica = new plansza;
	int x, y, x_pionka, y_pionka;
	while (wlaczony)
	{
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
			
			szachownica->wyswietl_plansze();
			while (!koniec_gry)
			{
				cout << "Wczytaj pozycje pionka, ktorym chcesz sie ruszyc: " << endl; 
				cout << "Rzad: "; cin >> x_pionka; cout << "Kolumna: "; cin >> y_pionka;
				cout << "Wczytaj ruch pionka: " << endl;
				cout << "Rzad: "; cin >> x; cout << "Kolumna: "; cin >> y; 
				if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(x_pionka,y_pionka),x,y) == true)
				{
					szachownica->zwroc_pionek(x_pionka, y_pionka).zmien_pozycje(x, y);
					szachownica->ustaw_pionek(szachownica->zwroc_pionek(x_pionka, y_pionka), x, y);
					szachownica->ustaw_pole(x, y, 1);
					szachownica->ustaw_pole(x_pionka, y_pionka, 0);
					wyczysc_ekran();
					szachownica->wyswietl_plansze();
					cout << "sdadas";
				}
			//	koniec_gry = 1;
			}
			break;
		default:
			cout << "Niedozwolona opcja.";
			break;
		}
	}
}

int main()
{
	int a, x=0, y=0;
	
	dzialaj();

	cin >> a;
	return 0;
}