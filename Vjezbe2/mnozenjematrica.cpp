#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void multiply_matrices(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int n, int m, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

int main()
{
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    int n, m, p;

    cout << "Unesite broj redova i kolona prve matrice";
    cin >> n >> m;

    cout << "Unesite elemente prve matrice: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Unesite broj redova i kolona druge matrice ";
    cin >> m >> p;

    cout << "Unesite elemente druge matrice: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> b[i][j];
        }
    }

    multiply_matrices(a, b, c, n, m, p);

    cout << "Rezultat je: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}