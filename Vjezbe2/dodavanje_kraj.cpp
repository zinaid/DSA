#include <iostream>
using namespace std;

int main()

{

    int n, i, item;

    printf("Unesite velicinu niza: ");

    cin >> n;
    int array[n];

    printf("Unesite clanove niza: \n");

    for (i = 0; i < n; i++)

    {
        cin >> array[i];
    }

    printf("Unesite element koji zelite dodati na kraj: ");

    cin >> item;

    // Doda se element na kraj niza
    array[n] = item;

    printf("Novi niz: \n");

    for (i = 0; i < n + 1; i++)

    {
        printf("%d", array[i]);
    }

    return 0;
}