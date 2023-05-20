#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, int size)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    // Kreiranje privremenog niza
    int temp[size];

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    // Kopiranje ostatka elemenata lijevog podniza, ako ih ima
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Kopiranje ostatka elemenata desnog podniza, ako ih ima
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // kopiranje privremenog niza u originalni niz
    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right, int size)
{
    // ovaj uslov se nece ispuniti samo kad ostane jedan element
    if (left < right)
    {
        // sredina
        int mid = (left + right) / 2;

        // rekurzivni pozivi mergeSort funkcije na lijevi podniz i desni podniz
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);

        // merge
        merge(arr, left, mid, right, size);
    }
}

int main()
{
    int myarray[] = {1, 2, 4, 3, 11, 19, 7, 4, 1};
    int size = sizeof(myarray) / sizeof(myarray[0]);

    cout << "Prije sortiranja: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;

    mergeSort(myarray, 0, (size - 1), size);

    cout << "Poslije sortiranja: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}