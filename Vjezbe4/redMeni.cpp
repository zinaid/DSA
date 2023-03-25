#include <iostream>
using namespace std;

const int MAX = 10;

struct Red
{
    int pocetak;
    int kraj;
    int niz[MAX];
};

void inicijalizirajRed(Red *red)
{
    red->pocetak = -1;
    red->kraj = -1;
};

bool isFull(Red *red)
{
    if (red->kraj == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool isEmpty(Red *red)
{
    if (red->kraj == -1 && red->pocetak == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void enQueue(Red *red, int element)
{
    if (isFull(red))
    {
        cout << "Red je već pun" << endl;
        return;
    }

    if (isEmpty(red))
    {
        red->pocetak = 0;
        red->kraj = 0;
    }
    else
    {
        red->kraj++;
    }

    red->niz[red->kraj] = element;
}

void deQueueu(Red *red)
{
    if (isEmpty(red))
    {
        cout << "Red je već prazan";
        return;
    }

    if (red->pocetak == red->kraj)
    {
        red->pocetak = -1;
        red->kraj = -1;
    }
    else
    {
        red->pocetak++;
    }
}

int pocetakReda(Red *red)
{
    if (isEmpty(red))
    {
        cout << "Red je prazan \n";
        return -1;
    }
    else
    {
        cout << "Pocetak je: " << red->niz[red->pocetak] << endl;
    }

    return red->niz[red->pocetak];
}

int krajReda(Red *red)
{
    if (isEmpty(red))
    {
        cout << "Red je prazan \n";
        return -1;
    }
    else
    {
        cout << "Kraj je: " << red->niz[red->kraj] << endl;
    }

    return red->niz[red->kraj];
}

void ispisiRed(Red *red)
{
    if (isEmpty(red))
    {
        cout << "Red je prazan" << endl;
        return;
    }

    cout << "Red je: ";
    for (int i = red->pocetak; i <= red->kraj; i++)
    {
        cout << red->niz[i] << " ";
    }
    cout << endl;
}

int main()
{
    int opcija = 0;
    int element;
    Red *red = new Red;

    inicijalizirajRed(red);

    while (opcija != -1)
    {
        cout << "\nMENI" << endl;
        cout << "1. DODAJ ELEMENT" << endl;
        cout << "2. UKLONI ELEMENT" << endl;
        cout << "3. ISPISI ELEMENTE REDA" << endl;
        cout << "4. VIDI ELEMENT NA POCETKU" << endl;
        cout << "5. VIDI ELEMENT NA KRAJU" << endl;
        cout << "6. PROVJERI JE LI RED PUN" << endl;
        cout << "7. PROVJERI JE LI RED PRAZAN" << endl;
        cout << "Izlaz je -1." << endl;

        cout << "Odaberite opciju: ";
        cin >> opcija;

        switch (opcija)
        {
        case 1:
            cout << "\nOdabrali ste dodavanje elementa u red. \n";
            cout << "Unesite element: ";
            cin >> element;
            enQueue(red, element);
            break;

        case 2:
            cout << "\nOdabrali ste brisanje elementa iz reda. \n";
            deQueueu(red);
            break;

        case 3:
            cout << "Odabrali ste ispis reda. \n";
            ispisiRed(red);
            break;

        case 4:
            cout << "Odabrali ste prikaz pocetka reda. \n";
            pocetakReda(red);
            break;

        case 5:
            cout << "Odabrali ste prikaz kraja reda. \n";
            krajReda(red);
            break;

        case 6:
            cout << "Odabrali ste opciju provjere je li red pun. \n";
            if (isFull(red))
            {
                cout << "\nRed je pun" << endl;
            }
            else
            {
                cout << "\nRed nije pun" << endl;
            }
            break;

        case 7:
            cout << "Odabrali ste opciju provjere je li red prazan. \n";
            cout << ((isEmpty(red)) ? "\nRed je prazan.\n" : "\nRed nije prazan.\n"); // Ternarni operator za if else uslov u C++
            break;

        case -1:
            cout << "Izlazim ..." << endl;
            break;
        default:
            cout << "Odabrali ste pogresnu opciju" << endl;
            break;
        }
    };
    return 0;
}