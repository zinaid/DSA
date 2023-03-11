#include <iostream>
using namespace std;

int faktorijel(int broj)
{
    int ukupno = 1;
    for (int i = 1; i <= broj; i++)
    {
        ukupno = ukupno * i;
    }
    return ukupno;
}

int main()
{
    int broj;
    cout << "Unesite broj: ";
    cin >> broj;
    cout << "Faktorijel broja " << broj << " je: " << faktorijel(broj) << endl;
    system("pause");
}
