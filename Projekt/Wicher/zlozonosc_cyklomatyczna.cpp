#pragma once
#include"../Graf.h"


void graf::Graf::zlozonosc_cyklomatyczna()
{
	// funkcje nalepiej jednak by bylo dodac do clasy Graf tak po przemysleniu sytuacji XD
	//oraz dodac do struct Funkcja 	nalezy dodac `int zlozonosc = 1;` bez ciapek
	//funckja po kolei sprawdza plik i kazde slowo po czym jesli znajdzie slowo
	//zwiekszajace zlozonosc cyklomatyczna to zwieksza zmienna

	//ogolnie o zlozonosci:
	// 0-10 kod prosty niewielkie ryzyko
	//11-20 kod zlozony powodujacy duze ryzyko
	//21-50	kod bardzo zlozony zwiazany z wysokim ryzykiem
	//50 i wyzej pamietacie nasz program sprzez refactoringu ??? :D

int const rozmiar_tablicy = 2;

std::fstream otwarty_plik;
std::string linia;

std::string slowa_klucze[rozmiar_tablicy] = { "if", "case" };	//slowa ktore powoduja wieksza ilosc "sciezek"

for (int plik = 0; plik < pliki.size(); plik++)	//iteruje po kolei dla kazdego pliku
{
	otwarty_plik.open(pliki[plik].nazwa_pliku, std::ios::in);

	while (getline(otwarty_plik, linia))
	{
		std::vector<std::string> slowa_w_linii = Wojtas::dzielenie_na_slowa(linia);	//dzieli linie na slowa

		for (int nr_slowa = 0; nr_slowa < slowa_w_linii.size(); nr_slowa++)			//szuka slow kluczy
		{
			for (int ktora_funkcja = 0; ktora_funkcja < wszystkie_funkcje_we_wszystkich_plikach.size(); ktora_funkcja++)	//sprawdzana jest kazda funkcja
			{
				if (slowa_w_linii[nr_slowa] == wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji)
				{
					if (slowa_w_linii[nr_slowa] == slowa_klucze[1] || slowa_w_linii[nr_slowa] == slowa_klucze[2])
					{
						wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc++;
						//cout << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji << " -> " << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc << endl;
					}
					//cout << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji << " -> " << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc << endl;
				}
				//cout << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].nazwa_funkcji << " -> " << wszystkie_funkcje_we_wszystkich_plikach[ktora_funkcja].zlozonosc << endl;
			}
		}
	}
	otwarty_plik.close();
}
}

