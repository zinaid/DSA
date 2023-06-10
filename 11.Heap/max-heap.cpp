#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void heapify(vector<int> &hT, int i)
{
    // izracuna velicinu niza
    int size = hT.size();
    // postavi da je najveci trenutno i
    int largest = i;
    // nadje njegovu djecu
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    // ako je lijevo dijete unutar velicine niza i ako je
    // lijevo dijete vece od najveceg postavi najveci za lijevo dijete
    if (l < size && hT[l] > hT[largest])
        largest = l;
    // isto ponovi za desno dijete
    if (r < size && hT[r] > hT[largest])
        largest = r;

    // ako se najveci razlikuje od i-tog odradi swap trenutnog elementa u nizu i najveceg
    if (largest != i)
    {
        swap(hT[i], hT[largest]);
        // pozovi heapify nad najvećim
        heapify(hT, largest);
    }
}

void insert(vector<int> &hT, int newNum)
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

void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
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

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Max-Heap: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "Nakon brisanje elementa: ";

    printArray(heapTree);
}