#include <iostream>
using namespace std;

int main()
{
    string hrana = "Burek";
    string &obrok = hrana;

    // Ispis vrijednosti varijable hrana i reference obrok
    cout << hrana << endl;
    cout << obrok << endl;

    // Ispis memorijskih adresa varijable hrana i reference
    cout << &hrana << endl;
    cout << &obrok << endl;

    obrok = "Pita";
    cout << hrana << endl;
    cout << obrok << endl;
    return 0;
}