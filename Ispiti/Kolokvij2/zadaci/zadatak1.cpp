#include <iostream>
#include <vector>
using namespace std;

void insertNode(vector<int> &hT, int newNum);
void deleteNode(vector<int> &hT, int num);
void print(const vector<int> &hT);
void heapify(vector<int> &hT, int i);
void swap(int &a, int &b);
void peek(const vector<int> &hT);

int main()
{
    vector<int> hT;
    int newNum;
    int opcija = 0;
    while (opcija != -1)
    {
        cout << "\nMENI\n";
        cout << "1.Dodaj cvor\n";
        cout << "2.Izbrisi cvor\n";
        cout << "3.Ispisi niz\n";
        cout << "4.Vidi najmanji element(Peek)\n";

        cout << "Odaberite opciju: ";
        cin >> opcija;

        switch (opcija)
        {
        case 1:
            cout << "Unesite element: ";
            cin >> newNum;
            insertNode(hT, newNum);
            break;

        case 2:
            cout << "Unesite element koji zelite obrisati: ";
            cin >> newNum;
            deleteNode(hT, newNum);
            break;

        case 3:
            print(hT);
            break;

        case 4:
            peek(hT);
            break;

        case -1:
            cout << "Izlazite iz programa ...";
            break;
        default:
            break;
        }
    }

    return 0;
}

void print(const vector<int> &hT)
{
    if (hT.size() == 0)
    {
        cout << "Heap je prazan" << endl;
        return;
    }

    for (int i = 0; i < hT.size(); i++)
    {
        cout << hT[i] << " ";
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertNode(vector<int> &hT, int newNum)
{
    hT.push_back(newNum);

    int index = hT.size() - 1;
    int parentIndex = (index - 1) / 2;

    while (index > 0 && hT[index] < hT[parentIndex])
    {
        swap(hT[index], hT[parentIndex]);

        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }

    for (int i = hT.size() / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

void heapify(vector<int> &hT, int i)
{
    // izracuna velicinu niza
    int size = hT.size();
    // postavi da je najmanji trenutno i
    int smallest = i;
    // nadje njegovu djecu
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // ako je lijevo dijete unutar velicine niza i ako je
    // lijevo dijete manje od najmanjeg postavi najmanji za lijevo dijete
    if (l < size && hT[l] < hT[smallest])
        smallest = l;
    // isto ponovi za desno dijete
    if (r < size && hT[r] < hT[smallest])
        smallest = r;

    // ako se najmanji razlikuje od i-tog odradi swap trenutnog elementa u nizu i najmanjeg
    if (smallest != i)
    {
        swap(hT[i], hT[smallest]);
        // pozovi heapify nad najmanjim
        heapify(hT, smallest);
    }
}

void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    if (size == 0)
    {
        cout << "Heap je prazan" << endl;
        return;
    }

    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(hT[i], hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

void peek(const vector<int> &hT)
{
    if (hT.size() == 0)
    {
        cout << "Heap je prazan" << endl;
    }
    else
    {
        cout << "Najmanji element je: " << hT[0] << endl;
    }
}