#include <iostream>
using namespace std;

int main()

{

    int array[100], pos, size, val;

    printf("Unesite velicinu niza:");

    cin >> size;

    printf("Unesite %d elemente\n", size);

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    printf("Unesite lokaciju \n");

    cin >> pos;

    printf("Unesite vrijednost \n");

    cin >> val;

    for (int i = size - 1; i >= pos - 1; i--)
    {
        array[i + 1] = array[i];
    }

    array[pos - 1] = val;

    printf("Rezultat je\n");

    for (int i = 0; i <= size; i++)

        printf("%d\n", array[i]);

    return 0;
}