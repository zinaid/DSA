#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // Vrati mid ako je nadjen odmah na sredini
        if (array[mid] == x)
            return mid;

        // Trazi lijevu polovicu
        if (array[mid] > x)
            return binarySearch(array, x, low, mid - 1);

        // Suprotno trazi desnu polovicu
        return binarySearch(array, x, mid + 1, high);
    }

    return -1;
}

int main(void)
{
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Nema elementa");
    else
        printf("Element se nalazi na indeksu %d", result);
}