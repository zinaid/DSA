#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
    Cvor *prethodni;
};

Cvor *glava = nullptr;

bool isListaEmpty()
{
    if (glava == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dodajCvorNaKraj(int element)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = nullptr;

    if (glava == nullptr)
    {
        noviCvor->prethodni = nullptr;
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
        noviCvor->prethodni = temp;
    }
}

void dodajCvorNaPocetak(int element)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = glava;
    noviCvor->prethodni = nullptr;
    glava = noviCvor;
}

void dodajCvorNaPoziciju(int element, int pozicija)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = element;

    Cvor *temp = glava;

    for (int i = 2; i < pozicija; i++)
    {
        while (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }
    }
    noviCvor->sljedeci = temp->sljedeci;
    temp->sljedeci = noviCvor;
    noviCvor->prethodni = temp;
}

void izbrisiCvorNaPocetku()
{
    if (!isListaEmpty())
    {
        Cvor *temp = glava;
        if (temp->sljedeci != nullptr)
        {
            glava->sljedeci->prethodni = nullptr;
            glava = glava->sljedeci;
        }
        else
        {
            glava = nullptr;
        }
    }
    else
    {
        cout << "Lista je prazna.";
    }
}

void izbrisiCvorNaKraju()
{
    if (!isListaEmpty())
    {
        Cvor *temp = glava;
        if (temp->sljedeci != nullptr)
        {
            while (temp->sljedeci->sljedeci != nullptr)
            {
                temp = temp->sljedeci;
            }
            temp->sljedeci = nullptr;
        }
        else
        {
            glava = nullptr;
        }
    }
    else
    {
        cout << "Lista je prazna.";
    }
}

void izbrisiCvorNaPoziciji(int pozicija)
{
    if (!isListaEmpty())
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
        temp->sljedeci->prethodni = temp;
    }
    else
    {
        cout << "Lista je prazna";
    }
}

int prebrojCvorove()
{
    int brojac = 0;
    Cvor *temp = glava;
    while (temp != nullptr)
    {
        brojac++;
        temp = temp->sljedeci;
    }

    return brojac;
}

void ispisiListu()
{
    if (!isListaEmpty())
    {
        Cvor *temp = glava;
        while (temp != nullptr)
        {
            cout << temp->vrijednost << " ";
            temp = temp->sljedeci;
        }
    }
    else
    {
        cout << "Lista je prazna";
    }
}

int main()
{
    int opcija = 1;
    int element, pozicija;

    while (opcija != -1)
    {
        cout << "\nMENI\n";
        cout << "1. Dodaj na pocetak \n";
        cout << "2. Dodaj na kraj \n";
        cout << "3. Dodaj na poziciju \n";
        cout << "4. Obrisi sa pocetka \n";
        cout << "5. Obrisi sa kraja \n";
        cout << "6. Obrisi sa pozicije \n";
        cout << "7. Ispisi listu \n";
        cout << "8. Broj cvorova \n";

        cout << "Unesi opciju: ";
        cin >> opcija;

        switch (opcija)
        {
        case 1:
            cout << "Unesi element: ";
            cin >> element;
            dodajCvorNaPocetak(element);
            break;
        case 2:
            cout << "Unesi element: ";
            cin >> element;
            dodajCvorNaKraj(element);
            break;
        case 3:
            cout << "Unesi element: ";
            cin >> element;
            cout << "Unesi poziciju: ";
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
            cout << "Unesi poziciju: ";
            cin >> pozicija;
            if (prebrojCvorove() == pozicija)
            {
                izbrisiCvorNaKraju();
            }
            else
            {
                izbrisiCvorNaPoziciji(pozicija);
            }
            break;
        case 7:
            ispisiListu();
            break;
        case 8:
            cout << "Broj cvorova je: " << prebrojCvorove();
            break;
        }
    }
    return 0;
}