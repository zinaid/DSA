#include <iostream>
using namespace std;

void napravi_treci_niz(int niz1[], int velicina1, int niz2[], int velicina2, int rezultat[], int velicina_rezultata)
{
    // Prolazak kroz prvi niz i pravi niz sa indeksima od 0 do velicine1
    for (int i = 0; i < velicina1; i++)
    {
        rezultat[i] = niz1[i];
    }

    // Prolazak kroz drugi niz i dodaje clanove na novi niz sa indeksima od velicine1 do velicine1+velicina2
    for (int i = 0; i < velicina2; i++)
    {
        rezultat[velicina1 + i] = niz2[i];
        velicina_rezultata++;
    }
}

int main()
{
    int niz1[] = {1, 2, 3};
    int velicina1 = 3;

    int niz2[] = {4, 5, 6};
    int velicina2 = 3;
    int velicina_rezultata = velicina1 + velicina2;
    int rezultat[velicina_rezultata];
    napravi_treci_niz(niz1, velicina1, niz2, velicina2, rezultat, velicina_rezultata);

    cout << velicina_rezultata;

    cout << "Rezultat: ";
    for (int i = 0; i < velicina_rezultata; i++)
    {
        cout << rezultat[i] << " ";
    }
    cout << endl;

    return 0;
}
