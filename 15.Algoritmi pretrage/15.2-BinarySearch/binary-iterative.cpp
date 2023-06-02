#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high)
{

    // Ponavljaj dok se low i high ne susretnu
    while (low <= high)
    {
        // koristi se umjesto (low+high)/2 da se izbjegne overflow kod velikih vrijednosti
        int mid = low + (high - low) / 2;

        // ako nadje vrati mid
        if (array[mid] == x)
            return mid;

        // ako je trazeni broj veci onda je donja granica sljedeci element poslije njega
        if (array[mid] < x)
            low = mid + 1;
        // suprotno onda je gornja granica element prije njega
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int array[] = {3, 4, 5, 6, 7, 8, 9};
    int x = 8;
    int n = sizeof(array) / sizeof(array[0]);
    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        printf("Nema elementa.");
    else
        printf("Element se nalazi na indeksu %d", result);
}