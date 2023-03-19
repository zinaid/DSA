#include <iostream>

using namespace std;

int main()
{
    int rows1, cols1, rows2, cols2;

    cout << "Unesite broj redova prve matrice: ";
    cin >> rows1;
    cout << "Unesite broj kolona prve matrice: ";
    cin >> cols1;

    cout << "Unesite broj redova druge matrice: ";
    cin >> rows2;
    cout << "Unesite broj redova druge matrice: ";
    cin >> cols2;

    if (cols1 != rows2)
    {
        cout << "Matrice se ne mogu mnoziti";
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // Unos matrica
    cout << "Unesite matricu 1:" << endl;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            cout << "Unesi element [" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "Unesite matricu 2:" << endl;
    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            cout << "Unesi element [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // Mnozenje matrica
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Prikaz rezultata
    cout << "Rezultat:" << endl;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}