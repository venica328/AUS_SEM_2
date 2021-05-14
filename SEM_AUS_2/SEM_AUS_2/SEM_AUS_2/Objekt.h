#pragma once
#include <string>
#include "../structures/table/treap.h"

using namespace std;

class Objekt
{
public:
	Objekt(string nazov, int pocetObyvatelov, int pocPreprodObyvatelov, int pocProduktivnychObyvatelov,
		int pocPoprodObyvatelov, int zastavanost, int celkovaVymera, int zastavanaPlocha);
	~Objekt();

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

};

