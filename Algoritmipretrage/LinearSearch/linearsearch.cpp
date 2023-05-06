#include <iostream>
using namespace std;

int linearsearch(int array[], int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == item)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int item;
    int array[] = {2, 10, 12, 4, 3};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Unesite element koji trazite: ";
    cin >> item;

    int result = linearsearch(array, n, item);

    (result != -1) ? cout << "Element se nalazi na poziciji: " << result : cout << "Nema elementa";
}