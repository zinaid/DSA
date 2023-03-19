#include <iostream>
using namespace std;

void ispisPokazivac(int *niz);
void ispis(int niz[]);

int main()
{
    int niz[] = {1, 2, 3, 4, 5};
    ispis(niz);
    cout << "\n";
    ispisPokazivac(niz);
    return 0;
}

void ispis(int niz[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << niz[i];
    }
}

void ispisPokazivac(int *niz)
{
    for (int i = 0; i < 5; i++)
    {
        cout << *niz + i;
    }
}