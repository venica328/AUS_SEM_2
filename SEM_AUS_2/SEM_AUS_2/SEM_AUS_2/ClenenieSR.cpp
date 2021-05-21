#include "ClenenieSR.h"

ClenenieSR::ClenenieSR(string nazovObce, string nazovOkresu, string nazovKraja, string nazovRepubliky) :
	nazovObce(nazovObce),nazovOkresu(nazovOkresu),nazovKraja(nazovKraja),nazovRepubliky(nazovRepubliky),
	objektObec(new Treap<string, Obec*>()),
	objektOkres(new Treap<string, Okres*>()),
	objektKraj(new Treap<string, Kraj*>())
{
}

ClenenieSR::~ClenenieSR()
{
	for (auto it = objektObec->begin(); it != objektObec->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektObec->clear();
	delete objektObec;
	objektObec = nullptr;

	for (auto it = objektOkres->begin(); it != objektOkres->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektOkres->clear();
	delete objektOkres;
	objektOkres = nullptr;

	for (auto it = objektKraj->begin(); it != objektKraj->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	objektKraj->clear();
	delete objektKraj;
	objektKraj = nullptr;
}

void ClenenieSR::setDataObec(Obec* dataObec)
{
	QuickSort<string, Obec*> stringSort;
	UnsortedSequenceTable<string, Obec*> nazovTable;
	string key = dataObec->getNazovObce();
	//key = setlocale(LC_ALL, "slovak");
	objektObec->insert(key, dataObec);
	nazovTable.insert(key, dataObec);

}

void ClenenieSR::setDataOkres(Okres* dataOkres)
{
	string key = dataOkres->getNazovOkresu();
	//key = setlocale(LC_ALL, "slovak");
	objektOkres->insert(key, dataOkres);
}

void ClenenieSR::setDataKraj(Kraj* dataKraj)
{
	string key = dataKraj->getNazovKraja();
	//key = setlocale(LC_ALL, "slovak");
	objektKraj->insert(key, dataKraj);
}

Obec* ClenenieSR::getDataObec(string nazov)
{
	if (objektObec->containsKey(nazov))
	{
		return (*objektObec)[nazov];
	}
	else
	{
		return nullptr;
	}
}

Okres* ClenenieSR::getDataOkres(string nazov)
{
	if (objektOkres->containsKey(nazov))
	{
		return (*objektOkres)[nazov];
	}
	else
	{
		return nullptr;
	}
}

Kraj* ClenenieSR::getDataKraj(string nazov)
{
	if (objektKraj->containsKey(nazov))
	{
		return (*objektKraj)[nazov];
	}
	else
	{
		return nullptr;
	}
}

string ClenenieSR::getRepubliku()
{
	return "Slovensko";
}

string ClenenieSR::getNazovObce()
{
	return nazovObce;
}

string ClenenieSR::getNazovOkresu()
{
	return nazovOkresu;
}

string ClenenieSR::getNazovKraja()
{
	return nazovKraja;
}

string ClenenieSR::vypisObjekt()
{
	stringstream vypisInfo;
	vypisInfo << "Obec: " << getNazovObce() << endl;
	vypisInfo << "Okres: " << getNazovOkresu() << endl;
	vypisInfo << "Kraj: " << getNazovKraja() << endl;
	vypisInfo << "Stat: " << getRepubliku() << endl;
	return vypisInfo.str();
}
