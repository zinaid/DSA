#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        swap(array[min_idx], array[i]);
    }
}

int main()
{
    int array[] = {1, 2, 5, 3, 7, 11, 5, 3};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Prije sortiranja: " << endl;
    printArray(array, size);

    selectionSort(array, size);

    cout << "\nPoslije sortiranja: " << endl;
    printArray(array, size);
    return 0;
}