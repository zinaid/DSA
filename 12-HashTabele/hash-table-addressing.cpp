#include <iostream>
#include <vector>
using namespace std;

const int table_size = 10;

struct Node
{
    int key;
    int value;
};

// Kreira vektor naziva table koji cuva cvorove za tablicu
vector<Node> table(table_size);

int hash_func(int key)
{
    return key % table_size;
}

void insert(int key, int value)
{
    int index = hash_func(key);
    int start_index = index;

    while (table[index].key != 0 && table[index].key != key)
    {
        index = (index + 1) % table_size;
        if (index == start_index)
        {
            cout << "Hash tabela je puna" << endl;
            return;
        }
    }

    table[index].key = key;
    table[index].value = value;
}

int get(int key)
{
    int index = hash_func(key);
    int start_index = index;

    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            return table[index].value;
        }
        index = (index + 1) % table_size;
        if (index == start_index)
        {
            break;
        }
    }

    return -1;
}

void remove(int key)
{
    int index = hash_func(key);
    int start_index = index;

    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            table[index].key = 0;
            table[index].value = 0;
            return;
        }
        index = (index + 1) % table_size;
        if (index == start_index)
        {
            break;
        }
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
