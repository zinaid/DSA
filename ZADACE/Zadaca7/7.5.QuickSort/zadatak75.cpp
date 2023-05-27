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

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int partitionIndex = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(array[end], array[partitionIndex]);

    return partitionIndex;
}

void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(array, start, end);
        quickSort(array, start, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, end);
    }
}

int main()
{
    int array[] = {1, 2, 5, 3, 9, 7};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Prije sortiranja: " << endl;
    printArray(array, size);

    quickSort(array, 0, size - 1);

    cout << "\nPoslije sortiranja: " << endl;
    printArray(array, size);

    return 0;
}