#include <iostream>
using namespace std;

int main()
{
    int n, i, flag;
    flag = 1;
    i = 2;
    cout << "Unesite n: ";
    cin >> n;

    while (i <= n / 2)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
        else
        {
            i = i + 2;
        }
    }

    if (flag == 0)
    {
        cout << "n nije prost";
    }
    else
    {
        cout << "n je prost";
    }

    return 0;
}

/*
Implementirani kod predstavlja algoritam za provjeru
da li je neki broj prost. Prateci pseudokod urađena je
i implementacija.

Vremenska slozenost ovog algoritma je O(n), odnosno linearna
rastom broja n linearno raste i vremensko trajanje.

Tačnije, složenost je O(n/2) što se zaokruži na O(n).

Prostorna složenost ovog algoritma je O(1) jer je memorija
konstantna.
*/