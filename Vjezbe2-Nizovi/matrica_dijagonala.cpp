#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3];

    // Unos matrice
    cout << "Unesite elemente matrice:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Ispis matrice
    cout << "Brojevi ispod dijagonale su:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Ispis brojeva ispod dijagonale
    cout << "Brojevi ispod dijagonale su:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
