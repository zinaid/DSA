#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    struct Cvor *sljedeci;
};

Cvor *dodajNaPraznuListu(Cvor *zadnji, int vrijednost)
{
    if (zadnji != nullptr)
        return zadnji;

    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = vrijednost;
    zadnji = noviCvor;
    // sam na sebe pokazuje
    zadnji->sljedeci = zadnji;
    return zadnji;
}

Cvor *dodajNaKraj(Cvor *zadnji, int vrijednost)
{
    if (zadnji == nullptr)
        return dodajNaPraznuListu(zadnji, vrijednost);

    struct Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = vrijednost;
    // novi cvor pokazuje na zadnji, a zadnji pokazuje na novi cvor
    noviCvor->sljedeci = zadnji->sljedeci;
    zadnji->sljedeci = noviCvor;
    // novi cvor postaje zadnji
    zadnji = noviCvor;

    return zadnji;
}

struct Cvor *dodajNaPocetak(Cvor *zadnji, int vrijednost)
{
    if (zadnji == nullptr)
        return dodajNaPraznuListu(zadnji, vrijednost);

    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = vrijednost;
    // novi cvor pokazuje na prvi (jer zadnji pokazuje na prvi)
    noviCvor->sljedeci = zadnji->sljedeci;
    // novi cvor postaje prvi
    zadnji->sljedeci = noviCvor;

    return zadnji;
}

Cvor *dodajNaPoziciju(Cvor *zadnji, int vrijednost, int pozicija)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = vrijednost;

    if (pozicija == 1)
    {
        noviCvor->sljedeci = zadnji;
        return noviCvor;
    }

    Cvor *temp = zadnji;
    for (int i = 1; i < pozicija && temp != nullptr; i++)
    {
        temp = temp->sljedeci;
    }

    if (temp == nullptr)
    {
        cout << "\n Cvor nije u listi. " << endl;
        return zadnji;
    }

    noviCvor->sljedeci = temp->sljedeci;
    temp->sljedeci = noviCvor;

    return zadnji;
}

Cvor *obrisiPoVrijednosti(Cvor *zadnji, int vrijednost)
{
    // da li je prazna lista
    if (zadnji == NULL)
        return nullptr;

    // Ako lista ima samo jedan element i taj element ima vrijednost
    if (zadnji->vrijednost == vrijednost && zadnji->sljedeci == zadnji)
    {
        delete zadnji;
        zadnji = nullptr;
        return nullptr;
    }

    Cvor *temp = zadnji;

    // Ako se brise zadnji
    if (zadnji->vrijednost == vrijednost)
    {
        // naci cvor prije zadnjeg
        while (temp->sljedeci != zadnji)
            temp = temp->sljedeci;

        // temp sljedeci pokazuje na zadnji sljedeci tj prvi
        temp->sljedeci = zadnji->sljedeci;
        zadnji = temp->sljedeci;
        return zadnji;
    }

    // nadji cvor za brisanje
    while (temp->sljedeci != zadnji && temp->sljedeci->vrijednost != vrijednost)
    {
        temp = temp->sljedeci;
    }

    // ako nadje tu vrijednost
    if (temp->sljedeci->vrijednost == vrijednost)
    {
        // privremena vrijednost u koju spremamo temp->sljedeci
        Cvor *d = temp->sljedeci;
        temp->sljedeci = d->sljedeci;
        delete d;
    }

    return zadnji;
}

void traverse(struct Cvor *zadnji)
{

    if (zadnji == nullptr)
    {
        cout << "Lista je prazna." << endl;
        return;
    }

    Cvor *temp = zadnji->sljedeci;

    do
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;

    } while (temp != zadnji->sljedeci);
}

int main()
{
    struct Cvor *zadnji = NULL;

    zadnji = dodajNaPraznuListu(zadnji, 6);
    zadnji = dodajNaKraj(zadnji, 8);
    zadnji = dodajNaPocetak(zadnji, 2);

    zadnji = dodajNaPoziciju(zadnji, 10, 2);

    traverse(zadnji);

    zadnji = obrisiPoVrijednosti(zadnji, 8);

    cout << endl;
    traverse(zadnji);

    zadnji = obrisiPoVrijednosti(zadnji, 2);

    cout << endl;
    traverse(zadnji);

    zadnji = obrisiPoVrijednosti(zadnji, 6);

    cout << endl;
    traverse(zadnji);

    zadnji = obrisiPoVrijednosti(zadnji, 10);

    cout << endl;
    traverse(zadnji);

    return 0;
}