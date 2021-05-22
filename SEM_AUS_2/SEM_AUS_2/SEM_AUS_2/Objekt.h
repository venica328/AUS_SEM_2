#pragma once
#include <string>
#include "../structures/table/treap.h"
#include "../structures/table/sorting/quick_sort.h"
#include "../structures/table/unsorted_sequence_table.h"
#include "AddData.h"
#include "AddDataObyvatelia.h"
#include "AddDataZastavanost.h"

using namespace std;
using namespace structures;

class Objekt
{
public:
	Objekt(string nazov, int pocetObyvatelov, int pocPreprodObyvatelov, int pocProduktivnychObyvatelov,
		int pocPoprodObyvatelov, int zastavanost, int celkovaVymera, int zastavanaPlocha);
	~Objekt();

	void setAddedData(AddData* data);
	void setAddedDataPocObyvatelov(AddDataObyvatelia* pocObyvatelov);
	void setAddedDataZastavanost(AddDataZastavanost* zastavanost);
	void setDataToTable(UnsortedSequenceTable<int, AddDataObyvatelia*>* tableObyvatelia, AddDataObyvatelia* pocObyvatelov);
	AddData* getAddedData(string nazov);
	AddDataObyvatelia* getAddedDataPocObyvatelov(int pocet);
	AddDataZastavanost* getAddedDataZastavanost(int zastavanost);
	Treap<string, AddData*>* getObjekty() { return objektNazov; }
	Treap<int, AddDataObyvatelia*>* getObjektyObyvatelia() { return objektObyvatelia; }
	Treap<int, AddDataZastavanost*>* getObjektyZastavanot() { return objektZastavanost; }

	string getNazov();
	int getPocetObyvatelov();
	int getPocetPreproduktivnych();
	int getPocetProduktivnych();
	int getPocetPoproduktivnych();
	int getZastavanost();
	int getCelkovaVymera();
	int getZastavanaPlocha();
	string vypisObjekt();

private:
	string nazov;
	int pocetObyvatelov;
	int pocPreprodObyvatelov;
	int pocProduktivnychObyvatelov;
	int pocPoprodObyvatelov;
	int zastavanost;
	int celkovaVymera;
	int zastavanaPlocha;
	Treap<string, AddData*>* objektNazov;
	Treap<int, AddDataObyvatelia*>* objektObyvatelia;
	Treap<int, AddDataZastavanost*>* objektZastavanost;
};

