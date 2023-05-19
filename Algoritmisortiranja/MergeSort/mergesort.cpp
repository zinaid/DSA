#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

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

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++)
    {
        arr[left + p] = temp[p];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int myarray[] = {2, 1, 5, 3, 4, 10, 1, 17};
    int arr_size = sizeof(myarray) / sizeof(myarray[0]);

    cout << "Prije sortiranja: " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (arr_size - 1));

    cout << "Poslije sortiranja: " << endl;
    for (int i = 0; i < arr_size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}