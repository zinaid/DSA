#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

Cvor *top = nullptr;

void push(int element)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = element;
    noviCvor->sljedeci = top;
    top = noviCvor;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Stack je prazan." << endl;
        return;
    }
    Cvor *temp = top;
    top = top->sljedeci;
    delete (temp);
}

void display()
{
    if (top == nullptr)
    {
        cout << "Stack je prazan." << endl;
        return;
    }
    Cvor *temp = top;
    while (temp != nullptr)
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}
