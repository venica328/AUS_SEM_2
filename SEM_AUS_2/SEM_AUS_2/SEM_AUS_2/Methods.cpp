#include "Methods.h"
#include <iostream>

using namespace std;
using namespace structures;

Methods::Methods()
{
	obce = new Treap<string, Objekt*>();
}

Methods::~Methods()
{
}

Objekt* Methods::getNazovSlovensko()
{
	return slovensko;
}

Objekt* Methods::getNazovObce(string nazov)
{
	return (*obce)[nazov];
}

Objekt* Methods::getNazovOkresu(string nazov)
{
	return (*okresy)[nazov];
}

Objekt* Methods::getNazovKraja(string nazov)
{
	return (*kraje)[nazov];
}

void Methods::method1()
{
	Treap<string, Objekt*>* objekt = nullptr;
	objekt = obce;
	objekt->isEmpty();
	string obec = "Prievidza";

	cout << (*objekt)[obec]->vypisObjekt();

	if (objekt->containsKey(obec))
	{
		cout << (*objekt)[obec]->vypisObjekt();
	}
	else
	{
		cout << "kravinaaaaaaaa" << endl;
	}

	cout << "Vyber filter: 1 = nazov | 2 = pocet obyvatelov | 3 = zastavanost" << endl;
	string nazov = "";
	int pocObyvatelov = 0;
	int zastavanost = 0;
	int filter = 0;
	cin >> filter;

	switch (filter)
	{
	case 1:
		cout << "Zadaj nazov!" << endl;
		cin >> nazov;
		objekt->containsKey(nazov) ? cout << (*objekt)[nazov]->vypisObjekt() << endl :
			cout << "Zadali ste zly nazov/Taky objekt neexistuje!" << endl;
		break;
	case 2:
		objekt = okresy;
		break;
	case 3:
		objekt = kraje;
		break;
	default:
		cout << "Zly typ!" << endl;
		break;
	}
}

void Methods::method3()
{
	Treap<string, Objekt*>* objekt = nullptr;
	cout << "Vyber typ: 1 = obec | 2 = okres | 3 = kraj" << endl;
	int typ = 0;
	cin >> typ;

	switch (typ)
	{
	case 1:
		objekt = obce;
		break;
	case 2:
		objekt = okresy;
		break;
	case 3:
		objekt = kraje;
		break;
	default:
		cout << "Zly typ!" << endl;
		break;
	}


	cout << "Vyber filter: 1 = nazov | 2 = pocet obyvatelov | 3 = zastavanost" << endl;
	string nazov = "";
	int pocObyvatelov = 0;
	double zastavanost = 0;
	int filter = 0;
	cin >> filter;

	switch (filter)
	{
	case 1:
		cout << "Zadaj nazov!" << endl;
		cin >> nazov;
		objekt->containsKey(nazov) ? cout << (*objekt)[nazov]->vypisObjekt() << endl : 
			cout << "Zadali ste zly nazov/Taky objekt neexistuje!" << endl;
		break;
	case 2:
		objekt = okresy;
		break;
	case 3:
		objekt = kraje;
		break;
	default:
		cout << "Zly typ!" << endl;
		break;
	}
}
