#pragma once
#include <string.h>
#include "Objekt.h"
#include "../structures/list/array_list.h"
#include "../structures/table/unsorted_sequence_table.h"
#include "../structures/table/sorting/quick_sort.h"

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
	Methods();
	~Methods();
	Objekt* getNazovSlovensko();
	Objekt* getNazovObce(string nazov);
	Objekt* getNazovOkresu(string nazov);
	Objekt* getNazovKraja(string nazov);

	void setSlovensko(Objekt& objekt) { slovensko = &objekt; };

	void method1();
	void method3();

};

