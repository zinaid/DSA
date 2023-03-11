#include <iostream>
using namespace std;

int main()

{

    int array[10], n, i, item;

    printf("Unesite velicinu niza: ");

    cin >> n;

    printf("Unesite clanove niza: \n");

    for (i = 0; i < n; i++)

    {

        scanf("%d", &array[i]);
    }

    printf("Unesite element koji želite dodati na početak: ");

    scanf("%d", &item);

    n++;

    for (i = n; i > 1; i--)

    {

        array[i - 1] = array[i - 2];
    }

    array[0] = item;

    printf("Novi niz: \n");

    for (i = 0; i < n; i++)

    {

        printf("\n%d", array[i]);
    }

    return 0;
}