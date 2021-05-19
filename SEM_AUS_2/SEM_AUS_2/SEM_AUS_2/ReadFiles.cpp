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
int argCisloUlohy;
int argMin;
int argMax;
int argZastavanost;

ReadFiles::ReadFiles()
{
	treap = new Treap<string, Objekt*>();
	addData = new Treap<string, AddData*>();
	addDataObyvatelia = new Treap<int, AddDataObyvatelia*>();
	addDataZastavanost = new Treap<int, AddDataZastavanost*>();
	addDataObec = new Treap<string, Obec*>();
}

void ReadFiles::readSlovensko()
{
	ifstream file;
	file.open("../CSV/Obce.csv");
	string line;
	string nazov = setlocale(LC_ALL,"slovak");
	string nazovObce = setlocale(LC_ALL, "slovak");
	string pom;
	
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

			AddDataZastavanost* dataZastavanost = new AddDataZastavanost(celkovaVymera - zastavanaPlocha);
			slovensko->setAddedDataZastavanost(dataZastavanost);

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
					cout << slovensko->vypisObjekt() << endl;
				}
			}
			if (argCisloUlohy == 13)
			{
				if (slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() <= argMax &&
					slovensko->getAddedDataZastavanost(celkovaVymera - zastavanaPlocha)->getZastavanost() >= argMin)
				{
					cout << slovensko->vypisObjekt() << endl;
				}
			}
		}	
	}
	//celkovy pocet riadkov
	//std::cout << rows <<endl;

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
			//std::cout << clenenie->vypisObjekt() << endl;

			Obec* obec = new Obec(nazov);
			clenenie->setDataObec(obec);


			if (clenenie->getDataObec(nazov)->getNazovObce() == argNazovObce)
			{
				cout << clenenie->vypisObjekt() << endl;
			}
		}
	}
	//celkovy pocet riadkov
	//std::cout << rows << endl;

	file.close();
}

string ReadFiles::zistiNazovObce(string nazov)
{
	argNazovObce = nazov;
	int siz = nazov.length();
	for (int i = 0; i < nazov.length(); i++) {
		if (nazov[i] == '*')
		{
			nazov[i] = ' ';
		}
	}
	argNazovObce = nazov;
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
