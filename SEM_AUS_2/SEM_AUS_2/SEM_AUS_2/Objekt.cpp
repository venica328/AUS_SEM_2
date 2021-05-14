#include "Objekt.h"
#include <sstream>

using namespace std;
using namespace structures;


Objekt::Objekt(string nazov, int pocetObyvatelov, int pocPreprodObyvatelov, int pocProduktivnychObyvatelov, 
	int pocPoprodObyvatelov, int zastavanost, int celkovaVymera, int zastavanaPlocha) :
	nazov(nazov), pocetObyvatelov(pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov), 
	pocPreprodObyvatelov(pocPreprodObyvatelov),	pocProduktivnychObyvatelov(pocProduktivnychObyvatelov), 
	pocPoprodObyvatelov(pocPoprodObyvatelov), zastavanost(zastavanost),
	celkovaVymera(celkovaVymera), zastavanaPlocha(zastavanaPlocha)
{
}

Objekt::~Objekt()
{
}

string Objekt::getNazov()
{
	return nazov;
}

int Objekt::getPocetObyvatelov()
{
	return pocetObyvatelov;
}

int Objekt::getPocetPreproduktivnych()
{
	return pocPreprodObyvatelov;
}

int Objekt::getPocetProduktivnych()
{
	return pocProduktivnychObyvatelov;
}

int Objekt::getPocetPoproduktivnych()
{
	return pocPoprodObyvatelov;
}

int Objekt::getZastavanost()
{
	return zastavanost;
}

int Objekt::getCelkovaVymera()
{
	return celkovaVymera;
}

int Objekt::getZastavanaPlocha()
{
	return zastavanaPlocha;
}

string Objekt::vypisObjekt()
{
	stringstream vypisInfo;
	vypisInfo << "Nazov: " << getNazov() << endl;
	vypisInfo << "Pocet obyvatelov: " << getPocetObyvatelov() << endl;
	vypisInfo << "Pocet preproduktivnych: " << getPocetPreproduktivnych() << endl;
	vypisInfo << "Pocet produktivnych: " << getPocetProduktivnych() << endl;
	vypisInfo << "Pocet poproduktivnych: " << getPocetPoproduktivnych() << endl;
	vypisInfo << "Zastavanost: " << getZastavanost() << endl;
	vypisInfo << "Celkova vymera: " << getCelkovaVymera() << endl;
	vypisInfo << "Zastavana plocha: " << getZastavanaPlocha() << endl;
	return vypisInfo.str();
}
