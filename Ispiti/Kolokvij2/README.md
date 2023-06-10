# DRUGI KOLOKVIJ IZ PREDMETA ALGORITMI I STRUKTURE PODATAKA

HEAP – 35b

1. Implementirati min-heap sa sljedećim opcijama:
	# MENI
    1.DODAJ ČVOR
    2.IZBRIŠI ČVOR
    3.ISPIŠI NIZ
    4.VIDI NAJMANJI ELEMENT (PEEK)
UNESITE -1 ZA IZLAZAK IZ MENIJA

Program implementirati  koristeći sljedeće deklaracije funkcija:

```c++
void insertNode(vector<int> &hT, int newNum);
void deleteNode(vector<int> &hT, int num);
void print(const vector <int> &hT);
void heapify(vector<int> &hT, int i);
void swap(int &a, int &b);
void peek(const vector<int> &hT);
```
Napomena: Meni 2b, heapify 10b, dodaj čvor 10b, izbriši čvor 5b, ispis niza 3b, peek 5b

HASH TABELA – 25 bodova
2.	Implementirati hash tabelu koristeći sljedeće funkcije:

```c++
Node *create_node(int key, int value);
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
    Node *next;
};
```

Main funkcija je:

```c++
int main()
{
    insert(1, 11);
    insert(2, 22);
    insert(3, 33);
    cout << get(1) << endl;
    cout << get(2) << endl;
    cout << get(3) << endl;
    remove(2);
    cout << get(2) << endl;
    return 0;
}
```

Problem kolizije riješiti:
a)	Metodom ulančavanja

Napomena: Dodavanje čvora 10b, Pregled čvora 5b, Brisanje čvora 5b, Ulančavanje 5b

    ALGORITMI SORTIRANJA I PRETRAGE – 40b
3.	Napisati program koji vrši binarnu pretragu nad vektorom cijelih brojeva. Program treba tražiti od korisnika da unese elemente. Unos elemenata traje dok god se ne unese broj -1. Nakon toga program ispisuje unešeni vektor. Zatim, program treba tražiti od korisnika da unese ciljni broj koji želi pronaći u nizu. Program treba ispisati da li je broj pronađen u nizu i njegovu poziciju ako je pronađen, ili poruku koja ukazuje da broj nije prisutan u nizu. Za sortiranje niza prije binarne pretrage koristiti Merge sort. Izračunati i objasniti vremensku i prostornu složenost napisanog koda.

Implementirati sljedeće funkcije:

```c++
vector<int> enterVector();
int binarySearch(const vector<int> &vec, const int &target, int low, int high);
void mergeSort(vector<int> &vec, int left, int right);
void merge(vector<int> &vec, int left, int mid, int right);
void print(const vector<int> &vec);
```
Napomena: Osnovna struktura zadatka 5b, Binarna pretraga 15b, Merge sort 15b, Složenost 5b
