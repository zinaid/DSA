#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fajl;
    fajl.open("fajl.txt", ios::app);

    if (fajl.is_open())
    {
        fajl << "Hello New \n";
    }

    fajl.close();
    return 0;
}