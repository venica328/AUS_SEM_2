#pragma once
#include <string>

using namespace std;

class Kraj
{
public:
	Kraj(string nazovKraja);
	~Kraj();
	string getNazovKraja();

private:
	string nazovKraja;
};
