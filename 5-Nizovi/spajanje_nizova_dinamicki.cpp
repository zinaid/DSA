#include <iostream>
using namespace std;

void create_third_array(int *niz1, int velicina1, int *niz2, int velicina2, int *rezultat, int velicina_rezultata)
{

    // Prolazak kroz prvi niz
    for (int i = 0; i < velicina1; i++)
    {
        rezultat[i] = niz1[i];
    }

    // Prolazak kroz drugi niz
    for (int i = 0; i < velicina2; i++)
    {
        rezultat[i + velicina1] = niz2[i];
    }
}

int main()
{
    int velicina1 = 3;
    int *niz1 = new int[velicina1]{1, 2, 3};

    int velicina2 = 3;
    int *niz2 = new int[velicina2]{4, 5, 6};

    int velicina_rezultata = velicina1 + velicina2;
    int *rezultat = new int[velicina_rezultata];

    create_third_array(niz1, velicina1, niz2, velicina2, rezultat, velicina_rezultata);

    cout << "Rezultat: ";
    for (int i = 0; i < velicina_rezultata; i++)
    {
        cout << rezultat[i] << " ";
    }
    cout << endl;

    // Frisanje nizova i čišćenje memorije
    delete[] niz1;
    delete[] niz2;
    delete[] rezultat;

    return 0;
}
