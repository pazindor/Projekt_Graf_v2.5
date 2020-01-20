#include "menu.h"

using namespace std;


void menu() {
	char wybor;
	for (;;) 
	{
		cout << "MENU GLOWNE" << endl;
		cout << "-----------------" << endl;
		cout << "1. Wyswietl graf plikow" << endl;
		cout << "2. Wyswietl graf funkcji" << endl;
		cout << "3. Wyswietl graf modulow" << endl;
		cout << "4. Wyswietl graf plikow i funkcji" << endl;
		cout << "5. Wyswietl graf plikow i modulow <work in progress>" << endl;
		cout << "6. Wyswietl graf funkcji i modulow <work in progress>" << endl;
		cout << "7. Wyswietl graf plikow, funkcji i modulow <work in progress>" << endl;
		cout << "8. Wyswietl graf funkcji z podzialem na optymalne klastry" << endl;
		cout << "9. Koniec programu" << endl;
		
		cout << endl;


		cout << "Wybor: ";
		cin >> wybor;

		switch (wybor)
		{
		case '1':
			cout << "Graf plikow";
			system("start ..\\output\\graf_plikow.png");
			break;

		case '2':
			cout << "Graf funkcji";
			system("start ..\\output\\graf_funkcji.png");
			break;

		case '3':
			cout << "Graf modulow";
			system("start ..\\output\\graf_modulu.png");
			break;

		case '4':
			cout << "Graf plikow i funkcji";
			system("start ..\\output\\graf_pliki_funkcje.png");
			break;
		case '5':
			cout << "Graf plikow i modulow\n";
			system("start ..\\output\\graf_pliki_moduly.png");
			break;
		case '6':
			cout << "Graf funkcji i modulow\n";
			system("start ..\\output\\graf_funkcje_moduly.png");
			break;;
		case '7':
			cout << "Graf plikow, funkcji i modulow\n";
			system("start ..\\output\\graf_wszystkiego.png");
			break;
		case '8':
			cout << "Graf funkcji z podzialem na optymalne klastry";
			system("start ..\\output\\graf_metis_funkcje.png");
			break;
		case '9':
			exit(0);
			break;		

		default: cout << "Nie ma takiej opcji w menu!";
		}
		getchar();
		system("cls");
	}
}