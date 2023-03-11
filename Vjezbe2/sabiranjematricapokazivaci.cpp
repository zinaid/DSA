#include <iostream>
using namespace std;

void enter_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void sum_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;

    cout << "Broj redova: ";
    cin >> rows;
    cout << "Broj kolona: ";
    cin >> cols;

    // Alokacija memorije za matrice
    int **matrix1 = new int *[rows];
    int **matrix2 = new int *[rows];
    int **result = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        result[i] = new int[cols];
    }

    cout << "Unos matrice 1:" << endl;
    enter_matrix(matrix1, rows, cols);

    cout << "Unos matrice 2:" << endl;
    enter_matrix(matrix2, rows, cols);

    sum_matrices(matrix1, matrix2, result, rows, cols);

    cout << "Matrica 1:" << endl;
    print_matrix(matrix1, rows, cols);

    cout << "Matrica 2:" << endl;
    print_matrix(matrix2, rows, cols);

    cout << "Suma matrica:" << endl;
    print_matrix(result, rows, cols);

    // Oslobađanje memorije
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] result[i];
    }

    delete[] matrix1;
    delete[] matrix2;
    delete[] result;

    return 0;
}
