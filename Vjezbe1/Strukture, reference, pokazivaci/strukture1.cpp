#include <iostream>
using namespace std;

int main()
{
    struct Osoba
    {
        int godine;
        string ime, prezime;
    };

    Osoba osoba1, osoba2;

    cout << "Unesite ime prve osobe: " << endl;
    cin >> osoba1.ime;
    cout << "Unesite prezime prve osobe:" << endl;
    cin >> osoba1.prezime;
    cout << "Unesite godine prve osobe:" << endl;
    cin >> osoba1.godine;

    cout << "Unesite ime druge osobe:" << endl;
    cin >> osoba2.ime;
    cout << "Unesite prezime druge osobe:" << endl;
    cin >> osoba2.prezime;
    cout << "Unesite godine druge osobe: " << endl;
    cin >> osoba2.godine;

    if (osoba1.godine > osoba2.godine)
    {
        cout << "Prva osoba: " << osoba1.ime << " " << osoba1.prezime << " je starija";
    }
    else
    {
        cout << "Druga osoba: " << osoba2.ime << " " << osoba2.prezime << " je starija";
    }

    return 0;
}