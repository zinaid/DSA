#include <iostream>
using namespace std;

int main()
{
    float arr[3];

    // deklaracija pokazivaca
    float *ptr;

    cout << "Prikaz adresa koristeci nizove: " << endl;

    for (int i = 0; i < 3; ++i)
    {
        cout << "&arr[" << i << "] = " << &arr[i] << endl;
    }

    // ptr = &arr[0]
    ptr = arr;

    cout << "\nPrikaz adresa koristeci pokazivace: " << endl;

    for (int i = 0; i < 3; ++i)
    {
        cout << "ptr + " << i << " = " << ptr + i << endl;
    }

    return 0;
}