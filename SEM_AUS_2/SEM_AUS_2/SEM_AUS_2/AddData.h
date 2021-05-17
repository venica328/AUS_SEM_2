#pragma once
#include <string>

using namespace std;

class AddData
{
public:
	AddData(string nazov);
	~AddData();
	string getNazov();

private:
	string nazov;
};

