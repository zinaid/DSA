#include <iostream>
using namespace std;

int findMaxPointers(int *arr, int size);
int findMaxWithoutPointers(int arr[], int size);

int main()
{
    int arr[] = {5, 2, 7, 1, 9};
    // Računanje veličine niza
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = findMaxPointers(arr, size);
    cout << "Najveci element koristeci pokazivace: " << max << endl;

    int max2 = findMaxWithoutPointers(arr, size);
    cout << "Najveci element: " << max << endl;

    return 0;
}

int findMaxPointers(int *arr, int size)
{
    int max = *arr;
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}

int findMaxWithoutPointers(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}