#include "../Graf.h"
#pragma once

using namespace std;

void graf::Graf::przypisuje_funkcje_i_pliki_do_modulow()
{
	string linia;
	string granica_wycinania = ":";

	vector <string> duplikaty_nazw_plikow;
	int licznik = 0;

	for (unsigned int i = 0; i < pliki.size(); i++)
	{
			for (unsigned int j = 0; j < pliki[i].funkcje.size(); j++)
			{
					linia = pliki[i].funkcje[j].nazwa_funkcji;
					if (linia.find(granica_wycinania) != string::npos)
					{
						Wojtas::wycinanie_rekurencyjne(&linia, granica_wycinania, FALSE);
						for (unsigned int obecna_przestrzen = 0; obecna_przestrzen < przestrzenie_nazw.size(); obecna_przestrzen++)
						{
								if (linia == przestrzenie_nazw[obecna_przestrzen].nazwa_przestrzeni)
								{
									przestrzenie_nazw[obecna_przestrzen].polaczenia_z_funkcjami.push_back(pliki[i].funkcje[j].nazwa_funkcji);
									//sprawdzam duplikaty plikow
									if (przestrzenie_nazw[obecna_przestrzen].polaczenia_z_plikami.size() == 0)
									{
										przestrzenie_nazw[obecna_przestrzen].polaczenia_z_plikami.push_back(pliki[i].nazwa_pliku);
										duplikaty_nazw_plikow.push_back(pliki[i].nazwa_pliku);
									}
									else 
									{
										licznik = duplikaty_nazw_plikow.size();
										for (unsigned int k = 0; k < duplikaty_nazw_plikow.size(); k++)
										{
											if (pliki[i].nazwa_pliku == duplikaty_nazw_plikow[k])
											{
												licznik--;
											}
										}
										if (licznik == duplikaty_nazw_plikow.size())
										{
											przestrzenie_nazw[obecna_przestrzen].polaczenia_z_plikami.push_back(pliki[i].nazwa_pliku);
											duplikaty_nazw_plikow.push_back(pliki[i].nazwa_pliku);
										}
									}
								}
						}
					}
					
			
			}

	}

	//Sprawdzenie
/*
	for (unsigned int i = 0; i < przestrzenie_nazw.size(); i++)
	{
		cout << "Modul: " << przestrzenie_nazw[i].nazwa_przestrzeni << " \n{\n";
		for (unsigned int j = 0; j < przestrzenie_nazw[i].polaczenia_z_funkcjami.size(); j++)
		{
			cout << " -> Funkcja: " << przestrzenie_nazw[i].polaczenia_z_funkcjami[j].nazwa_polaczonego_elementu << " \n";
		}
		for (unsigned int j = 0; j < przestrzenie_nazw[i].polaczenia_z_plikami.size(); j++)
		{
			cout << " ===> Plik: " << przestrzenie_nazw[i].polaczenia_z_plikami[j].nazwa_polaczonego_elementu << " \n";
		}
	}
*/

}