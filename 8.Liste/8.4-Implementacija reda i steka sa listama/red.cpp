#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

struct Queue
{
    Cvor *pocetak;
    Cvor *kraj;
};

Cvor *createNode(int data)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = data;
    noviCvor->sljedeci = nullptr;
    return noviCvor;
}

Queue *createQueue()
{
    Queue *queue = new Queue;
    queue->pocetak = queue->kraj = nullptr;
    return queue;
}

bool isEmpty(Queue *queue)
{
    return queue->pocetak == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(Queue *queue, int data)
{
    Cvor *noviCvor = createNode(data);
    if (queue->pocetak == nullptr)
    {
        queue->pocetak = queue->kraj = noviCvor;
        return;
    }
    queue->kraj->sljedeci = noviCvor;
    queue->kraj = noviCvor;
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return;

    Cvor *temp = queue->pocetak;
    queue->pocetak = queue->pocetak->sljedeci;

    if (queue->pocetak == nullptr)
        queue->kraj = nullptr;

    delete (temp);
}

// Function to get the element at the front of the queue
int front(Queue *queue)
{
    if (isEmpty(queue))
        return -1;

    return queue->pocetak->vrijednost;
}

// Function to get the element at the rear of the queue
int rear(Queue *queue)
{
    if (isEmpty(queue))
        return -1;

    return queue->kraj->vrijednost;
}

// Function to print the elements in the queue
void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue je prazan!" << endl;
        return;
    }
    cout << "Queue elementi su: ";
    Cvor *temp = queue->pocetak;
    while (temp != nullptr)
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;
    }
    cout << endl;
}

int main()
{
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    cout << "Element at front: " << front(queue) << endl;
    cout << "Element at rear: " << rear(queue) << endl;

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    cout << "Element at front: " << front(queue) << endl;
    cout << "Element at rear: " << rear(queue) << endl;

    dequeue(queue);

    printQueue(queue);

    cout << "Element at front: " << front(queue) << endl;
    cout << "Element at rear: " << rear(queue) << endl;

    dequeue(queue);

    printQueue(queue);

    cout << "Element at front: " << front(queue) << endl;
    cout << "Element at rear: " << rear(queue) << endl;

    dequeue(queue);
    printQueue(queue);

    cout << "Element at front: " << front(queue) << endl;
    cout << "Element at rear: " << rear(queue) << endl;

    return 0;
}
