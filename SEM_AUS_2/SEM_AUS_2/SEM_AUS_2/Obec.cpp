#include "Obec.h"

Obec::Obec(string nazovObce) : nazovObce(nazovObce)
{
}

Obec::~Obec()
{
}

string Obec::getNazovObce()
{
	return nazovObce;
}
