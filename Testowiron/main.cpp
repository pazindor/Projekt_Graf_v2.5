#pragma once
#include "Naglowek.h"

using namespace std;

int main()
{
	Drzewo* drzewo = new Drzewo;
	string linia;
	fstream otwierany_plik;
	otwierany_plik.open("lista.txt", ios::in);
	while (getline(otwierany_plik, linia, ' '))
	{
		drzewo->dodaj_i_konwertuj(linia);
	}

	drzewo->przegladaj_drzewo_in_order(drzewo->korzen);

	delete drzewo;
	return 0;
}

