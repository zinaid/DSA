#include <iostream>
using namespace std;

#define MAX_SIZE 100

// Struktura za red
struct Queue
{
    int pocetak;
    int kraj;
    int niz[MAX_SIZE];
};

// Funkcija za kreiranje praznog reda
Queue *createQueue()
{
    Queue *queue = new Queue;
    queue->pocetak = -1;
    queue->kraj = -1;
    return queue;
}

// Funkcija za provjeru je li red pun
bool isFull(Queue *queue)
{
    if (queue->kraj == MAX_SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funkcija za provjeru je li red prazan
bool isEmpty(Queue *queue)
{
    if (queue->pocetak == -1 && queue->kraj == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funkcija za dodavanje elementa u red
void enqueue(Queue *queue, int x)
{
    if (isFull(queue))
    {
        cout << "Red je pun\n";
        return;
    }
    if (isEmpty(queue))
    {
        queue->pocetak = 0;
        queue->kraj = 0;
    }
    else
    {
        queue->kraj++;
    }
    queue->niz[queue->kraj] = x;
}

// Funkcija za uklanjanje elemenata iz reda
void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Red je prazan\n";
        return;
    }
    if (queue->pocetak == queue->kraj)
    {
        queue->pocetak = -1;
        queue->kraj = -1;
    }
    else
    {
        queue->pocetak++;
    }
}

// Funkcija za dobijanje pocetka reda
int pocetak(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Red je prazan \n";
        return -1;
    }
    return queue->niz[queue->pocetak];
}

// Funkcija za dobijanje kraja reda
int kraj(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Red je prazan \n";
        return -1;
    }
    return queue->niz[queue->kraj];
}

// Funkcija za ispis reda
int ispis(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Red je prazan \n";
        return -1;
    }

    for (int i = queue->pocetak; i <= queue->kraj; i++)
    {
        cout << queue->niz[i] << " ";
    }

    cout << endl;
}

int main()
{
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    ispis(queue);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 22);
    ispis(queue);
    cout << "Pocetak reda: " << pocetak(queue) << endl;
    cout << "Kraj reda: " << kraj(queue) << endl;
    return 0;
}
