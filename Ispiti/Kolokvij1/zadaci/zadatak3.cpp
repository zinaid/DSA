#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

Cvor *glava = nullptr;

Cvor *addCvorToEnd(int element)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = nullptr;

    if (glava == nullptr)
    {
        cout << "Prazna lista \n";
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

    return noviCvor;
}

Cvor *addCvorToPosition(int element, int pozicija)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;

    if (glava == nullptr)
    {
        cout << "Lista je prazna pa ce se dodati na pocetak\n";
        glava = noviCvor;
        noviCvor->sljedeci = nullptr;
    }
    else
    {
        if (pozicija != 1)
        {
            Cvor *temp = glava;
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
        else
        {
            noviCvor->sljedeci = glava;
            glava = noviCvor;
        }
    }
}

void deleteElementOnBegin()
{
    glava = glava->sljedeci;
}

void searchElement(int element)
{
    if (glava == nullptr)
    {
        cout << "Prazna lista \n";
    }
    else
    {
        Cvor *temp = glava;
        while (temp != nullptr)
        {
            if (temp->vrijednost == element)
            {
                cout << "Pronadjen element \n";
            }
            else
            {
                cout << "Trazeni element ne postoji u listi \n";
            }
            temp = temp->sljedeci;
        }
    }
}

void printList()
{
    if (glava == nullptr)
    {
        cout << "Prazna lista \n";
    }
    else
    {
        Cvor *temp = glava;
        while (temp != nullptr)
        {
            cout << temp->vrijednost << " ";
            temp = temp->sljedeci;
        }
    }
}

int main()
{
    int opcija = 0;
    int element;
    int pozicija;

    while (opcija != -1)
    {
        cout << "\n MENI \n";
        cout << "1. Dodaj element na kraj \n";
        cout << "2. Dodaj element na poziciju \n";
        cout << "3. Obrisi element sa pocetka liste \n";
        cout << "4. Ispisi listu \n";
        cout << "5. Pretrazi cvor \n";
        cout << "Unesite -1 za izlazak iz menija \n";

        cin >> opcija;

        switch (opcija)
        {
        case 1:
            cout << "Unesite element: ";
            cin >> element;
            addCvorToEnd(element);
            break;

        case 2:
            cout << "Unesite poziciju: ";
            cin >> pozicija;
            cout << "Unesite element: ";
            cin >> element;
            addCvorToPosition(element, pozicija);
            break;
        case 3:
            deleteElementOnBegin();
            break;

        case 4:
            printList();
            break;
        case 5:
            cout << "Unesite element koji trazite: ";
            cin >> element;
            searchElement(element);
            break;
        case -1:
            cout << "Izlazak...";
            break;
        default:
            cout << "Pogresan odabir...\n";
            break;
        }
    }

    return 0;
}