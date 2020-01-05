#pragma once

#include "Naglowek.h"

using namespace std;

Galaz* Drzewo::dodaj_galaz(Galaz* temp, int otrzymana_zmienna)
{
	
	if (temp == nullptr)
	{
		Galaz* nowa = new Galaz(otrzymana_zmienna);
		temp = nowa;
	}

	else if (temp->zawartosc < otrzymana_zmienna)
	{
		temp->prawy = dodaj_galaz(temp->prawy, otrzymana_zmienna);
		temp->prawy->rodzic = temp;
	}

	else if (temp->zawartosc >= otrzymana_zmienna)
	{
		temp->lewy = dodaj_galaz(temp->lewy, otrzymana_zmienna);
		temp->lewy->rodzic = temp;
	}
	
	return temp;
}

void Drzewo::dodaj_i_konwertuj(string dane)
{
	int zmienna = stoi(dane);
	korzen = dodaj_galaz(korzen, zmienna);
}

void Drzewo::przegladaj_drzewo_in_order(Galaz* temp)
{
	if (!temp) return;

	przegladaj_drzewo_in_order(temp->lewy);
	cout << temp->zawartosc << "  ";
	przegladaj_drzewo_in_order(temp->prawy);
}