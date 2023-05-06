# Napraviti program koji implementira hash tabelu i sadrži sljedeće funkcije:

```c++


int hash_func(int key);

void insert(int key, int value);

int get(int key);

void remove(int key);
```

Struktura čvora je:

```c++
struct Node
{
    int key;
    int value;
};
```

Main funkcija je sljedeća:

```c++
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
```

Problem kolizije riješiti 

a) koristeći metodu otvorenog adresiranja i linearnog sondiranja.

b) koristeći metodu otvorenog adresiranja i kvadratnog sondiranja

c) koristeći metodu otvorenog adresiranja i duplog heširanja