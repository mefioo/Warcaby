#ifndef DRZEWO_H
#define DRZEWO_H
#include "Wezel.h"

class drzewo
{
	wezel *korzen = new wezel;
	int glebokosc;

public:
	drzewo();
	~drzewo();

	int zwroc_glebokosc();

	wezel* zwroc_korzen();

	void buduj_drzewo(plansza* szachownica, wezel *korzen, int ruch);

};




#endif 
