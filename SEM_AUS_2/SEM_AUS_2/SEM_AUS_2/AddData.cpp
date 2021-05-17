#include "AddData.h"

AddData::AddData(string nazov) : nazov(nazov)
{
}

AddData::~AddData()
{
}

string AddData::getNazov()
{
    return nazov;
}
