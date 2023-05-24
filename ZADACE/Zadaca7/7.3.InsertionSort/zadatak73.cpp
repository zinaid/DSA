#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main()
{
    int array[] = {1, 3, 2, 10, 11, 4};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Prije sortiranja: ";
    printArray(array, size);

    insertionSort(array, size);

    cout << "\nPoslije sortiranja: ";
    printArray(array, size);
    return 0;
}