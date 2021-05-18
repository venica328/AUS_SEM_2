#pragma once
#include <string>

using namespace std;

class Okres
{
public:
	Okres(string nazovOkresu);
	~Okres();
	string getNazovOkresu();

private:
	string nazovOkresu;
};

