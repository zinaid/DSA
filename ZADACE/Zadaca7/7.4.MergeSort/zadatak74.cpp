#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right, int size)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    int temp[size];

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (int s = left; s <= right; s++)
    {
        array[s] = temp[s];
    }
}

void mergeSort(int array[], int left, int right, int size)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid, size);
        mergeSort(array, mid + 1, right, size);
        merge(array, left, mid, right, size);
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
    int array[] = {1, 2, 4, 3, 1, 11, 6};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Prije sortiranja: " << endl;
    printArray(array, size);

    mergeSort(array, 0, (size - 1), size);

    cout << "\n Poslije sortiranja: " << endl;
    printArray(array, size);

    return 0;
}