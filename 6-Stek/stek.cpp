#include <iostream>

using namespace std;

const int MAX = 10;

// Kreiranje strukture stack
struct stack
{
    int stek[MAX];
    int top;
    int velicina = 0;
};
typedef struct stack st; // typedef nam omogucuje da sad koristimo alias st za kreiranje strukture tipa stack

void createEmptyStack(st *s);
int isfull(st *s);
int isempty(st *s);
void push(st *s, int newitem);
void pop(st *s);
void printStack(st *s);

int main()
{
    st *s = new st;

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nNakon izbacivanja: \n";
    printStack(s);
}

void createEmptyStack(st *s)
{
    s->top = -1;
}

// Provjera jel stek pun
int isfull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Provjera jel stek prazan
int isempty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Dodaj element u stek
void push(st *s, int newitem)
{
    if (isfull(s))
    {
        cout << "Pun stek";
    }
    else
    {
        s->top++;
        s->stek[s->top] = newitem;
        s->velicina++;
    }
}

// Obrisi element iz steka
void pop(st *s)
{
    if (isempty(s))
    {
        cout << "\n Prazan stek \n";
    }
    else
    {
        cout << "Izbacen element= " << s->stek[s->top];
        s->top--;
        s->velicina--;
    }
    cout << endl;
}

// Ispisi elemente iz steka
void printStack(st *s)
{
    printf("Stek: ");
    for (int i = 0; i < s->velicina; i++)
    {
        cout << s->stek[i] << " ";
    }
    cout << endl;
}
