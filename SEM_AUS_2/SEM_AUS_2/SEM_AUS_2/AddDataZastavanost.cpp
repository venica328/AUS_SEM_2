#include "AddDataZastavanost.h"

AddDataZastavanost::AddDataZastavanost(int zastavanost) : zastavanost(zastavanost)
{
}

AddDataZastavanost::~AddDataZastavanost()
{
}

int AddDataZastavanost::getZastavanost()
{
	return zastavanost;
}
