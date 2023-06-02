#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int pindex = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[pindex]);
            pindex++;
        }
    }

    swap(array[end], array[pindex]);
    return pindex;
}

void quicksort(int array[], int start, int end)
{
    if (start < end)
    {
        int p = partition(array, start, end);
        quicksort(array, start, (p - 1));
        quicksort(array, (p + 1), end);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int myarray[] = {1, 4, 2, 3, 8, 9};
    int size = sizeof(myarray) / sizeof(myarray[0]);

    cout << "Prije sortiranja: " << endl;
    printArray(myarray, size);

    quicksort(myarray, 0, (size - 1));

    cout << "\nPoslije sortiranja: " << endl;
    printArray(myarray, size);

    return 0;
}