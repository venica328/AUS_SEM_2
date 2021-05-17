#pragma once
#include <string>
#include "../structures/table/treap.h"
#include "AddData.h"

using namespace std;
using namespace structures;

class Objekt
{
public:
	Objekt(string nazov, int pocetObyvatelov, int pocPreprodObyvatelov, int pocProduktivnychObyvatelov,
		int pocPoprodObyvatelov, int zastavanost, int celkovaVymera, int zastavanaPlocha);
	~Objekt();

	void setAddedData(AddData* data);
	AddData* getAddedData(string nazov);
	Treap<string, AddData*>* getObjekty() { return objekty; }

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
	Treap<string, AddData*>* objekty;
	Treap<string, Objekt*>* obce;
};

