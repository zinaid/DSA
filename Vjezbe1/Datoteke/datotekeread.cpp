#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fajl;
    fajl.open("fajl.txt", ios::in);

    if (fajl.is_open())
    {
        string line;
        while (getline(fajl, line))
        {
            cout << line << endl;
        }
    }

    fajl.close();
    return 0;
}