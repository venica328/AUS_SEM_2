#pragma once
#include "ReadFiles.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <locale.h>

using namespace std;
using namespace structures;

string argNazovObce = "";
string argNazovOkresu = "";
string argNazovKraja = "";
string argOkres = "";
string argKraj = "";
string argObec = "";
bool argEscape = false;
int argCisloUlohy;
int argMin;
int argMax;
int argVzostupnost;
int argZastavanost;
int argumentZastavanost;
int argObyvatelia;

ReadFiles::ReadFiles() : tableObec(new UnsortedSequenceTable<string, Obec*>()),
						 sortingObce(new QuickSort<string, Obec*>()),
						tableObyvatelia(new UnsortedSequenceTable<int, AddDataObyvatelia*>()),
						sortingObyvatelia(new QuickSort<int, AddDataObyvatelia*>()),
						tableZastavanost(new UnsortedSequenceTable<int, AddDataZastavanost*>()),
						sortingZastavanost(new QuickSort<int, AddDataZastavanost*>())
{
	treap = new Treap<string, Objekt*>();
	addData = new Treap<string, AddData*>();
	addDataObyvatelia = new Treap<int, AddDataObyvatelia*>();
	addDataZastavanost = new Treap<int, AddDataZastavanost*>();
	addDataObec = new Treap<string, Obec*>();
	addDataOkres = new Treap<string, Okres*>();
	addDataKraj = new Treap<string, Kraj*>();
	nazovTable = new UnsortedSequenceTable<string, AddData*>;
	stringSort = new QuickSort<string, AddData*>;
}

void ReadFiles::readSlovensko()
{
	ifstream file;
	file.open("../CSV/Obce.csv");
	string line;
	string nazov = setlocale(LC_ALL, "slovak");
	string nazovObce = setlocale(LC_ALL, "slovak");
	string pom;
	
	int rows = 0;
	int rowsTotal = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
	file.clear();
	file.seekg(0);

	int pocPreprodObyvatelov;
	int pocProduktivnychObyvatelov;
	int pocPoprodObyvatelov;
	int celkovaVymera;
	int zastavanaPlocha;
	
	while (rows < rowsTotal)
	{
		rows++;
		
		if (rows < 2)
		{
			getline(file, line);
			getline(file, line, ';');
		}
		
		if (rows > 1) {
			
			nazov = line;
			pom = this->separateData(nazov, pom);

			getline(file, line, ';');
			pocPreprodObyvatelov = stoi(line);
			getline(file, line, ';');
			pocProduktivnychObyvatelov = stoi(line);
			getline(file, line, ';');
			pocPoprodObyvatelov = stoi(line);
			getline(file, line, ';');
			celkovaVymera = stoi(line);
			getline(file, line, ';');
			zastavanaPlocha = stoi(line);
		
			if (rows == 2) {
				nazovObce = nazov;				
			}
			else
			{
				nazovObce = pom;
			}

			Objekt* slovensko = new Objekt(nazovObce, pocPreprodObyvatelov + pocProduktivnychObyvatelov +
				pocPoprodObyvatelov, pocPreprodObyvatelov, pocProduktivnychObyvatelov, pocPoprodObyvatelov,
				celkovaVymera - zastavanaPlocha, celkovaVymera, zastavanaPlocha);

			AddData* data = new AddData(nazovObce);
			slovensko->setAddedData(data);

			AddDataObyvatelia* dataObyvatelia = new AddDataObyvatelia(pocPreprodObyvatelov + pocProduktivnychObyvatelov +
				pocPoprodObyvatelov);
			slovensko->setAddedDataPocObyvatelov(dataObyvatelia);
			if (argCisloUlohy != 422 && argCisloUlohy != 432)
			{
				slovensko->setDataToTable(tableObyvatelia, dataObyvatelia);
			}

			AddDataZastavanost* dataZastavanost = new AddDataZastavanost(celkovaVymera - zastavanaPlocha);
			slovensko->setAddedDataZastavanost(dataZastavanost);
			if (argCisloUlohy != 423 && argCisloUlohy != 433)
			{
				slovensko->setDataToTableZastavanost(tableZastavanost, dataZastavanost);
			}
			

			if (argCisloUlohy == 10)
			{
				cout << slovensko->vypisObjekt() << endl;
				argNazovObce = slovensko->getNazov();
				this->readClenenie();
			}
			if (argCisloUlohy == 11)
			{
				if (slovensko->getAddedData(nazovObce)->getNazov() == argNazovObce)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
			}
			if (argCisloUlohy == 12)
			{
				int poc_Obyvatelov = pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov;
				if (slovensko->getAddedDataPocObyvatelov(poc_Obyvatelov)->getPocetObyvatelov() <= argMax &&
					slovensko->getAddedDataPocObyvatelov(poc_Obyvatelov)->getPocetObyvatelov() >= argMin)
				{
					argObec = slovensko->getNazov();
					cout << slovensko->vypisObjekt() << endl;
					this->readClenenie();
				}
			}
			if (argCisloUlohy == 13)
			{
				if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() <= argMax &&
					slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() >= argMin)
				{
					argObec = slovensko->getNazov();
					cout << slovensko->vypisObjekt() << endl;
					this->readClenenie();
				}
			}

			if (argCisloUlohy == 21)
			{
				if (slovensko->getAddedData(nazovObce)->getNazov() == argObec)
				{
					cout << slovensko->vypisObjekt() << endl;
					delete slovensko;
					file.close();
					return;
				}
			}

			if (argCisloUlohy == 22 || argCisloUlohy == 422 || argCisloUlohy == 432)
			{
				if (slovensko->getAddedDataPocObyvatelov(pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov)->getPocetObyvatelov() == argObyvatelia)
				{
					cout << slovensko->vypisObjekt() << endl;
					delete slovensko;
					file.close();
					return;
				}
			}

			if (argCisloUlohy == 23 || argCisloUlohy == 423 || argCisloUlohy == 433)
			{
				if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() == argZastavanost)
				{
					cout << slovensko->vypisObjekt() << endl;
					delete slovensko;
					file.close();
					return;
				}
			}

			if (argCisloUlohy == 31)
			{
				argObec = slovensko->getNazov();
				cout << slovensko->vypisObjekt() << endl;
				this->readClenenie();
			}
			
			if (argCisloUlohy == 321 || argCisloUlohy == 33)
			{
				if (slovensko->getNazov() == argObec)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
			}

			if (argCisloUlohy == 322)
			{
				if (slovensko->getNazov() == argObec)
				{
					int poc_Obyvatelov = pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov;
					if (poc_Obyvatelov <= argMax && poc_Obyvatelov >= argMin)
					{
						argObec = slovensko->getNazov();
						argNazovObce = slovensko->getNazov();
						cout << slovensko->vypisObjekt() << endl;
						argEscape = true;
						this->readClenenie();

						delete slovensko;
						file.close();
						return;
					}
				}
			}

			if (argCisloUlohy == 323)
			{
				if (slovensko->getNazov() == argObec)
				{
					if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() <= argMax &&
						slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() >= argMin)
					{
						argObec = slovensko->getNazov();
						argNazovObce = slovensko->getNazov();
						cout << slovensko->vypisObjekt() << endl;
						argEscape = true;
						this->readClenenie();

						delete slovensko;
						file.close();
						return;
					}
				}
			}

			if (argCisloUlohy == 331)
			{
				if (slovensko->getNazov() == argObec)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
			}

			if (argCisloUlohy == 332)
			{
				if (slovensko->getNazov() == argObec)
				{
					int poc_Obyvatelov = pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov;
					if (slovensko->getAddedDataPocObyvatelov(poc_Obyvatelov)->getPocetObyvatelov() <= argMax &&
						slovensko->getAddedDataPocObyvatelov(poc_Obyvatelov)->getPocetObyvatelov() >= argMin)
					{
						argObec = slovensko->getNazov();
						argNazovObce = slovensko->getNazov();
						cout << slovensko->vypisObjekt() << endl;
						argEscape = true;
						this->readClenenie();

						delete slovensko;
						file.close();
						return;
					}
				}
			}

			if (argCisloUlohy == 333)
			{
				if (slovensko->getNazov() == argObec)
				{
					if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() <= argMax &&
						slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() >= argMin)
					{
						argObec = slovensko->getNazov();
						argNazovObce = slovensko->getNazov();
						cout << slovensko->vypisObjekt() << endl;
						argEscape = true;
						this->readClenenie();

						delete slovensko;
						file.close();
						return;
					}
				}
			}

			if (argCisloUlohy == 422 || argCisloUlohy == 432)
			{
				if (slovensko->getNazov() == argObec)
				{
					int poc_Obyvatelov = pocPreprodObyvatelov + pocProduktivnychObyvatelov + pocPoprodObyvatelov;
					if (poc_Obyvatelov <= argMax && poc_Obyvatelov >= argMin)
					{
						slovensko->setDataToTable(tableObyvatelia, dataObyvatelia);
					}

					delete slovensko;
					return;
				}
			}

			if (argCisloUlohy == 423 || argCisloUlohy == 433)
			{
				if (slovensko->getNazov() == argObec)
				{
					if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() <= argMax &&
						slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() >= argMin)
					{
						slovensko->setDataToTableZastavanost(tableZastavanost, dataZastavanost);
					}

					delete slovensko;
					return;
				}
			}

			delete slovensko;
		}	
	}

	bool zostupne = argVzostupnost == 2;

	if (argCisloUlohy == 22 || argCisloUlohy == 432)
	{
		sortingObyvatelia->sort(*tableObyvatelia);
		if (zostupne)
		{
			otocPoradieObyvatelov(tableObyvatelia);
		}
		vypisObyvatelov();
	}
	if (argCisloUlohy == 23)
	{
		sortingZastavanost->sort(*tableZastavanost);
		if (zostupne)
		{
			otocPoradieZastavanost(tableZastavanost);
		}
		vypisZastavanost();
	}

	file.close();
}



void ReadFiles::readClenenie()
{
	ifstream file;
	file.open("../CSV/Clenenie.csv");
	string line;
	string nazov;
	string nazovObce = setlocale(LC_ALL, "slovak");
	string nazovOkresu = setlocale(LC_ALL, "slovak");
	string nazovKraja = setlocale(LC_ALL, "slovak");
	string nazovRepubliky = "Slovensko";

	int rows = 0;
	string pom;
	string pom2;

	while (!file.eof())
	{
		rows++;
		
		if (rows < 2)
		{
			getline(file, line);
			getline(file, line, ';');
		}

		if (rows > 1) 
		{
			nazovObce = line;
			getline(file, line, ';');
			nazovOkresu = line;
			getline(file, line, ';');
			nazovKraja = line;

			pom = this->separateObec(nazovObce, pom);
			pom2 = this->separateKraj(nazovKraja, pom2);

			if (rows == 2) 
			{
				nazov = nazovObce;
			}
			else
			{
				nazov = pom;
			}
			
			ClenenieSR* clenenie = new ClenenieSR(nazov, nazovOkresu, pom2, nazovRepubliky);

			bool zostupne = true;

			Obec* obec = new Obec(nazov);
			clenenie->setDataObec(obec);
			if (argCisloUlohy != 421 && argCisloUlohy != 431)
			{
				clenenie->setDataToTable(tableObec, obec);
			}

			Okres* okres = new Okres(nazovOkresu);
			clenenie->setDataOkres(okres);

			Kraj* kraj = new Kraj(pom2);
			clenenie->setDataKraj(kraj);


			if (clenenie->getDataObec(nazov)->getNazovObce() == argNazovObce)
			{
				cout << clenenie->vypisObjekt() << endl;

				if (argEscape)
				{
					argEscape = false;
					delete clenenie;
					file.close();
					return;
				}
			}
			if (argCisloUlohy == 12 || argCisloUlohy == 13)
			{
				if (clenenie->getDataObec(nazov)->getNazovObce() == argObec)
				{
					cout << clenenie->vypisObjekt() << endl;
					delete clenenie;
					file.close();
					return;
				}
			}

			if (argCisloUlohy == 321)
			{
				if (clenenie->getDataOkres(nazovOkresu)->getNazovOkresu() == argNazovOkresu)
				{
					argOkres = clenenie->getNazovOkresu();
					if (clenenie->getNazovObce() == argNazovObce)
					{
						argObec = clenenie->getNazovObce();
						this->readSlovensko();
					}
				}
			}
			if (argCisloUlohy == 322 || argCisloUlohy == 422 || argCisloUlohy == 423)
			{
				if (argCisloUlohy == 322 && argEscape)
				{
					delete clenenie;
					continue;
				}

				if (nazovOkresu == argNazovOkresu)
				{
					argOkres = clenenie->getNazovOkresu();
					argObec = clenenie->getNazovObce();
					this->readSlovensko();
				}
			}
			if (argCisloUlohy == 323)
			{
				if (argEscape)
				{
					delete clenenie;
					continue;
				}

				if (nazovOkresu == argNazovOkresu)
				{
					argOkres = clenenie->getNazovOkresu();
					argObec = clenenie->getNazovObce();
					this->readSlovensko();
				}
			}

			if (argCisloUlohy == 331)
			{
				if (clenenie->getDataKraj(pom2)->getNazovKraja() == argNazovKraja)
				{
					argKraj = clenenie->getNazovKraja();
					if (clenenie->getNazovObce() == argNazovObce)
					{
						argObec = clenenie->getNazovObce();
						this->readSlovensko();
					}
				}
			}

			if (argCisloUlohy == 332 || argCisloUlohy == 432 || argCisloUlohy == 433)
			{
				if (argCisloUlohy == 332 && argEscape)
				{
					delete clenenie;
					continue;
				}

				if (clenenie->getDataKraj(pom2)->getNazovKraja() == argNazovKraja)
				{
					argKraj = clenenie->getNazovKraja();
					argObec = clenenie->getNazovObce();
					this->readSlovensko();
				}
			}

			if (argCisloUlohy == 333)
			{
				if (argEscape)
				{
					delete clenenie;
					continue;
				}

				if (clenenie->getDataKraj(pom2)->getNazovKraja() == argNazovKraja)
				{
					argKraj = clenenie->getNazovKraja();
					argObec = clenenie->getNazovObce();
					this->readSlovensko();
				}
			}

			if (argCisloUlohy == 421)
			{
				if (clenenie->getDataOkres(nazovOkresu)->getNazovOkresu() == argNazovOkresu)
				{
					clenenie->setDataToTable(tableObec, obec);
				}
			}

			if (argCisloUlohy == 431)
			{
				if (clenenie->getDataKraj(pom2)->getNazovKraja() == argNazovKraja)
				{
					clenenie->setDataToTable(tableObec, obec);
				}
			}

			delete clenenie;
		}
	}

	bool zostupne = argVzostupnost == 2;

	if (argCisloUlohy == 31 || argCisloUlohy == 21 || argCisloUlohy == 421 || argCisloUlohy == 431)
	{
		sortingObce->sort(*tableObec);
		if (zostupne)
		{
			otocPoradie(tableObec);
		}
		vypisObce();
	}

	if (argCisloUlohy == 422 || argCisloUlohy == 432)
	{
		sortingObyvatelia->sort(*tableObyvatelia);
		if (zostupne)
		{
			otocPoradieObyvatelov(tableObyvatelia);
		}
		vypisObyvatelov();
	}

	if (argCisloUlohy == 423 || argCisloUlohy == 433)
	{
		sortingZastavanost->sort(*tableZastavanost);
		if (zostupne)
		{
			otocPoradieZastavanost(tableZastavanost);
		}
		vypisZastavanost();
	}

	file.close();
}

string ReadFiles::zistiNazovObce(string nazov)
{
	argNazovObce = nazov;
	int siz = nazov.length();
	for (int i = 0; i < nazov.length(); i++) {
		if (nazov[i] == '_')
		{
			nazov[i] = ' ';
		}
	}
	argNazovObce = nazov;
	return nazov;
}

string ReadFiles::zistiNazovOkresu(string nazov)
{
	string a = "Okres ";
	argNazovOkresu = nazov;
	int siz = nazov.length();
	for (int i = 0; i < nazov.length(); i++) {
		if (nazov[i] == '_')
		{
			nazov[i] = ' ';
		}
	}
	argNazovOkresu = a + nazov;
	//cout << a + nazov << endl;
	return nazov;
}

string ReadFiles::zistiNazovKraja(string nazov)
{
	argNazovKraja = nazov;
	return nazov;
}

int ReadFiles::zistiCisloUlohy(int uloha)
{
	argCisloUlohy = uloha;
	return uloha;
}

int ReadFiles::zistiMIN(int min)
{
	argMin = min;
	return min;
}

int ReadFiles::zistiMAX(int max)
{
	argMax = max;
	return max;
}

void ReadFiles::zistiVzostupnost(int vzostupnost)
{
	argVzostupnost = vzostupnost;
}

string ReadFiles::separateData(string obec, string name)
{
	int siz = obec.length();
	for (int i = 0; i < obec.length(); i++) {
		if (obec[i] == '\n') {
			name = obec.substr(i + 1, siz);
			obec = name;
		}
	}
	return name;
}

string ReadFiles::separateKraj(string kraj, string name)
{
	int siz = kraj.length();
	for (int i = 0; i < kraj.length(); i++) {
		if (kraj[i] == '\n') {
			name = kraj.substr(0, i);
			kraj = name;
		}
	}
	return name;
}

string ReadFiles::separateObec(string obec, string name)
{
	int siz = obec.length();
	for (int i = 0; i < obec.length(); i++) {
		if (obec[i] == '\n') {
			name = obec.substr(i+1, siz);
			obec = name;
		}
	}
	return name;
}

void ReadFiles::otocPoradie(UnsortedSequenceTable<string, Obec*> *oldTable)
{
	UnsortedSequenceTable<string, Obec*> *newTable = new UnsortedSequenceTable<string, Obec*>();

	for (int it = oldTable->size() - 1; it >= 0; it--)
	{
		//Obec* dataObec = oldTable->getItemAtIndex(it).accessData();
		string obec = oldTable->getItemAtIndex(it).getKey();
		newTable->insert(obec, nullptr);
	}

	oldTable->clear();

	for (auto it = newTable->begin(); it != newTable->end(); it.operator++()) {
		string obec = (*it)->getKey();
		oldTable->insert(obec, nullptr);
	}
}


void ReadFiles::otocPoradieObyvatelov(UnsortedSequenceTable<int, AddDataObyvatelia*>* oldTableObyvatelia)
{
	UnsortedSequenceTable<int, AddDataObyvatelia*>* newTable = new UnsortedSequenceTable<int, AddDataObyvatelia*>();

	for (int it = oldTableObyvatelia->size() - 1; it >= 0; it--)
	{
		int obyvatelia = oldTableObyvatelia->getItemAtIndex(it).getKey();
		newTable->insert(obyvatelia, nullptr);
	}

	oldTableObyvatelia->clear();

	for (auto it = newTable->begin(); it != newTable->end(); it.operator++()) {
		int obyvatelia = (*it)->getKey();
		oldTableObyvatelia->insert(obyvatelia, nullptr);
	}
}

void ReadFiles::otocPoradieZastavanost(UnsortedSequenceTable<int, AddDataZastavanost*> *oldTableZastavanost)
{
	UnsortedSequenceTable<int, AddDataZastavanost*>* newTable = new UnsortedSequenceTable<int, AddDataZastavanost*>();

	for (int it = oldTableZastavanost->size() - 1; it >= 0; it--)
	{
		int zastavanost = oldTableZastavanost->getItemAtIndex(it).getKey();
		newTable->insert(zastavanost, nullptr);
	}

	oldTableZastavanost->clear();

	for (auto it = newTable->begin(); it != newTable->end(); it.operator++()) {
		int zastavanost = (*it)->getKey();
		oldTableZastavanost->insert(zastavanost, nullptr);
	}
}

void ReadFiles::vypisObce()
{
	for (TableItem<string, Obec*> *obecIterator : *tableObec)
	{
		cout << obecIterator->getKey() << endl;
		argObec = obecIterator->getKey();
		argNazovObce = obecIterator->getKey();
		readSlovensko();
	}
}

void ReadFiles::vypisObyvatelov()
{
	for (TableItem<int, AddDataObyvatelia*> *obyvateliaIterator : *tableObyvatelia)
	{
		cout << obyvateliaIterator->getKey() << endl;
		argObyvatelia = obyvateliaIterator->getKey();
		readSlovensko();
	}
}

void ReadFiles::vypisZastavanost()
{
	for (TableItem<int, AddDataZastavanost*> *zastavanostIterator : *tableZastavanost)
	{
		cout << zastavanostIterator->getKey() << endl;
		argZastavanost = zastavanostIterator->getKey();
		readSlovensko();
	}
}

void ReadFiles::vynuluj()
{
	argNazovObce = "";
	argNazovOkresu = "";
	argNazovKraja = "";
	argOkres = "";
	argKraj = "";
	argObec = "";
	argEscape = false;
	argCisloUlohy = 0;
	argMin = 0;
	argMax = 0;
	argVzostupnost = 0;
	argZastavanost = 0;
	argumentZastavanost = 0;
	argObyvatelia = 0;
}

ReadFiles::~ReadFiles()
{
	for (auto it = treap->begin(); it != treap->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	treap->clear();
	delete treap;
	//treap = nullptr;

	for (auto it = addData->begin(); it != addData->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addData->clear();
	delete addData;
	//addData = nullptr;

	for (auto it = addDataObyvatelia->begin(); it != addDataObyvatelia->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addDataObyvatelia->clear();
	delete addDataObyvatelia;
	//addDataObyvatelia = nullptr;

	for (auto it = addDataZastavanost->begin(); it != addDataZastavanost->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addDataZastavanost->clear();
	delete addDataZastavanost;
	//addDataZastavanost = nullptr;

	for (auto it = addDataObec->begin(); it != addDataObec->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addDataObec->clear();
	delete addDataObec;
	//addDataObec = nullptr;

	for (auto it = addDataOkres->begin(); it != addDataOkres->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addDataOkres->clear();
	delete addDataOkres;
	//addDataOkres = nullptr;

	for (auto it = addDataKraj->begin(); it != addDataKraj->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	addDataKraj->clear();
	delete addDataKraj;

	for (auto it = nazovTable->begin(); it != nazovTable->end(); it.operator++()) {
		delete (*it)->accessData();
	}
	nazovTable->clear();
	delete nazovTable;

	tableObec->clear();
	delete tableObec;

	tableObyvatelia->clear();
	delete tableObyvatelia;

	tableZastavanost->clear();
	delete tableZastavanost;
}
