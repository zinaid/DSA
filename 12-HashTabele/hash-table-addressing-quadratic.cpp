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
    int i = 1;

    while (table[index].key != 0 && table[index].key != key)
    {
        index = (start_index + i * i) % table_size;
        i++;
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
    int i = 1;

    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            return table[index].value;
        }
        index = (start_index + i * i) % table_size;
        i++;
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
    int i = 1;

    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            table[index].key = 0;
            table[index].value = 0;
            return;
        }
        index = (start_index + i * i) % table_size;
        i++;
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
    insert(11, 40);
    insert(4, 60);
    cout << get(1) << endl;
    cout << get(2) << endl;
    cout << get(3) << endl;
    cout << get(11) << endl;
    cout << get(4) << endl;
    cout << get(5) << endl;
    remove(2);
    cout << get(2) << endl;
    return 0;
}
