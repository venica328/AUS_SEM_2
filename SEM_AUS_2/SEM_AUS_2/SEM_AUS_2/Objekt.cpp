#include "Objekt.h"
#include <sstream>
#include <locale.h>
#include <iostream>
#include <string>

using namespace std;
using namespace structures;

Objekt::Objekt(string nazov, int pocetObyvatelov, int pocPreprodObyvatelov, int pocProduktivnychObyvatelov, 
	int pocPoprodObyvatelov, int zastavanost, int celkovaVymera, int zastavanaPlocha) :
	nazov(nazov), pocetObyvatelov(pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov), 
	pocPreprodObyvatelov(pocPreprodObyvatelov),	pocProduktivnychObyvatelov(pocProduktivnychObyvatelov), 
	pocPoprodObyvatelov(pocPoprodObyvatelov), zastavanost(celkovaVymera - zastavanaPlocha),
	celkovaVymera(celkovaVymera), zastavanaPlocha(zastavanaPlocha),
	objektNazov(new Treap<string, AddData*>()),
	objektObyvatelia(new Treap<int, AddDataObyvatelia*>()),
	objektZastavanost(new Treap<int, AddDataZastavanost*>())
{
}

Objekt::~Objekt()
{
	for (auto it = objektNazov->begin(); it != objektNazov->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektNazov->clear();
	delete objektNazov;
	objektNazov = nullptr;

	for (auto it = objektObyvatelia->begin(); it != objektObyvatelia->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektObyvatelia->clear();
	delete objektObyvatelia;
	objektObyvatelia = nullptr;

	for (auto it = objektZastavanost->begin(); it != objektZastavanost->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektZastavanost->clear();
	delete objektZastavanost;
	objektZastavanost = nullptr;
}

void Objekt::setAddedData(AddData* data)
{
	string key = data->getNazov();
	//key = setlocale(LC_ALL, "slovak");
	objektNazov->insert(key, data);
	objektNazov->isEmpty();
}

void Objekt::setAddedDataPocObyvatelov(AddDataObyvatelia* pocObyvatelov)
{
	int key = pocObyvatelov->getPocetObyvatelov();
	//key = setlocale(LC_ALL, "slovak");
	objektObyvatelia->insert(key, pocObyvatelov);
}

void Objekt::setAddedDataZastavanost(AddDataZastavanost* zastavanost)
{
	int key = zastavanost->getZastavanost();
	//key = setlocale(LC_ALL, "slovak");
	objektZastavanost->insert(key, zastavanost);
}

void Objekt::setDataToTable(UnsortedSequenceTable<int, AddDataObyvatelia*>* tableObyvatelia, AddDataObyvatelia* pocObyvatelov)
{
	int key = pocObyvatelov->getPocetObyvatelov();
	tableObyvatelia->insert(key, pocObyvatelov);
}

AddData* Objekt::getAddedData(string nazov)
{
	//nazov = setlocale(LC_ALL, "slovak");
	//cout << "nazov: " << (*objekty)[nazov]->getNazov() << endl;
	if (objektNazov->containsKey(nazov))
	{
		return (*objektNazov)[nazov];
	}
	else
	{
		return nullptr;
	}
}


AddDataObyvatelia* Objekt::getAddedDataPocObyvatelov(int pocet)
{
	if (objektObyvatelia->containsKey(pocet))
	{
		return (*objektObyvatelia)[pocet];
	}
	else
	{
		return nullptr;
	}
}

AddDataZastavanost* Objekt::getAddedDataZastavanost(int zastavanost)
{
	if (objektZastavanost->containsKey(zastavanost))
	{
		return (*objektZastavanost)[zastavanost];
	}
	else
	{
		return nullptr;
	}
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
