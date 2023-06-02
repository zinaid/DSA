#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Unesite broj redova i kolona: ";
    cin >> rows >> cols;

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];

    // Unos prve matrice
    cout << "\nUnesite prvu matricu:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Unesite element [" << i << ", " << j << "]: ";
            cin >> mat1[i][j];
        }
    }

    // Unos druge matrice
    cout << "\nUnesite drugu matricu:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Unesite element [" << i << ", " << j << "]: ";
            cin >> mat2[i][j];
        }
    }

    // Saberi dvije matrice
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Suma matrica
    cout << "\nSuma matrica je:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
