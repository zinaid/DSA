#include <iostream>

using namespace std;

int main()
{
    int n, pozicija;
    cout << "Koliki niz hocete:\t";
    cin >> n;

    int niz[n];

    cout << "Unesite niz: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    cout << "Koju poziciju zelite obrisati\t";
    cin >> pozicija;

    int j = pozicija;

    while (j < n)
    {
        niz[j] = niz[j + 1];
        j = j + 1;
    }

    n = n - 1;

    // ispisi niz
    for (int i = 0; i < n; i++)
    {
        cout << niz[i];
    }

    return 0;
}