#pragma once
#include "ReadFiles.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <locale.h>

using namespace std;
using namespace structures;

ReadFiles::ReadFiles()
{
	treap = new Treap<string, Objekt*>();
	addData = new Treap<string, AddData*>();
	addDataObyvatelia = new Treap<int, AddDataObyvatelia*>();
	addDataZastavanost = new Treap<int, AddDataZastavanost*>();
}

void ReadFiles::readSlovensko()
{
	ifstream file;
	file.open("../CSV/Obce.csv");
	string line;
	string nazov = setlocale(LC_ALL,"slovak");
	
	int rows = 0;

	int pocPreprodObyvatelov;
	int pocProduktivnychObyvatelov;
	int pocPoprodObyvatelov;
	int celkovaVymera;
	int zastavanaPlocha;
	
	while (!file.eof())
	{
		rows++;

		if (rows < 2)
		{
			getline(file, line);
			getline(file, line, ';');
		}
		
		if (rows > 1) {
			string pom;
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
				Objekt* slovensko = new Objekt(nazov, pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov, pocPreprodObyvatelov, pocProduktivnychObyvatelov, pocPoprodObyvatelov,
					celkovaVymera - zastavanaPlocha, celkovaVymera, zastavanaPlocha);
				//std::cout << slovensko->vypisObjekt() << endl;

				AddData* data = new AddData(nazov);
				slovensko->setAddedData(data);
				AddDataObyvatelia* dataObyvatelia = new AddDataObyvatelia(pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov);
				slovensko->setAddedDataPocObyvatelov(dataObyvatelia);
				AddDataZastavanost* dataZastavanost = new AddDataZastavanost(zastavanaPlocha);
				slovensko->setAddedDataZastavanost(dataZastavanost);
				
			}
			else
			{
				Objekt* slovensko = new Objekt(pom, pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov, pocPreprodObyvatelov, pocProduktivnychObyvatelov, pocPoprodObyvatelov,
					celkovaVymera - zastavanaPlocha, celkovaVymera, zastavanaPlocha);
				//std::cout << slovensko->vypisObjekt() << endl;

				AddData* data = new AddData(pom);
				slovensko->setAddedData(data);
				AddDataObyvatelia* dataObyvatelia = new AddDataObyvatelia(pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov);
				slovensko->setAddedDataPocObyvatelov(dataObyvatelia);
				AddDataZastavanost* dataZastavanost = new AddDataZastavanost(celkovaVymera - zastavanaPlocha);
				slovensko->setAddedDataZastavanost(dataZastavanost);

				/**
				string p = "Valaská Belá";
				if (slovensko->getAddedData(pom)->getNazov() == p)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
				int p = 2051;
				if (slovensko->getAddedDataPocObyvatelov(pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov)->getPocetObyvatelov() <= 100)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
				if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() > 50000)
				{
					cout << slovensko->vypisObjekt() << endl;
				}**/
			}
		}	
	}
	//celkovy pocet riadkov
	std::cout << rows <<endl;

	file.close();
}

void ReadFiles::readKraje()
{
	
}

void ReadFiles::readOkresy()
{
}

void ReadFiles::readObce()
{
}

string ReadFiles::readClenenie(string obec)
{
	ifstream file;
	file.open("../CSV/Clenenie.csv");
	string line;
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
				ClenenieSR* clenenie = new ClenenieSR(nazovObce, nazovOkresu, pom2, nazovRepubliky);
				std::cout << clenenie->vypisObjekt() << endl;

				AddData* data = new AddData(nazovObce);
				//clenenie->setAddedData(data);
				string p = "Prievidza";
			}
			else
			{
				ClenenieSR* clenenie = new ClenenieSR(pom, nazovOkresu, pom2, nazovRepubliky);
				std::cout << clenenie->vypisObjekt() << endl;

				AddData* data = new AddData(nazovObce);
				//clenenie->setAddedData(data);
				string p = "Prievidza";
			}
		}
	}
	//celkovy pocet riadkov
	std::cout << rows << endl;

	file.close();

	return string;
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
			name = obec.substr(i+1,siz);
			obec = name;
		}
	}
	return name;
}

ReadFiles::~ReadFiles()
{
}
