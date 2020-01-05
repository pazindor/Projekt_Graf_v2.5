#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Galaz
{
	Galaz* rodzic;
	Galaz* prawy;
	Galaz* lewy;
	int zawartosc;

	Galaz(int zaw)
	{
		zawartosc = zaw;
		rodzic = nullptr;
		lewy = nullptr;
		prawy = nullptr;
	}

};

struct Drzewo
{
	Galaz* korzen;
	Drzewo()
	{
		korzen = nullptr;
	}

	Galaz* dodaj_galaz(Galaz*, int);
	void dodaj_i_konwertuj(string);
	void przegladaj_drzewo_in_order(Galaz*);
};

