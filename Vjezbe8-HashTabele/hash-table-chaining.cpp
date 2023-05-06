#include <iostream>
#include <vector>
using namespace std;

const int table_size = 10;

struct Node
{
    int key;
    int value;
    Node *next;
};

Node *create_node(int k, int v)
{
    Node *new_node = new Node;
    new_node->key = k;
    new_node->value = v;
    new_node->next = nullptr;
    return new_node;
}

// Kreira vektor naziva table koji cuva pokazivace na cvorove i inicijalizira na nullptr za duzinu tabele
vector<Node *> table(table_size, nullptr);

int hash_func(int key)
{
    return key % table_size;
}

void insert(int key, int value)
{
    // kupi indeks iz hash funkcije
    int index = hash_func(key);
    // kreira novi cvor
    Node *new_node = create_node(key, value);
    // da li vec postoji element na tom indeksu i ako nema stavi novi cvor
    // ako vec postoji onda metodom ulancavanja stavi da je trenutni jednak elementu na tom indeksu
    // i kad dodjes do kraja liste postavi da trenutni pokazuje na novi cvor
    if (table[index] == nullptr)
    {
        table[index] = new_node;
    }
    else
    {
        Node *curr = table[index];
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

int get(int key)
{
    int index = hash_func(key);
    Node *curr = table[index];
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            return curr->value;
        }
        curr = curr->next;
    }
    return -1;
}

void remove(int key)
{
    int index = hash_func(key);
    Node *curr = table[index];
    Node *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            if (prev == nullptr)
            { // radi se o prvom cvoru i stavi da je cvor na indeksu sljedeci od trenutnog
                table[index] = curr->next;
            }
            else
            {
                // ovo znaci da je u nekoj od sljedecih iteracija u kojima je nadjen taj element uslo ovdje
                // postavi da je sljedeci od prethodnog sljedeci od trenutnog
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        // ako ima vise od jednog clana postavit ce prosli na trenutni, a trenutni na sljedeci od trenutnog
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    cout << get(1) << endl;
    cout << get(2) << endl;
    cout << get(3) << endl;
    remove(2);
    cout << get(2) << endl;
    return 0;
}
