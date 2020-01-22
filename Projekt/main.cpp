#pragma once
#include "Graf.h"
#include "Ewelina\menu.h"
#include <iostream>
#include <sstream>


int main() {
	graf::Graf* program = new graf::Graf;

	program->wykonaj();

	for (auto& i : program->wszystkie_funkcje_we_wszystkich_plikach) {
		std::cout << i.nazwa_funkcji << std::endl;
		for (auto& j : i.polaczenia_miedzy_funkcjami) {
			std::cout << "\t" <<j.nazwa_polaczonego_elementu<<"  "<<j.waga<< std::endl;
		}
	}
	std::cout << "--------" << std::endl;
	
	menu();

	delete program;
	
	return 0;
}

