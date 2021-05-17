#pragma once
#include "Objekt.h"
#include "AddData.h"
#include "Methods.h"
#include "ClenenieSR.h"
#include "../structures/table/treap.h"
#include "../structures/table/unsorted_sequence_table.h"

class ReadFiles
{
private:

public:
	ReadFiles();
	void readSlovensko();
	void readKraje();
	void readOkresy();
	void readObce();
	void readClenenie();
	string separateData(string obec, string name);
	string separateKraj(string kraj, string name);
	string separateObec(string obec, string name);
	structures::Treap<string, Objekt*>* treap = nullptr;
	structures::Treap<string, AddData*>* addData = nullptr;
	~ReadFiles();
};

