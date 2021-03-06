#pragma once
#include "Objekt.h"
#include "AddData.h"
#include "AddDataObyvatelia.h"
#include "AddDataZastavanost.h"
#include "Methods.h"
#include "ClenenieSR.h"
#include "../structures/table/treap.h"
#include "../structures/table/unsorted_sequence_table.h"
#include "../structures/table/sorting/quick_sort.h"

class ReadFiles
{
private:

public:
	ReadFiles();
	void readSlovensko();
	void readClenenie();
	string zistiNazovObce(string nazov);
	string zistiNazovOkresu(string nazov);
	string zistiNazovKraja(string nazov);
	int zistiCisloUlohy(int uloha);
	int zistiMIN(int min);
	int zistiMAX(int max);
	void zistiVzostupnost(int vzostupnost);
	string separateData(string obec, string name);
	string separateKraj(string kraj, string name);
	string separateObec(string obec, string name);

	structures::Treap<string, Objekt*>* treap = nullptr;
	structures::Treap<string, AddData*>* addData = nullptr;
	structures::Treap<int, AddDataObyvatelia*>* addDataObyvatelia = nullptr;
	structures::Treap<int, AddDataZastavanost*>* addDataZastavanost = nullptr;
	structures::Treap<string, Obec*>* addDataObec = nullptr;
	structures::Treap<string, Okres*>* addDataOkres = nullptr;
	structures::Treap<string, Kraj*>* addDataKraj = nullptr;
	UnsortedSequenceTable<string, AddData*>* nazovTable = nullptr;
	UnsortedSequenceTable<int, AddDataObyvatelia*>* obyvateliaTable = nullptr;
	UnsortedSequenceTable<int, AddDataZastavanost*>* zastavanostTable = nullptr;
	QuickSort<string, AddData*>* stringSort = nullptr;
	QuickSort<int, AddDataObyvatelia*>* intSort = nullptr;
	QuickSort<int, AddDataZastavanost*>* intSortZastavanost = nullptr;
	void otocPoradie(UnsortedSequenceTable<string, Obec*> *oldTable);
	void otocPoradieObyvatelov(UnsortedSequenceTable<int, AddDataObyvatelia*> *oldTableObyvatelia);
	void otocPoradieZastavanost(UnsortedSequenceTable<int, AddDataZastavanost*> *oldTableZastavanost);
	void vypisObce();
	void vypisObyvatelov();
	void vypisZastavanost();
	void vynuluj();
	~ReadFiles();

private:
	UnsortedSequenceTable<string, Obec*>* tableObec;
	UnsortedSequenceTable<int, AddDataObyvatelia*>* tableObyvatelia;
	UnsortedSequenceTable<int, AddDataZastavanost*>* tableZastavanost;
	QuickSort<string, Obec*>* sortingObce;
	QuickSort<int, AddDataObyvatelia*>* sortingObyvatelia;
	QuickSort<int, AddDataZastavanost*>* sortingZastavanost;
};

