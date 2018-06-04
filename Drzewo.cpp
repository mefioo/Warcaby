#include "Drzewo.h"

drzewo::drzewo()
{

}

drzewo::~drzewo()
{
}

int drzewo::zwroc_glebokosc()
{
	return glebokosc;
}

wezel * drzewo::zwroc_korzen()
{
	return korzen;
}

void drzewo::buduj_drzewo(plansza * szachownica, wezel* _wezel, int ruch)
{
	int wartosc, kolor, i, j, licznik, x_pionka, y_pionka, pom, glebokosc = 1, indeks, x, y, kol2;
	while (ruch<2)
	{
		wezel *dziecko = new wezel;
		
		if (ruch % 2 == 0)
		{
			licznik = 0;
			kolor = 1;
			kol2 = 2;
		}
		else
		{
			licznik = 12;
			kolor = 2;
			kol2 = 1;
		}
		for (pom = licznik; pom < 12 + licznik; pom++)
		{
			if (szachownica->zwroc_pionek(pom)->czy_zbity() == false)
			{
				for (i = 0; i < 8; i++)
				{
					for (j = 0; j < 8; j = j + 2)
					{
						if (i % 2 == 1)
							j++;
						if (szachownica->czy_poprawny_ruch(szachownica->zwroc_pionek(pom), i, j) == true)
						{
							plansza *kopia = new plansza;
							x_pionka = szachownica->zwroc_pionek(pom)->zwroc_x();
							y_pionka = szachownica->zwroc_pionek(pom)->zwroc_y();
							kopia->plansza_porownaj(szachownica);
							if ((szachownica->zwroc_pole(i, j) == 1 && szachownica->zwroc_pole(x_pionka, y_pionka) == 2) ||
								(szachownica->zwroc_pole(i, j) == 2 && szachownica->zwroc_pole(x_pionka, y_pionka) == 1))
								indeks = szachownica->zwroc_pionek(i, j)->zwroc_index();
							szachownica->wykonaj_ruch(kolor, i, j, x_pionka, y_pionka);
							wartosc = szachownica->wartosc_planszy();
				//			std::cout << "wartosc planszy: " << wartosc << "  pionek x=" << x_pionka << " y=" << y_pionka << "  na x=" << i << " y=" << j << std::endl;
				//			dziecko->ustaw_wartosc(wartosc);							
							_wezel->dodaj_dziecko(new wezel(wartosc, x_pionka, y_pionka, i, j));
							
							//	_wezel->
							buduj_drzewo(szachownica, _wezel->zwroc_ostatnie() , ruch + 1);
							if (szachownica->czy_bylo_bicie(kopia) == true)
							{
								x = szachownica->zwroc_pionek(pom)->zwroc_x();
								y = szachownica->zwroc_pionek(pom)->zwroc_y();
								szachownica->zwroc_pionek(indeks)->ustaw_niezbity();
								szachownica->zwroc_pionek(indeks)->ustaw_pozycje(i, j);
								szachownica->zwroc_pionek(pom)->ustaw_pozycje(x_pionka, y_pionka);
								szachownica->ustaw_pole(i, j, kol2);
								szachownica->ustaw_pole(x, y, 0);
								szachownica->ustaw_pole(x_pionka, y_pionka, kolor);
								
							}
							else
								szachownica->wykonaj_ruch(kolor, x_pionka, y_pionka, i, j);
							delete kopia;
						}
						if (i % 2 == 1)
							j--;
					}

				}
			}
		}
		ruch++;
	}
	
}


