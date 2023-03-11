#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3];

    // Read the values of the matrix
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Print the numbers below the diagonal
    cout << "The numbers below the diagonal are:\n";
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    return 0;
}
