#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void bubbleSortOptimized(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{
    int array[] = {1, 3, 5, 2, 10};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Prije sortiranja: " << endl;
    printArray(array, size);

    bubbleSort(array, size);

    cout << "Poslije sortiranja: " << endl;
    printArray(array, size);

    return 0;
}