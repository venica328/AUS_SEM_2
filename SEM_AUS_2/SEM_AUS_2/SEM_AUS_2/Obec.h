#pragma once
#include <string>

using namespace std;

class Obec
{
public:
	Obec(string nazovObce);
	~Obec();
	string getNazovObce();

private:
	string nazovObce;
};

