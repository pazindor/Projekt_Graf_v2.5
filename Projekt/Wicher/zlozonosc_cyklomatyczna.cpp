#include"../Graf.h"
#pragma once

// funkcje nalepiej jednak by bylo dodac do clasy Graf tak po przemysleniu sytuacji XD
//oraz dodac do struct Funkcja 	nalezy dodac `int zlozonosc = 1;` bez ciapek
//funckja po kolei sprawdza plik i kazde slowo po czym jesli znajdzie slowo
//zwiekszajace zlozonosc cyklomatyczna to zwieksza zmienna

//ogolnie o zlozonosci:
// 0-10 kod prosty niewielkie ryzyko
//11-20 kod zlozony powodujacy duze ryzyko
//21-50	kod bardzo zlozony zwiazany z wysokim ryzykiem
//50 i wyzej pamietacie nasz program sprzez refactoringu ??? :D

void graf::Graf::zlozonosc_cyklomatyczna()
{
	int licznik_klamer = 0;

	const int rozmiar_tablicy = 2;

	std::fstream otwarty_plik;
	std::string linia;

	for (int plik = 0; plik < pliki.size(); plik++)	//otwiera kazdy plik po kolei
	{
		otwarty_plik.open(pliki[plik].nazwa_pliku, std::ios::in);

		while (getline(otwarty_plik, linia))	//po kolei zwczytuje kazda linie
		{
			Wojtas::szukanie_klamer(linia, licznik_klamer);	//szuka klamr zeby znalezc cialo funkcji

			if (licznik_klamer != 0)	//jesli licznik klamr jest rozny od 0 to znaczy ze jestesmy w ciele funkcji
			{
				for (int ktora_funkcja = 0; ktora_funkcja < wszystkie_funkcje_we_wszystkich_plikach.size(); ktora_funkcja++)	//iteruje po nazwach funkcji
				{
					if (linia.find(wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji) != std::string::npos)	//szuka kazdej funkcji
					{
						if ((linia.find("if ") != std::string::npos) || (linia.find("case") != std::string::npos))	//jesli znajdzie slowo klucz to zwieksza zlozonosc
						{
							wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc++;
							cout << "WEWNETRZNY IF" << endl;
						}
						cout << "ZEWNETRZNY IF" << endl;
					}
					cout << " Out" << endl;
				}
			}
		}
	}
}