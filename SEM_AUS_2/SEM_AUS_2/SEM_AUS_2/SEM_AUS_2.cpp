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

    SetConsoleOutputCP(1250);
    SetConsoleCP(1250);
    setlocale(LC_ALL, "slovak");

    int x = 1, y, z;
    int min;
    int max;
    int pocetObyvatelov;
    int zastavanost;
    string nazovObce;
    string cele;
    string nazovOkresu;
    string nazovKraja;

    ReadFiles* r = new ReadFiles();    

    while (x != 0)
    {
        r->vynuluj();

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
            cout << "0 = nedefinovane" << endl;
            cout << "1 = nazov obce" << endl;
            cout << "2 = pocet obyvatelov" << endl;
            cout << "3 = zastavanost" << endl;
            cin >> y;

            switch (y)
            {
            case 0:
                r->zistiCisloUlohy(10);
                r->readSlovensko();
                break;
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
                break;
            default:
                cout << "Zadali ste zlu hodnotu!" << endl;
                break;
            }
            break;

        case 2:
            cout << "Zoradte obce podla: " << endl;
            cout << "0 = nedefinovane" << endl;
            cout << "1 = nazov" << endl;
            cout << "2 = pocet obyvatelov" << endl;
            cout << "3 = zastavanost" << endl;
            cin >> y;
            switch (y)
            {
            case 0:
            case 1:
                cout << "1 = vzostupne (od A po Z)" << endl;
                cout << "2 = zostupne (od Z do A)" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                case 2:
                    r->zistiCisloUlohy(21);
                    r->zistiVzostupnost(x);
                    r->readClenenie();
                    r->readSlovensko();
                    break;
                default:
                    cout << "Zadali ste zlu hodnotu!" << endl;
                    break;
                }
                break;
            case 2:
                cout << "1 = vzostupne (od 0 po infinity)" << endl;
                cout << "2 = zostupne (od infinity do 0)" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                case 2:
                    r->zistiCisloUlohy(22);
                    r->zistiVzostupnost(x);
                    r->readSlovensko();
                    break;
                default:
                    cout << "Zadali ste zlu hodnotu!" << endl;
                    break;
                }
                break;
            case 3:
                cout << "1 = vzostupne (od 0 po infinity)" << endl;
                cout << "2 = zostupne (od infinity do 0)" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                case 2:
                    r->zistiCisloUlohy(23);
                    r->zistiVzostupnost(x);
                    r->readSlovensko();
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
            break;

        case 3:
            cout << "Vyber typ uzemnej jednotky!" << endl;
            cout << "0 = nedefinovane" << endl;
            cout << "1 = obec" << endl;
            cout << "2 = okres" << endl;
            cout << "3 = kraj" << endl;
            cin >> y;
            switch (y)
            {
            case 0:
                r->zistiCisloUlohy(10);
                r->readSlovensko();
                break;
            case 1:
                cout << "Vyber filter!" << endl;
                cout << "1 = nazov obce" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> z;
                switch (z)
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
                    break;
                }
                break;

            case 2:
                cout << "Vyber filter!" << endl;
                cout << "1 = nazov obce" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> z;
                switch (z)
                {
                case 1:
                    r->zistiCisloUlohy(321);
                    cout << "Zadajte okres: " << endl;
                    cin >> nazovOkresu;
                    r->zistiNazovOkresu(nazovOkresu);
                    cout << "Zadajte nazov obce:" << endl;
                    cin >> nazovObce;
                    r->zistiNazovObce(nazovObce);
                    cout << endl;
                    r->readClenenie();
                    break;
                case 2:
                    r->zistiCisloUlohy(322);
                    cout << "Zadajte okres: " << endl;
                    cin >> nazovOkresu;
                    r->zistiNazovOkresu(nazovOkresu);
                    cout << "Zadajte pocet obyvatelov v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    r->readClenenie();
                    break;
                case 3:
                    r->zistiCisloUlohy(323);
                    cout << "Zadajte okres: " << endl;
                    cin >> nazovOkresu;
                    r->zistiNazovOkresu(nazovOkresu);
                    cout << "Zadajte aky interval zastavanosti pozadujete!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    r->readClenenie();
                    break;
                }
                break;

            case 3:
                cout << "Vyber filter!" << endl;
                cout << "1 = nazov obce" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> z;
                switch (z)
                {
                case 1:
                    r->zistiCisloUlohy(331);
                    cout << "Zadajte kraj: " << endl;
                    cin >> nazovKraja;
                    r->zistiNazovKraja(nazovKraja);
                    cout << "Zadajte nazov obce:" << endl;
                    cin >> nazovObce;
                    r->zistiNazovObce(nazovObce);
                    cout << endl;
                    r->readClenenie();
                    break;
                case 2:
                    r->zistiCisloUlohy(332);
                    cout << "Zadajte kraj: " << endl;
                    cin >> nazovKraja;
                    r->zistiNazovKraja(nazovKraja);
                    cout << "Zadajte pocet obyvatelov v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    r->readClenenie();
                    break;
                case 3:
                    r->zistiCisloUlohy(333);
                    cout << "Zadajte kraj: " << endl;
                    cin >> nazovKraja;
                    r->zistiNazovKraja(nazovKraja);
                    cout << "Zadajte aky interval zastavanosti pozadujete!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    r->readClenenie();
                    break;
                }
                break;

            }
            break;

        case 4:
            cout << "Vyber typ uzemnej jednotky!" << endl;
            cout << "0 = nedefinovane" << endl;
            cout << "1 = obec" << endl;
            cout << "2 = okres" << endl;
            cout << "3 = kraj" << endl;
            cin >> y;
            switch (y)
            {
            case 0:
                cout << "1 = vzostupne (od A po Z)" << endl;
                cout << "2 = zostupne (od Z do A)" << endl;
                cin >> x;
                switch (x)
                {
                case 1:
                case 2:
                    r->zistiCisloUlohy(21);
                    r->zistiVzostupnost(x);
                    r->readClenenie();
                    r->readSlovensko();
                    break;
                default:
                    cout << "Zadali ste zlu hodnotu!" << endl;
                    break;
                }
                break;
            case 1:
                cout << "Zoradte obce podla: " << endl;
                cout << "1 = nazov" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> y;
                switch (y)
                {
                case 1:
                    cout << "1 = vzostupne (od A po Z)" << endl;
                    cout << "2 = zostupne (od Z do A)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(21);
                        r->zistiVzostupnost(x);
                        r->readClenenie();
                        r->readSlovensko();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }

                case 2:
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(22);
                        r->zistiVzostupnost(x);
                        r->readSlovensko();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                case 3:
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(23);
                        r->zistiVzostupnost(x);
                        r->readSlovensko();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                default:
                    cout << "Zadali ste zlu hodnotu!" << endl;
                    break;
                }
                break;
            case 2:
                cout << "Zadajte okres: " << endl;
                cin >> nazovOkresu;
                r->zistiNazovOkresu(nazovOkresu);
                cout << "Zoradte obce podla filtra v danom okrese: " << endl;
                cout << "1 = nazov" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> y;
                switch (y)
                {
                case 1:
                    cout << "1 = vzostupne (od A po Z)" << endl;
                    cout << "2 = zostupne (od Z do A)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(421);
                        r->zistiVzostupnost(x);
                        r->readClenenie();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                    break;
                case 2:
                    cout << "Zadajte pocet obyvatelov v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(422);
                        r->zistiVzostupnost(x);
                        r->readClenenie();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                    break;
                case 3:
                    cout << "Zadajte zastavanost v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(423);
                        r->zistiVzostupnost(x);
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
                break;
            case 3:
                cout << "Zadajte kraj: " << endl;
                cin >> nazovKraja;
                r->zistiNazovKraja(nazovKraja);
                cout << "Zoradte obce podla filtra v danom kraji: " << endl;
                cout << "1 = nazov" << endl;
                cout << "2 = pocet obyvatelov" << endl;
                cout << "3 = zastavanost" << endl;
                cin >> y;
                switch (y)
                {
                case 1:
                    cout << "1 = vzostupne (od A po Z)" << endl;
                    cout << "2 = zostupne (od Z do A)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(431);
                        r->zistiVzostupnost(x);
                        r->readClenenie();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                    break;
                case 2:
                    cout << "Zadajte pocet obyvatelov v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(432);
                        r->zistiVzostupnost(x);
                        r->readClenenie();
                        break;
                    default:
                        cout << "Zadali ste zlu hodnotu!" << endl;
                        break;
                    }
                    break;
                case 3:
                    cout << "Zadajte zastavanost v intervale!" << endl;
                    cout << "MIN: ";
                    cin >> min;
                    r->zistiMIN(min);
                    cout << "MAX: ";
                    cin >> max;
                    r->zistiMAX(max);
                    cout << endl;
                    cout << "1 = vzostupne (od 0 po infinity)" << endl;
                    cout << "2 = zostupne (od infinity do 0)" << endl;
                    cin >> x;
                    switch (x)
                    {
                    case 1:
                    case 2:
                        r->zistiCisloUlohy(433);
                        r->zistiVzostupnost(x);
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
                break;
            default:
                cout << "Zadali ste zlu hodnotu!" << endl;
                break;
            }
            default:
                cout << "Zadali ste zlu hodnotu!" << endl;
        }
    }

    delete r;
    return 0;
}

