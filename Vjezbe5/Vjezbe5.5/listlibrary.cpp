#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Kreiranje prazne liste
    list<int> my_list;

    // Dodavanje elemenata u listu
    my_list.push_back(10);
    my_list.push_back(20);
    my_list.push_back(30);

    // Ispis liste
    cout << "List contents: ";
    for (auto it = my_list.begin(); it != my_list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Dodavanje na pocetak
    my_list.push_front(5);

    // Uklanjanje elementa iz liste
    my_list.remove(20);

    // Ispis liste
    cout << "List contents after modification: ";
    for (auto it = my_list.begin(); it != my_list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Velicina liste
    cout << "List size: " << my_list.size() << endl;

    // Provjera je li lista prazna
    cout << "Is list empty? " << boolalpha << my_list.empty() << endl;

    return 0;
}
