#include <iostream>
using namespace std;

const int MAX = 10;

struct Stek
{
    int stek[MAX];
    int top;
    int velicina = 0;
};

typedef struct Stek st;

void ispisSteka(st *s)
{
    cout << "Stek: \n"
         << endl;
    for (int i = 0; i < s->velicina; i++)
    {
        cout << s->stek[i] << " ";
    }
    cout << endl;
}

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isEmpty(st *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(st *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(st *s, int noviElement)
{
    if (isfull(s))
    {
        cout << "Stek je pun";
    }
    else
    {
        s->top++;
        s->stek[s->top] = noviElement;
        s->velicina++;
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        cout << "Stek je prazan";
    }
    else
    {
        cout << "Izbačenni element= " << s->stek[s->top];
        s->top--;
        s->velicina--;
    }
}

int main()
{
    int noviElement;
    st *s = new st;

    createEmptyStack(s);

    int opcija;
    do
    {
        cout << "\nMENI" << endl;
        cout << "1. Ispisi stek" << endl;
        cout << "2. Provjeri jel prazan stek" << endl;
        cout << "3. Dodaj element u stek" << endl;
        cout << "4. Izbaci element iz steka" << endl;
        cout << "5. Provjeri jel pun stek" << endl;
        cout << "Za izlaz pritisnite -1" << endl;

        cout << "Odaberite opciju" << endl;
        cin >> opcija;
        if (opcija < 1 || opcija > 5)
        {
            cout << "Nevazeca opcija." << endl;
        }

        if (opcija == 1)
        {
            ispisSteka(s);
        }
        else if (opcija == 2)
        {
            if (isEmpty(s))
            {
                cout << "Prazan \n";
            }
            else
            {
                cout << "Nije prazan \n";
            };
        }
        else if (opcija == 3)
        {
            cout << "Unesi novi element: " << endl;
            cin >> noviElement;
            push(s, noviElement);
        }
        else if (opcija == 4)
        {
            pop(s);
        }
        else if (opcija == 5)
        {
            if (isfull(s))
            {
                cout << "Pun stek \n";
            }
            else
            {
                cout << "Nije pun stek \n";
            };
        }
    } while (opcija != -1);

    delete s;

    return 0;
}