#include <iostream>
#include <vector>
using namespace std;

void swapElements(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void printHeap(vector <int> &hT){
    for(int i=0;i<hT.size();i++){
        cout<<hT[i];
    }
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

    // Bubble up
    while (index > 0 && hT[index] > hT[parentIndex])
    {
        swap(hT[index], hT[parentIndex]);

        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void deleteElement(vector<int> &hT, int numToDelete)
{
    // nadjemo velicinu
    int size = hT.size();
    int i;
    // for petlja za pronalazak elementa
    for (i = 0; i < size; i++)
    {
        // u ovom trenutku ulovi poziciju elementa za brisati
        if (numToDelete == hT[i])
            break;
    }

    // zamjena zadnjeg elementa i elementa na poziciju koju smo nasli
    swapElements(hT[i], hT[size - 1]);

    // brisemo zadnji element
    hT.pop_back();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

int peek(vector <int> &hT){
    return hT[0];
}

int main(){
    int opcija = 0;
    int element;

    vector <int> heapTree;

    do{
        cout<<"MENI"<<endl;
        cout<<"1. Dodaj element u heap"<<endl;
        cout<<"2. Izbrisi element u heapu"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Ispis heapa"<<endl;
        cout<<"-1 EXIT"<<endl;

        cout<<"Odaberi opciju"<<endl;
        cin>>opcija;

        if(opcija == 1){
            cout<<"Unesite element"<<endl;
            cin>>element;
            insert(heapTree, element);
        }else if(opcija == 2){
            cout<<"Unesite element koji zelite obrisati"<<endl;
            cin>>element;
            deleteElement(heapTree, element);
        }else if(opcija == 3){
            cout<<peek(heapTree);
        }else if(opcija == 4){
            printHeap(heapTree);
        }else{
            cout<<"Greska"<<endl;
        }

    }while(opcija != -1);

    return 0;
}