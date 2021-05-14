
#include <iostream>
#include "../structures/list/list.h"
#include "../structures/list/array_list.h"
#include "ReadFiles.h"

using namespace std;

int main()
{
    initHeapMonitor();

    ReadFiles* r = new ReadFiles();
    r->readSlovensko();
    cout << r << endl;

    cout << "Hello World!\n";
}

