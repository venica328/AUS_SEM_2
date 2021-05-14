#pragma once
#include "ReadFiles.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
using namespace structures;

ReadFiles::ReadFiles()
{
}

void ReadFiles::readSlovensko()
{
	ifstream file;
	file.open("../CSV/Obce.csv");
	string line;
	string nazov;
	
	int rows = 0;
	int pocObjektov=0;

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

			int siz = nazov.length();
			for (int i = 0; i < nazov.length(); i++) {
				if (nazov[i] == '\n') {
					pom = nazov.substr(i+1, siz);
					nazov = pom;
				}
			}
			
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
					celkovaVymera, celkovaVymera, zastavanaPlocha);
				std::cout << slovensko->vypisObjekt() << endl;
			}
			else
			{
				Objekt* slovensko = new Objekt(pom, pocPreprodObyvatelov + pocProduktivnychObyvatelov +
					pocPoprodObyvatelov, pocPreprodObyvatelov, pocProduktivnychObyvatelov, pocPoprodObyvatelov,
					celkovaVymera, celkovaVymera, zastavanaPlocha);
				std::cout << slovensko->vypisObjekt() << endl;
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

ReadFiles::~ReadFiles()
{
}
