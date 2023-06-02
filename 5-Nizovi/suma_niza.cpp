#include <iostream>
using namespace std;

void ispisi(int *, int);
void unesi(int *, int);
int saberi(int *, int);

int main()
{
    int n;
    cout << "Unesite velicinu niza: " << endl;
    cin >> n;

    if (n <= 0)
    {
        cerr << "Error: Invalid input for array size" << endl;
        return 1;
    }

    int *niz = new int[n];

    unesi(niz, n);
    ispisi(niz, n);
    cout << "\nSuma je: " << saberi(niz, n) << endl;

    delete[] niz;

    return 0;
}

void unesi(int *niz, int n)
{
    cout << "Unesite clanove niza: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
}

void ispisi(int *niz, int n)
{
    cout << "Niz je: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << niz[i] << " ";
    }
}

int saberi(int *niz, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += niz[i];
    }

    return suma;
}
