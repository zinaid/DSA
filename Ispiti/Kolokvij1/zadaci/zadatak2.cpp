#include <iostream>
using namespace std;
const int MAX = 10;

struct Red
{
    int niz[MAX];
    int glava;
    int rep;
};

Red *createRed()
{
    Red *red = new Red();
    red->glava = -1;
    red->rep = -1;
    return red;
}

bool isEmpty(Red *red)
{
    if (red->glava == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Red *red)
{
    if (red->rep == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void addElement(Red *red, int element)
{
    if (!isFull(red))
    {
        if (isEmpty(red))
        {
            red->glava = 0;
            red->rep = 0;
        }
        else
        {
            red->rep++;
        }

        red->niz[red->rep] = element;
    }
    else
    {
        cout << "Red je pun";
    }
}

void removeElement(Red *red)
{
    if (!isEmpty(red))
    {
        if (red->glava == red->rep)
        {
            red->glava = -1;
            red->rep = -1;
        }
        else
        {
            red->glava++;
        }
    }
    else
    {
        cout << "Red je prazan";
    }
}

void printRed(Red *red)
{
    if (!isEmpty(red))
    {
        for (int i = red->glava; i <= red->rep; i++)
        {
            cout << red->niz[i] << " ";
        }
    }
    else
    {
        cout << "Red je prazan";
    }
}

int main()
{
    int opcija = 0;
    int element;

    Red *red = createRed();

    while (opcija != -1)
    {
        cout << "\nMENI \n";
        cout << "1.DODAJ ELEMENT U RED\n";
        cout << "2. UKLONI ELEMENT IZ REDA\n";
        cout << "3. ISPIS REDA\n";
        cout << "UNESITE -1 ZA IZLAZAK IZ MENIJA\n";

        cout << "Odaberi: ";
        cin >> opcija;

        if (opcija == 1)
        {
            cout << "Unesite element: ";
            cin >> element;
            addElement(red, element);
        }
        else if (opcija == 2)
        {
            removeElement(red);
        }
        else if (opcija == 3)
        {
            printRed(red);
        }
        else
        {
            cout << "Izlazite ...";
            break;
        }
    }
    return 0;
}