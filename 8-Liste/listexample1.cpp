#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    struct Cvor *sljedeci;
};

int main()
{
    /* Initialize nodes */
    struct Cvor *glava;
    struct Cvor *prvi = nullptr;
    struct Cvor *drugi = nullptr;
    struct Cvor *treci = nullptr;

    /* Allocate memory */
    prvi = new Cvor;
    drugi = new Cvor;
    treci = new Cvor;

    /* Assign data values */
    prvi->vrijednost = 1;
    drugi->vrijednost = 2;
    treci->vrijednost = 3;

    /* Connect nodes */
    prvi->sljedeci = drugi;
    drugi->sljedeci = treci;
    treci->sljedeci = nullptr;

    /* Save address of first node in head */
    glava = prvi;
    cout << "Vrijednost glave liste je: " << glava->vrijednost << " njegova adresa je " << glava << " i on pokazuje na: " << glava->sljedeci << "." << endl;
    cout << "Vrijednost prvog clana je: " << prvi->vrijednost << " njegova adresa je " << prvi << " i on pokazuje na: " << prvi->sljedeci << "." << endl;
    cout << "Vrijednost drugog clana je: " << drugi->vrijednost << " njegova adresa je " << drugi << " i on pokazuje na: " << drugi->sljedeci << "." << endl;
    cout << "Vrijednost treceg clana je: " << treci->vrijednost << " njegova adresa je " << treci << " i on pokazuje na: " << treci->sljedeci << "." << endl;

    return 0;
}