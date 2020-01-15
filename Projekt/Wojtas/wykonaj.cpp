#pragma once
#include "..\Graf.h"

void graf::Graf::wykonaj() {
	CreateDirectoryA("..\\temp", NULL);
	sprawdz_czy_cos_jest_w_inpucie();
	policz_linijki_kodu_dla_pliku();
	znajdz_polaczenia_pomiedzy_plikami();

	znajdz_definicje_funkcji();
	znajdz_funkcje_i_wagi_pomiedzy_plikami();
	znajdz_polaczenia_miedzy_funkcjami();
	zlozonosc_cyklomatyczna();


	znajdz_przestrzenie_nazw();
	znajdz_elementy_przestrzeni_nazw();
	przypisuje_funkcje_i_pliki_do_modulow();
	polaczenie_modulu_z_plikiem();

	std::string graf_pliki = zamien_na_string_dla_plikow_do_grafu();
	std::string graf_funkcje = zamien_na_string_dla_funkcji_do_grafu();
	std::string graf_modul = zamien_na_string_dla_modulu();
	std::string graf_pliki_funkcje = string_dla_plikow_i_funkcji(graf_pliki, graf_funkcje);
	std::string graf_pliki_moduly = string_dla_plikow_i_modulu(graf_pliki, graf_modul);
	std::string graf_funkcjie_moduly = string_dla_funkcji_i_modulu(graf_funkcje, graf_modul);
	std::string graf_wszystkego = string_dla_wszystkiego(graf_pliki_funkcje, graf_pliki_moduly, graf_funkcjie_moduly);
	//std::string graf_metis_funkcje = przygotujPlikZFunkcjamiDlaMetisa();

	std::string do_txt_funkcje = przygotuj_txt_dla_funkcji_do_visual_paradigma();
	std::string do_txt_pliki = przygotuj_txt_dla_plikow_do_visual_paradigma();
	przygotuj_txt_dla_plikow_i_funkcji_do_visual_paradigma(do_txt_pliki, do_txt_funkcje);

	rysuj_graf(graf_pliki, "graf_plikow");
	rysuj_graf(graf_funkcje, "graf_funkcji");
	rysuj_graf(graf_modul, "graf_modulu");
	rysuj_graf(graf_pliki_funkcje, "graf_pliki_funkcje");
	rysuj_graf(graf_pliki_moduly, "graf_pliki_moduly");
	rysuj_graf(graf_funkcjie_moduly, "graf_funkcje_moduly");
	rysuj_graf(graf_wszystkego, "graf_wszystkiego");
	//rysuj_graf(graf_metis_funkcje, "graf_metis_funkcje");
	usun_tempa();
}

void graf::Graf::usun_tempa()
{
	string sciezka_do_pliku;
	//Najpierw usuwamy pliki w folderze
	for (unsigned int i = 0; i < pliki.size(); i++)
	{
		sciezka_do_pliku = "..\\temp\\" + pliki[i].nazwa_pliku;
		remove(sciezka_do_pliku.c_str());
	}
	//Teraz usuwamy katalog
	RemoveDirectoryA("..\\temp");
}