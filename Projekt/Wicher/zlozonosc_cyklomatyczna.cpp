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

	std::fstream otwarty_plik;
	std::string linia;

	for (int plik = 0; plik < pliki.size(); plik++)
	{
		otwarty_plik.open(pliki[plik].nazwa_pliku, std::ios::in || std::ios::out);

		for (int ktora_funkcja = 0; ktora_funkcja < wszystkie_funkcje_we_wszystkich_plikach.size(); ktora_funkcja++)
		{
			do
			{
				while (!otwarty_plik.eof())
				{
					getline(otwarty_plik, linia);

					if (linia.find(wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji) != std::string::npos)
					{
						Wojtas::szukanie_klamer(linia, licznik_klamer);
					}
				}
			} while (licznik_klamer == 0);


			while (licznik_klamer != 0)
			{
				while (!otwarty_plik.eof())
				{
					getline(otwarty_plik, linia);

					if ((linia.find("if") != string::npos) || (linia.find("case") != string::npos))
					{
						wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc++;
					}
					Wojtas::szukanie_klamer(linia, licznik_klamer);
				}
			}
		}
		otwarty_plik.close();
	}

	//Wypisanie
	for (int i = 0; i < wszystkie_funkcje_we_wszystkich_plikach.size(); i++)
	{
		std::cout << wszystkie_funkcje_we_wszystkich_plikach[i].zlozonosc << std::endl;

	}

}