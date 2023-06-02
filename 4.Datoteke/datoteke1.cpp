#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fajl;
    fajl.open("fajl.txt", ios::out);

    if (fajl.is_open())
    {
        fajl << "Hello 3\n";
    }

    fajl.close();
    return 0;
}