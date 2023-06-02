#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

void dodajElement(Cvor **glavaRef, int element)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = nullptr;

    if (*glavaRef == nullptr)
    {
        *glavaRef = noviCvor;
    }
    else
    {
        Cvor *temp = *glavaRef;
        while (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }

        temp->sljedeci = noviCvor;
    }
}

void ispisListe(Cvor **glavaRef)
{
    Cvor *temp = *glavaRef;

    while (temp != nullptr)
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;
    }
}

int main()
{
    int element = 1;
    Cvor *glava = nullptr;

    while (element > 0)
    {
        cout << "Unesite novi element: ";
        cin >> element;
        if (element > 0)
        {
            dodajElement(&glava, element);
        }
    }
    cout << "Lista je: ";
    ispisListe(&glava);

    return 0;
}