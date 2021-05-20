#pragma once
#include <string>
#include <sstream>
#include <locale.h>
#include "../structures/table/treap.h"
#include "Obec.h"
#include "Okres.h"

using namespace std;
using namespace structures;

class ClenenieSR
{
public:
	ClenenieSR(string nazovObce, string nazovOkresu, string nazovKraja, string nazovRepubliky);
	~ClenenieSR();

	void setDataObec(Obec* dataObec);
	void setDataOkres(Okres* dataOkres);
	Obec* getDataObec(string nazov);
	Okres* getDataOkres(string nazov);
	Treap<string, Obec*>* getObjektyObce() { return objektObec; }
	Treap<string, Okres*>* getObjektyOkres() { return objektOkres; }
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
	Treap<string, Okres*>* objektOkres;
};

