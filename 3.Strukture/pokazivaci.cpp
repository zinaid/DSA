#include <iostream>
using namespace std;

int main()
{
    string hrana = "Burek";
    // Pokazivac je varijabla koja sprema memorijsku adresu druge varijable
    string *pokazivac = &hrana;

    // Pokazivac ce ispisati memorijsku adresu kao i &hrana, ali pokazivac ima i
    // svoju memorijsku adresu
    cout << hrana << endl;
    cout << &hrana << endl;
    cout << pokazivac << endl;
    cout << &pokazivac << endl;

    // Dereferenciranje
    cout << *pokazivac << endl;

    // Modificiranje pokazivaca
    *pokazivac = "Sirnica";

    cout << *pokazivac << endl;
    cout << hrana << endl;

    return 0;
}