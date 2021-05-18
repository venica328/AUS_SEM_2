
#include <iostream>
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "ReadFiles.h"
#include "Methods.h"

using namespace std;

int main()
{
    initHeapMonitor();

    ReadFiles* r = new ReadFiles();
    r->readSlovensko();
   // r->readClenenie();
    //cout << r << endl;

    //Methods* method = new Methods();
   // method->method1();

    cout << "Hello World!\n";
}

