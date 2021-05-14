#pragma once
#include <string.h>
#include "Objekt.h"

using namespace std;
using namespace structures;

class Methods
{
private:
	Objekt* slovensko;
	Treap<string, Objekt*>* obce;
	Treap<string, Objekt*>* okresy;
	Treap<string, Objekt*>* kraje;
public:
	Objekt* getNazovSlovensko();
	Objekt* getNazovObce(string nazov);
	Objekt* getNazovOkresu(string nazov);
	Objekt* getNazovKraja(string nazov);

	void method3();

};

