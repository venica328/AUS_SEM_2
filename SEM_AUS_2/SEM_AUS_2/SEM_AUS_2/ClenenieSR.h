#pragma once
#include <string>
#include <sstream>
#include <locale.h>
#include "../structures/table/treap.h"
#include "Obec.h"

using namespace std;
using namespace structures;

class ClenenieSR
{
public:
	ClenenieSR(string nazovObce, string nazovOkresu, string nazovKraja, string nazovRepubliky);
	~ClenenieSR();

	void setDataObec(Obec* dataObec);
	Obec* getDataObec(string nazov);
	Treap<string, Obec*>* getObjektyObce() { return objektObec; }
	string getRepubliku();
	string getNazovObce();
	string getNazovOkresu();
	string getNazovKraja();
	string vypisObjekt();

private:
	string nazovObce;
	string nazovOkresu;
	string nazovKraja;
	string nazovRepubliky;
	Treap<string, Obec*>* objektObec;
};

