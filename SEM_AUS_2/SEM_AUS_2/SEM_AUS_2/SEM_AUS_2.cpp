#pragma once
#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "ReadFiles.h"
#include "Methods.h"

using namespace std;


int main(char* arc, char** argv)
{
    initHeapMonitor();
    int x = 1, y;
    int min;
    int max;
    int pocetObyvatelov;
    int zastavanost;
    string nazovObce;
    string cele;
  //  char nazovObce[256];

    ReadFiles* r = new ReadFiles();    

    while (x != 0)
    {
        SetConsoleOutputCP(1254);
        SetConsoleCP(1254);

        cout << "\nVyber ulohu!\n"
            << "1 = Uloha1\n"
            << "2 = Uloha2\n"
            << "3 = Uloha3\n"
            << "4 = Uloha4\n"
            << "5 = Uloha5\n"
            << "6 = Uloha6\n"
            << "7 = Uloha7\n"
            << "8 = Uloha8\n"
            << "9 = Uloha9\n"
            << "0 = Koniec" << endl;
        cin >> x;

        switch (x)
        {
        case 0:
            cout << "Koniec..." << endl;
            break;

        case 1:
            cout << "Zisti informacie o obciach podla filtra!" << endl;
            cout << "1 = nazov obce" << endl;
            cout << "2 = pocet obyvatelov" << endl;
            cout << "3 = zastavanost" << endl;
            cin >> y;

            switch (y)
            {
            case 1:
                
                r->zistiCisloUlohy(11);
                cout << "Zadajte nazov obce:" << endl;
                cin >> nazovObce;
                r->zistiNazovObce(nazovObce);
                r->readSlovensko();
                r->readClenenie();
                break;
            case 2:
                r->zistiCisloUlohy(12);
                cout << "Zadajte pocet obyvatelov v intervale!" << endl;
                cout << "MIN: ";
                cin >> min;
                r->zistiMIN(min);
                cout << "MAX: ";
                cin >> max;
                r->zistiMAX(max);
                r->readSlovensko();
                r->readClenenie();
                break;
            case 3:
                r->zistiCisloUlohy(13);
                cout << "Zadajte aky interval zastavanosti pozadujete!" << endl;
                cout << "MIN: ";
                cin >> min;
                r->zistiMIN(min);
                cout << "MAX: ";
                cin >> max;
                r->zistiMAX(max);
                r->readSlovensko();
                r->readClenenie();
                break;
            default:
                cout << "Zadali ste zlu hodnotu!" << endl;
                break;
            }
            break;

        default:
            cout << "Zadali ste zlu hodnotu!" << endl;
            break;
        }

    }
    return 0;
    
}

