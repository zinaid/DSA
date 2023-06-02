#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
    Cvor *prethodni;
};

int main()
{
    struct Cvor *glava;
    struct Cvor *prvi = nullptr;
    struct Cvor *drugi = nullptr;
    struct Cvor *treci = nullptr;

    // Alokacija memorije

    prvi = new Cvor;
    drugi = new Cvor;
    treci = new Cvor;

    prvi->vrijednost = 1;
    drugi->vrijednost = 2;
    treci->vrijednost = 3;

    prvi->sljedeci = drugi;
    prvi->prethodni = nullptr;

    drugi->sljedeci = treci;
    drugi->prethodni = prvi;

    treci->sljedeci = nullptr;
    treci->prethodni = drugi;

    glava = prvi;

    cout << "Glava je na memorijskoj lokaciji: " << glava << " i njen sljedeci je: " << glava->sljedeci << ", a prethodni: " << glava->prethodni << ". Vrijednost je: " << glava->vrijednost << endl;
    cout << "Prvi je na memorijskoj lokaciji: " << prvi << " i njen sljedeci je: " << prvi->sljedeci << ", a prethodni: " << prvi->prethodni << ". Vrijednost je: " << prvi->vrijednost << endl;
    cout << "Drugi je na memorijskoj lokaciji: " << drugi << " i njen sljedeci je: " << drugi->sljedeci << ", a prethodni: " << drugi->prethodni << ". Vrijednost je: " << drugi->vrijednost << endl;
    cout << "Treci je na memorijskoj lokaciji: " << treci << " i njen sljedeci je: " << treci->sljedeci << ", a prethodni: " << treci->prethodni << ". Vrijednost je: " << treci->vrijednost << endl;

    return 0;
}