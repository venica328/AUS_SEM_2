#include "ClenenieSR.h"

ClenenieSR::ClenenieSR(string nazovObce, string nazovOkresu, string nazovKraja, string nazovRepubliky) :
	nazovObce(nazovObce),nazovOkresu(nazovOkresu),nazovKraja(nazovKraja),nazovRepubliky(nazovRepubliky)
{
}

ClenenieSR::~ClenenieSR()
{
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
	vypisInfo << "Republika: " << getRepubliku() << endl;
	return vypisInfo.str();
}
