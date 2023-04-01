#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

Cvor *glava = nullptr;

void dodajCvorNaKraj(int element)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = nullptr;

    if (glava == nullptr)
    {
        glava = noviCvor;
    }
    else
    {
        Cvor *temp = glava;

        while (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }

        temp->sljedeci = noviCvor;
    }
}

void dodajCvorNaPocetak(int element)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = glava;
    glava = noviCvor;
}

void dodajCvorNaPoziciju(int element, int pozicija)
{
    struct Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;

    struct Cvor *temp = glava;
    for (int i = 2; i < pozicija; i++)
    {
        if (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }
    }
    noviCvor->sljedeci = temp->sljedeci;
    temp->sljedeci = noviCvor;
}

void izbrisiCvorNaPocetku()
{
    glava = glava->sljedeci;
}

void izbrisiCvorNaKraju()
{
    struct Cvor *temp = glava;
    while (temp->sljedeci->sljedeci != nullptr)
    {
        temp = temp->sljedeci;
    }
    temp->sljedeci = nullptr;
}

void izbrisiCvorSaPozicije(int pozicija)
{
    Cvor *temp = glava;
    for (int i = 2; i < pozicija; i++)
    {
        if (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }
    }

    temp->sljedeci = temp->sljedeci->sljedeci;
}

void ispisiListu()
{
    Cvor *temp = glava;

    while (temp != nullptr)
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;
    }
}

bool pretraziCvor(int element)
{
    Cvor *temp = glava;
    while (temp != nullptr)
    {
        if (temp->vrijednost == element)
        {
            return true;
        }
        temp = temp->sljedeci;
    }
    return false;
}

int main()
{
    int opcija = 0;
    int element, pozicija;

    while (opcija != -1)
    {
        cout << "\n1. Dodaj cvor na kraj liste \n";
        cout << "2. Dodaj cvor na pocetak liste \n";
        cout << "3. Dodaj cvor na poziciju u listi \n";
        cout << "4. Izbrisi prvi cvor u listi \n";
        cout << "5. Izbrisi cvor na kraju liste \n";
        cout << "6. Izbrisi cvor sa pozicije u listi \n";
        cout << "7. Ispisi listu \n";
        cout << "8. Provjeri da li se element nalazi u listi \n";
        cout << "-1 Izlaz iz menu-a \n";

        cout << "\nUnesite opciju\n";
        cin >> opcija;

        switch (opcija)
        {
        case 1:
            cout << "Unesite element koji zelite dodati: ";
            cin >> element;
            dodajCvorNaKraj(element);
            break;
        case 2:
            cout << "Unesite element koji zelite dodati: ";
            cin >> element;
            dodajCvorNaPocetak(element);
            break;
        case 3:
            cout << "Unesite element koji zelite dodati: ";
            cin >> element;
            cout << "Unesite poziciju na koju zelite dodati: ";
            cin >> pozicija;
            dodajCvorNaPoziciju(element, pozicija);
            break;
        case 4:
            izbrisiCvorNaPocetku();
            break;
        case 5:
            izbrisiCvorNaKraju();
            break;
        case 6:
            cout << "Unesite poziciju cvora koji zelite obrisati: ";
            cin >> pozicija;
            izbrisiCvorSaPozicije(pozicija);
            break;
        case 7:
            cout << "Lista je: ";
            ispisiListu();
            break;
        case 8:
            cout << "Unesite cvor koji trazite: ";
            cin >> element;
            if (pretraziCvor(element))
            {
                cout << "Cvor postoji. \n";
            }
            else
            {
                cout << "Cvor ne postoji. \n";
            }
            break;
        case -1:
            cout << "Izlaz ..." << endl;
            break;
        default:
            cout << "Pogresna opcija" << endl;
            break;
        }
    }

    return 0;
}