#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    struct Cvor *sljedeci;
};

struct Cvor *addToEmpty(struct Cvor *zadnji, int vrijednost)
{
    if (zadnji != NULL)
        return zadnji;

    // allocate memory to the new node
    struct Cvor *noviCvor = new Cvor;

    // assign data to the new node
    noviCvor->vrijednost = vrijednost;

    // assign last to newNode
    zadnji = noviCvor;

    // create link to iteself
    zadnji->sljedeci = zadnji;

    return zadnji;
}

// add node to the end
struct Cvor *addEnd(struct Cvor *zadnji, int vrijednost)
{
    // check if the node is empty
    if (zadnji == NULL)
        return addToEmpty(zadnji, vrijednost);

    // allocate memory to the new node
    struct Cvor *noviCvor = new Cvor;

    // add data to the node
    noviCvor->vrijednost = vrijednost;

    // store the address of the head node to next of newNode
    noviCvor->sljedeci = zadnji->sljedeci;

    // point the current last node to the newNode
    zadnji->sljedeci = noviCvor;

    // make newNode as the last node
    zadnji = noviCvor;

    return zadnji;
}

// add node to the front
struct Cvor *addFront(struct Cvor *zadnji, int vrijednost)
{
    // check if the list is empty
    if (zadnji == NULL)
        return addToEmpty(zadnji, vrijednost);

    // allocate memory to the new node
    struct Cvor *noviCvor = new Cvor;

    // add data to the node
    noviCvor->vrijednost = vrijednost;

    // store the address of the current first node in the newNode
    noviCvor->sljedeci = zadnji->sljedeci;

    // make newNode as head
    zadnji->sljedeci = noviCvor;

    return zadnji;
}

// insert node after a specific node
struct Cvor *addAfter(struct Cvor *zadnji, int vrijednost, int pozicija)
{
    // check if the list is empty
    if (zadnji == NULL)
        return NULL;

    struct Cvor *noviCvor, *p;

    p = zadnji->sljedeci;
    do
    {
        // if the item is found, place newNode after it
        if (p->vrijednost == pozicija)
        {
            // allocate memory to the new node
            noviCvor = new Cvor;
            // add data to the node
            noviCvor->vrijednost = vrijednost;

            // make the next of the current node as the next of newNode
            noviCvor->sljedeci = p->sljedeci;

            // put newNode to the next of p
            p->sljedeci = noviCvor;

            // if p is the last node, make newNode as the last node
            if (p == zadnji)
                zadnji = noviCvor;
            return zadnji;
        }

        p = p->sljedeci;
    } while (p != zadnji->sljedeci);

    cout << "\nThe given node is not present in the list" << endl;
    return zadnji;
}

// delete a node
void deleteNode(Cvor **zadnji, int kljuc)
{
    // if linked list is empty
    if (*zadnji == NULL)
        return;

    // if the list contains only a single node
    if ((*zadnji)->vrijednost == kljuc && (*zadnji)->sljedeci == *zadnji)
    {
        free(*zadnji);
        *zadnji = NULL;
        return;
    }

    Cvor *temp = *zadnji, *d;

    // if last is to be deleted
    if ((*zadnji)->vrijednost == kljuc)
    {
        // find the node before the last node
        while (temp->sljedeci != *zadnji)
            temp = temp->sljedeci;

        // point temp node to the next of last i.e. first node
        temp->sljedeci = (*zadnji)->sljedeci;
        free(*zadnji);
        *zadnji = temp->sljedeci;
    }

    // travel to the node to be deleted
    while (temp->sljedeci != *zadnji && temp->sljedeci->vrijednost != kljuc)
    {
        temp = temp->sljedeci;
    }

    // if node to be deleted was found
    if (temp->sljedeci->vrijednost == kljuc)
    {
        d = temp->sljedeci;
        temp->sljedeci = d->sljedeci;
        free(d);
    }
}

void traverse(struct Cvor *zadnji)
{
    struct Cvor *p;

    if (zadnji == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }

    p = zadnji->sljedeci;

    do
    {
        cout << p->vrijednost << " ";
        p = p->sljedeci;

    } while (p != zadnji->sljedeci);
}

int main()
{
    struct Cvor *last = NULL;

    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addFront(last, 2);

    last = addAfter(last, 10, 2);

    traverse(last);

    deleteNode(&last, 8);
    cout << endl;

    traverse(last);

    return 0;
}