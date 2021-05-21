#pragma once
#include <string>
#include <sstream>
#include <locale.h>
#include "../structures/table/treap.h"
#include "../structures/table/sorting/quick_sort.h"
#include "../structures/table/unsorted_sequence_table.h"
#include "Obec.h"
#include "Okres.h"
#include "Kraj.h"

using namespace std;
using namespace structures;

class ClenenieSR
{
public:
	ClenenieSR(string nazovObce, string nazovOkresu, string nazovKraja, string nazovRepubliky);
	~ClenenieSR();

	void setDataObec(Obec* dataObec);
	void setDataOkres(Okres* dataOkres);
	void setDataKraj(Kraj* dataKraj);
	Obec* getDataObec(string nazov);
	Okres* getDataOkres(string nazov);
	Kraj* getDataKraj(string nazov);
	Treap<string, Obec*>* getObjektyObce() { return objektObec; }
	Treap<string, Okres*>* getObjektyOkres() { return objektOkres; }
	Treap<string, Kraj*>* getObjektyKraje() { return objektKraj; }
	string getRepubliku();
	string getNazovObce();
	string getNazovOkresu();
	string getNazovKraja();
	string vypisObjekt();

private:
	string nazovObce;
	string nazovOkresu;
	string nazovKraja;
	string nazovRepubliky;
	Treap<string, Obec*>* objektObec;
	Treap<string, Okres*>* objektOkres;
	Treap<string, Kraj*>* objektKraj;
	
};

