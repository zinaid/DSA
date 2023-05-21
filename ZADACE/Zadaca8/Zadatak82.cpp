#include <iostream>
using namespace std;

int binarnaPretraga(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size;
    cout << "Unesite broj elemenata u nizu: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Unesite elemente: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, size);

    int cilj;
    cout << "Unesite broj koji trazite: ";
    cin >> cilj;

    int pozicija = binarnaPretraga(arr, size, cilj);

    if (pozicija != -1)
    {
        cout << "\nSortiranje niza...\n";
        cout << "\nBroj " << cilj << " je pronadjen na poziciji " << pozicija << ".\n";
    }
    else
    {
        cout << "\nSortiranje niza...\n";
        cout << "\nBroj " << cilj << " nije prisutan u nizu.\n";
    }

    delete[] arr;

    return 0;
}
