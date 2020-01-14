#pragma once
#include "Graf.h"
#include "Ewelina\menu.h"
#include <iostream>
#include <sstream>


int main() {
	graf::Graf* program = new graf::Graf;

	program->wykonaj();

	menu();

	delete program;
	
	return 0;
}

void zmiana()
{
	cout << "lol";
}